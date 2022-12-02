#include<stdio.h>
#include"pthread.h"

void delay_s(int delay){
    for (int i = 0; i < delay*300000000; i++);
}

void *CT1(){
    int i = 0;
    while (1)
    {
        printf("CT1 = %d\n",i);
        i++;
        delay_s(1);
    }
    
}

void *CT2(){
    int i = 0;
    while (1)
    {
        printf("CT2 = %d\n",i);
        i++;
        delay_s(1);
    }
    
}

int main(int argc, char const *argv[])
{
    pthread_t task1, task2;

    pthread_create(&task1, NULL, CT1, NULL);
    pthread_create(&task2, NULL, CT2, NULL);
    while (1)
    {
        
    }
    
    return 0;
}
