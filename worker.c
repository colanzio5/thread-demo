#include <iostream>
#include "worker.h"

// take in an void * (integer) arg
// print the result of the arg to stdout
void *worker(void *arg) 
{
    int *number = (int *)arg;
    printf("%i\n",(*number) * (*number));
}