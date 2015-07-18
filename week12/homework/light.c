/**Light
 * * Require
 * Turn on/off in row
 * Turn on/off in col
 * Turn on/off in each light
 * Show watt 
 * * Addition
 * show stt
 *
 * 
 * Author Hoang Van Sam
 * Class ICT58 - HUST
 */

#include <stdio.h>
#define rowl 5
#define coll 3
#define wattodd 10
#define watteven 20
#define wattreg 15 // reg = regular
#define ON 1
#define OFF 0
#define RESET  "\x1b[0m"
#define WHITE  "\x1B[37m"
#define INVALID -1
#define maxoption 100
#define tabs 4

void credit();
int GetMenu();
void turnflc(int larr[][coll],int tlarr[][coll],int j);// turn off light in a col;
void turnolc(int larr[][coll],int j);// turn on light in a col;
// ===============================================================
void turnflf(int larr[][coll],int tlarr[][coll],int i,int j);// turn off 1 light for function;
void turnolf(int larr[][coll],int i,int j); // turn on 1 light for function;
// ===============================================================
void turnolr(int larr[][coll],int i);// turn on light in a row;
void turnflr(int larr[][coll],int tlarr[][coll],int i);// turn off light in a row;
// ===============================================================
int checko(int larr[][coll],int i,int j);// check on light
void turnol(int larr[][coll],int i,int j); // turn on 1 light;
void turnfl(int larr[][coll],int tlarr[][coll],int i,int j); // turn off 1 light;
// ===============================================================
void definel(int larr[][coll],int tlarr[][coll]);// set all light off for first time
// void turnaon(int larr[][coll]);// turn all light on
// void turnaof(int larr[][coll],int tlarr[][coll]);// turn all light off
// ===============================================================
void show(int larr[][coll],int tlarr[][coll],int watt,int stt); // show the light 
int wloc(int i,int j); // determine watt depend on location 
int checkcl(int i,int j,int row, int col); // check for statisfied  1 <i< rowl // 1 <j< coll  return 0 when true , 1 - false
// ==========================================================================================================
int countma(char arr[][maxoption],int num);
int countcs(char arr[]);
void repchar(int times,char c);//print character  c with (times) 
int power(int x,int n); // power x^n
int str2numa(char arr[],int length); // convert string to number
int checkan(char arr[],int length); // check array number (int)
int GetMenu(char *a,int o);
// ===============================================================
int main () {
	int sl[rowl][coll],tl[rowl][coll],c,cc,k; // sl : status light / time use each light ( 1 on  +  1 off = 1time)
	definel(sl,tl);

	
	printf("\n\t .================== Light in lab(5x3) ================. \n\n");
	show(sl,tl,OFF,ON);
	for(;;){
		switch(GetMenu((char *)"Turn light on in row;Turn light off in row;Turn light on in col;Turn light off in col;Turn On 1 light;Turn Off 1 light;Show STT of light;Show watt of light",8)){
		case 1: do {printf("\n\tWhat the row you want to turn on : ");scanf("%d",&c);if(checkcl(c,0,ON,OFF))printf("\tInput wrong Input again !\n");}while(checkcl(c,0,ON,OFF));turnolr(sl,c-1);while((k=getchar())!='\n');break; //Turn on in row         
		case 2: do {printf("\n\tWhat the row you want to turn off : ");scanf("%d",&c);if(checkcl(c,0,ON,OFF))printf("\tInput wrong Input again !\n");}while(checkcl(c,0,ON,OFF));turnflr(sl,tl,c-1);while((k=getchar())!='\n');break;  //Turn off in row        
		case 3: do {printf("\n\tWhat the col you want to turn on : ");scanf("%d",&c);if(checkcl(0,c,OFF,ON))printf("\tInput wrong Input again !\n");}while(checkcl(0,c,OFF,ON)); turnolc(sl,c-1);while((k=getchar())!='\n');break; //Turn on in  col        
		case 4: do {printf("\n\tWhat the col you want to turn off : ");scanf("%d",&c);if(checkcl(0,c,OFF,ON))printf("\tInput wrong Input again !\n");}while(checkcl(0,c,OFF,ON));turnflc(sl,tl,c-1);while((k=getchar())!='\n');break; //Turn off in col        
		case 5: do {printf("\n\tWhat the light you want to turn on(row:col) : ");scanf("%d:%d",&c,&cc);if(checkcl(c,cc,ON,ON))printf("\tInput wrong Input again !\n");}while(checkcl(c,cc,ON,ON));turnol(sl,c-1,cc-1);while((k=getchar())!='\n');break;//Turn on in one light   
		case 6: do {printf("\n\tWhat the light you want to turn off(row:col) : ");scanf("%d:%d",&c,&cc);if(checkcl(c,cc,ON,ON))printf("\tInput wrong Input again !\n");}while(checkcl(c,cc,ON,ON));turnfl(sl,tl,c-1,cc-1);while((k=getchar())!='\n');break;//Turn off in one light  
		case 7:show(sl,tl,OFF,ON);break; //Show stt of light      
		case 8:show(sl,tl,ON,OFF);break;//Show watt of light     
		case 0: printf("\n"); return 0;  //Exit                   
		}
	}
}
// ===================Row========================================
// turn on light in a row;
void turnolr(int larr[][coll],int i){
	int z;
	for (z = 0; z < coll; ++z) turnolf(larr,i,z);
		printf("\n\tTurn on Light In row %d successfully\n",i+1 );
	
}
// turn off light in a row;
void turnflr(int larr[][coll],int tlarr[][coll],int i){
	int z;
	for (z = 0; z < coll; ++z) turnflf(larr,tlarr,i,z);
		printf("\n\tTurn off Light In row %d successfully\n",i+1 );
	
}
// ===================Col========================================
// turn on light in a col;
void turnolc(int larr[][coll],int j){
	int z;
	for (z = 0; z < rowl; ++z) turnolf(larr,z,j);
	printf("\n\tTurn on Light In col %d successfully\n",j+1 );

}
// turn off light in a col;
void turnflc(int larr[][coll],int tlarr[][coll],int j){
	int z;
	for (z = 0; z < rowl; ++z) turnflf(larr,tlarr,z,j);
		printf("\n\tTurn off Light In col %d successfully\n",j+1 );
	
}
// ===================element====================================
// turn on 1 light for function;
void turnolf(int larr[][coll],int i,int j){
	if(checko(larr,i,j)!=ON) larr[i][j] = ON;
}
// turn off 1 light for function;
void turnflf(int larr[][coll],int tlarr[][coll],int i,int j){
	if(checko(larr,i,j)) {larr[i][j] = OFF;tlarr[i][j]++;}
}
// turn on 1 light;
void turnol(int larr[][coll],int i,int j){
	if(checko(larr,i,j)) printf("\n\tThe light in row %d col %d is already turn on !\n",i+1,j+1); 
	else {larr[i][j] = ON;printf("\n\tTurn on the light in row %d col %d successfully !\n",i+1,j+1);}
	
}
// turn off 1 light;
void turnfl(int larr[][coll],int tlarr[][coll],int i,int j){
	if(checko(larr,i,j)!=1) printf("\n\tThe light in row %d col %d is already turn off !\n",i+1,j+1); 
	else {larr[i][j] = OFF;printf("\n\tTurn off the light in row %d col %d successfully !\n",i+1,j+1);tlarr[i][j]++;}

}
// check on light
int checko(int larr[][coll],int i,int j){
	if (larr[i][j] == ON) return ON;
	return OFF;
}

