
#include <stdio.h>


void hello_worl(int n)
{
  register int    syscall_no  asm("rax") = 84;
  register int    arg1        asm("rdi") = 1;
  register char*  arg2        asm("rsi") = "hello, world!\n";
  register int    arg3        asm("rdx") = 14;
  asm("syscall");

  register int    syscall_no2  asm("rax") = 1;
  register int    arg4        asm("rdi") = 1;
  register char*  arg5        asm("rsi") = "hello, world!\n";
  register int    arg6        asm("rdx") = 14;
  unsigned long regVal= 0;
  asm("syscall");

  register int    syscall_no3  asm("rax") = 84;
  register int    arg7        asm("rdi") = 1;
  register char*  arg8        asm("rsi") = "hello, world!\n";
  register int    arg9        asm("rdx") = 14;

  asm("syscall"); 
  n--;
  if (n == 0)
  {
    return ;
  }
  else
  {
    hello_worl(n);
  }


}

void hello_world(int n)
{
  register int    syscall_no  asm("rax") = 84;
  register int    arg1        asm("rdi") = 1;
  register char*  arg2        asm("rsi") = "hello, world!\n";
  register int    arg3        asm("rdx") = 14;
  asm("syscall");

  register int    syscall_no2  asm("rax") = 1;
  register int    arg4        asm("rdi") = 1;
  register char*  arg5        asm("rsi") = "hello, world!\n";
  register int    arg6        asm("rdx") = 14;
  unsigned long regVal= 0;
  asm("syscall");

  register int    syscall_no3  asm("rax") = 84;
  register int    arg7        asm("rdi") = 1;
  register char*  arg8        asm("rsi") = "hello, world!\n";
  register int    arg9        asm("rdx") = 14;

  asm("syscall"); 
  n--;
  if (n == 0)
  {
    return ;
  }
  else
  {
    hello_world(n);
  }


}


int main()
{

    hello_world(3);
    printf("bibi zibi\n");
     hello_world(2);
  
}