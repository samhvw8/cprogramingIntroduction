#include <stdio.h>
void incomeplus(int* s,int* year);
int main () {
  int salary,year;
  printf("Input current salary per month :");scanf("%d",&salary);
  printf("How many year has been work :");scanf("%d",&year);
  incomeplus(&salary,&year);
  printf("Your salary now %d \n",salary);
}
void incomeplus(int *s,int* year){
  if(*year > 3) {*s *= 2;printf("Your salary has increase \n");} 
  else printf("Your salary hasn't increase !\n");
}
