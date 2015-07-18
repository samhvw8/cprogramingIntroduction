#include <stdio.h>
#define MAX 100
typedef struct Date{
	int day;
	int month;
	int year;
}date;

void swap(date *d1,date *d2);
int inputa(date arr[]);
void inputday(date *d);
void printd(date *d);
int main()
{
	int l;
	date date[MAX];
	l = inputa(date);
	printd(&date[l-1]);
}

int inputa(date arr[]){
	int i=0;
	printf("%s\n","Input day 1 : ");inputday(&arr[i]);i= 1;
	while(1){
		if(arr[i-1].day == arr[i-1].month ==  arr[i-1].year == 0) break;
		printf("%s%d :\n","Input day  ",i+1);inputday(&arr[i]);
		i++;

	}
	return i;
}
void inputday(date *d)
{
	do{
	printf("Input day (dd/mm/yyyy) :");
	scanf("%d%*c%d%*c%d",&d->day,&d->month,&d->year);
	if (d->day == d-> month == d -> year == 0) break;
	if (d->day < 0 ||d->day >31 || d->month < 0|| d->month > 12 || d -> year < 0) printf("\n%s\n","Wrong iput ! input again");

	}while(d->day < 0 ||d->day >31 || d->month < 0|| d->month > 12 || d -> year < 0);
}
void printd(date *d){
	printf("%02d/%02d/%04d\n",d->day,d->month,d->year);
}
void swap(date *d1,date *d2){
	date tempd;
	//
	tempd.day = d1->day;
	tempd.month = d1->month;
	tempd.year= d1->year;
	//
	d1->day = d2->day;
	d1->month = d2->month;
	d1->year = d2->year;
	//
	d2->day =tempd.day;
	d2->month =tempd.month;
	d2->year =tempd.year;
}


