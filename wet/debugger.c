
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
int runDebuggerSysFailsCnt(pid_t child_pid,char*argv[]);
void plant_breaking_point(unsigned long address,unsigned long original_inst); 

//run_debugger(child_pid);

int main(int argc,char** argv)
{
    pid_t child_pid;
    child_pid = run_target(argv);
    printf("number of failed_sys_calls is : %d\n",runDebuggerSysFailsCnt(child_pid,argv));
    return 0;
}


void setBp(unsigned long address,pid_t child_pid,unsigned long *old_instruction)
{
    *old_instruction = ptrace(PTRACE_PEEKTEXT,child_pid,(void*)address,NULL);
    unsigned long long new_instruction = (*old_instruction & 0XFFFFFFFFFFFFFF00) | 0xCC;
    ptrace(PTRACE_POKETEXT,child_pid,(void*)address,(void*)new_instruction);
}

unsigned long getPostFuncAddress(pid_t child_pid)
{
    struct user_regs_struct regs;
    ptrace(PTRACE_GETREGS, child_pid,NULL, &regs);
    return ptrace(PTRACE_PEEKTEXT, child_pid, (void*)regs.rsp,NULL);
}

int runDebuggerSysFailsCnt(pid_t child_pid,char*argv[])
{
    int wait_status;
    int sys_calls_failure_cnt = 0;
    unsigned long func_inst,post_func_inst ;
    struct user_regs_struct regs;


    unsigned long func_address = get_function_address(argv[1],argv[2]);
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
                    return sys_calls_failure_cnt;
                }
            } while (regs.rip-1 != func_address);
            long post_func_address = getPostFuncAddress(child_pid);
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
                        return sys_calls_failure_cnt;
                    }
                    if ( regs.rip-1 == post_func_address)
                    {
                        break; 
                    }
                    curr_inst = ptrace(PTRACE_PEEKTEXT, child_pid,(void*)regs.rip-2, NULL);
                    curr_inst = (curr_inst & 0xffff);
                } while ((curr_inst != 0x050f) || ( regs.rip-1 == post_func_address));
                if ( regs.rip-1 == post_func_address)
                {
                        break; 
                }

                ptrace(PTRACE_SYSCALL, child_pid, NULL, NULL);
                wait(&wait_status);
                if (WIFEXITED(wait_status))
                {
                    return sys_calls_failure_cnt;
                }    
                ptrace(PTRACE_GETREGS, child_pid,NULL, &regs);            
                if ( (long long)regs.rax < 0 )
                {
                    sys_calls_failure_cnt++;
                }
            }
            ptrace(PTRACE_POKETEXT, child_pid, (void*)post_func_address, (void*)post_func_inst); //clean bp of post_func
            regs.rip-=1;
            ptrace(PTRACE_SETREGS, child_pid, 0, &regs);
    }   
    return sys_calls_failure_cnt;
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