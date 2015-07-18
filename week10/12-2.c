#include <stdio.h>

int is_prime(int n);

int main () {
  int n,l,k;
  printf("Input limit Number :");scanf("%d",&l);k = 0;
  for ( n = 0 ; n <= l;n++) if (is_prime(n) && k < 5) {printf("%d\t",n);k++;}
    else if (is_prime(n) && k == 5) {printf("\n%d\t",n);k = 1;}
  printf("\n");
  return 0; 
  
}
int is_prime(int n){
  int i;
  if (n == 1 || n == 0) return 0;
else  if(n == 2) return 1;
 else for (i = 2 ; i < n-1 ;i++) if(n%i==0)return 0;
  return 1;
}
