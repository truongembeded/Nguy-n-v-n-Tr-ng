#include <stdio.h>
#include <stdlib.h>
void NhapMang(int arr[],int n){
   int *p = &arr[0];
    for (int i = 0; i < n; i++)
    {
        printf("Nhap a[%d] = ", i);
        scanf("%d", (p + i));
    }
}

void XuatMang(int arr[], int n){
   int *p = &arr[0];
   for (int i = 0; i < n; i++)
    {
        printf("\nGia tri a[%d] = %d", i, *(p + i));
    }
}

void TachMangChan(int arr[], int n, int Even[],int *e, int Odd[], int *d){

   for(int i = 0; i < n; i++) {
      if(arr[i] % 2 == 0) {
         Even[*e] = arr[i];
         *e++;
      }else {
         Odd[*d] = arr[i];
         *d++;
      }
   }
}

int main() {

   int n;
   
   do
   {
      printf("Nhap so luong phan tu mang: ");
      scanf("%d",&n);
   } while (n<1);
   int *arr = (int *)malloc(n * sizeof(int *));
   NhapMang(arr,n);

   printf("Xuat mang da nhap:\n ");   
   XuatMang(arr,n);
   int Even[n], Odd[n];
   int e = 0;
   int d = 0;
   printf("\nMang da tach ->",TachMang(arr, n, Even, &d, Odd, &e));
   
   printf("Mang chan -> \n");
   XuatMang(Even, &e);
        
   printf("\nMang le -> ");
   XuatMang(Odd, &d);
    
   free(arr);
   return 0;
}