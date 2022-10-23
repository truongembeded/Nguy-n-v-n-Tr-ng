#include <stdio.h>
 
int main() {
   int arr[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
   int even[10], odd[10];
   int i, e, d;
    
   e = d = 0;
    
   for(i = 0; i < 10; i++) {
      if(arr[i] % 2 == 0) {
         even[e] = arr[i];
         e++;
      }else {
         odd[d] = arr[i];
         d++;
      }
   }
   printf("Chia mot mang thanh hai mang trong C:\n\n");   
   printf("Mang ban dau la -> ");
   for(i = 0; i < 10; i++) {
      printf(" %d", arr[i]);
   }
        
   printf("\nMang chan -> ");
   for(i = 0; i < e; i++) {
      printf(" %d", even[i]);   
   }
    
   printf("\nMang le -> ");
   for(i = 0; i < d; i++) {
      printf(" %d", odd[i]);   
   }
    
   return 0;
}