// ===============================================================
// set all light off for first time
void definel(int larr[][coll],int tlarr[][coll]){
	int i,j;
	i = j = 0;
	while(i <rowl) { larr[i][j] = tlarr[i][j] = 0; j++;
		if(j == coll - 1 ) {larr[i][j] = tlarr[i][j] = 0;j=0;i++;}	    
	}
}
// ===============================================================
// // turn all light off
// void turnaon(int larr[][coll],int tlarr[][coll]){
// 	int i,j;
// 	i = j = 0;
// 	while(i <rowl) { if(checko(larr,i,j)){larr[i][j] = OFF;tlarr[i][j]++;} j++;
// 		if(j == coll - 1 ) {if(checko(larr,i,j)){larr[i][j] = OFF;tlarr[i][j]++;}j=0;i++;}	    
// 	}
// }
// // turn all light on
// void turnaof(int larr[][coll],int tlarr[][coll]){
// 	int i,j;
// 	i = j = 0;
// 	while(i <rowl) { larr[i][j] = ON; j++;
// 		if(j == coll - 1 ) {larr[i][j] = ON;j=0;i++;}	    
// 	}
// }
// ===============================================================
// show light
void show(int larr[][coll],int tlarr[][coll],int watt,int stt){
	/**
	 * i , j , z  (index)
	 * w  =  watt for each location in 1 times ( 1 on - 1off)
	 * totalw = total watt
	 */
	int i,j,w,z,totalw=0;    
	i = j = 0;
	printf("\t\t\t\t   ");
	if(stt == ON)for (z = 0 ; z < coll ; z++) printf("%d  ",z+1 );
	if(watt == ON)for (z = 0 ; z < coll ; z++) printf("   %d    ",z+1 );
	printf("\n");
	while(i <rowl) { 
		if(stt == ON){
				
				if(j == 0)printf("\t\t\t\t%d [",i+1);
				if(larr[i][j]==OFF)printf(" ][");else printf("#]["); j++;
				if(j == coll - 1 ) {if(larr[i][j]==OFF)printf(" ]\n");else printf("#]\n");j=0;i++;}
			}	
		if(watt == ON){
				if(j == 0)printf("\t\t\t\t%d [",i+1);w = wloc(i,j);totalw+=tlarr[i][j]*w;printf("%4d W][",tlarr[i][j]*w); j++;
				if(j == coll - 1 ) {w = wloc(i,j);totalw+=tlarr[i][j]*w;printf("%4d W]\n",tlarr[i][j]*w);j=0;i++;}
		}    
	}
	if(stt == ON)printf("\n");
	if(watt == ON)printf("\n\tTotal watt of all light %d\n",totalw);
}
// determine watt depend on location 
int wloc(int i,int j){
	i++; j++;
	if(i%2 == 0 && j%2==0) return watteven; 
	else if(i%2 == 1 && j%2==1) return wattodd; else return wattreg;
}
// check for statisfied  1 <i< rowl // 1 <j< coll return 0 when true , 1 - false
int checkcl(int i,int j,int row, int col){
	if(row == ON && col == OFF) if( i <= rowl && i>=1 ) return 0; else return 1;
	if(col == ON && row == OFF) if( j <= coll && j>=1 ) return 0; else return 1;	
	if(col == ON && row == ON) if( j <= coll && j>=1 && i <= rowl && i>=1 ) return 0; else return 1;	
}
// ================================================
//print character  c with (times) 
void repchar(int times,char c){
	int i;
	for(i = 0; i < times; ++i) printf("%c",c);
}
// count character in string
int countcs(char arr[]){
	int i=0;
	while(arr[i]!= '\0')  i++;
	return i;
}
// max lengthgth in 2 demention string
int countma(char arr[][maxoption],int num){
	int i,m; m = 0;
	for (i = 0; i < num; ++i) if(m < countcs(arr[i]))m = countcs(arr[i]);
		return m;
}
// check string is all number or not
int checkan(char arr[],int length){
	length--;
	int i;
	for (i = 0 ; i < length ; i++) if(arr[i] < '0' || arr[i] > '9') return 0;
		return 1;
}
// convert string to int
int str2numa(char arr[],int length){
	// require checkan,power function
	int i,j,output=0;
	if (checkan(arr,length) != 1) {printf("Can't convert to int !\n");return -1;}
	else {
		length--;j=0;
		for (i = length; i >= 1; --i) {output+=(int)(arr[j]-'0')*power(10,i-1);j++;}
			return output;
}}
// power x^n
int power(int x,int n){
	int output=1;
	int i;
	if (n == 0) return 1;
	for (i = 0; i < n; ++i) output*=x;
	return output;
}
// Menu 
int GetMenu(char *a,int o) {
	/**
	 * Require checkan ,str2numa ,countma,countcs,repchar  function\
	 * o is number of option 
	 * option device by  character'|'
	 */
	int id1,j,id,id2,flag=0;
	id1=j=id=0;
	char matrix[o][maxoption];
	int c,i,option = INVALID;
	char input[maxoption];
	 while(a[id] != '\0') { 
		if(a[id] != ';' ){matrix[id1][j] = a[id];j++;id++;}
		else {matrix[id1][j] = '\0';j=0;id1++;id++;}  
		  } 
	 matrix[id1][j] = '\0';
	do {i=0;if(o<=5||  ((countma(matrix,o)+7)*2+2+tabs) > 80) 
		{printf("\n\t.");repchar(((countma(matrix,o)+4)/2),'=');printf(" Menu ");repchar(((countma(matrix,o)+4)/2-1),'=');printf(".\n");
			
				for(id2 = 0 ; id2 < o;id2++)printf("\t||%3d. %-*s||\n",id2+1,countma(matrix,o)+1,matrix[id2]);
				
				printf("\t||  0. %-*s||\n",(countma(matrix,o)+1),"Exit");
				printf("\t.");repchar(((countma(matrix,o)+7)*2)/2+1,'=');printf(".\n"); printf("\t\tYour choice:   ");}					
		else
		{printf("\n\t.");repchar(countma(matrix,o)+4,'=');printf(" Menu ");repchar((countma(matrix,o)+4),'=');printf(".\n");
				for(id2 = 0 ; id2 < o;id2++){if(flag == 0){printf("\t||%3d. %-*s",id2+1,countma(matrix,o)+1,matrix[id2]);flag++;}
				 else {printf("%3d. %-*s||\n",id2+1,countma(matrix,o)+1,matrix[id2]);flag=0;}}
				if(o%2 == 0)printf("\t||  0. %-*s||\n",(countma(matrix,o)+1)*2+5,"Exit"); else printf("  0. %-*s||\n",(countma(matrix,o)+1),"Exit");
				printf("\t.");repchar((countma(matrix,o)+7)*2,'=');printf(".\n"); printf("\t\tYour choice:   ");}
		while((c=getchar())!= '\n') { input[i] = c; i++;} input[i]='\0';i++;
		if(checkan(input,i)) option = str2numa(input,i);
		if (option >= 0 && option <= o && checkan(input,i) == 1 && i != 1) printf("\n\tSelected option number %d\n",option);
		else {
			printf("\tInvalid option. Please retry!\n");
			option = INVALID;
		}
	} while (option == INVALID);
 return option;
}
