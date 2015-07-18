///////////////////////////////////
// Hoang van Sam - ict 58 - hust //
///////////////////////////////////

#include <stdio.h>


int main () {
	char name[30];
    
    float dep ,irate, itrest ;
    int choice,i,y;
for (;;)
{	printf("\n\n----------------------------------------------------------------\n1. Deposit & deposit deadline\n2. Interest rate\n3. Print statistical\n4. Quit\n\tYour choice :");scanf("%d",&choice);
	switch(choice){
		case 1:printf("\n----------------------------------------------------------------\n");
				printf("Input name :");scanf(" %[^\n]",name);
				printf("Input deposit:");scanf("%f",&dep);
				printf("Input deposit deadline(year) :");scanf("%d",&y);printf("\n----------------------------------------------------------------\n");break;
		case 2:printf("\n----------------------------------------------------------------\n");
				printf("Input interest rate :");scanf("%f",&irate);printf("\n----------------------------------------------------------------\n");break;
		case 3:printf("\n----------------------------------------------------------------\n");
				printf("Account name : %s\n",name);
				itrest = 0;
				printf("%6s %-22s %-22s %-22s\n","Month","Money Before","Interest","Money After");
				for (i = 1; i <= 12*y; ++i)	{printf("%6d %-22.2f %-22.2f %-22.2f\n",i,dep,irate*dep,dep+irate*dep);dep = dep+irate*dep;itrest =itrest+ irate*dep;}
				printf("\n\nTotal interest : %.2f",itrest);printf("\n----------------------------------------------------------------\n");break;
		case 4:return 0;
}}}
