#include <stdio.h>
void swap(int *a,int *b);
int main () {
  int x,y,z;
  x = 1;y =2 ; z =3;
  int * p,*q,*r;

  p = &x;
  q = &y;
  r = &z;

  printf("x = %d\n ",x);
 printf("y = %d \n",y);
 printf("z = %d \n",z);
 printf("p = %x \n",p);
 printf("q = %x \n",q);
 printf("r = %x \n",r);
 printf("*p = %d \n",*p);
 printf("*q = %d \n",*q);
 printf("*r = %d \n",*r);

 printf("After swap x & y:\n");
 swap(x,y);
 printf("x = %d\n ",x);
 printf("y = %d \n",y);
}
void swap(int *a,int *b){
  int temp;
  temp = *a;
  *a = *b;
  *b = temp;
}
