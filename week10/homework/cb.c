///////////////////////////////////
// Hoang van Sam - ict 58 - hust //
///////////////////////////////////

#include <stdio.h>

void cb(int x,int base);
int main (){
	int o,choice;

	for(;;){
		printf("----------------------------\n1. Input positve Number on base 10\n2. Convert to binary\n3. Convert to Hex\n4. Convert to Octal\n5. Quit\n\tYour answer : ");scanf("%d",&choice);
		switch(choice){
			case 1: do{ printf("Input positve Number on base 10 : ");scanf("%d",&o); if(o<0)printf("Input positve number !!!\n");} while(o<0);break; 
			case 2: printf("Binary : ");cb(o,2);break;
			case 3: printf("Hex : ");cb(o,16);break;
			case 4: printf("Octal : ");cb(o,8);break;
			case 5:return 0;
}}}

void cb(int x,int base) {
	int input,c=0,lost,f;
	int i,j,z;
		{while(x > 0) {input = x;i = 0;
				    while(input > 0) {
				        f = input%base;input=input/base;i++;
				       }
				       	if(c == 1) for(z = 1 ; z < (j - i);z++)printf("0");
				       	if(base != 16)printf("%d",f); 
				       	else {if(f < 10) printf("%d",f); else if (f == 10 )printf("A");
			       	else if (f == 11 )printf("B");else if (f == 12 )printf("C");else if (f == 13 )printf("D");	
			       	else if (f == 14 )printf("E");else if (f == 15 )printf("F");}
				       	lost = 1;for (z = 1; z < i; ++z) lost =lost*base;
				       	x = x - f*lost;
				       	if (x == 0) for (z = 1; z < i; ++z) printf("0");
				       	j = i;
				       	c = 1 ;
				}printf("\n\n");}}
