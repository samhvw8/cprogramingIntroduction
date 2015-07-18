////////////////////////////
// Author : Hoang Van Sam //
// Class :ICT 58 - HUST   //
////////////////////////////

#include <stdio.h>
#include <math.h>
int main () {
float ctx,cty,cgx,cgy,x,y,d; // c = current ,  g = target (goal)


int gn, ge, gs, gw;// n = North  e = east s = South w = West 
int cn, ce, cs, cw;// n = North  e = east s = South w = West 

gn = ge = gs = gw = 0;
cn = ce = cs = cw = 0;

printf("%s","Insert your present coordinates x,y : " );scanf("%f%*c%f",&ctx,&cty); /*input current coordinates*/
printf("%s","Insert your target coordinates x,y : " );scanf("%f%*c%f",&cgx,&cgy);  /*input goal coordinates*/
// calculate Distance
 x = (ctx - cgx)>0?(ctx - cgx):(cgx - ctx);
 y = (cty - cgy)>0?(cty - cgy):(cgy - cty);
d = sqrt(x*x + y*y);
// ------identify the location between current location and target location ---------------------------

if (ctx > cgx && cty > cgy) {gw = 1; gs = 1;ce = 1;cn = 1;}
if (ctx > cgx && cty < cgy) {gw = 1; gn = 1;ce = 1;cs =1 ;}
if (ctx < cgx && cty > cgy) {ge = 1; gs = 1;cw =1;cn = 1;}
if (ctx < cgx && cty < cgy) {ge = 1; gn = 1;cw = 1; cs =1;}
if (ctx == cgx && cty > cgy) {gs = 1;cn = 1;}
if (ctx == cgx && cty < cgy) {gn = 1;cs = 1;}
if (ctx > cgx && cty == cgy) {gw = 1;ce = 1;}
if (ctx < cgx && cty == cgy) {ge = 1;cw = 1;}
// ------identify where are you with target location---------------------------------------------------
printf("\n\n");
printf("%s","it is about ");
if (cn == 1 && cs == 0 && ce == 0 && cw == 0 ) printf("%.2f km away from target location at the %s\n",d,"North " );  
if (cs == 1 && cn == 0 && ce == 0 && cw == 0 ) printf("%.2f km away from target location at the %s\n",d,"South " );  
if (ce == 1 && cn == 0 && cs == 0 && cw == 0 ) printf("%.2f km away from target location at the %s\n",d,"east ");  
if (cw == 1 && cn == 0 && cs == 0 && ce == 0 ) printf("%.2f km away from target location at the %s\n",d,"West "); 
if (ce == 1 && cn == 1 && cw == 0 && cs == 0)  printf("%.2f km away from target location at the %s\n",d,"east of North" );
if (cw == 1 && cn == 1 && ce == 0 && cs == 0)  printf("%.2f km away from target location at the %s\n",d,"West of North" );
if (ce == 1 && cs == 1 && cw == 0 && cn == 0)  printf("%.2f km away from target location at the %s\n",d,"east of South" );
if (cw == 1 && cs == 1 && ce == 0 && cn == 0)  printf("%.2f km away from target location at the %s\n",d,"West of South" );

// ------identify the direction should go--------------------------------------------------------------
printf("\n\n");
// printf("%s%.2f\n","Distance to target location : ",d);
printf("%s","you should go to ");
if (gn == 1 && gs == 0 && ge == 0 && gw == 0 ) printf("%s with Distance %.2f km\n","North",d );  
if (gs == 1 && gn == 0 && ge == 0 && gw == 0 ) printf("%s with Distance %.2f km\n","South",d );  
if (ge == 1 && gn == 0 && gs == 0 && gw == 0 ) printf("%s with Distance %.2f km\n","east",d);  
if (gw == 1 && gn == 0 && gs == 0 && ge == 0 ) printf("%s with Distance %.2f km\n","West",d); 
if (ge == 1 && gn == 1 && gw == 0 && gs == 0)  printf("%s%.2f km\n","east of North with Distance ",d );
if (ge == 1 && gs == 1 && gw == 0 && gn == 0)  printf("%s%.2f km\n","east of South with Distance ",d );
if (gw == 1 && gn == 1 && ge == 0 && gs == 0)  printf("%s%.2f km\n","West of North with Distance ",d );
if (gw == 1 && gs == 1 && ge == 0 && gn == 0)  printf("%s%.2f km\n","West of South with Distance ",d );
// --------------------------------------------------------------
 	return 0;
}


