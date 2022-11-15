#include<stdio.h>
#include<stdlib.h>
typedef struct Node 
{
    int data;
    struct Node *next;//con trỏ chỉ ô kế tiếp
}Node;

typedef struct Node* Position;

typedef struct{
    Position front, rear;// 2 con trỏ trỏ tới đầu với cuối
}Queue;


void MakeEmpty(Queue *value){
    Position temp;
    temp = (struct Node*)malloc(sizeof(struct Node));
    temp->next = NULL;
    value->front = temp;
    value->rear = temp;
}


int IsEmpty(Queue value){
    return value.front == value.rear;
}


void Enqueue(Queue *value, int A){
    value->rear->next = (struct Node*)malloc(sizeof(struct Node));
    value->rear = value->rear->next;
    value->rear->data = A;// ĐẶT giá trị cho rear
    value->rear->next = NULL;
}

void DeQueue(Queue *value){
    if(!IsEmpty(*value)){
        Position temp;
        temp = value->front;
        value->front = value->front->next;
        free(temp);
        
    }else{
        printf("ERROR mang rong\n");
    }
}



 
int main(int argc, char const *argv[])
{

    return 0;
}
