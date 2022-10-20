#include<stdio.h>
#include<stdlib.h>


struct typeArr
{
    int *arr;
    int size;
};



void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}


void SxLonDenBe (struct typeArr *value){

     for(int i = 1; i < value->size;i ++){
        for(int j = 0 ; j < value->size-1;j++){
            if(value->arr[j]< value->arr[j+1]){
                swap(&value->arr[j],&value->arr[j+1]);
            }
        }
    }
}

void SxBeDenLon(struct typeArr *value){
   for(int i = 1; i < value->size;i ++){
        for(int j = 0 ; j < value->size-1;j++){
            if(value->arr[j]>value->arr[j+1]){
                swap(&value->arr[j],&value->arr[j+1]);
            }
        }
    }
}


int SoLonNhat (struct typeArr *value){
    int maxvalue = value->arr[0];
    for (int i = 0; i < value->size; i++)
    {
        if (value->arr[i] > maxvalue)
        {
            maxvalue = value->arr[i];
        }
    }

    return maxvalue;
}


struct typeArr *NhapThongTin(){

    static struct typeArr arr;//0x01

    int*ptr;

    int size;

    printf("\t Nhap kich thuoc mang :");
    scanf("%d",&size);

    ptr = (int*)malloc(size* sizeof(int));

    for (int i = 0; i < size; i++)
    {
        printf("Nhap gia tri tai ar[%d] = ", i);
        scanf("%d",&ptr[i]);
    }
    arr.size= size;
    arr.arr =ptr;

    return &arr;
}


  
int main(int argc, char const *argv[])
{
    int nhan = 0;
    struct typeArr *arr;

    arr = NhapThongTin();

    do
    {
        printf("\n Thuc hien nhan nut :");
        scanf("%d",&nhan);
         if(nhan == 1){
            SxLonDenBe(arr);
            for(int i = 0; i < arr->size; i++){
            printf("\narr[%d] = %d",i, arr->arr[i] );
            }
        }else if(nhan ==2 ){
           SxBeDenLon(arr);
            for(int i = 0; i < arr->size; i++){
            printf("\narr[%d] = %d",i, arr->arr[i] );
            }
        }else if(nhan == 3){
            printf("\nSo lon nhat trong mang : %d",SoLonNhat(arr));
            }
    } while (nhan != 4);
        printf("\n---Da Thoat Chuong trinh---");
    
    return 0;
}

