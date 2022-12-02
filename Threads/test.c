#include <conio.h>
#include "pthread.h"
#include <stdio.h>

void * printx(void * data)
{
	while(1)
	{
		printf("x");
	}
    
}

int main(int argc, char * argv[])
{
	pthread_t idthread;
	pthread_create(&idthread,NULL,&printx,NULL);
	while(1)
	{
		printf("o");
	}
	getch();
	return 0;
}