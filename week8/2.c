#include <stdio.h>
#include <string.h>
int main () {
  char s[20];
  printf("insert string :");scanf(" %[^\n]",s);
  int i,j;
  for (i = 0, j=strlen(s)-1;i<j;i++,j--)printf("%d\n",i+j);

  return 0;
}
