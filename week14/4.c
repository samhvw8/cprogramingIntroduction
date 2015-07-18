#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int checkarr(char *arr);
int main() {
  char a[100];
  printf("input = \n");scanf("%[^\n]",a);
  printf("Check %d\n",checkarr(a));
  return 0;
}
int checkarr(char *arr){
  int i;
  if(strlen(arr)!= 8) return 0;
  if(!isalpha(arr[0])) return 0;
  for(i = 1;i <strlen(arr);i++)
    {if(i < 3) if(!isalpha(arr[i]))return 0;
      if(i > 3) if(!isdigit(arr[i]))return 0;}
     return 1;
}
