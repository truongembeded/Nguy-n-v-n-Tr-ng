#include "pthread.h"
#include <stdio.h>
#include <conio.h>

int couter = 0;
pthread_mutex_t mutex1 = PTHREAD_MUTEX_INITIALIZER;
void * funcC(void *data)
{
	pthread_mutex_lock(&mutex1);
	couter += 100;
	printf("Gia tri couter trong Func:%d\n",couter);
	pthread_mutex_unlock(&mutex1);
	return NULL;
}
void * funcC1(void *data)
{
	pthread_mutex_lock(&mutex1);
	couter += 200;
	printf("Gia tri couter trong Func1:%d\n",couter);
	pthread_mutex_unlock(&mutex1);
	return NULL;
}
int main(int argc, char * argv[])
{
	pthread_t thread1, thread2;
	pthread_create(&thread1,NULL,&funcC,NULL);
	pthread_create(&thread2,NULL,&funcC1,NULL);
	pthread_join(thread1,NULL);
	pthread_join(thread2,NULL);
	printf("Gia tri cuoi cung cua counter: %d\n",couter);
	getch();
	return 0;
}