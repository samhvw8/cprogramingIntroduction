#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdlib.h>
#define INVALID -1
#define maxoption 100
#define tabs 8

// ================================================
//print character  c with (times) 
void repchar(int times,char c){
	int i;
	for(i = 0; i < times; ++i) printf("%c",c);
}

// max lengthgth in 2 demention string
int count2da(char arr[][maxoption],int num){
	int i,m; m = 0;
	for (i = 0; i < num; ++i) if(m < strlen(arr[i]))m = strlen(arr[i]);
		return m;
}
// check string is all number or not
int checkan(char arr[],int length){
	length--;
	int i;
	for (i = 0 ; i < length ; i++) if(arr[i] < '0' || arr[i] > '9') return 0;
		return 1;
}
// Menu 
int GetMenu(const char *a,int o,int EXIT){
    /**
     * Require checkan ,count2da,repchar  function
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
    do {i=0;if(o<=5||  ((count2da(matrix,o)+7)*2+2+tabs) > 80)
        {     if(count2da(matrix,o)%2!=0) {printf("\n\t.");repchar(((count2da(matrix,o)+4)/2),'=');printf(" Menu ");repchar(((count2da(matrix,o)+4)/2-1),'=');printf(".\n");}
        else {printf("\n\t.");repchar(((count2da(matrix,o)+4)/2-1),'=');printf(" Menu ");repchar(((count2da(matrix,o)+4)/2-1),'=');printf(".\n");}
                for(id2 = 0 ; id2 < o;id2++)printf("\t||%3d. %-*s||\n",id2+1,count2da(matrix,o)+1,matrix[id2]);

                if(EXIT == 1)printf("\t||  0. %-*s||\n",(count2da(matrix,o)+1),"Exit");
                printf("\t.");repchar(((count2da(matrix,o)+7)*2)/2+1,'=');printf(".\n"); printf("\t\tYour choice:   ");}
        else
        {
            printf("\n\t.");repchar(count2da(matrix,o)+4,'=');printf(" Menu ");repchar(count2da(matrix,o)+4,'=');printf(".\n");
                for(id2 = 0 ; id2 < o;id2++){if(flag == 0){printf("\t||%3d. %-*s",id2+1,count2da(matrix,o)+1,matrix[id2]);flag++;}
                 else {printf("%3d. %-*s||\n",id2+1,count2da(matrix,o)+1,matrix[id2]);flag=0;}}
                if(EXIT == 1) if(o%2 == 0)printf("\t||  0. %-*s||\n",(count2da(matrix,o)+1)*2+5,"Exit"); else printf("  0. %-*s||\n",(count2da(matrix,o)+1),"Exit");
                printf("\t.");repchar((count2da(matrix,o)+7)*2,'=');printf(".\n"); printf("\t\tYour choice:   ");}
        while((c=getchar())!= '\n') { input[i] = c; i++;} input[i]='\0';i++;
        if(checkan(input,i)) option = atoi(input);
        if (option >= 0 && option <= o && checkan(input,i) == 1 && i != 1) printf("\n\tSelected option number %d\n",option);
        else {
            printf("\tInvalid option. Please retry!\n");
            option = INVALID;
        }
    } while (option == INVALID);
 return option;
}
// my fflush
void mfflush() {
	int ch;
	while((ch = getchar()) && ch != '\n' && ch != EOF);
}
// swap interger
void swap(int *a , int *b){
	int temp;
	temp  = *a;
	*a  = *b;
	*b = temp;
}
// sort interger array
void intersort(int arr[],int n){
  int i,j;
  for(i = 1 ; i < n ; i++){ j = i ;
    while( ( j > 0)&& arr[j]<arr[j-1] ){
      swap(&arr[j],&arr[j-1]);
      j--;
    }  
  }
}