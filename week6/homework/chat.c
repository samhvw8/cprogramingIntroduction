#include <stdio.h>

int main() {
int point1,point2;
int height1,height2,mheight;
int age1,age2;
point1 = point2 = 0;
printf("%s","Login - enter your height(cm) :"); scanf("%d",&mheight);
printf("%s\n","Hi lan: "); // 1
printf("%s","- How old are you ? ");scanf("%d",&age1);
printf("%s","- What's your height? " );scanf("%d",&height1);
printf("%s\n","Hi Mai: "); // 2 
printf("%s","- How old are you ? ");scanf("%d",&age2);
printf("%s","- What's your height? " );scanf("%d",&height2);
(age1 >25 )?(point1 = point1 + 2):((16 < age1 < 21 )?(point1 = point1 + 5):(point1 = point1+0));
(age2 >25 )?(point2 = point2 + 2):((16 < age2 < 21 )?(point2 = point2 + 5):(point2 = point2+0));
(height1>=mheight)?(point1 = point1 - 1):((height1 < mheight - 30)?(point1 = point1 - 2):(point1 = point1 + 3));
(height2>=mheight)?(point2 = point2 - 1):((height2 < mheight - 30)?(point2 = point2 - 2):(point2 = point2 + 3));
 printf("lan's point :%d \n",point1);
 printf("Mai's point :%d \n",point2);
(point1==point2)?(printf("Lan, are you free on saturday?\nMai, are you free on sunday?\n")):((point1>point2)?(printf("Lan, are you free on saturday?\n")):(printf("Mai, are you free on sunday?\n")));
return 0;	
}


