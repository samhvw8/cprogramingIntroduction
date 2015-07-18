#include <stdio.h>

int main () {
  int n,mod;
  int smallest,largest,atmost,extract;
  int ns;
  float d;
 printf("insert number of student : = ");scanf("%d",&n);
 d = (float)n/7;mod = n%7;
 smallest = (n - mod )/7;
    largest = smallest +1;
    ns = 7 -mod;
    atmost = (mod>3)?mod:ns;
    extract = (mod == 0)?7:0;
  printf("the number of students in the smallest class  = %d\n",smallest);
  printf("the number of students in the largest class  = %d\n",largest);
  printf("the average number of students per class   = %.2f\n",d);
  printf("the number of class above average size  = %d\n",mod);
  printf("the number of class at most average size  = %d\n",atmost);
  printf("the number of student in class of larger than avarage size = %d\n",largest);
  printf("the number of class extractly average size  = %d\n",extract);
  return 0;}
