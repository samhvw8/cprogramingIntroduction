////////////////////////////
// Author : Hoang Van Sam //
// Class :ICT 58 - HUST   //
////////////////////////////
#include <stdio.h>
int main () {
/** temt = temperature 
 * humi = Humidity 
 * crainy =  check for rainy
 */
	int crainy;
	float temt,humi;
// ----------------------------------------------------------
	printf("%s","temperature : " );scanf("%f",&temt); 
	printf("%s","Humidity (%): " );scanf("%f",&humi); 
	printf("%s","rainy or not ( rain = 1 , not  = 0 ) :" );scanf("%d",&crainy); 
// ----------------------------------------------------------
    printf("\n%s\n%s\n","Yahoo Weather Forecast","Today");
    printf("Details\n");
    printf("%s %.2f degree of C and %s: %.2f%%\n","Temperature :",temt,"Humidity",humi);
    if (crainy == 1) printf("%s\n","it may rain\n"); 
// ----------------------------------------------------------
    printf("%s","You should " );
if (temt > 35.0 && humi > 67.0 ) printf("%s\n","Rest at home !" ); 
else if ((temt < 30.0 && humi < 40.0 ) && (temt > 20.0 && humi > 32.0) && crainy == 0 ) printf("%s\n","Go Out for photography " );
else printf("%s\n","Remember to take  umbrella !" );
return 0;
}