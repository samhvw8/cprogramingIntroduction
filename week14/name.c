#include <stdio.h>
#include <string.h>

void inputname(char *input);
void convertname(char *str);
int main(){
	char a[100];
	inputname(a);
	convertname(a);
	printf("\"%s\"\n",a);
	return 0;
}
void inputname(char *input){
	printf("Input Your Name : ");
	scanf(" %[^\n]",input);
}
void convertname(char *str){
	char s[strlen(str)+1];
	int i,z=0,f=1;
	while(str[z] == ' ')z++;
	for(i = z, z= 0 ; i<strlen(str) ;i++){
	    if(str[i]!=' '&& f == 1 && str[i] <= 'z' && str[i] >= 'a'){s[z] = str[i] - 'a' + 'A';f=0;z++;i++;}
	    if(str[i]!=' '&& f == 1 && str[i] <= 'Z' && str[i] >= 'A'){s[z] = str[i];f=0;z++;i++;}
	    if(str[i]!=' '){s[z] = str[i];z++;}
	    if(str[i]==' ' && f == 0) {s[z] = str[i];f = 1;z++;}
	    if(f == 1) while(str[i]== ' ' && str[i+1]== ' ') i++;
	}
	if(s[z-1]== ' ') z--;
	for (i = 0; i < z; ++i)str[i] = s[i];
	str[i] = '\0';
}