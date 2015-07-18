#include <stdio.h>

int main () {
  int t,c;
  double hp,tp;
  for(;;){
    printf("1. Compute for a employer\n2. Quit\n\tYour Choice : ");scanf("%d",&c);
    switch(c) {case 1:
  do{
    printf("time work for a day :");scanf("%d",&t);}
  while ( t> 20 || t<0 );
do{
  printf("salary for 1 hour :");scanf("%lf",&hp);}
 while (hp < 0);
 tp = (float)hp*t;
 printf("pay : %.5f\n",tp);break;
  case 2 :return 0;
    }
  }
}
