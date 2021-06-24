#include <stdio.h>
#include "utils.h"
int main()
{
  printf(" global_func address is %lx\n",get_function_address("hello_world","/home/student/Desktop/OS-HW4/ATAM4/wet/tests/function_parsing/global_func"));       
  printf(" local_func address is %lx\n",get_function_address("hello_world","/home/student/Desktop/OS-HW4/ATAM4/wet/tests/function_parsing/local_func"));
  printf(" longer_func address is %lx\n",get_function_address("hello_world","/home/student/Desktop/OS-HW4/ATAM4/wet/tests/function_parsing/longer_func"));
  printf(" missing_func address is %lx\n",get_function_address("hello_world","/home/student/Desktop/OS-HW4/ATAM4/wet/tests/function_parsing/missing_func"));
  printf(" shorter_func address is %lx\n",get_function_address("hello_world","/home/student/Desktop/OS-HW4/ATAM4/wet/tests/function_parsing/shorter_func"));
}