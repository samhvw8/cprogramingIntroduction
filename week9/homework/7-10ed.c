///////////////////////////////////
// Hoang van Sam - ict 58 - hust //
///////////////////////////////////

#include <stdio.h>

int main () {
	int n,i,z,zz,choice;
	int cp;

for(;;){
	printf("\n-------------------------------------------\n1. input number\n2. List Perfect Number\n3. List Prime Number\n4. List Divisor\n5. Quit\n-------------------------------------------\n\tYour Choice : " );scanf("%d",&choice);
	switch(choice){
		// -------------------------------------------------------------------
		case 1: do {printf("Input Number limit : ");scanf("%d",&n);
		if(n < 0) printf("Wrong input! Input again\n");
		} while (n < 0);break;
		// -------------------------------------------------------------------
		case 2:printf("List Perfect Number : \n\n" );for (i = 3; i < n ;++i) {

			zz = 0;
			for (z = 1; z < i;z++) if(i%z == 0) zz = zz + z; if (zz == i) {
				printf("%d\t",i);printf("= ");cp = 0;
				for (z = 1; z < i ; z++) if(i%z == 0 && cp == 0) {printf("%d",z);cp = 1;} else if (i%z == 0 && cp == 1) 
				printf("+ %d",z);
				printf("\n");}
			}printf("\n\n");
		break;
		// -------------------------------------------------------------------
		case 3:	printf("List prime Number : \n\n" );if(n >= 2) printf("2\t");
			for(i = 3;i < n;i++) {cp = 0 ;for (z = 2; z <= i - 1; ++z) if(i%z == 0){cp = 1; break;}if (cp == 0) printf("%d\t",i ); }
			printf("\n\n");break;
		// -------------------------------------------------------------------
		case 4:printf("List Divisor of %d : \n\n",n );
			for (i = 1; i < n; ++i) if (n%i == 0) printf("%d\t",i);
		break;
		// -------------------------------------------------------------------
		case 5:return 0;
}}}