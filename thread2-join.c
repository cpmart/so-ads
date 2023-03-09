#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

#define N_THREAD 5

void delay(int n) {
    
    int i;
    int valor = 5;
    for (i = 0; i < valor; i++)
        printf("%d x %d = %d\n",n,i,n*i);
}

int *funcao(void *arg) {
    
    printf("Oi,");
    int *pvalor;
    pvalor = arg;
    printf (" executando %i ... \n", *pvalor);
    delay(*pvalor);
    printf ("finalizando %i ... \n", *pvalor);
    return 0;
}

int main() {
    pthread_t threads[N_THREAD];
    int i, arg[N_THREAD];
    for (i=0; i < N_THREAD; i++) {
        arg[i] = i + 1;
        pthread_create(&threads[i], NULL, funcao, (void *)&arg[i]);
        //pthread_join(threads[i], NULL);
        //Colocando o pthread_join nesta linha, as threads iniciam e só vão para a proxima quando é finalizada.
    }
    for (i = 0; i < N_THREAD; i++)
     pthread_join(threads[i], NULL);
     printf ("\n");
    for (i=15; i < 20; i++) {
        arg[i] = i + 1;
        pthread_create(&threads[i], NULL, funcao, (void *)&arg[i]);
        //pthread_join(threads[i], NULL);
        //Colocando o pthread_join nesta linha, as threads iniciam e só vão para a proxima quando é finalizada.
    }
    return 0;
}

