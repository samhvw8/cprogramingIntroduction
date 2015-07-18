#include <stdio.h>
#define REGULART 40

int main () {
  int t,w;
  printf("Input time employee has worked in week : ");scanf("%d",&t);
  if( t > REGULART ) w = (REGULART*25000 + (t-REGULART)*40000);
  else {w = t*25000;}  printf("\nwages for employee in week is: %d \n",w);
  
  return 0;
}
