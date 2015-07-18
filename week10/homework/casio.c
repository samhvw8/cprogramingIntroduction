///////////////////////////////////
// Hoang van Sam - ict 58 - hust //
///////////////////////////////////

#include <stdio.h>
#define PI 3.14159265358979323846

double power(double x,double n);
double msqrt(double x,double e);
double msin(double x,double e);
double mex(double x,double e);
double Factorial(double x);

int main () {
  double o,ee,input;int c;
	for(;;){
	printf("-----------------------------------------\n1. Input positive number\n2. Caculate sine x\n3. Caculate square root\n4. Caculate e*x\n5. Quit\n\tYour Answer :");scanf("%d",&c);printf("-----------------------------------------\n");
	switch(c){
		case 1:	printf("-----------------------------------------\nInput positive number :");scanf("%lf",&o);
				printf("Input error in approximation :");scanf("%lf",&ee);printf("-----------------------------------------\n");break;
		case 3: printf("-----------------------------------------\n");
				if (o < 0) {printf("-----------------------------------------\nCan't Caculate suqare root of negative number !\n-----------------------------------------\n");break;}
				printf("square root of %.5f  =  %.5f\n",o,msqrt(o,ee));printf("-----------------------------------------\n");break;
		case 2: input = o;
		if( input >= 2*PI) while( input >= 2*PI)  input =  input - 2*PI;
		printf("sin(%.5lf)  =  %.5lf\n",o,msin(input,ee));printf("-----------------------------------------\n");break;
		case 4:
		  printf("e^%.5lf  =  %.5f\n",o,mex(o,ee));printf("-----------------------------------------\n");break;
		case 5:return 0;
		}}}
double Factorial(double x){
  double i,o;o = 1;
  if (x == 0 )return 1;
  for (i = 1; i <= x ; i+=1) o = o*i;
return o;
}
double power(double x,double n){
  double i,o=1;
  if (n == 0) return 1;
  if (n >= 1) {
  for (i = 1; i <= n ;i+=1) o = o*x;}
return o;
}
double msqrt(double x,double e) {
  	double a,b;
	a = x;b = (a + x/a)/2;
		do {
			a = b;
			b = (a + x/a)/2;
			}
		while((a-b)>e);
return b;
}
double msin(double x,double e) {
  double j,a,b,k;
  b= x ; j = 1 ;
  	do 	{
  		k = power(-1,j);  a  =k*power(x,2*j+1)/Factorial(2*j+1);	b =b + a;
		j+=1;
		}
	while(a*k>e);
return b;
}
double mex(double x,double e){
 	double j,a,b;
	b= 1; j = 1 ;
 	do 	{
 		a =power(x,j)/Factorial(j);b = b + a;
		j+=1;
		}
	while(a>e);
return b;
}
