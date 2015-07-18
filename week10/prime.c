#include <stdio.h>

int is_prime(int n);

int main () {
  int n;
  printf("Input Number :");scanf("%d",&n);
  if(is_prime(n))printf("%d is prime number\n",n);else printf("%d isn't prime number\n",n);
  return 0;
}
int is_prime(int n){
  int i;
  if (n == 1 || n == 0) return 0;
else  if(n == 2) return 1;
 else for (i = 2 ; i < n-1 ;i++) if(n%i==0)return 0;
  return 1;
}
