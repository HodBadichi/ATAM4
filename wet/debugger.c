
#include <stdio.h>
#include "utils.h"
#include <unistd.h>
#include <sys/types.h>
#include <sys/ptrace.h>
#include <sys/user.h>
#include <stdlib.h>
#include <assert.h>
#include <sys/wait.h>

pid_t run_target( char* argv[]);
void runDebuggerSysFailsCnt(pid_t child_pid,char*argv[]);
void setBp(unsigned  long address,pid_t child_pid,unsigned  long *old_instruction);

int main(int argc,char** argv)
{
    pid_t child_pid;
    child_pid = run_target(argv);
    runDebuggerSysFailsCnt(child_pid,argv);
    return 0;
}

void setBp(unsigned  long address,pid_t child_pid,unsigned  long *old_instruction)
{
    *old_instruction = ptrace(PTRACE_PEEKTEXT,child_pid,(void*)address,NULL);
    unsigned long  new_instruction = (*old_instruction & 0XFFFFFFFFFFFFFF00) | 0xCC;
    ptrace(PTRACE_POKETEXT,child_pid,(void*)address,(void*)new_instruction);
}

unsigned  long getPostFuncAddress(pid_t child_pid)
{
    struct user_regs_struct regs;
    ptrace(PTRACE_GETREGS, child_pid,NULL, &regs);
    return ptrace(PTRACE_PEEKTEXT, child_pid, (void*)regs.rsp,NULL);
}

void runDebuggerSysFailsCnt(pid_t child_pid,char*argv[])
{
    int wait_status;
    int sys_calls_failure_cnt = 0;
    unsigned  long func_inst,post_func_inst ;
    unsigned long ret_rsp_val;
    struct user_regs_struct regs;
    unsigned  long func_address = get_function_address(argv[1],argv[2]);
    wait(&wait_status);
    while(1)
    {
        setBp(func_address,child_pid,&func_inst);    
            do
            {
                ptrace(PTRACE_CONT,child_pid,NULL,NULL);
                wait(&wait_status);
                ptrace(PTRACE_GETREGS, child_pid,NULL, &regs);
                if (WIFEXITED(wait_status))  
                {
                    return ;
                }
            } while (regs.rip-1 != func_address);
            ptrace(PTRACE_GETREGS, child_pid,NULL, &regs);
            ret_rsp_val = regs.rsp;
            unsigned  long post_func_address = getPostFuncAddress(child_pid);
            setBp(post_func_address,child_pid,&post_func_inst);
            ptrace(PTRACE_POKETEXT, child_pid, (void*)func_address, (void*) func_inst); //clean bp of func
            regs.rip-=1;
            ptrace(PTRACE_SETREGS, child_pid,NULL, &regs);
            unsigned long curr_inst;
            while(1)
            {
                do
                {
                    ptrace(PTRACE_SYSCALL, child_pid, NULL, NULL);
                    wait(&wait_status);
                    ptrace(PTRACE_GETREGS, child_pid,NULL, &regs);
                    if (WIFEXITED(wait_status))   
                    {
                        return ;
                    }
                    if ( regs.rip-1 == post_func_address)
                    {
                        break; 
                    }
                    curr_inst = ptrace(PTRACE_PEEKTEXT, child_pid,(void*)regs.rip-2, NULL);
                    curr_inst = (curr_inst & 0xffff);
                } while ((curr_inst != 0x050f) || 
                ( regs.rip-1 == post_func_address)&&(ret_rsp_val>regs.rsp));

                if ( regs.rip-1 == post_func_address && ret_rsp_val<regs.rsp)
                {
                    break; 
                }

                ptrace(PTRACE_SYSCALL, child_pid, NULL, NULL);
                wait(&wait_status);
                if (WIFEXITED(wait_status))
                {
                    return ;
                }    
                ptrace(PTRACE_GETREGS, child_pid,NULL, &regs);            
                if ( (long long)regs.rax < 0 )
                {
                    unsigned long rip_address=regs.rip-2;
                     long return_value = (long )regs.rax;
                    printf("PRF:: syscall in %lx returned with %ld\n",rip_address,return_value);
                }
            }
            ptrace(PTRACE_POKETEXT, child_pid, (void*)post_func_address, (void*)post_func_inst); //clean bp of post_func
            regs.rip-=1;
            ptrace(PTRACE_SETREGS, child_pid, 0, &regs);
    }   
    return ;
}

pid_t run_target( char* argv[])
{
    
    pid_t pid= fork();
    if (pid > 0)
    {
        return pid;
    }
    else if ( pid == 0)
    {
        if (ptrace(PTRACE_TRACEME,0,NULL,NULL))
        {
            perror("ptrace");
            exit(1);
        };
        execv(argv[2],argv);
    }
    else
    {
        perror("fork");
        exit(1);
    }
}