/** 
 * MATRIX. 
 * * require
 * Input square matrix 
 * // + matrix
 * // - matrix
 * // x matrix
 * // transpose matrix
 *
 * * addition
 * 	detmatrix 
 * 	transpose complement of matrix 
 * 	invert matrix 
 *  rank square matrix
 * 
 * Author : Hoang Van Sam 
 * Class : ICT58 - HUST 
 */
#include <stdio.h>
#define max 50
#define INVALID -1
#define maxoption 100
#define tabs 4
// ==========================================================================================================
int checkloc(int i,int j,int r1,int c1);// check location 
void definematrix(int matrix[][max],int matrix2[][max],int length); // input 2 matrix
void inputmatrix(int matrix[][max],int length); // input 1 matrix
void plus(int matrix[][max],int matrix2[][max],int asmatrix[][max],int length); // +
void subtract(int matrix[][max],int matrix2[][max],int asmatrix[][max],int length); // -
void multiplication(int matrix[][max],int matrix2[][max],int asmatrix[][max],int length); // multiplication
int multielement(int matrix[][max],int matrix2[][max],int length,int i,int j); // multiplication element
void transpose(int matrix[][max],int asmatrix[][max],int length); //transpose
void printmatrix(int matrix[][max],int length); //print 1 matrix
void print2matrix(int matrix[][max],int matrix2[][max],int length); //print 2 matrix
int countdigit(int num); // count digit
// =====================================================================
int detmatrix(int matrix[][max],int length);  // detmatrix of matrix
int detseparate(int matrix[][max],int length,int i,int j);// detmatrix of m matrix 
void separete(int matrix[][max],int asmatrix[][max],int length,int i,int j);// split matrix
int maxdigitarray(int matrix[][max],int length); // max digit in array
// void invertm(int matrix[][max],int asmatrix[][max],int length);// invert matrix for float
void compmatrixtrans(int matrix[][max],int asmatrix[][max],int length);// transpose complement of matrix 
void printinvert(int asmatrix[][max],int smatrix[][max],int length); // print invert from transpose complement of matrix 
int cena(int num);// center of heigh array
int ceven(int num);// check even
int rankm(int matrix[][max],int length); // rank square matrix
// ==========================================================================================================
int countma(char arr[][maxoption],int num);
int countcs(char arr[]);
void repchar(int times,char c);//print character  c with (times) 
int power(int x,int n); // power x^n
int str2numa(char arr[],int length); // convert string to number
int checkan(char arr[],int length); // check array number (int)
int GetMenu(char *a,int o);
// ==========================================================================================================
int main () {
	int a[max][max],b[max][max],asmatrix[max][max];
	int k,n,c,z=0;
	 	switch(
	 	GetMenu((char *)"Input length square of Matrix , Maxtrix A,B;Plus 2 Maxtrix;Subtract 2 Matrix ;Multiplile 2 Matrix;Transpose Matrix;Addition feature for matrix",6)
	 	// GetMenu((char *)"Input length square of Matrix , Maxtrix A,B;Plus 2 Maxtrix  A+B;Subtract A-B;Multiplile A*B;Transpose Matrix",5)
	 	)
	 	{	case 1:z=1;do{printf("\tSize of matrix A & B (nxn) n : ");scanf("%d",&n); if(n>max) printf("\n\tPlease Input length < %d !\n",max);}while(n>max);definematrix(a,b,n);break;
	 		case 2:if(z==0){printf("\tPlease input matrix first\n");;break;}else{plus(a,b,asmatrix,n);print2matrix(a,b,n);printf("\tThe matrix After A+B or B+A is :\n"); printmatrix(asmatrix,n);}break;
	 		case 3:if(z==0){printf("\tPlease input matrix first\n");;break;}else{for(;;){c = GetMenu((char *)"A-B;B-A;Return to main menu",3);
	 			if(c == 0 )return 0;
	 			if(c == 1 ){subtract(a,b,asmatrix,n);print2matrix(a,b,n);printf("\tThe matrix After A-B is :\n"); printmatrix(asmatrix,n);}
	 			if(c == 2 ){subtract(b,a,asmatrix,n);print2matrix(b,a,n);printf("\tThe matrix After B-A is :\n"); printmatrix(asmatrix,n);}
	 			if(c == 3 )break;}}break;
	 		case 4:if(z==0){printf("\tPlease input matrix first\n");break;}else{for(;;){ c = GetMenu((char *)"A*B;B*A;Return to main menu",3);
	 			if(c == 0)	return 0;
	 			if(c == 1)	{multiplication(a,b,asmatrix,n);print2matrix(a,b,n);printf("\tThe matrix After A*B is :\n"); printmatrix(asmatrix,n);}
	 			if(c == 2)	{multiplication(b,a,asmatrix,n);print2matrix(b,a,n);printf("\tThe matrix After B*A is :\n"); printmatrix(asmatrix,n);}
	 			if(c == 3)	break;}}break;
	 		case 5:if(z==0){printf("\tPlease input matrix first\n");break;}else{
	 					for(;;){
	 					c = GetMenu((char *)"Transpose matrix A;Transpose matrix B;Return to main menu",3);
	 					if(c == 0) return 0;
	 					if(c == 1){transpose(a,asmatrix,n);printf("\tMatrix A (left) transpose of A (right) \n");print2matrix(a,asmatrix,n);}
	 		   			if(c == 2){transpose(b,asmatrix,n);printf("\tMatrix B (left) transpose of B (right) \n");print2matrix(b,asmatrix,n);}
	 					if(c == 3) break;
	 					
	 					}}break;
	 		case 6:if(z==0){printf("\tPlease input matrix first\n");break;}else{

	 			for(;;){c = GetMenu((char *)"Determinant A;Determinant B;Invert matrix A;Invert matrix B;Rank matrix A;Rank matrix B;Return to main menu",7);
	 					if(c == 0) return 0;
	 					if(c == 1) {printf("\n\tMatrix A :\n");printmatrix(a,n);printf("\n\tDeterminant Of A is %d\n",detmatrix(a,n));}
	 					if(c == 2) {printf("\n\tMatrix B :\n");printmatrix(b,n);printf("\n\tDeterminant Of B is %d\n",detmatrix(b,n));}
	 					if(c == 3){printf("\n\tMatrix A :\n");printmatrix(a,n);compmatrixtrans(a,asmatrix,n);if(detmatrix(a,n)!= 0){printf("\n\tInvert of A is \n");printinvert(asmatrix,a,n);}}
	 					if(c == 4){printf("\n\tMatrix B :\n");printmatrix(b,n);compmatrixtrans(b,asmatrix,n);if(detmatrix(b,n)!= 0){printf("\n\tInvert of B is \n");printinvert(asmatrix,b,n);}}
	 					if(c == 5){printf("\n\tMatrix A :\n");printmatrix(a,n);printf("\n\tRank Of A is %d\n",rankm(a,n));}
	 					if(c == 6) {printf("\n\tMatrix B :\n");printmatrix(b,n);printf("\n\tRank Of B is %d\n",rankm(b,n));}
	 					if(c == 7) break;
	 		}}break;	
	 		case 0:return 0;
	 }}}
	 	
