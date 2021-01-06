#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <unistd.h>
#include <string.h>

#define NUM_THREADS 5

void* test_thread(void* _threadid){
    long tid;
    tid = (long)_threadid;
    printf("HelloSCR. Written by thread %ld\n", tid);
    pthread_exit(NULL);
}

int main(int argc, char *argv[]){

/* identyfikator wątku */    
pthread_t threads[NUM_THREADS];

for(long i = 0;i < NUM_THREADS;i++)
    {
     pthread_create(&threads[i],NULL,test_thread,(void*)i);
    }

pthread_exit(NULL);
}
