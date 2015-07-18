#include <stdio.h>
#define rwkend 10
#define roday 7
#define Cldr 0.5
#define SCr 0.3

int main () {
  char movie[10];  
  int age,chose,cc,csc,price;
  printf("insert your age : ");scanf("%d",&age);
  printf("Your movie want to buy : ");scanf("%s",movie);
 printf("You want to watch in \n 1. Weekend 10$\n 2. Other Day 7$\nYour Answer: ");scanf("%d",&chose); 
 cc = csc = 0;
 if ( age < 18 ) cc = 1; else if ( age >=65 ) csc = 1;
 price = (chose == 1 )?10:7;
price = ( cc ==1 )?(price*Cldr):((csc == 1)?(price*SCr):(price));
  printf("\n\n-Movie :%s\n",movie);
 printf("-Class :");
 if (cc == 1 )  printf("Child\n");
 if (csc == 1 )  printf("Senior Citizen\n");
 if (cc == 0 && csc == 0 ) printf("Adult\n");
 printf("-Date :");
 if (chose == 1 )printf("Weekend\n");
if (chose == 2 )printf("OtherDay\n");
 printf("-Price :%d\n",price);
  return 0;}
