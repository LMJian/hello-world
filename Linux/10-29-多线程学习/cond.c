#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<pthread.h>
#define num 2
pthread_cond_t cond;
pthread_mutex_t mutex;

int count=10000;

void* test(void* arg){
  (void)arg;
  while(1)
  {
    pthread_mutex_lock(&mutex);
    printf("传球！！！\n");
    usleep(123456);
    pthread_cond_signal(&cond);
    pthread_mutex_unlock(&mutex);
  }
}
void* test1(void* arg){
  (void)arg;
  while(1)
  {
    pthread_mutex_lock(&mutex);
    pthread_cond_wait(&cond,&mutex);
    printf("扣篮！！！\n");
    pthread_mutex_unlock(&mutex); 
  }
}
int main()
{
  pthread_cond_init(&cond,NULL);
  pthread_mutex_init(&mutex,NULL);
  pthread_t arr1,arr2; 
  pthread_create(&arr1,NULL,test,NULL);
  pthread_create(&arr2,NULL,test1,NULL);

  pthread_join(arr1,NULL);
  pthread_join(arr2,NULL);

  pthread_cond_destroy(&cond);
  pthread_mutex_destroy(&mutex);
  return 0;
}

