#include <stdio.h>
#define k1 100000
#define k2 20000
#define k3 10000
#define k4 5000

int main () {
  int a,c,z1,z2,z3,z4,ch;
  for(;;){printf("1. Change cash\n2. Quit\n\tYour Choice : ");scanf("%d",&ch);
    switch(ch){case 1:
  do {
    printf("Input cash :");scanf("%d",&a);
  }
  while (a<0);
  z1 = a / k1; c = a % k1;
  z2 = c / k2 ; c = c % 
k2;
  z3 = c / k3 ; c = c % k3;
  z4 = c / k4 ;c = c %k4;

  printf("100k = %d\n",z1);
  printf("20k = %d\n",z2);
  printf("10k = %d\n",z3);
  printf("5k = %d\n",z4);break;
    case 2:return 0;
    }
  }
}
