#include <stdio.h>
#define A 15
#define B 12
#define C 9



int main (){
	int a,b,c;float final,sum;
	printf("Amount of tickets sold in class A is: ");scanf("%d",&a);
	printf("Amount of tickets sold in class B is: ");scanf("%d",&b);
	printf("Amount of tickets sold in class C is: ");scanf("%d",&c);
	sum = a*A + b*B + c*C;
	final = sum*(1-0.05);
	printf("\nThe money vff gets : %.2f\n",final);
	return 0;
} 
