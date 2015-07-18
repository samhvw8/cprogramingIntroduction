////////////////////////////////
// Hoang Van Sam - ICT - HUST //
////////////////////////////////

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define INVALID -1



void rolldice(int c,int arr[]); // roll dice
int getMenu();
int main () {
	int logp[11],c;
	int i;
	for(;;){
		switch(getMenu()){
			
				// create table of log dice's point
			case 1:
			for (i = 0; i < 11; ++i)logp[i] = 0;
				
			printf("\n\tHow many time you want to roll : ");scanf("%d",&c);
			srand(time(NULL));//seed
			printf("\n");
			rolldice(c,logp);break;
			case 0:return 0;
}}}

int getMenu() {
	char option = INVALID;
	do {
		printf("\n\t .=============== MENU ===============. \n");
		printf("\t||  1. DICE                           ||\n");
		printf("\t||  0. Exit                           ||\n");
		printf("\t.|_____Your choie:  __________________|.\r\t.|_____Your choie: ");
		scanf(" %c",&option);
		if (option > '0'-1 || option < '3') printf("\tSelected option number %c\n",option);
		else {
			printf("\tInvalid option. Please retry!\n");
			option = INVALID;
		}
	} while (option == INVALID);
	option -= '0';
	return (int)option;
}

void rolldice(int c,int arr[]) {
	int pd1,pd2,i;
	if (c == 0) for (i = 0;i < 11;++i) printf("\tPoint %-2d : %d\n",i+2,arr[i]);
	if (c != 0)
	{
		pd1 = rand()%6+1;
		pd2 = rand()%6+1;
		++arr[pd1+pd2-2];
		c--;
		rolldice(c,arr);
	}
}

