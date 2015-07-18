///////////////////////////
// Name : Hoang Van Sam  //
// Class : ICT58         //
///////////////////////////


#include <stdio.h>
#define inpahos 150000  // 150k / day   inpahos = inpatient hospitalization
#define iG 0.3   // Gold  1      
#define iS 0.5   // sliver  2
#define iC 0.7	//citizen  3

int main () {
char name[50];
int lendoh,checksgy,tinsur,choise;
int npatient,nG,nS,nC;
double total,surgery,bdrug; 
double tfee ,mp ;
surgery = tfee =mp = npatient= nG = nS = nC = 0;
for(;;){printf("1. Input data/Bill for new patient\n2. Print the total report\n3. Quit\n\tYour Choise :");scanf("%d",&choise);
	if(choise == 1){npatient++;
		printf("\n\n----------------------------------------------------------------------------------\n");
printf("%s","Patient's Name : " );scanf(" %[^\n]",name);
printf("%s","Number of days in hospital :" );scanf("%d",&lendoh);
printf("%s","Is patient has surgery (1 = yes ,2 = no) \n Your answer: " );scanf("%d",&checksgy);
if (checksgy == 1){printf("%s","surgery bill : " );scanf("%lf",&surgery);}
printf("%s","drugs bill : " );scanf("%lf",&bdrug);
printf("%s","Type of medicine assurance :\n1 .Gold\n2 .Sliver\n3 .Citizen\n4 .Don't have insurance health\n\tYour answer :" );scanf("%d",&tinsur);
printf("---------------------------------------------------------------------------------\n\n");
total = (float)(lendoh*inpahos + surgery +bdrug);

printf("would you like to printt bill \n1. Yes\n2.No\n");printf("your choise : ");scanf("%d",&choise);if(choise == 1){
printf("\n\n----------------------------------------------------------------------------------\n");
printf("%s\n","hospital bills ");
printf("Patient's Name :%s\n",name);
printf("Your type of insurance health :");
if (tinsur == 1)printf("%s\n","Gold" );
if (tinsur == 2)printf("%s\n","Sliver" );
if (tinsur == 3)printf("%s\n","Citizen" );
if (tinsur == 4)printf("%s\n","None" );
if (checksgy == 1) printf("%s\n","The patient has surgery" );
printf("----------------------------------------------------------------------------------\n");
printf("%-30s %20s %10s %19s\n","components","Rate","qty","Amount");
printf("%-30s %20d %10d %19.2f\n","inpatient hospitalization",inpahos,lendoh,(float)inpahos*lendoh);
printf("%-30s %20.2f %10s %19.2f\n","Drugs Bills",bdrug,"1",bdrug);
if (checksgy == 1) printf("%-30s %20.2f %10s %19.2f\n","Surgery bill",surgery,"1",surgery);
printf("----------------------------------------------------------------------------------\n");
printf("Your net payment is %62.2f\n",total);
if (tinsur == 1){printf("%51s %10.2f\n","your have insurance health Gold - you have discount 70%%  equals to" ,total - total*iG);(mp <(total - total * iG))?(mp = total - total * iG):(printf(""));total = total * iG;}
if (tinsur == 2){printf("%49s %12.2f\n","your have insurance health Sliver - you have discount 50%%  equals to" ,total - total*iS);(mp <(total - total * iS))?(mp = total - total * iS):(printf(""));total = total * iS;}
if (tinsur == 3){printf("%51s %10.2f\n","your have insurance health Citizen - you have discount 30%%  equals to" ,total - total*iC);(mp <(total - total * iC))?(mp = total - total * iC):(printf(""));total = total * iC;}
printf("Total %76.2f\n",total);
printf("---------------------------------------------------------------------------------\n\n");
}
else {
if (tinsur == 1){(mp <(total - total * iG))?(mp = total - total * iG):(printf("")) ;total = total * iG;nG++;}
if (tinsur == 2){(mp <(total - total * iS))?(mp = total - total * iS):(printf("")) ;total = total * iS;nS++;}
if (tinsur == 3){(mp <(total - total * iC))?(mp = total - total * iC):(printf("")) ;total = total * iC;nC++;}
}
tfee =+ total;

}
 if(choise == 2){
 	printf("\n\n---------------------------------------------------------------------------------");
 	printf("The Number of patient is %d\n",npatient); 
 	printf("THe average of fee %.2lf\n",(float)tfee/npatient );
 	printf("The Number of Medicine assurance \n");printf("Type Gold : %d\n",nG);printf("Type sliver : %d\n",nS);printf("Type Citizen : %d\n",nC);
 	printf("The most profit from  assurance a Patient  can get %.2lf\n",mp);

 	//medicine assurance
 	printf("---------------------------------------------------------------------------------\n\n");
 }
 if(choise == 3)return 0;
 // --------------------------------------------------------------------------
}
}