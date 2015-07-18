#include <stdio.h>

int main () {
  int a,b,c,max,z,check;
  printf("insert 3 number : a,b,c: ");
  scanf("%d%*c%d%*c%d",&a,&b,&c);
 max = (((a>b)?a:b)>c)?((a>b)?a:b):c;
 printf("max of three number : %d\n",max);
 z = ((a+b+c)/3 > 10)?(a+b):(b-c);

 z = z>0?z:-z;

 printf("z depend on average : %d\n",z);
 return 0;
}
