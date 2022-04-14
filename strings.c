#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
int number = 2;
int counter = 0;

int IsItPrimeornot(int value) {
   int i;
   for (i =2; i<= value/2; i++) {
      if (value%i == 0) {
         return 0;
      }
   }
   return 1;
}

void *calculate (  ) {

unsigned  mycopy;


while(number<=100000) {
    pthread_mutex_lock (&mutex);
          mycopy = number++;
    pthread_mutex_unlock (&mutex);

    unsigned int ret_value = IsItPrimeornot(mycopy) ;

    if(IsItPrimeornot(mycopy) == 1)  {
    pthread_mutex_lock (&mutex);
    counter++;
    pthread_mutex_unlock (&mutex);

    }
}
 

} 

int main ()
{
     pthread_t t1 , t2;
     int  thread1, thread2 ;


   thread1 = 
      pthread_create ( &t1, NULL, calculate, NULL);
   thread2 = 
      pthread_create ( &t2, NULL, calculate, NULL);



   printf ( "count is %d \n", counter) ;



}