// ==========================================================================================================
// =======================================================================
// print matrix
void printmatrix(int matrix[][max],int length){
	// require countdigit maxdigitarray power  function
	int i,j; // i index row , j index col
	int k;
	i = j = 0;
	printf("\n");
	if(length == 1) printf("[%d]\n",matrix[i][j]);
	if(length != 1 )while(i < length) {
		if(j == 0)printf("\t[");printf("%*d|",maxdigitarray(matrix,length),matrix[i][j]);j++;
		if(j == length-1) {printf("%*d]\n",maxdigitarray(matrix,length),matrix[i][j]);i++;j= 0;}
	}
}
// print 2 matrix
void print2matrix(int matrix[][max],int matrix2[][max],int length){
	// require countdigit maxdigitarray power repchar function
	int i,j,i1,j1; // i index row , j index col
	int k;
	i = j =i1 =j1 = 0;
	printf("\n");

	if(length == 1) printf("[%d]\t\t[%d]\n",matrix[i][j],matrix2[i][j]);

	if(length != 1 )while(i1 < length) {
		while(j < length-1){
			if(j == 0)printf("\t[");
			printf("%*d|",maxdigitarray(matrix,length),matrix[i][j]);
			j++;
		}
		if(j == length-1) {
			printf("%*d]",maxdigitarray(matrix,length),matrix[i][j]);
			i++;
			j= 0;
		}
	
		while(j1 < length-1){
			if(j1 == 0)printf("\t\t[");
			printf("%*d|",maxdigitarray(matrix2,length),matrix2[i1][j1]);
			j1++;
		}
		if(j1 == length-1) {
			printf("%*d]\n",maxdigitarray(matrix2,length),matrix2[i1][j1]);
			i1++;
			j1= 0;
		}
	}
	printf("\n");
}
// Transpose matrix
void transpose(int matrix[][max],int asmatrix[][max],int length){
	int i,j; // i index row , j index col
	i = j = 0;
	if(length == 1)asmatrix[i][j] = matrix[j][i];
	if(length != 1)while(i < length) {
		asmatrix[i][j] = matrix[j][i];j++;
		if(j == length-1) {asmatrix[i][j] = matrix[j][i];i++;j= 0;}
	}
}
// Define matrix
void definematrix(int matrix[][max],int matrix2[][max],int length){
	printf("\n\tInput first Matrix  : \n");inputmatrix(matrix,length);
	printf("\n\tInput second Matrix  : \n");inputmatrix(matrix2,length);
}
// input varible to matrix
void inputmatrix(int matrix[][max],int length){
	int i,j; // i index row , j index col
	int k;
	i = j = 0;
	if (length == 1) {printf("\tInput (%d,%d) :",i+1,j+1);scanf("%d",&matrix[i][j]);}
	if(length > 1) while(i < length) {
		printf("\tInput row %d :",i+1);while(j < length-1) {scanf("%d",&matrix[i][j]);j++;}
		if(j == length-1) {scanf("%d",&matrix[i][j]);i++;j= 0;}while((k= getchar())!='\n');
	}
}
// + matrix
void plus(int matrix[][max],int matrix2[][max],int asmatrix[][max],int length){
	int i,j; // i index row , j index col
	i = j = 0;
	if(length == 1)asmatrix[i][j] = matrix[i][j]+matrix2[i][j];
	if(length != 1)while(i < length) {
		asmatrix[i][j] = matrix[i][j]+matrix2[i][j];j++;
		if(j == length-1) {asmatrix[i][j] = matrix[i][j]+matrix2[i][j];i++;j= 0;}
	}
}
// - matrix
void subtract(int matrix[][max],int matrix2[][max],int asmatrix[][max],int length){
	int i,j; // i index row , j index col
	i = j = 0;
	if(length == 1)asmatrix[i][j] = matrix[i][j]-matrix2[i][j];
	if(length != 1)while(i < length) {
		asmatrix[i][j] = matrix[i][j]-matrix2[i][j];j++;
		if(j == length-1) {asmatrix[i][j] = matrix[i][j]-matrix2[i][j];i++;j= 0;}
	}
}
// x matrix
void multiplication(int matrix[][max],int matrix2[][max],int asmatrix[][max],int length){
	int i,j; // i index row , j index col
	i = j = 0;
	if(length == 1)multielement(matrix,matrix2,length,i,j);
	if(length != 1)while(i < length) {
		asmatrix[i][j] = multielement(matrix,matrix2,length,i,j);j++;
		if(j == length-1) {asmatrix[i][j] = multielement(matrix,matrix2,length,i,j);i++;j= 0;}
	}
}
// x element matrix
int multielement(int matrix[][max],int matrix2[][max],int length,int i,int j){
	int z,a;
	a = 0;
	if(length == 1)a += matrix[i][0]*matrix2[0][j];
	if(length != 1)for (z = 0; z < length; z++) {
	 a += matrix[i][z]*matrix2[z][j];
	}
return a;
}
// detmatrix of matrix
int detmatrix(int matrix[][max],int length){
	int id;// index
	int o=0;
	if(length == 1) return matrix[0][0];
	else if(length  == 2) return matrix[0][0]*matrix[1][1]-matrix[1][0]*matrix[0][1];
	else for (id = 1; id <= length; ++id) o+=matrix[0][id-1]*power(-1,1+id)*detseparate(matrix,length,0,id-1);
	return o;
}
// detmatrix of m matrix 
int detseparate(int matrix[][max],int length,int i,int j){
	int matrix2[max][max];
	int id; // index 
	int l,output=0;
	l = length-1;
	separete(matrix,matrix2,length,i,j);
	if(l == 1) return matrix2[0][0];
	else if(l == 2) return matrix2[0][0]*matrix2[1][1]-matrix2[1][0]*matrix2[0][1];
	else for (id = 1; id <= l; ++id){ output+= matrix2[0][id-1]*power(-1,1+id)*detseparate(matrix2,l,0,id-1);}
	return output;
}
// invert matrix for float type of output array
// void invertm(int matrix[][max],int asmatrix[][max],int length){
// 			/**
// 			 * require detmatrix function 
// 			 * power function 
// 			 * detseparate function 
// 			 */
// 	int i,j; // i index row , j index col
// 	int matrix2[max][max];
// 	i = j = 0;
// 	if(detmatrix(matrix,length) == 0) printf("Haven't invert !!\n"); else {
// 		if(length == 1)asmatrix[i][j] = matrix[i][j];
// 		if(length != 1)while(i < length) {
// 			asmatrix[i][j] = power(-1,i+j+2)*detseparate(matrix,length,i,j);j++;
// 			if(j == length-1) {asmatrix[i][j] = power(-1,i+j+2)*detseparate(matrix,length,i,j);i++;j= 0;}
// 		}
// 		i=j=0;
// 		transpose(asmatrix,matrix2,length);
// 		if(length == 1)asmatrix[i][j] = matrix2[i][j]/detmatrix(matrix,length);
// 		if(length != 1)while(i < length) {
// 			asmatrix[i][j] = matrix2[i][j]/detmatrix(matrix,length);j++;
// 			if(j == length-1) {matrix2[i][j]/detmatrix(matrix,length);i++;j= 0;}
// 		}}
// }
// find transpose Complement of matrix 
void compmatrixtrans(int matrix[][max],int asmatrix[][max],int length){
			/**
			 * require detmatrix function 
			 * power function 
			 * detseparate function 
			 */
	int i,j; // i index row , j index col
	int matrix2[max][max];
	i = j = 0;
	if(detmatrix(matrix,length) == 0) printf("Haven't invert !!\n"); else {
		if(length == 1)matrix2[i][j] = matrix[i][j];
		if(length != 1)while(i < length) {
			matrix2[i][j] = power(-1,i+j+2)*detseparate(matrix,length,i,j);j++;
			if(j == length-1) {matrix2[i][j] = power(-1,i+j+2)*detseparate(matrix,length,i,j);i++;j= 0;}
		}
		i=j=0;
		transpose(matrix2,asmatrix,length);
	}
}
 // print invert from transpose complement of matrix
