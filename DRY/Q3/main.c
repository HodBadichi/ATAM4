#include <stdio.h>
#include <unistd.h>
#include <sys/syscall.h>
//int print_dynamic(int a,int b);
 void hello_world()
{
	   register int    syscall_no  asm("rax") = 1;
  	register int    arg1        asm("rdi") = 1;
  	register char*  arg2        asm("rsi") = "hello, world!\n";
  	register int    arg3        asm("rdx") = 14;
  	asm("syscall");
}


int main()
{
	hello_world();
	return 0;
}
