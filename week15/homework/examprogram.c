#include "Ginz.h"
#define MAXLQ 100
#define MAXLA 100
#define MAXQ 50
#define MAXP 5

typedef struct {
	char q[MAXLQ];
	char a1[MAXLA];
	char a2[MAXLA];
	char a3[MAXLA];
	int correct;
} Quest;

typedef struct {
	int no,point;
} playerp;

int inputdata(Quest arr[],FILE *fp);
void printq(Quest arr[],int q);
void submitas(int arr[][MAXQ],int q);
void checks(playerp parr[],int sarr[][MAXQ],Quest questa[],int q);
void swap(playerp *a , playerp *b);
void sortplayer(playerp parr[]);
void printp(playerp parr[]);

int main (){
	playerp playerp[MAXP];// player point
	Quest questa[MAXQ];	
	int players[MAXP][MAXQ]; // player solution
	int q,c=0;

	q = inputdata(questa,fopen("quest.dat", "r"));fclose("quest.dat");
	printq(questa,q);
	for(;;){switch(GetMenu("Submit Solution;Print Point and sort from big to small",2,1)){
			case 1:c=1;submitas(players,q);
			checks(playerp,players,questa,q);mfflush();break;
		
			case 2:if(c!=1)printf("\n\tSubmit Solution First"); 
			else {
				sortplayer(playerp);printp(playerp);
				}break;
			case 0:return 0;
		}
	}
}

int inputdata(Quest arr[],FILE *fp){
	int q,i;
	fscanf(fp,"%d\n",&q);
	for (i = 0 ; i < q ; i ++){
		fgets(arr[i].q,sizeof(arr[i].q),fp);
		fgets(arr[i].a1,sizeof(arr[i].a1),fp);
		fgets(arr[i].a2,sizeof(arr[i].a2),fp);
		fgets(arr[i].a3,sizeof(arr[i].a3),fp);
		fscanf(fp, "%d\n",&arr[i].correct);
	}
	fclose(fp);
	return q;
}
void printq(Quest arr[],int q){
	int i;
	printf("\t%s\n\n","QUESTION LIST ");
	for (i = 0; i < q; ++i){
		printf("\t%s %d: ","Quest",i+1);
		printf("%s",arr[i].q);
		printf("\tSolution :\n\t1. %s",arr[i].a1);
		printf("\t2. %s",arr[i].a2);
		printf("\t3. %s",arr[i].a3);
	}
	printf("\n");
}
void submitas(int arr[][MAXQ],int q){
	int i,j;
	for (i = 0; i < MAXP; ++i)
	{
		printf("\n%s%d submit Solution(q1 q2 q3 q4 q5): ","Player ",i+1);
		for(j = 0; j < q ;++j)scanf("%d",&arr[i][j]);
	}
}
void checks(playerp parr[],int sarr[][MAXQ],Quest questa[],int q){
	int i,j;
	for (i = 0; i < MAXP; ++i) {parr[i].point = 0;parr[i].no = i+1;}
	for (i = 0; i < q; ++i) {
		for (j = 0; j < MAXP; ++j) if(sarr[j][i] == questa[i].correct) parr[j].point++;
	}
}
void sortplayer(playerp parr[]){
	int i,j;
	for (i = 1 ;i < MAXP ;i++){
		j = i;
		while(j>0 && (parr[j].point > parr[j-1].point )){
			swap(&parr[j],&parr[j-1]);
			j--;
		}
	}
}

void printp(playerp parr[]){
	int i;
	printf("\n\n\t%s","Player | ");
	for (i = 0; i < MAXP; ++i)printf("%d| ",parr[i].no);
	printf("\n\t%s","-------|--|--|--|--|--|");
	printf("\n\t%s","Point  | ");
	for (i = 0; i < MAXP; ++i)printf("%d| ",parr[i].point);
	printf("\n");
}

void swap(playerp *a , playerp *b){
  playerp temp;
  temp  = *a;
  *a  = *b;
  *b = temp;
}