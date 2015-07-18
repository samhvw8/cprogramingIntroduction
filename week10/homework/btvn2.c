////////////////////////////////
// Hoang van Sam -ICT58 -HUST //
////////////////////////////////

#include <stdio.h>
// #define BOLDRED     "\033[1;31m"				// highlight on
// #define BLUE    "\x1b[34m"					// highlight on
// #define RESET   "\x1b[0m"					// highlight on
// #define BLACK   "\033[30m"					// highlight on
// #define BOLDBLUE    "\033[1m\033[34m"		// highlight on
// #define BOLDBLACK   "\033[1m\033[30m"		// highlight on
// #define BBLUE "\x1b[44m"						// highlight on

int a,e,u,i,y,o; 
int check(int z);
void counter(int z);
int main () {
	int c;
		a = e = u = i = y = o = 0;
		printf("Input :\n");
	while ( (c = getchar()) != EOF) 
	{
		counter(c);
		if (check(c)) putchar(c - 'a' + 'A'); else putchar(c);  // highlight  off
		// if (check(c)) printf(BLUE"%c"RESET ,c - 'a' + 'A');else putchar(c); // highlight on
	}
	printf("number of character \"a\" = %d\nnumber of character \"e\" = %d\nnumber of character \"u\" = %d\nnumber of character \"i\" = %d\nnumber of character \"y\" = %d\nnumber of character \"o\" = %d\n",a,e,u,i,y,o );
}
void counter(int z){
	if(z == 'a') a++;if(z == 'e') e++;if(z == 'u') u++;if(z == 'i') i++;
	if(z == 'y') y++;if(z == 'o') o++;
}

int check(int z){
	if(z == 'a' || z == 'A') return 1 ;else if(z == 'e'|| z == 'E') return 1 ;else if(z == 'u'|| z == 'U') return 1 ;else if(z == 'i'|| z == 'I') return 1 ; 
else if(z == 'y'|| z == 'Y') return 1 ;else if(z == 'o'|| z == 'O') return 1 ; else return 0;
}