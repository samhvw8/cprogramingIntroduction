#include <stdio.h>
#define ipod 148
#define ipad 288
#define discount 0.1
int main () {
	int nipod,nipad,sum;
	float total;
printf("the number of ipod buy : ");scanf("%d",&nipod);
printf("the number of ipad buy : ");scanf("%d",&nipad);
sum = nipod*ipod + nipad*ipad;
printf("%s\n","BILL" );
printf("__________________________________________\n");
printf("|%-8s|%-8s|%-10s|%-11s|\n","Product","Qty","rate","amount" );
(nipad > 0 )?(printf("|%-8s|%-8d|%-10d|%-10.2f$|\n","Ipad",nipad,ipad,(float)nipad*ipad )):(printf(""));
(nipod > 0 )?(printf("|%-8s|%-8d|%-10d|%-10.2f$|\n","Ipod",nipod,ipod,(float)nipod*ipod )):(printf(""));
printf("|________________________________________|\n");
(sum > 1020 || nipod > 3 && nipad > 2)?(total = sum*(1-discount)):(total = sum);
 (sum > 1020 || nipod > 3 && nipad > 2)?(printf("%s\n","You have discount  10%")):(printf(""));
printf("                   Your net payment is  %-9.2f$    \n",total);
return 0;
}
