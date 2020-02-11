/* syscall.c
 *
 * Group Members Names and NetIDs:
 *   1.Rahil Chertara; rc924
 *   2.Julian Seepersaud; jss395
 *
 * ILab Machine Tested on: kill.cs.rutgers.edu
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <sys/syscall.h>

double avg_time = 0;

int main(int argc, char *argv[])
{
    double start_time = 0;
    double end_time = 0;
    double total = 0;
    struct timeval start, end;
    /* Implement Code Here */
    for (int i = 0; i < 5000000; i++)
    {

        gettimeofday(&start, NULL);

        syscall(SYS_getuid);

        gettimeofday(&end, NULL);

        start_time = 1000000 * start.tv_sec + start.tv_usec;
        end_time = 1000000 * end.tv_sec + end.tv_usec;
        total += end_time - start_time;
    }

    avg_time = total / 5000000;
    // Remember to place your final calculated average time
    // per system call into the avg_time variable

    printf("Average time per system call is %f microseconds\n", avg_time);

    return 0;
}