#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define INVALID -1
#define PLAYER 11

// =============================== Function ==============================================================================
int getMenu();
void play(int parr[]);
int cplay(int num,int parr[]);
void pplay(double pp1[],double pp2[],double pp3[],double pp4[],double pp5[]);
double random();
double lt(double p);
void pt(int parr[],double pp1[],double pp2[],double pp3[],double pp4[],double pp5[]);
double max(double arr[]);
double min(double arr[]);
int checkmx(double m1,double m2,double m3,double m4,double m5);
int checkmn(double m1,double m2,double m3,double m4,double m5);
double floor(double num);
// =============================== Main ==================================================================================
int main () {
	int i;
	float p = 2.6,a;
	a = floor(2.6);
	int sp[PLAYER];
	double pp1[PLAYER],pp2[PLAYER],pp3[PLAYER],pp4[PLAYER],pp5[PLAYER];
	// create table
	for (i = 0; i < PLAYER; ++i)sp[i] = pp1[i] = pp2[i] = pp3[i] = pp4[i] = pp5[i] = 0;
	srand(time(NULL));
	for(;;){
		switch(getMenu())
	{	case 1:play(sp);
		pplay(pp1,pp2,pp3,pp4,pp5);break;
		case 2:pt(sp,pp1,pp2,pp3,pp4,pp5);break;
		case 3:printf("The jury rigorous is %d\n",checkmx(max(pp1),max(pp2),max(pp3),max(pp4),max(pp5)));
		printf("The Jury facile is %d\n",checkmx(min(pp1),min(pp2),min(pp3),min(pp4),min(pp5))) ;break;
	}
	}
}

// =============================== Function ==============================================================================
int getMenu() {
	char option = INVALID;
	do {
		printf("\n\t .===================== MENU ===================. \n");
		printf("\t**  1. Input player number && player rate         **\n");
		printf("\t**  2. Print Player Point                         **\n");
		printf("\t**  3. show the judge most rigorous and facile    **\n");
		printf("\t**  0. Exit                                       **\n");
		printf("\t**_____Your choie:  ______________________________**\r\t|_____Your choie: ");
		scanf(" %c",&option);
		if (option > '0'-1 || option < '4') printf("\tSelected option number %c\n",option);
		else {
			printf("\tInvalid option. Please retry!\n");
			option = INVALID;
		}
	} while (option == INVALID);
	option -= '0';
	return (int)option;
}
//================================ Insert the player ===================================================================
void play(int parr[]){
	int i;
	for (i = 0; i < PLAYER; ++i)
	{	do
		{printf("%d Insert Player no : ",i+1);scanf("%d",&parr[i]);
		if (parr[i] == 0  || cplay(parr[i],parr))printf("Wrong input ! Input again\n");}
		while(parr[i] == 0 || cplay(parr[i],parr));
	}
}
int cplay(int num,int parr[]){
	int i,j; j =0;
	for (i = 0; i < PLAYER; ++i)
	{
		if(num == parr[i]) j++;
	}
	if(j > 1)return 1;
	return 0;
}
double lt(double p){
	double o,a;
	a = floor(p);
	o = p -a;
	if (o == 0.5) return a + 0.5;
	if (o >=0.25 && o < 0.5) return a + 0.5;
	if (o >=0 && o < 0.25) return a;
	if (o >0.5 && o <0.75) return a + 0.5; 
	if (o >=0.75 ) return a + 1; 
}
double random(){
	return rand()%11 + (float)(rand()%100)/100;
}
void pplay(double pp1[],double pp2[],double pp3[],double pp4[],double pp5[]){
int i;
	for (i = 0; i < PLAYER; ++i)pp1[i] = lt(random());
	for (i = 0; i < PLAYER; ++i)pp2[i] = lt(random());
	for (i = 0; i < PLAYER; ++i)pp3[i] = lt(random());
	for (i = 0; i < PLAYER; ++i)pp4[i] = lt(random());
	for (i = 0; i < PLAYER; ++i)pp5[i] = lt(random());
}
void pt(int parr[],double pp1[],double pp2[],double pp3[],double pp4[],double pp5[]){
int i,k;
		printf("\n\t-=============TABLE OF POINT==============-\n");
		printf("\t.=========================================.\n");
		printf("\t|No.   |  jd1 |  jd2 |  jd3 |  jd4 |  jd5 |\n");
		printf("\t-------------------------------------------\n");
	for (i = 0; i < PLAYER; ++i){printf("\t|No.%2d | %5.2f| %5.2f| %5.2f| %5.2f| %5.2f|\n",parr[i],pp1[i],pp2[i],pp3[i],pp4[i],pp5[i]);
			if(k==PLAYER-1) printf("\t.=========================================.\n\n");  else printf("\t-------------------------------------------\n");k++;
		 }

}
double max(double arr[]) {
	double max;
	int i;
	max = arr[0];
	for (i = 1; i < PLAYER; ++i)
	{
		if (arr[i] >= max) max = arr[i];
	}
	return max;
}
double min(double arr[]) {
	double min;
	int i;
	min = arr[0];
	for (i = 1; i < PLAYER; ++i)
	{
		if (arr[i] <= min) min = arr[i];
	}
	return min;
}
int checkmx(double m1,double m2,double m3,double m4,double m5) {
	double max;	int i;
	max = m1;i = 1;if (max >= m2 && max >= m3 && max >= m4 && max >= m5) return i;
	max = m2;i = 2;if (max >= m1 && max >= m3 && max >= m4 && max >= m5) return i;
	max = m3;i = 3;if (max >= m1 && max >= m2 && max >= m4 && max >= m5) return i;
	max = m4;i = 4;if (max >= m1 && max >= m2 && max >= m3 && max >= m5) return i;
	max = m5;i = 5;if (max >= m1 && max >= m2 && max >= m3 && max >= m4) return i;
}
int checkmn(double m1,double m2,double m3,double m4,double m5) {
	double min;	int i;
	min = m1;i = 1;if (min <= m2 && min <= m3 && min <= m4 && min <= m5) return i;
	min = m2;i = 2;if (min <= m1 && min <= m3 && min <= m4 && min <= m5) return i;
	min = m3;i = 3;if (min <= m1 && min <= m2 && min <= m4 && min <= m5) return i;
	min = m4;i = 4;if (min <= m1 && min <= m2 && min <= m3 && min <= m5) return i;
	min = m5;i = 5;if (min <= m1 && min <= m2 && min <= m3 && min <= m4) return i;
}
double floor(double num){
	double o=num;
	while(o >= 1) {
	    o-=1;
	}
	return num -o;
}