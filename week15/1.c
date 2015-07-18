
#include <stdio.h>
#define MAX 100
typedef struct Date{
  int day;
  int month;
  int year;
}date;
//
void softdate(date arr[],int n);
int inputdatea(Date arr[]);
void inputday(date *d);
int datecmp(Date day1,Date day2);
void swap(date *d1,date *d2);
void printd(date d);
void printdata(date arr[],int l);
//
int main()
{ 
  int l;
  date Datea[MAX];
  l = inputdatea(Datea);
  // printd(date[1]);
  printdata(Datea,l);
  
  printdata(Datea,l);

}
//

int inputdatea(date arr[]){
  int i=0;

  do {
    printf("Input day %d : ",i+1);inputday(&arr[i]);i++;
  }while(arr[i-1].day != 0  && arr[i-1].month != 0  &&arr[i-1].year != 0);

  if(i == 0) return 1;
   return i-1;
}

void inputday(date *d)
{ 
  do{
  printf("Input day (dd/mm/yyyy) :");
  scanf("%2d%*c%2d%*c%4d",&d->day,&d->month,&d->year);
  if (d->day == d-> month == d -> year == 0) break;
  if (d->day < 0 ||d->day >31 || d->month < 0|| d->month > 12 || d -> year < 0) printf("\n%s\n","Wrong input ! input again");

  }while(d->day < 0 ||d->day >31 || d->month < 0|| d->month > 12 || d -> year < 0);
}
void printd(date d){
  printf("%02d/%02d/%04d\n",d.day,d.month,d.year);
}
void swap(date *d1,date *d2){
  date tempd;
  tempd = *d1;
  *d1 = *d2;
  *d2 = tempd;
} 

int datecmp(date day1,date day2){
  if(day1.year < day2.year) return -1;
  else if(day1.year > day2.year) return 1;
  else if(day1.month < day2.month) return -1;
  else if(day1.month > day2.month) return 1;
  else if(day1.day < day2.day) return -1;
  else if(day1.day > day2.day) return 1;
  else return 0;
}

void softdate(date arr[],int n){
  int i,j;
  for(i = 1 ; i < n ; i++){ j = i ;
    while( ( j > 0)&&( datecmp(arr[j],arr[j-1]) != 1 ))
      {swap(&arr[j],&arr[j-1]);j--;}  
  }
}
void printdata(date arr[],int l){
  int i;
  printf("%-4s %-11s\n","STT","dd/mm/yyyy");
   for (i = 0; i < l; ++i)  {printf("\n%-5d",i+1);printd(arr[i]);}
    printf("\n");
}
