#include <stdio.h>

int main () {
  int i,j,l;
  printf("chieu dai canh cua tam giac :");scanf("%d",&l);
  for (i=0;i<l;i++)
    { for(j=0;j<i+1;j++)if(j==0)printf("*");else printf(" *");printf("\n");}
  return 0;}
