/**
 * Upgrade Dice exersice 
 * caculate Standard deviation 
 *
 * Author : Hoang Van Sam
 * CLass : ICT 58
 */

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define INVALID -1
#define maxoption 100
#define MPoint 11
#define tabs 8

double msqrt(double x,double e);
double sd(int arr[],int c);// Standard deviation 
void rolldice(int c,int arr[]); // roll dice
void createa(int arr[],int len);
double ap(int arr[],int c);
// ==================================================
int countma(char arr[][maxoption],int num);
int countcs(char arr[]);
void repchar(int times,char c);//print character  c with (times) 
int power(int x,int n); // power x^n
int str2numa(char arr[],int length); // convert string to number
int checkan(char arr[],int length); // check array number (int)
int GetMenu(char *a,int o);
// ==========================================================
int main () {
	int logp[MPoint],t;
	int i,k;
	for(;;){
		switch(GetMenu((char *)"Dice;Average score;Standard deviation",3))
		{
			case 1:	
			createa(logp,MPoint);
			printf("\n\tHow many time you want to roll : ");scanf("%d",&t);srand(time(NULL));//seed
			rolldice(t,logp);while((k=getchar())!= '\n');
			break; 
			case 2:printf("\n\t Average score : %lf\n",ap(logp,t));break;
			case 3:printf("\n\t Standard deviation  : %lf\n",sd(logp,t));break;
			case 0:return 0;
		}
	}
}
// create array
void createa(int arr[],int len){
	int i;
for (i = 0; i < len; ++i) arr[i] = 0;}


void rolldice(int c,int arr[]) {
	int pd1,pd2,i;
	if (c == 0) for (i = 0;i < MPoint;++i) printf("\tPoint %-2d : %d\n",i+2,arr[i]);
	if (c != 0)
	{
		pd1 = rand()%6+1;
		pd2 = rand()%6+1;
		++arr[pd1+pd2-2];
		c--;
		rolldice(c,arr);
	}
}
// Standard deviation 
double sd(int arr[],int times){
	double output = 0;
	double tbp = 0; // tong diem binh phuong 
	double t  = 0;// tong diem
	int i;
	for (i = 0; i < MPoint; ++i)
	{
		tbp += (i+1)*(i+1)*arr[i];
		t += arr[i]*(i+1);
	}
	output += (tbp - t*t/times)/(times-1);
	output = msqrt(output,0.000001);
	return output;
}
// ap
double ap(int arr[],int times){
	int i;double output=0;
	for (i = 0; i < MPoint; ++i) output+= arr[i]*(i+2);
		return output/times;
}
double msqrt(double x,double e) {
  	double a,b;
	a = x;b = (a + x/a)/2;
		do {
			a = b;
			b = (a + x/a)/2;
			}
		while((a-b)>e);
return b;
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
	}	
}
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