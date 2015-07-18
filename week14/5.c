#include <stdio.h>
#include <stdlib.h>
#include <string.h>


char *mystrcpy(char *str,char *sstr);
int main (){
  char a[] =  "ABCS";
    char b[6];
  
  printf("b = %s\n",mystrcpy(b,a));

  return 0;
}
char *mystrcpy(char *str,char *sstr){
  int i;
  for (i = 0; i < strlen(sstr);i++)
    str[i] = sstr[i];
  str[i] = '\0';

  return str;
}
