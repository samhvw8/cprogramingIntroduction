#include <stdio.h>
int check(int a);

int main() {
  int o;
  
  do {
    printf("Insert Number : ");scanf("%d",&o); 
    if(o < 0) printf("\nWrong input!\n");} while(o < 0);
  if(co(o)) printf("\nall figures on %d is odd\n",o);
 else if(ce(o)) printf("\nall figures on %d is even\n",o);
 else printf("\b%d is nothing !\n",o);
return 0;
}
int check(int c){
  if(c%2 == 0 )return 1;
 return 0;
}
int ce(int c){
  do {
  if(1-check(c%10))return 0; 
  c = c /10;}while ( c != 0);
  return 1;
}
int co(int c){
  do {
  if(check(c%10))return 0; 
  c = c /10;}while ( c != 0);
  return 1;
}
