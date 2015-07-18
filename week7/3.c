#include <stdio.h>
#define rtulanh 8000000
#define rtivi 15000000
#define rhp 12000000
int main () {
  int tulanh,tivi,hp;
  printf("insert Freezer had been sold : ");scanf("%d",&tulanh);
  printf("insert TV had been sold : ");scanf("%d",&tivi);
  printf("insert Laptop had been sold : ");scanf("%d",&hp);
  printf("\n\n");
  printf("--------------------------------------------------\n");
  printf("%-8s%-5s%15s%22s\n","Product","Qty","Rate","Amount");
  printf("%-8s%-5d%15d%22d\n","Freezer",tulanh,rtulanh,tulanh*rtulanh);
  printf("%-8s%-5d%15d%22d\n","TV",tivi,rtivi,tivi*rtivi);
  printf("%-8s%-5d%15d%22d\n","Laptop",hp,rhp,hp*rhp);
    printf("--------------------------------------------------\n");

    if ( tulanh > tivi && tulanh > hp) printf("The most Product is Freezer\n");
    else if ( tulanh < tivi && tulanh < hp) printf("The bad Product is Freezer\n");
if ( tivi  > tulanh  && tivi > hp) printf("The most Product is TV\n");
 else if ( tivi  < tulanh  && tivi < hp)  printf("The bad Product is TV\n");
if ( hp > tivi && hp > tulanh) printf("The most Product is Laptop\n");
 else if ( hp < tivi && hp < tulanh)   printf("The bad Product is Laptop\n");
    printf("--------------------------------------------------\n");
 if ( tulanh*rtulanh > tivi*rtivi && tulanh*rtulanh > hp*rhp)
 printf("The most Product is Freezer\n");
    else if ( tulanh*rtulanh < tivi*rtivi && tulanh*rtulanh < hp*rhp)
 printf("The bad profit  is Freezer\n");
if ( tivi*rtivi  > tulanh*rtulanh  && tivi*rtivi > hp*rhp) 
printf("The most profit is TV\n");
 else if ( tivi*rtivi  < tulanh*rtulanh  && tivi*rtivi < hp*rhp)
  printf("The bad profit  is TV\n");
if ( hp*rhp > tivi*rtivi && hp*rhp > tulanh*rtulanh) 
printf("The most profit is Laptop\n");
 else if ( hp*rhp < tivi*rtivi && hp*rhp < tulanh*rtulanh) 
  printf("The bad profit  is Laptop\n");
    printf("--------------------------------------------------\n");
return 0;}


