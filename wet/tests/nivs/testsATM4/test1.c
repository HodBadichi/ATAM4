#include <stdio.h>

char* name='555';

int num_of_loops_main=3;
int num_of_loops_func = 3;
int num_of_loops_recursion=3;

void hello_world(int n)
{
  if(n =0){
      return;
  }
    for (int i=0; i<num_of_loops_func; i++){
        register int    syscall_no  asm("rax") = 83;
        register int    arg1        asm("rdi") = &name;
        register char*  arg2        asm("rsi") = 0777;
        register int    arg3        asm("rdx") = 14;
        asm("syscall"); //success call

        register int    syscall_no2  asm("rax") = 1;
        register int    arg4        asm("rdi") = 1;
        register char*  arg5        asm("rsi") = "hello, world!\n";
        register int    arg6        asm("rdx") = 14;
        unsigned long regVal= 0;
        asm("syscall"); //success call


        register int    syscall_no3  asm("rax") = 84;
        register int    arg7        asm("rdi") = 1;
        register char*  arg8        asm("rsi") = "hello, world!\n";
        register int    arg9        asm("rdx") = 14;
        asm("syscall"); //failed call

        register int    syscall_no4  asm("rax") = 84;
        register int    arg10        asm("rdi") = name;
        register char*  arg11        asm("rsi") = 0777;
        register int    arg12        asm("rdx") = 14;
        asm("syscall"); //success call

                register int    syscall_no5  asm("rax") = 83;
        register int    arg13        asm("rdi") = 1;
        register char*  arg14       asm("rsi") = "hello, world!\n";
        register int    arg15       asm("rdx") = 14;
        asm("syscall"); //failed call

    }
    
}

void hello_world2(){
  register int    syscall_no2  asm("rax") = 1;
  register int    arg4        asm("rdi") = 1;
  register char*  arg5        asm("rsi") = "hello, world!\n";
  register int    arg6        asm("rdx") = 14;
  unsigned long regVal= 0;
  asm("syscall"); //success call

  register int    syscall_no3  asm("rax") = 84;
  register int    arg7        asm("rdi") = 1;
  register char*  arg8        asm("rsi") = "hello, world!\n";
  register int    arg9        asm("rdx") = 14;
  asm("syscall"); //failed call
}


int main()
{

    hello_world(num_of_loops_recursion);

    for(int i=0; i<num_of_loops_main; i++){
        hello_world(num_of_loops_recursion);
        hello_world(num_of_loops_recursion);
        hello_world2();
    }
    hello_world(num_of_loops_recursion);

}