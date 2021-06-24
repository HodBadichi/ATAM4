#include <stdio.h>

char* name='555';

int num_of_loops_main=3;
int num_of_loops_func = 3;
int num_of_loops_recursion=3;



void hello_world()
{
        register int    syscall_no2  asm("rax") = 1;
        register int    arg4        asm("rdi") = 1;
        register char*  arg5        asm("rsi") = "hello, world!\n";
        register int    arg6        asm("rdx") = 14;
        unsigned long regVal= 0;
        asm("syscall"); //success call
        asm("syscall"); //success call



        register int    syscall_no3  asm("rax") = 84;
        register int    arg7        asm("rdi") = 1;
        register char*  arg8        asm("rsi") = "hello, world!\n";
        register int    arg9        asm("rdx") = 14;
        asm("syscall"); //failed call
        asm("syscall"); //failed call

}




int main()
{
    asm("syscall"); //failed call
    register int    syscall_no1  asm("rax") = 84;
    register int    arg1        asm("rdi") = 1;
    register char*  arg2        asm("rsi") = "hello, world!\n";
    register int    arg3        asm("rdx") = 14;
    asm("syscall"); //failed call

    hello_world();
    asm("syscall"); //failed call
    printf("hello, world");


    register int    syscall_no3  asm("rax") = 84;
    register int    arg7        asm("rdi") = 1;
    register char*  arg8        asm("rsi") = "hello, world!\n";
    register int    arg9        asm("rdx") = 14;
    asm("syscall"); //failed call
}