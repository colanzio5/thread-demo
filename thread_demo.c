/**
 * COLIN CASAZZA
 * CS570 - OPERATING SYSTEMS
 * CSSC1070
 * ASSIGNMENT THREE - THREADS
 * 3/13/19
 */
#include <iostream>
#include <stdio.h> 
#include <stdlib.h> 
#include <pthread.h>
#include "worker.h"

#define MAX_WORKERS 5

int main(int argc, char **argv)
{
    // allocate memory for worker threads
    pthread_t workers[MAX_WORKERS];
    // get arg or use dummy arg
    int arg;
    if(argc > 1) arg = atoi(argv[1]);
    else arg=5;
    // create worker threads
    for(int i = 0; i< MAX_WORKERS; i++)
    {
        pthread_create(&workers[i], NULL, worker, &arg);
    }
    // join all of the threads so they all complete
    for(int i =0; i< MAX_WORKERS; i++)
    {
        pthread_join(workers[i], NULL);
    }
    return 0;
}

