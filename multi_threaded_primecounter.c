#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

pthread_mutex_t myMutex = PTHREAD_MUTEX_INITIALIZER;

int count = 0;
unsigned int number = 2;

int IsItPrimeorNot(unsigned int value){
  
    int i;
    for(i = 2; i < value/2; i++){
        if(value%i == 0){//If value is not prime.
            return 0;
        }
    }
    return 1;
}
void *calculate(){

    while(number <= 100000){
        pthread_mutex_lock(&myMutex);
        int copy = number++;
        pthread_mutex_unlock(&myMutex);
        
        if(IsItPrimeorNot(copy) == 1){
            pthread_mutex_lock(&myMutex);
            count++;
            pthread_mutex_unlock(&myMutex);
        }
    }
}

int main (int argc, char *argv[])
{
    pthread_t t1, t2; // two threads
    int thread1, thread2;

    thread1 =
        pthread_create(&t1, NULL, calculate, NULL);
    thread2 =
        pthread_create(&t2, NULL, calculate, NULL);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    
    printf ("count is %d \n", count);
}