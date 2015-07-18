#include <stdio.h>

int main () {
  double x,y;
  printf("insert 2 double x,y :");scanf("%lf,%lf",&x,&y);
  if ( x == y ) printf("x and y are equal\n"); else if ( x > y ) printf("x larger than y\n"); else  printf("y larger than x\n");
  return 0;}
