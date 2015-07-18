#include <stdio.h>

int main () {
  int a[] = {17,289,4913}, *p,*q;
  p = a;
  q = p +2;
  printf("a is %p\n",a);
  printf("p is %p, q is %p\n",p,q);
  printf("p points to &d and q points to %d\n",*p,*q);
  printf("The pointer distance between p and q is %d\n",q-p);
  printf("The integer distance between p and q is %d\n",(int)q -(int)p);
  return 0;
}
