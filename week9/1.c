#include <stdio.h>
#include <math.h>

int main () {
  double o,a,b;
  int c,k=0;
  for(;;){
    printf("1. Caculate square root\n2. Quit\n\tYour Answer :");scanf("%d",&c);
    switch(c){ case 1:
 do {
    printf("Input positive number :");
    scanf("%lf",&o);
    if(o < 0) printf("Wrong Input ! Input Again\n");
    else {a = o;b = (float)(a + o/a)/2;}
    }
 while (o < 0);
   
 do {
   a = b;
   b = (float)(a + o/a)/2;  
  }
 while(fabs(b-a)>0.000001);
 printf("square root of %.5f  =  %.5f\n",o,b);break;
    case 2:return 0;


    } }
  
}


