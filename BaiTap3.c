//1 thung chua ngau nhien vo do, vang, xanh. Dem co bao nhieu doi vo cung mau
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum{  
    VO_DO,
    VO_VANG,
    VO_XANH
}VO;

typedef struct{
    VO *arr;
    int size;
}typeArr;

typeArr *nhapthongtin(){
    static typeArr arr;
    arr.arr = ( VO*) malloc ( sizeof(VO) );
    printf("\n Nhap so vo: ");
    scanf("%d",&arr.size);
    int i = 0;
    do{
        char a[10];
        printf("\nNhap vo %d: ",i);
        scanf("%s",a);
        if(!strcmp(a,"VO_DO")){
            arr.arr[i] = VO_DO;
            i++;
        }else if(!strcmp(a,"VO_VANG")){
            arr.arr[i] = VO_VANG;
            i++;
        }else if(!strcmp(a,"VO_XANH")){
            arr.arr[i] = VO_XANH;
            i++;
        }else{
            printf("\nNhap sai!!!");
        }
        
    }while(i < arr.size);
    
    return &arr;
}

void process(typeArr *s){
    int sl1=0,sl2=0,sl3=0;
    for(int i = 0; i< s->size;i++){
        if(s->arr[i] == 0){
            sl1++;
        }else if(s->arr[i] == 1){
            sl2++;
        }else{
            sl3++;
        }
    }
    printf("\nCo %d vo mau do",sl1/2);
    printf("\nCo %d vo mau vang",sl2/2);
    printf("\nCo %d vo mau xanh",sl3/2);
}

int main(){
    typeArr *s;
    s = nhapthongtin();
    for(int i = 0; i < s->size; i++){
        if(s->arr[i] == 0){
            printf("\nThu %d : VO_DO",i);
        }else if(s->arr[i] == 1){
            printf("\nThu %d : VO_VANG",i);
        }else{
             printf("\nThu %d : VO_XANH",i);
        }
    }
    process(s);

    return 0;
}