void printinvert(int asmatrix[][max],int smatrix[][max],int length) {
	// require countdigit maxdigitarray power  function
	int i,j; // i index row , j index col
	int k;
	i = j = 0;
	printf("\n");
	if(length == 1) {if(detmatrix(smatrix,length) != 1 && detmatrix(smatrix,length) != -1) printf("\t1/%d[%d]\n",detmatrix(smatrix,length),asmatrix[i][j]);
					else if(detmatrix(smatrix,length) != 1 ) printf("\t[%d]\n",asmatrix[i][j]); else  printf("\t-[%d]\n",asmatrix[i][j]);}

	if(length != 1 )while(i < length) {
		if(j == 0){
			if(i == cena(length)) {	if(detmatrix(smatrix,length) == 1) printf("\t [%*d|",maxdigitarray(asmatrix,length),asmatrix[i][j]);
									else if(detmatrix(smatrix,length) == -1) printf("\t-[%*d|",maxdigitarray(asmatrix,length),asmatrix[i][j]);
									else if(detmatrix(smatrix,length) > 0) printf("\t1/%d[%*d|",detmatrix(smatrix,length),maxdigitarray(asmatrix,length),asmatrix[i][j]);
									else if(detmatrix(smatrix,length) < 0) printf("\t-1/%d[%*d|",-detmatrix(smatrix,length),maxdigitarray(asmatrix,length),asmatrix[i][j]);
										j++;}
				else {printf("\t");
				if(detmatrix(smatrix,length) == 1 ||detmatrix(smatrix,length) == -1)repchar(countdigit(detmatrix(smatrix,length)),' ');
				else repchar(countdigit(detmatrix(smatrix,length))+2,' ');printf("[%*d|",maxdigitarray(asmatrix,length),asmatrix[i][j]);j++;}
		}
		if(j != 0 && j != (length-1)) {printf("%*d|",maxdigitarray(asmatrix,length),asmatrix[i][j]);j++;}
		if(j == (length-1)) {printf("%*d]\n",maxdigitarray(asmatrix,length),asmatrix[i][j]);i++;j= 0;}
	}
}
// check even number
int ceven(int num){
	if(num%2==0) return 1;
	return 0;
}
// center of heigh array
int cena(int num){
	if(ceven(num)) return num/2-1;
	else return num/2;
}
// split matrix
void separete(int matrix[][max],int asmatrix[][max],int length,int i,int j){
	int c1,r1,c2,r2;
	c1=r1=c2=r2=0;
	while (r2 <length-1){
		while(checkloc(i,j,r1,c1)!=0) {
			if(checkloc(i,j,r1,c1)==1) c1++;
			if(checkloc(i,j,r1,c1)==2) {c1++;r1++;}
			if(checkloc(i,j,r1,c1)==3) r1++;
		} if(r1 >= length) break;
		asmatrix[r2][c2] = matrix[r1][c1];c2++;c1++;
		while(checkloc(i,j,r1,c1)!=0) {
			if(checkloc(i,j,r1,c1)==1) c1++;
			if(checkloc(i,j,r1,c1)==2) {c1++;r1++;}
			if(checkloc(i,j,r1,c1)==3) r1++;
		} if(r1 >= length) break;
		if(c2 == length-1) {asmatrix[r2][c2] = matrix[r1][c1];c2=0;c1=0;r1++;r2++;}
	}
}
// check location for separete
int checkloc(int i,int j,int r1,int c1){
	if(r1 != i && c1 != j) return 0;
	if(r1 != i && c1 == j) return 1;
	if(r1 == i && c1 == j) return 2;
	if(r1 == i && c1 != j) return 3;
}
// digit in num
int countdigit(int num){
	int i=0;
	if (num == 0) return 1; else{ if(num < 0) {num = -num;i++;
			while(num!=0){num /=10;	i++;}
			return i;}
	else {	while(num!=0){num /=10;	i++;}
			return i;}
}}
// max digit in array
int maxdigitarray(int matrix[][max],int length){
	// require countdigit
	int m,i,j;
	i=j=0;m=countdigit(matrix[i][j]);
	while(i<length){
		if(m < countdigit(matrix[i][j])) m=countdigit(matrix[i][j]);j++;
		if(j == length-1) {if(m < countdigit(matrix[i][j])) m=countdigit(matrix[i][j]);j=0;i++;}
	}
	return m;
}
// rank of matrix for square matrix
int rankm(int matrix[][max],int length){
	int i,j;// index
	i=j=0; 
	int asmatrix[max][max];
	int rank = length;
	if(detmatrix(matrix,length) != 0) return rank;
		else {	rank--;
			while(i<length) {if(detseparate(matrix,length,i,j)!=0) return rank; else j++;
				if(j== length -1) {if(detseparate(matrix,length,i,j)!=0) return rank; else {j=0;i++;}}
			}i = j = 0;
			while(i<length-1) {separete(matrix,asmatrix,length,i,j); return rankm(asmatrix,length-1);  j++;
				if(j== length -1) {separete(matrix,asmatrix,length,i,j); return rankm(asmatrix,length-1); j=0;i++;}
			}
	}
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
