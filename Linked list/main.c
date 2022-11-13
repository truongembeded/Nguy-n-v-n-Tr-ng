#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

    struct Node
    {
        int data;
        struct Node *next;
    };
typedef struct Node *Node;


Node createNode(int value){
    Node temp;

    temp = (Node)malloc(sizeof(struct Node));
    temp ->next = NULL;
    temp->data = value;

    return temp;
}

void push_back(Node *head, int value){// struct Node **head nó sẽ lưu cái địa chỉ 0x01
    static int flag = 1;

    if(flag){
        *head = NULL;
        flag = 0;
    }
    Node temp = createNode(value);//temp sẽ tạo ra 1 cái Node 0xc7
    Node p = NULL;
    if(*head == NULL){
        *head = temp;// muốn cái head lưu 0xc7 thì phải là *head
    }else{

        p = *head;
        while (p->next != NULL)
        {
            p = p->next;
        }
        
       p->next = temp;

    }
}

void pop_back(Node *head){
    int i = 0;
    Node p = *head;
    while (p->next->next != NULL)
    {
        p = p->next;
        i++;
    }
    printf("i = %d",i);
    free(p->next->next);
    p->next = NULL;
    
}


int at(Node head, int index){
    int i = 0;
    Node p = head;

    while (p->next != NULL && i != index)
    {
        p = p ->next;
        i++;
    }
    return p->data;
}

//Để lấy ra phần tử đầu tiên của vector:
int front(Node head)
{
    Node p = head;
    if(p == NULL)
    {
        return 0;
    }
    else
    return p->data;
}

//Để bỏ đi tất cả các phần tử của vector:
void clear(Node *head)
{
    Node p = *head;
    while (p != NULL)
    {
        pop_back(head);
        p = *head;
    }
}

//Để lấy ra phần tử cuối cùng của vector:
int back(Node head)
{

    Node p = head;
    while (p->next != NULL)
    {
        p = p->next;
        
    }
    return p->data;
}

//Để biết số lượng phần tử của vector:
int size(Node head)
{
    Node p = head;
    int i=0;

    while (p->next != NULL)
    {
        p = p->next;
        i++;
    }
    return i+1 ;
}

//Để biết vector có phần tử hay không:
bool emty(Node *head)
{

    Node p = *head;
    if(p == NULL){
        printf("mang co phan tu !");
        return true;
    }else{
        printf("mang khong co phan tu");
        return false;
    }

    
    
}

int main(int argc, char const *argv[])
{
    Node Node;// vì con trỏ nên nó sẽ sinh ra 1 địa chỉ 0x01 mà giá trị của nó là Null


    push_back(&Node, 5);//0x01 mang giá trị 0xc7

    push_back(&Node, 6);

    push_back(&Node, 8);

    push_back(&Node, 15);



    // pop_back(&Node);// kiểm tra
    // pop_back(&Node);//xoá phần tử cuối

    // printf("%d\n",at(Node, 1));
    // printf("%d\n",size(Node));
    // printf("%d\n",front(Node));  
    // clear(&Node);
    // printf("%d\n",back(Node));
     emty(&Node);

    return 0;
}
