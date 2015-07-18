#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define WIN 1
#define LOSE 2
#define MAXMATCH 30
typedef struct {
	float str;
	float spd;
	float hp;
	int win;
	int lose;
	int draw;
} player;

void rewardCycle(player plr1, player plr2, player plr3);
void rewardMatch(player plr1, player plr2);
void rewardRan(player plr);
void reward(player plr, int result);
void createchar(player plr, int n);
int fight(player plr1, player plr2);
float ranfloat(int down, int up);
void reset(player plr);
void print(player plr);
void printstats(player plr1, player plr2, player plr3);
int getMenu();

int main(){
	player plr1,plr2,plr3;
	int times, check = 0, check1 = 0,i;
	srand(time(NULL));
	for (;;) {
		switch(getMenu()){
			case 1: check = 1;
			createchar(plr1,1);
			createchar(plr2,2);
			createchar(plr3,3);
			break;

			case 2: if (check != 0){
				check1 = 1;
				do {
					printf("\n\tHow many cycles do you want to match??\n");
					scanf("%d", &times);
					if ((times > MAXMATCH) || (times < 0)) printf("\tWrong input, please reinput!\n");
				} while ((times > MAXMATCH) || (times < 0));

				for (i = 0; i < times; i++) rewardCycle(plr1,plr2,plr3);
			} else printf("\tCreate character first!!");
			break;

			case 3:if (check != 0 && check1 != 0){
				printstats(plr1,plr2,plr3);
			} else if (check == 0) printf("\tCreate character first!!");
			else if (check1 == 0) printf("Fight first!!");
			break;

			case 4: reset(plr1);reset(plr2);reset(plr3);
			break;

			case 0: return 0;

		}
	}
}

void rewardCycle(player plr1, player plr2, player plr3){
	rewardMatch(plr1,plr2);
	rewardMatch(plr2,plr3);
	rewardMatch(plr1,plr3);
}
void rewardMatch(player plr1, player plr2){
	int randomplayer = rand()%2 + 1;
	int c = fight(plr1,plr2);
	if (c == 1){
		plr1.win++;
		plr2.lose++;
		reward(plr1,WIN);
		reward(plr2,LOSE);
	} else if (c == 2){
		plr1.lose++;
		plr2.win++;
		reward(plr1,LOSE);
		reward(plr2,WIN);
	} else if (c == 3);
	{
		plr1.draw++;
		plr2.draw++;
		reward(plr1,WIN);
		reward(plr2,WIN);
	}

	if (randomplayer == 1){
		rewardRan(plr1);
	} else if (randomplayer == 2){
		rewardRan(plr2);
	}
}

void rewardRan(player plr) {
	float percent = ranfloat(1,5);
	plr.str += plr.str*percent/100;
	plr.spd += plr.spd*percent/100;
	plr.hp += plr.hp*percent/100;
}
void createchar(player plr, int n){
	reset(plr);
	int choice, c = 0;
	do {
		printf("\tCreate character for player %d",n);
		plr.str = ranfloat(1,10);
		plr.spd = ranfloat(1,10);
		plr.hp = ranfloat(1,10);
		print(plr);
		do {
			printf("\n\tDo you want to create this character? 1:yes 0:no\n");
			scanf("%d", &choice);
			if ( choice != 1 && choice != 0){
				printf("\tWrong input, please retry");
				c = 1;
			} else if (choice == 0){
				printf("\tCreating another character...\n");
				c = 0;
			} else c = 2;
		} while ( c == 1);
	} while (c == 0);
}

int fight(player plr1, player plr2){
	if ((plr1.hp - plr2.str*plr2.spd) > (plr2.hp - plr1.str*plr1.spd)) return 1;
	else if ((plr1.hp - plr2.str*plr2.spd) < (plr2.hp - plr1.str*plr1.spd)) return 2;
	else return 3;
}
void reward(player plr, int result){
	if (result == WIN){
		plr.str += plr.str*2/100;
		plr.spd += plr.spd*2/100;
		plr.hp += plr.hp*2/100;
	} else if (result == LOSE) {
		plr.str += plr.str*1/100;
		plr.spd += plr.spd*1/100;
		plr.hp += plr.hp*1/100;
	}
}

/*int ranint(int down, int up){
	int range = up - down;
	int a;
	a = rand()%range;
	return down+a;
}*/
float ranfloat(int down, int up){
	int range = up - down;
	float a, b;

	a = rand()%range;
	b = rand()%99 + 1;
	return down+a+b/100;
}

void reset(player plr){
	plr.str = 0; plr.spd = 0;
	plr.hp = 0; plr.win = 0;
	plr.lose = 0; plr.draw = 0;
}

void print(player plr){
	printf("\n");
  printf("\t%-10s:%-8.2f\n","Strength",plr.str);
  printf("\t%-10s:%-8.2f\n","Speed",plr.spd);
  printf("\t%-10s:%-8.2f\n","HP",plr.hp);
}

void printstats(player plr1, player plr2, player plr3){
	print(plr1);
	print(plr2);
	print(plr3);
	/*printf("\n\tPlayer's Statistics\n");
	printf("\n\t----------------------------------\n\t|");
	printf("%-10s|%-10s|%-10s|\n\t----------------------------------\n","player 1","player 2","player 3");
  	printf("\t|%-4s: %-8.2f|%-8.2f|%-8.2f|\n","STR",plr1.str,plr2.str,plr3.str);
  	printf("\t|%-4s: %-8.2f|%-8.2f|%-8.2f|\n","SPD",plr1.spd,plr2.spd,plr3.spd);
  	printf("\t|%-4s: %-8.2f|%-8.2f|%-8.2f|\n","HP",plr1.hp,plr2.hp,plr3.hp);
  	printf("\t|%-4s: %-8d|%-8d|%-8d|\n","WIN",plr1.win,plr2.win,plr3.win);
  	printf("\t|%-4s: %-8d|%-8d|%-8d|\n","LOSE",plr1.lose,plr2.lose,plr3.lose);
  	printf("\t|%-4s: %-8d|%-8d|%-8d|\n","DRAW",plr1.draw,plr2.draw,plr3.draw);
  	printf("\t----------------------------------\n");
  	printf("\n");*/
}

int getMenu() {
		int option;
		printf("\n");
		printf("\t .================ MENU ================+. \n");
		printf("\t**  1. Create character                  **\n");
		printf("\t**  2. Fight                             **\n");
		printf("\t**  3. Print Statistics                  **\n");
		printf("\t**  4. Reset All Statistics              **\n");
		printf("\t**  0. Exit                              **\n");
		printf("\t------------------------------------------\n");
		printf("\tYour choice:  ");
		scanf(" %d",&option);
		printf("\tSelected option number %d\n",option);
	return option;
}
