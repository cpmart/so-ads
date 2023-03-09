
#include <pthread.h>
#include <stdio.h>
#define NUM_THREADS     10

void *PrintHello(void *threadid);
void *Tabuada(void *threadid);

int main ()
{
    pthread_t threads[NUM_THREADS];
    int rc;
    long t;
    for(t=0; t<NUM_THREADS; t++){
        printf("Na main: criando thread %ld\n", t);
        if(t%2)
            rc = pthread_create(&threads[t], NULL, PrintHello, (void *)t);
        else
            rc = pthread_create(&threads[t], NULL, Tabuada, (void *)t);
        if (rc){
            printf("ERROR; return code from pthread_create() is %d\n", rc);
        }
    }
}
void *PrintHello(void *threadid)
{
    int tid;
    tid = (int)threadid;
    printf("Hello World! Eu sou a thread #%d!\n", tid);
    pthread_exit(NULL);
}
void *Tabuada(void *threadid)
{
    int tid, i;
    tid = (int)threadid;
    printf("Hello World! Eu sou a thread #%d!\n", tid);
    for (i=0; i<5; i++) {
        printf("%d x %d = %d\n",tid,i,tid*i);
    }
    pthread_exit(NULL);
}