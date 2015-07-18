///////////////////////////////////
// Hoang van Sam - ict 58 - hust //
///////////////////////////////////


#include <stdio.h>

#define PI 3.14159265358979323846
int main () {
	double o,a,b,x,oo,input,i,j,z;
	int c;
	long int k;
	for(;;){
	printf("-----------------------------------------\n1. Input positive number\n2. Caculate sine x\n3. Caculate square root\n4. Caculate e*x\n5. Quit\n\tYour Answer :");scanf("%d",&c);printf("-----------------------------------------\n");
	switch(c){ 
		case 1:	printf("-----------------------------------------\nInput positive number :");scanf("%lf",&o);
				printf("Input error in approximation :");scanf("%lf",&x);printf("-----------------------------------------\n");break;
		case 3: printf("-----------------------------------------\n");
				if (o < 0) {printf("-----------------------------------------\nCan't Caculate suqare root of negative number !\n-----------------------------------------\n");break;}
				a = o;b = (a + o/a)/2;
				do {
					a = b;
					b = (a + o/a)/2;  
					}
				while((a-b)>x);
				printf("square root of %.5f  =  %.5f\n",o,b);printf("-----------------------------------------\n");break;
		case 2: input = o;
		if( input >= 2*PI) while( input >= 2*PI)  input =  input - 2*PI;
		b=  input ; j = 1 ;
				do {  k = -1; for (i = 1; i < j;i+=1 )k = k*(-1);oo=  input ;
					  for (i = 1; i < (2*j+1);i+=1 )oo= oo* input ;z = 1;
					  for (i = 1; i <= (2*j+1);i+=1 )z = z*i;
						a =k*oo/z;	b =b + a;
						j+=1;
				}
				while(a*k>x);
		printf("sin(%.5lf)  =  %.5lf\n",o,b);printf("-----------------------------------------\n");break;
		case 4:
				b= 1; j = 1 ;
				do {oo=  o ;  for (i = 1; i < j;i+=1 )oo = oo*o;z = 1;
					  for (i = 1; i <= j;i+=1 )z = z*i;
						a =oo/z;	b = b + a;
						j+=1;
				}
				while(a>x);
		printf("e^%.5f  =  %.5f\n",o,b);printf("-----------------------------------------\n");break;
		case 5:return 0;


	} }

}