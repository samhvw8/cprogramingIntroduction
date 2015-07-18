#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define max 100
int co(int a);
int sumo(int a[],int len);
int min(int a[],int len);
int main () {
  int num[max],i;
  srand(time(NULL));
  for (i = 0;i < max;i++) num[i] = rand()%100 + 1;
  printf("\nSum of odd number in array is %d\n",sumo(num,max));
  printf("\nMin in array is %d\n",min(num,max));

  return 0;
}
int sumo(int a[],int len) {
  int i,sum=0;
  for ( i = 0; i < len ; i++) if(co(a[i])) sum += a[i];
  return sum;
}
int min(int a[],int len){
  int i,min = a[0];
  for (i = 1 ; i < len ; i++) if(min > a[i]) min = a[i];
  return min;
}
int co(int a) {
  if(a&1 == 1) return 1;
  return 0;
}
