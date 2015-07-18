///////////////////////////
// Hoang van sam - ICT58 //
///////////////////////////


#include <stdio.h>


int main () {
	   // dung 5 nam 3  3*gia 1
	int i,j,z;     // i trau dung ; j trau nam  ; z trau gia 
	printf("%s\n\n","trau dung an 5 bo co,trau nam an 3 bo co, 3 trau gia an 1 bo co" );printf("----------------------------------------------------------------------------\n");
		for (i = 0; i < 20; ++i)for (j = 0; j < 33; ++j){
				z = 100 - i - j ;
				if(z%3 == 0) if (z/3+i*5+j*3 == 100) {printf("|%-27s= %-3d%-13s= %-3d%-13s= %-9d|\n","so trau trau dung ",i," trau nam ",j," trau gia",z );
				printf("|%-29s%-3d%-15s%-3d%-15s%-9d|\n","so bo co trau trau dung an = ",i*5," trau nam an = ",j*3," trau gia an =",z/3 );
				printf("----------------------------------------------------------------------------\n");
				 break;}
			}
		printf("\n");
		
	return 0;
}