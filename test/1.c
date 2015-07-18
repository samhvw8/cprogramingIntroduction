#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define INVALID -1
#define maxoption 100
#define tabs 8
void mfflush();

typedef struct $player
{
    int win,lose;
    
} player;
void reset(player *player1);
void credit();
int checkan(char arr[], int len);
int str2numa(char arr[], int len);
int lenstr(char arr[]);
void pt(char *a);
int GetMenu(char *a, int o);
void repchar(int s, int e, char c); //print character  c with (s-e times) // print square like %-4d with varible ..
int menuChoice(int numberOfOptions, ...);
int main()
{   
    player p1;
    int l, c, i = 0;
    p1.win = 1;p1.lose = 0;
    printf("%d   %d \n",p1.win,p1.lose );
    reset(&p1);
    printf("%d   %d \n",p1.win,p1.lose );
    return 1;
}
void reset(player *player1){
    player1->win= player1->lose = 0;
}





void credit()
{
    printf("\n################################################################################\n");
    printf("################################################################################\n");
    printf("#################  ####    ##  #######  #######  ##    ####  ###################\n");
    printf("###################               ####  ####               #####################\n");
    printf("######################               #  #               ########################\n");
    printf("#######################           ####  ####           #########################\n");
    printf("###########################      #####  #####      #############################\n");
    printf("############################    ######  ######    ##############################\n");
    printf("############################   #######  #######   ##############################\n");
    printf("############################# ################## ###############################\n");
    printf("################################################################################\n");
    printf("################################################################################\n\n");
}
