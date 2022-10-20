#include<stdio.h>
#include<stdint.h>

int check_date(int day, int month){
 if ((month!=2) && (day<=0) && (day>29)){
    printf("Khong co Ngay %d",day);
    return 0;
 }
 if ((
 (month!=1) ||
 (month!=3) ||
 (month!=5) ||
 (month!=7) ||
 (month!=8) ||
 (month!=10)||
 (month!=12)
 ) && ((day<=0) && (day>31)))
 {
    printf("Khong co Ngay %d",day);
    return 0;
 }
 if ((
 (month!=4) ||
 (month!=6) ||
 (month!=9) ||
 (month!=11)
 ) && ((day<=0) && (day>30)))
 {
    printf("Khong co Ngay %d",day);
    return 0;
 }
 return 1;
}
 
 
// Kiem tra thang hop le
int check_month(int month){
 if ((month<=0) && (month>12)){
    printf("Khong co Thang %d",month);
  return 0;
 }else{
  return 1;
 }
}
 
// Kiem tra nam hop le
int check_year(int year){
 
 if ((year<=999) && (year > 2022)){
    printf("Khong co Nam %d",year);
 return 0;
 }else{
 
 return 1;
 }
}



int main(int argc, char const *argv[])
{
    int ngay, thang, nam;
    int namhientai = 2022;
    int Tuoi;
    do
    {
        printf("nhap Ngay :\n");
        scanf("%d",&ngay);
        printf("Nhap Thang :\n");
        scanf("%d",&thang);
        printf("nhap Nam :\n");
        scanf("%d",&nam);
    } while ((check_date && check_month && check_year) == 0);
        if(thang < 12){
            namhientai= namhientai;

        }else {
           namhientai+=1;
        }
    Tuoi = namhientai - nam;
    
    printf("My age is :%d\n",Tuoi);
    return 0;
}

