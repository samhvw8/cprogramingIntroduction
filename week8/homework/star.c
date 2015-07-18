///////////////////////////
// Name : Hoang Van Sam  //
// Class : ICT58         //
///////////////////////////

#include <stdio.h>

int main ()
{
int h,choise;
int i,j; // counter
for (;;)
{
	printf("1. Print triangle\n2. Print rhombus\n3. Quit\n\tYour Answer :");scanf("%d",&choise);
switch(choise){
	case 1:
	for(;;){
	printf("1. Input height of triangle\n2. Print triangle\n3. Return Main Menu\n4. Quit\n\tYour Answer :" );scanf("%d",&choise);
			if (choise == 1){printf("%s","Insert height of triangle :" );scanf("%d",&h);
			//--------------------------------------------------------------------------------------
			printf("Do you want print shape now\n1. Yes\n2. No\nYour Answer :" );scanf("%d",&choise);
			if (choise == 1) choise = 2; else choise = 1;
			//--------------------------------------------------------------------------------------
		}
			if (choise == 2){for (i = h; i > 0; i--){for (j = 1; j <= 2*h - 1; j++){if (j >= i && (j <= 2*h -i )) printf("*"); else printf(" ");}	printf("\n");}}
			if (choise == 3)break;
			if (choise == 4)return 0;
			}break;
	case 2:
	for(;;){
	printf("1. Input height of rhombus\n2. Print rhombus\n3. Return Main Menu\n4. Quit\n\tYour Answer :" );scanf("%d",&choise);
			if (choise == 1){printf("%s","Insert height of rhombus :" );scanf("%d",&h);
			//--------------------------------------------------------------------------------------
			printf("Do you want print shape now\n1. Yes\n2. No\nYour Answer :" );scanf("%d",&choise);
			if (choise == 1) choise = 2; else choise = 1;
			//--------------------------------------------------------------------------------------
		}
			if (choise == 2){for (i = h; i > 0; i--){for (j = 1; j <= 2*h - 1; j++){if (j >= i && (j <= 2*h -i )) printf("*"); else printf(" ");}	printf("\n");}
							 for (i = 0; i < h; i++){for (j = 1; j <= 2*h - 1; j++)if (j<=i+1)printf(" ");else if (j<2*h-1-i)printf("*");printf("\n");}}
			if (choise == 3)break;
			if (choise == 4)return 0;		
			}break;
	case 3: return 0;
	
}
}
}


