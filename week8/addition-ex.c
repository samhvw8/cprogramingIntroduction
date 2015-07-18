#include <stdio.h>

int main () {
  int a,i=0;
  printf("in cac chu so nho hon 1000 va tong cac chu so hang tram va don vi =  so hang chuc va chia het cho 3 va 10 so xuong dong 1 lan :\n"); 
 for (a = 100;a<1000 ;a++) {
   if((a%10+a/100 == (a%100)/10) && a%3==0 )
     {if(i==10){
	 printf("\n");i =0;
} 
printf("%d ",a);i+=1;}
}

  return 0;}
