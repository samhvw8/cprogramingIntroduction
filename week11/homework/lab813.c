#include <stdio.h>
#define INVALID -1
#define com 40
#define ON 1
#define OFF 0
//======================================================== FUNCTION =============================================================================
int getMenu(); 					//menu
//===========================================================================================
int checkc(int no, int carr[]); 	// check status (on) of computer
//===========================================================================================
int ssc(int no, int stt, int carr[], int tcarr[]);	// change status of computer
void onc(int no, int carr[]);  	// set computer on
void ofc(int no, int carr[]); 	// set computer off
//=========================== TIME ==========================================================
void stc(int no, int tcarr[]);	// set time of computer
//=========================== USED ==========================================================
int max(int tcarr[]); // find computer most used
int min(int tcarr[]); // find computer less used
//=========================== PRINNT STATUS  ================================================
void pts(int status, int watt, int pay, int rank, int carr[], int tcarr[]);

//======================================================= MAIN ==================================================================================
int main () {
	int scom[com], tcom[com]; // scom status computer ; tcom time computer
	int i, c, k;
	//create status computer & time computer table
	for (i = 0 ; i < com; i++) {scom[i] = tcom[i] = 0;}
	for (;;)
	{	switch (getMenu()) {
		case 1: while ((k = getchar()) != '\n');
			do
			{printf("\nWhat computer you want to use : "); scanf("%d", &c); if (k = ssc(c, ON, scom, tcom))printf("Successful registration ! Ready To use\n");}
			while (k != 1); break;
		case 2: printf("What computer you have been used : "); scanf("%d", &c); if (ssc(c, OFF, scom, tcom))printf("Successful turn off !\n"); break;
		case 3: printf("Status Of computer \n"); pts(ON, OFF, OFF, OFF, scom, tcom); break;
		case 4: printf("Watt Of ecomputer \n"); pts(OFF, ON, OFF, OFF, scom, tcom); break;
		case 5: printf("Watt & payment Of computer \n"); pts(OFF, ON, ON, OFF, scom, tcom); break;
		case 6: printf("MAX & MIN Of computer \n"); pts(OFF, ON, OFF, ON, scom, tcom); break;
		case 7: printf("All detail computer \n"); pts(ON, ON, ON, ON, scom, tcom); break;
		case 0: return 0;
		}
	}
	// pts(ON,ON,ON,ON,scom,tcom);
}
//===============================================================================================================================================
int getMenu() {
	char option = INVALID;
	do {
		printf("\n\t .================ MENU ================. \n");
		printf("\t**  1. Use Computer                     **\n");
		printf("\t**  2. Leave computer                   **\n");
		printf("\t**  3. Print Status                     **\n");
		printf("\t**  4. Print watt                       **\n");
		printf("\t**  5. Print watt and payment           **\n");
		printf("\t**  6. Print max and min used computer  **\n");
		printf("\t**  7. All Detail                       **\n");
		printf("\t**  0. Exit                             **\n");
		printf("\t*._____Your choie:  ____________________.*\r\t|_____Your choie: ");
		scanf(" %c", &option);
		if (option > '0' - 1 && option < '8') printf("\tSelected option number %c\n", option);
		else {
			printf("\tInvalid option. Please retry!\n");
			option = INVALID;
		}
	} while (option == INVALID);
	option -= '0';
	return (int)option;
}


//=========================================================================================
// check status (on) of computer

int checkc(int no, int carr[]) {
	if (carr[no - 1] == ON) return 1; else return 0;
}
//=========================================================================================
// change status of computer
int ssc(int no, int stt, int carr[], int tcarr[]) {
	int h, m;
	if (stt == ON) {if (checkc(no, carr)) {printf("Computer No.%d is being used\nRegistration failed - Please Choice another computer !\n", no); return 0;} else {onc(no, carr); return 1;}}
	if (stt == OFF) {if (checkc(no, carr)) {ofc(no, carr); stc(no, tcarr); return 1;} else {printf("Computer No.%d is turned off !!\n", no); return 1;}}
}
//=========================================================================================
// set computer on
void onc(int no, int carr[]) {
	carr[no - 1] = ON;
}
// set computer off
void ofc(int no, int carr[]) {
	carr[no - 1] = OFF;
}
//=========================================================================================
// set time of computer
void stc(int no, int tcarr[]) {
	tcarr[no - 1] = tcarr[no - 1] + 1;
}

//=========================================================================================

// find computer most used
int max(int tcarr[]) {
	int max, i;
	max = tcarr[0];
	for (i = 1; i < com; i++) if (tcarr[i] >= max) max = tcarr[i];
	return max;
}

// find computer less used
int min(int tcarr[]) {
	int min, i;
	min = tcarr[0];
	for (i = 1; i < com; i++) if (tcarr[i] <= min) min = tcarr[i];
	return min;
}
//=========================================================================================
void pts(int status, int watt, int pay, int rank, int carr[], int tcarr[]) {
	int i, j, z, z1, z2, z3, z4, z5;
	z = z1 = z2 = z3 = z4 = z5 = 0;
	for (j = 0; j < 4; j++) {
		for (i = 0; i < 10; i++)printf(".=========."); printf("\n");
		for (i = 0; i < 10; i++)printf("|         |"); printf("\n");
		for (i = 0; i < 10; i++) {printf("|  NO.%02d  |", z + 1); z++;} printf("\n");
		if (status == ON) {for (i = 0; i < 10; i++) {if (carr[z2] == ON)printf("|    ON   |"); else printf("|    OFF  |"); z2++;} printf("\n");}
		if (watt == ON) {for (i = 0; i < 10; i++) {printf("|  %6dW|", tcarr[z3] * 400); z3++;} printf("\n");}
		if (pay == ON) {for (i = 0; i < 10; i++) {printf("|%8dD|", tcarr[z4] * 400 * 750); z4++;} printf("\n");}
		if (rank == ON) {
			for (i = 0; i < 10; i++) {
				if (tcarr[z5] == max(tcarr)) {printf("|   MAX   |"); z5++;}
				else if (tcarr[z5] == min(tcarr)) {printf("|   MIN   |"); z5++;}
				else {printf("|         |"); z5++;}
			} printf("\n");
		}
		for (i = 0; i < 10; i++)printf("|         |"); printf("\n");
		for (i = 0; i < 10; i++)printf(".=========."); printf("\n");
	}
}