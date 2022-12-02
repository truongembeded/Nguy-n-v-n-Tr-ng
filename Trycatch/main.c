#include<stdio.h>
#include<setjmp.h>
#include<stdlib.h>


jmp_buf buf;

int value = 0;

#define TRY if((value = setjmp(buf)) == 0)

#define CATCH(num) else if(value == num)

#define THRƠW(num) longjmp(buf, num)



double TB(double *value, int length){
    double sum = 0.0;

    if(length <= 0){
        THRƠW(1);
    }
    for (int i = 0; i < length; i++)
    {
        sum += value[i];
    }
    
    return sum/(double) length;
}

double thuong(int a, int b){
    if(b == 0){
        THRƠW(2);
    }
    return (double)(a/b);
}

int main(int argc, char const *argv[])
{
    double mang[]={1, 2, 3, 4, 5, 6};
    double avg;

    double result;

    TRY{
        // avg = TB(mang, 6);
        // printf("TB = %lf\n",avg);

        result = thuong(15,0);
        printf("thuong = %lf", result);
    }CATCH(1){
        printf("ERROR!!! LENGTH = 0\n");
    }CATCH(2){
         printf("ERROR!!! MAU = 0\n");
     }
    return 0;
}
