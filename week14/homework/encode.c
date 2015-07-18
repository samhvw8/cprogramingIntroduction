#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdlib.h>
#include "Ginz.h"
#define INVALID -1
#define maxoption 100
#define tabs 8
// ==========================================================================================================
int count2da(char arr[][maxoption],int num);
void repchar(int times,char c);//print character  c with (times) 
int checkan(char arr[],int length); // check array number (int)
int GetMenu(const char *a,int o,int EXIT);
// ==========================================================================================================
void input(char *input);
void encode(char *input,int k);
void decode(char *input,int k);
int main () {
	int shift,c=0;
	char s[100];
	for(;;){switch(GetMenu("Input Content;Input Shift value;Encode;Decode;Print Encoded",5,1)){
		case 1 :c=1;input(s);while(getchar() != '\n');break;
		case 2 :if(c!=0){c =2;printf("\t%s : ","Input Shift value");scanf("%d",&shift);while(getchar() != '\n');}else printf("\t%s\n","Input Content First !");break;
    case 3 :if(c==2)encode(s,shift);else printf("%s\n","Need Shift value !"); break;
    case 4 :if(c==2)decode(s,shift);else printf("%s\n","Need Shift value !");break;
    case 5 :if(c!=0)printf("\tContent :\"%s\"\n",s);else printf("\t%s\n","Input Content First !");break;
		case 0 :return 0;
		}
	}
}
// shift right k value of each character in string 
void encode(char *input,int k){
	while(*input != '\0') {
		if(*input != ' ') {
			if((*input + k <= 'z' && *input  +k  >= 'a') ||(*input +k  <= 'Z' && *input  +k  >= 'A' || (*input +k <= '9' && *input  + k >= '0'))) *input+=k;
			else if(*input + k > 'z') *input = 'a' + k - ('z' -*input )-1;
			else if(*input + k > '9') *input = '0' + k - ('9' -*input )-1;
			else *input = 'A' + k - ('Z' -*input )-1;
			input++;
		}
		else input++;
	}
}
// shift left k value of each character in string 
void decode(char *input,int k){
  while(*input != '\0') {
    if(*input != ' ') {
      if((*input - k <= 'z' && *input  - k  >= 'a') ||(*input -k  <= 'Z' && *input  -k  >= 'A' || (*input -k <= '9' && *input  + k >= '0'))) *input-=k;
      else if(*input - k < 'a') *input = 'z' - k + (*input - 'a' )-1;
      else if(*input - k < '0') *input = '9' - k + (*input - '0')-1;
      else *input = 'z' - k + (*input - 'A'  )-1;
      input++;
    }
    else input++;
  }
}
// Input string
void input(char *input){
	printf("\t%s","Input : ");
	scanf(" %[^\n]",input);
}