/////////////////////////////
// Author : Hoang Van Sam  //
// Class : ICT58  - HUST   //
/////////////////////////////
#include <stdio.h>
#define rwkend 10
#define roday 7
#define Cldr 0.5
#define SCr 0.3
int main () {
	char movie[10];  
	int age,chose,cc,csc;                   // check child = cc ; check Senior Citizen = csc 
	float price;
		printf("%s\n","child discount 50% , Senior Citizen discount 30% " );
		printf("insert your age : ");scanf("%d",&age);
		printf("Your movie want to buy : ");scanf(" %[^\n]",movie);
		printf("You want to watch in \n1. Sunday 10$\n2. Monday 7$\n3. Tuesday 7$\n4. Wednesday 7$\n5. Thursday 7$\n6. Friday 10$\n7. Saturday 10$\nYour Answer: ");
			scanf(" %d",&chose); 
			cc = csc = 0;
		if ( age < 18 ) cc = 1; else if ( age >=65 ) csc = 1;
		switch ( chose ) {
		case 1:case 6:case 7: price = 10.0; break;
		default: price = 7.0; break;}
	price = ( cc == 1 )?(price-price*Cldr):((csc == 1)?(price-price*SCr):(price));
	printf("\n\n--------BILL---------------------------\n");
	printf("-Movie :%s\n",movie);
	printf("-Class :");
		if (cc == 1 )  printf("Child\n");
		if (csc == 1 )  printf("Senior Citizen\n");
		if (cc == 0 && csc == 0 ) printf("Adult\n");
	printf("-Date :");
	switch ( chose ) {
	case 1: printf("Sunday \n"); break;
	case 2: printf("Monday\n"); break;
	case 3: printf("Tuesday\n"); break;
	case 4: printf("Wednesday\n"); break;
	case 5: printf("Thursday\n"); break;
	case 6: printf("Friday \n"); break;
	case 7: printf("Saturday \n"); break;
	}
	printf("-Price :%.2f $\n",price);
	printf("---------------------------------------\n");
	return 0;
}
