#include<stdio.h>
#include<stdint.h>
#include<stdbool.h>
#define MAX 10



uint8_t stacks[MAX] ;

int index = -1;


void push(uint8_t data){
    index++;
    data = stacks[index];
}

void pop(){
    stacks[index] = '\0';
    index--;
}

int top(){
    if( index < -1){
        printf("stacks is empty\n");
        return 0;
    }else{
        stacks[index] = MAX;
        return stacks[index] ;
    }
    
}

bool IsEmpty(){
    if(index = -1){
        return true;
    }else{
        return false;
    }
    
}

bool IsFull(){
    if(stacks[index] >= MAX - 1){
        printf("full!!!\n");
        return true;
    }else{
        return false;
    }
}

int size(){
    
    return index + 1;
}

int main(int argc, char const *argv[])
{


    push(30);
    printf("\nsize = %d", size());
    push(20);
    push(10);
    printf("\nsize = %d", size());
    push(40);
    printf("\ntop = %d", top(stacks));
    pop();
    printf("\nsize = %d", size());
    return 0;
}
