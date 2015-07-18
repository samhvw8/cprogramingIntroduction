#include <stdio.h>
#define VAT 0.04
int main(){
  char ISBN[50],Title[50];
  int qty;
  double price ,total,pay;

  printf("Insert title of book : ");scanf("%[^\n]",Title);
  printf("insert ISBN of book : ");scanf(" %[^\n]",ISBN);
printf("insert Quantity of book : ");scanf("%d",&qty);
printf("insert Prince of book : ");scanf("%lf",&price);
 total = qty*price;pay = total + total*VAT;
 printf("BK Bookseller\n");
 printf("Qty    ISBN              Title                 Price       Total\n");
 printf(" ----------------------------------------------------------------------\n");
 printf("%-7d%-18s%-22s%-10.2lf%.2lf\n\n",qty,ISBN,Title,price,total);
 printf("VAT : 4 %%\nYou have to pay :%.2lf\n",pay);


  return 0;}
