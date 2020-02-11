/* signal.c
 *
 * Group Members Names and NetIDs:
 *   1.Rahil Chertara; rc924
 *   2.Julian Seepersaud; jss395
 *
 * ILab Machine Tested on:
 *
 */

#include <signal.h>
#include <stdio.h>
#include <stdlib.h>

/* Part 1 - Step 2 to 4: Do your tricks here
 * Your goal must be to change the stack frame of caller (main function)
 * such that you get to the line after "r2 = *( (int *) 0 )"
 */


void segment_fault_handler(int signum)
{

    printf("I am slain!\n");

   
    /* Implement Code Here */

    int *ptr; 
    ptr = &signum; 
    char *p = (char*)ptr;
    p+=204;
    ptr = (int *)p;
    *ptr += 2;
}

int main(int argc, char *argv[])
{

    int r2 = 0;

    /* Part 1 - Step 1: Registering signal handler */
    signal(SIGSEGV, segment_fault_handler);
    /* Implement Code Here */

    r2 = *((int *)0); // This will generate segmentation fault

    printf("I live again!\n");

    return 0;
}