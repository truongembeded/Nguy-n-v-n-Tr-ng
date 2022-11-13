#include <stdio.h>
 
int Kiemtra(char *p) {
   int count = 0;
   while (*p != '\0') {
      count++;
      p++;
   }
   return count;
}
int main() {
   char Dad[] = "hoc vdk, hoc lap trinh online, hoc c, hoc c++, hoc java, ...";
   char Son[] = "hoc";
 
   int n = 0;
   int m = 0;
   int times = 0;
   int leghth = Kiemtra(Son);
 
   while(Dad[n] != '\0') {
 
      if(Dad[n] == Son[m]) {   
 
        
         while(Dad[n] == Son[m]  && Dad[n] !='\0') {
            n++;
            m++;
         }
 
         if(m == leghth && (Dad[n] == ' ' || Dad[n] == '\0')) {
 
            times++;
         }
      } else {
         while(Dad[n] != ' ') {    
            n++;
            if(Dad[n] == '\0') 
            break;
         }
      }
         
      n++;
      m=0;
   }
 
   if(times > 0) {
      printf("Chuoi '%s' xuat hien %d lan\n", Son, times);
   }else {
      printf("Chuoi '%s' khong xuat hien trong cau.\n", Son);
   }
 
   return 0;
}