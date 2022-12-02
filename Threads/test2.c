#include <stdio.h>
#include "pthread.h"


pthread_mutex_t mutex1 = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond1 = PTHREAD_COND_INITIALIZER;
void * funcC1(void * data);
void * funcC2(void * data);
int count = 0;
#define COUNT_DONE 10
#define COUNT_HALT1 3
#define COUNT_HALT2 6
int main(int argc, char * argv[])
{
	pthread_t tid1, tid2;
	pthread_create(&tid1,NULL,&funcC1,NULL);
	pthread_create(&tid2,NULL,&funcC2,NULL);

	pthread_join(tid1, NULL);
	pthread_join(tid2, NULL);
    
	printf("Gia tri counter cuoi cung: %d\n",count);

	getch();
	return 0;
}
//Viết các số từ 1-3 và 8-10 bởi  funcC1()
void * funcC1(void * data)
{
	for(;;)
	{
		//Khóa mutex và đợi tín hiệu để giải phóng mutex
		pthread_mutex_lock( &mutex1);
		//Đợi cho thủ tục funcC2() thao tác trên biến count
		//mutex1 mở khóa nếu biến cond1 nhận được tín hiệu của funcC2()
		pthread_cond_wait( &cond1, &mutex1);
		count++;
		printf("Gia tri counter cua funcC1: %d\n",count);
		pthread_mutex_unlock( &mutex1);
		if(count >= COUNT_DONE) return(NULL);
	}
}
//Viết các số từ 4-7 bởi thủ tục funcC2()
void * funcC2(void * data)
{
	for(;;)
	{
		pthread_mutex_lock( &mutex1);
		if( count < COUNT_HALT1 || count > COUNT_HALT2 )
        {
			//nếu giá trị count khớp với điều kiện
			//tín hiệu giải phóng chờ cho biến mutex
			//funcC1()được phép chỉnh sửa giá trị của count
			pthread_cond_signal( &cond1);
		}
		else
		{
			count++;
			printf("Gia tri counter cua funcC2: %d\n",count);
		}
		pthread_mutex_unlock( &mutex1);
		if(count >= COUNT_DONE) return(NULL);
	}
}

