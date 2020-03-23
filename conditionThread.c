#include<stdio.h>
#include<string.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>

#define THRESHOLD     5

pthread_t tid;  /* Counter is a global variable used two thread */

int counter;

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;   /* Declare mutex */
pthread_cond_t cond = PTHREAD_COND_INITIALIZER;      /* Declare condition varible */

void threadFunc(void)
{
   pthread_mutex_lock(&mutex);  /* Lock mutex to protect counter */
   printf("pthread has started\n");

   while(counter < THRESHOLD)
   {
       counter += 1;
       sleep(5);
   }

   pthread_cond_signal(&cond);
   printf("pthread has finished, counter = %d\n", counter);
   pthread_mutex_unlock(&mutex);  /* Unlock mutex */

   pthread_exit(NULL);
}

int main(void)
{
   int ret = 0;

   ret = pthread_create(&tid, NULL, (void*)&(threadFunc), NULL);
   if (ret != 0)
   {
       printf("pthread created fail\n");
   }

   pthread_mutex_lock(&mutex);  /* Lock mutex to protect counter */
   while(counter < THRESHOLD)  /* Check counter value as expected */
   {
       pthread_cond_wait(&cond, &mutex);   /* Wait signal from another thread */
       printf("Global variable counter = %d.\n", counter);  /* Access counter */
   }

   pthread_mutex_unlock(&mutex);  /* Unlock mutex*/
   pthread_join(tid, NULL);

   return 0;
}