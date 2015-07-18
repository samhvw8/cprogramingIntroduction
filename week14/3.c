#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int blank(char *x);
int main () {

char line[100];
  printf("Line : \n");
  scanf("%[^\n]",line);
  printf("Number of space is : %d\n",blank(line));
  return 0;
}
int blank(char *x){
  int o=0;
  int i ;
  for (i = 0 ; i <= strlen(x); i++)
    if(x[i] == ' ') o++;
  return o;
}
