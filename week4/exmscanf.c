#include <stdio.h>

int main () {
  int d,m,y,x;
  char ch1,ch2;
  float f;
  scanf("%d", &x);printf("%d\n",x);
  scanf("%2d%2d%4d", &d,&m,&y);printf("%02d%02d%04d\n",d,m,y);
 scanf("%d/%d/%d", &d,&m,&y);printf("%02d/%02d/%04d\n",d,m,y);
 scanf("%c%c",&ch1,&ch2);printf("%c%c\n",ch1,ch2);
 scanf("%f",&f);printf("%f\n",f);
 return 0;
}
