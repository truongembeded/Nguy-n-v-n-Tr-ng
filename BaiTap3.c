#include<stdio.h>
#include <stdlib.h>
#include<string.h>
//cho 1 cái thùng, nó chứa ngẫu nhiên số đôi tất đỏ vàng xanh, đếm xem có bao nhiêu đôi tất cùng màu

typedef enum{
    TAT_DO,
    TAT_VANG,
    TAT_XANH
}TAT;

typedef struct{
    TAT *ptr;
    int size;
}typeBox;


void Nhapthongtin(typeBox *value){
    char name[10];

    printf("\t Nhap kich thuoc mang size =");
    scanf("%d",&(value->size));

    value->ptr = (TAT*)malloc(value->size* sizeof(TAT));

   
    for (int i = 0; i < value->size; i++)
    {
        lable:
        printf("Nhap gia tri tai arr[%d] = ", i);
    
        scanf("%s",name);

        if( strcmp ((char*)"TAT_DO",name)== 0){
            value->ptr[i]= TAT_DO;
        }else if(strcmp ((char*)"TAT_VANG",name)== 0){
            value->ptr[i]= TAT_VANG;
        }else if(strcmp ((char*)"TAT_XANH",name)== 0){
            value->ptr[i]= TAT_XANH;
        }
        }else{
            printf("Nhap sai cu phap!!!\n");
            goto lable;
    }
}

int TinhToan(typeBox value){
    int sum = 0;
    for (int i = 0; i < value.size; i+=2)
    {
        if (value.ptr[i] % 2 != 0)
        {
            sum += value.ptr[i];
        }
    }
    return sum;
}

int main(int argc, char const *argv[])
{
    typeBox value;
    Nhapthongtin(&value);
    TinhToan(value);
   
    return 0;
}
