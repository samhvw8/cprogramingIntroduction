#include <stdio.h>
#include <math.h>
int main () {
  int i,j;
  
  printf("the prime <100 is :\n");
  printf("2\n");
  for (i=3;i<=100;i++)
    
    { for (j=2;j<i;j++)
	{ 
	  if(i%j==0) break;
	  if(j>sqrt(i)){printf("%d\n",i);break;}
 	}

    }
  return 0;}
