#include <stdio.h>

int main () {
  int point;
printf("input point = ");scanf("%d",&point);

 if (point >100 ) {printf("wrong input\n");
printf("input point = ");scanf("%d",&point);scanf("%d",&point);}
  else if( point>= 90 ) printf("your grade = A\n");
  else if( point>= 80 ) printf("your grade = B\n");
  else if( point >= 60 ) printf("your grade = C\n");
  else if( point >= 50 ) printf("your grade = D\n");
  else  printf("your grade = F");

  return 0;
}
