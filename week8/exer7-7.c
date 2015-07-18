#include <stdio.h>
#define feh(c) (1.8*c + 32.0)
int main (){
  int start,end,lamda;
  int i,c;
  for(;;)
    {printf("1.input data\n2.Print data\n3.Quit\n\tYour Choice : ");
      scanf("%d",&c);
      switch(c) {
      case 1:
  printf("start point : ");scanf("%d",&start);
  printf("end point : ");scanf("%d",&end); 
  printf("lamda : ");scanf("%d",&lamda);
  break;
    case 2:
      printf("%c   %c\n",'C','F');
  for (i = start ; i <= end; i += lamda) printf("%d   %.2f\n",i,feh(i));
  break;
      case 3:return;}
}
  return 0;}
