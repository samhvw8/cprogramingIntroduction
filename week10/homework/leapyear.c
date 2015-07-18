//////////////////////////////////
// Hoang Van Sam - ICT58 - HUST //
//////////////////////////////////

#include <stdio.h>
int isly(unsigned int y);
int dmonth(unsigned int m,unsigned int y);
int main () {
	unsigned int y,m;
	int c;
	for(;;){printf("-------------------------------\n1. Check Leap year\n2. Number of days in the month\n3. Quit\n\tYour Answer :");scanf("%d",&c);
		if(c == 1){printf("Insert Year :");scanf("%u",&y);
				if(isly(y)) printf("%u is leap year\n\n",y );else printf("%u isn't leap year\n-------------------------------\n",y );}
		if (c == 2 ) {printf("-------------------------------\nInsert Year :");scanf("%u",&y);printf("Insert Month :");scanf("%u",&m);printf("In month %u of %u year has %d days \n-------------------------------\n",m,y,dmonth(m,y));}
		if(c == 3)return 0;
	}
}
int isly(unsigned int y){
	if(y%400 == 0) return 1;
	else if (y%4 == 0 && y%100 != 0) return 1;
	else return 0;
}
int dmonth(unsigned int m,unsigned int y){
	if (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12) return 31;else if (isly(y) && m == 2)  return 29; else if (m == 2) return 28 ; 
	else return 30;
}