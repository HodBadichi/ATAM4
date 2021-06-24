#include <stdio.h>


char* name='555';

int num_of_loops_main=3;
int num_of_loops_func = 3;
int num_of_loops_recursion=3;


void helloworld()
{

}

int main(int argc, char **argv)
{
    for (int i=1; i<argc; i++){
        printf("argument %d: %s\n", i, argv[i]);
    }


}