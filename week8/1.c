#include <stdio.h>

int main () {
  int x,i;
  x = 0;
  for ( i = 1 ; i <100;i++){
    x += i;
    if((x%i)==0) i--;
}
  printf("%d",x);
  return 0;
}
