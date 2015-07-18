#include <stdio.h>

int main () {
  char a,b,c;
  printf("insert 3 character continuous : ");scanf("%c%c%c",&a,&b,&c);
  if(a<c && a< b) printf("the character in first of alpha : %c\n",a);
  if(b<c && a > b) printf("the character in first of alpha : %c\n",b);
  if(a>c && c< b) printf("the character in first of alpha : %c\n",c);
  return 0;
}
