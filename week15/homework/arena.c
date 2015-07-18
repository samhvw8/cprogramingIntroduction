#include "Ginz.h"
#define WIN 1
#define LOSE 0
#define MAXMATCH 30
#define MAXBONUS 5
#define COL 6

typedef struct $player
{
    float str,dex,hp;
    int win,lose,draw;
}player;

void printran(float randomz[][MAXMATCH],int numcycle);
void createchar(player *player,int num);
void createchar1(player *player,int num);
void cyclearena(player *player1,player *player2,player *player3,float randomz[][MAXMATCH],int cycle);
int arena(player *player1,player *player2);
void rewardarena(player *player1,player *player2,int playerwin,int p1,int p2,float randomz[][MAXMATCH],int cycle,int match);
void reward(player *player,int result);
void rewardran(player *player,float percent);
float ranfloat(int limdown,int limupr);
void printstats(player *player1,player *player2,player *player3);
void printss(player *player);
void reset(player *player);
void resetr(float ran[][MAXMATCH]);

// ==========================================================================================================

int main(){
    float randomz[COL][MAXMATCH];
    player p1,p2,p3;
    int i,times,k,z1,z=0,c;
    z1 = 0;
 
    for(;;){
        switch(GetMenu("Create character;Cycle Match;Print Stats of player and reward random;Reset stats;Reset reward random table",5,1))
        {
            case 1:z++;srand(time(NULL));
            for(;;){c = GetMenu("Create character with Random Stats;Create character with Manual Stats",2,0);
            if(c == 1){createchar(&p1,1);createchar(&p2,2);createchar(&p3,3);break;}
            if(c == 2){createchar1(&p1,1);createchar1(&p2,2);createchar1(&p3,3);break;}
            } while(getchar()!='\n');break;
            case 2:if(z != 0){z1++;
                do{ 
                    printf("\n\t%s %d: ","How many times you want to match cycle < ",MAXMATCH);
                    scanf("%d",&times);
                    if(times>MAXMATCH) printf("%s %d :\n","Wrong input ! Please Input <",MAXMATCH);
                } while(times>MAXMATCH);
                    resetr(randomz);
                    for(i = 0;i< times;i++)  cyclearena(&p1,&p2,&p3,randomz,i); while(getchar()!='\n');
                    }else {printf("\n%s\n","Create character first !");}break;
            case 3:if(z != 0&& z1!=0){
                printran(randomz,times);
                printf("\n");
                printstats(&p1,&p2,&p3);        
            }else if(z == 0)printf("\n\t%s\n","Create character first !");
                else if(z1 == 0)printf("\n\t%s\n","Take part in arena first !");
            break;
            case 4:reset(&p1);reset(&p2);reset(&p3);break;
            case 5:resetr(randomz);break;
            case 0:return 0;
        }
    }
    
}
// ==========================================================================================================
/**
 * reset all stats
 * @param player [player's stats array]
 */
void reset(player *player){
    (*player).str = (*player).dex = (*player).hp = 0; (*player).win= (*player).lose= (*player).draw = 0;
}
/**
 * Create character with manual stats
 * @param player array stats of player
 */
void createchar1(player *player,int num){
    reset(player);
        printf("%s%d :\n","Create character for player ",num);
        printf("Input STR : ");scanf("%d",&player->str);
        printf("Input DEX : ");scanf("%d",&player->dex);
        printf("Input HP  : ");scanf("%d",&player->hp); 
}
/**
 * Create character with random stats
 * @param player array stats of player
 */
void createchar(player *player,int num){
    int choice,c; c = INVALID;
    reset(player);
    do
    {
        printf("\n\tCreate character for player %d\n",num);
        player->str = ranfloat(1,10);
        player->dex = ranfloat(1,10);
        player->hp = ranfloat(1,10);
        printss(player);
        do
        {
            printf("\t%s","Do want create now ! (1:yes,0:no) :");scanf("%d",&choice);

            if(choice != 1 && choice != 0){
                printf("\t%s\n","Wrong input !!");
                c = INVALID+1;
            }
            else if(choice == 0) {
                printf("\t%s\n","Let random character's stats again !");
                c = INVALID;
            }
            else c = 1;
        } while(c == INVALID+1);
   }while(c == INVALID);
}

/**
 * create  1 arena match
 * @param  player1 [player1's stats]
 * @param  player2 [player2's stats]
 * @return         [who win 1 is player1 ; 2 is player2 ; 3 is draw]
 */
int arena(player *player1,player *player2){
    if((player1->hp-player2->str*player2->dex)>(player2->hp-player1->dex*player1->str)) return 1;
    else if((player1->hp-player2->str*player2->dex)<(player2->hp-player1->dex*player1->str)) return 2;
    else return 3;    
}
/**
 * reward 2 player after play 1 game
 * @param player1   sttarray of player 1
 * @param player2   sttarray of player 2
 * @param playerwin who win
 *
 * increase 2 player's stats after match and increase random of player with %
 */
void rewardarena(player *player1,player *player2,int playerwin,int p1,int p2,float randomz[][MAXMATCH],int cycle,int match){
    int ranplayer = rand()%2+1;
    int i,j;
    float ranpercent;
    i = 0; j = 1;// i index player  ; j index percent
    if(match == 2) {
        i+=2;
        j+=2;
    } else if(match == 3){
        i+=4;
        j+=4;
    }
   // reward player win
    if(playerwin == 3) {
        player1->draw++;
        player2->draw++;
        reward(player1,WIN);
        reward(player2,WIN);
    }
    if(playerwin == 1) {
        player1->win++;
        player2->lose++;
        reward(player1,WIN);
        reward(player2,LOSE);
    }
    if(playerwin == 2) {
        player1->lose++;
        player2->win++;
        reward(player1,LOSE);
        reward(player2,WIN);
    }
    ranpercent = ranfloat(0,MAXBONUS);
    // reward random
    if(ranplayer == 1) {
        randomz[i][cycle] = p1;
        randomz[j][cycle] = ranpercent;
        rewardran(player1,ranpercent);
    }
    else if(ranplayer == 2){
        randomz[i][cycle] = p2;
        randomz[j][cycle] = ranpercent;
        rewardran(player2,ranpercent);
    }
}

/**
 * reward the player after play 1 game
 * @param player sttarray of player 1
 * @param result  resulting of match
 *
 * increase player's stats after match
 */

void reward(player *player,int result){
    int i;
    // for player win
    if(result == WIN )    player->str+=player->str*2/100;player->dex+=player->dex*2/100;player->hp+=player->hp*2/100;
  
    
    // for player lose
    if (result == LOSE )  player->str+=player->str*1/100;player->dex+=player->dex*1/100;player->hp+=player->hp*1/100;
    
}
/**
 * reward random player after match with percent random
 * @param player  player's array stats
 * @param percent percent increase
 *
 * increase player's stats after match
 */
void rewardran(player *player,float percent){
    player->str+=player->str*percent/100;
    player->dex+=player->dex*percent/100;
    player->hp+=player->hp*percent/100;
}
/**
 * cyclearena description
 * @param player1 [player1's stats ]
 * @param player2 [player2's stats ]
 * @param player3 [player3's stats ]
 */
void cyclearena(player *player1,player *player2,player *player3,float randomz[][MAXMATCH],int cycle){
    rewardarena(player1,player2,arena(player1,player2),1,2,randomz,cycle,1);
    rewardarena(player1,player3,arena(player1,player3),1,3,randomz,cycle,2);
    rewardarena(player3,player2,arena(player3,player2),3,2,randomz,cycle,3);
}





void printstats(player *player1,player *player2,player *player3){
    printf("\n\tPlayer's stats\n");
    printf("\n\t----------------------------------\n\t|      %-8s|%-8s|%-8s|\n\t----------------------------------\n","player 1","player 2","player 3");
    printf("\t|%-4s: %-8.3f|%-8.3f|%-8.3f|\n","STR",player1->str,player2->str,player3->str);
    printf("\t|%-4s: %-8.3f|%-8.3f|%-8.3f|\n","DEX",player1->dex,player2->dex,player3->dex);
    printf("\t|%-4s: %-8.3f|%-8.3f|%-8.3f|\n","HP",player1->hp,player2->hp,player3->hp);
    printf("\t|%-4s: %-8d|%-8d|%-8d|\n","WIN",player1->win,player2->win,player3->win);
    printf("\t|%-4s: %-8d|%-8d|%-8d|\n","LOSE",player1->lose,player2->lose,player3->lose);
    printf("\t|%-4s: %-8d|%-8d|%-8d|\n\t----------------------------------\n","DRAW",player1->draw,player2->draw,player3->draw);
    printf("\n");
}

void printss(player *player){
    printf("\n");
    printf("\t%-5s:%-8.3f\n","STR",player->str);
    printf("\t%-5s:%-8.3f\n","DEX",player->dex);
    printf("\t%-5s:%-8.3f\n","HP",player->hp);
}

void printran(float randomz[][MAXMATCH],int numcycle){
    int i,z;

    printf("\n\tRandom reward statics\n");
    if(numcycle <15) {
        printf("\n\t");  repchar(13+6*(numcycle),'-');printf("\n"); 
        printf("\t|           |");
        for(i = 0; i< numcycle;i++) printf("%5d|",i+1);
          printf("\n\t");  repchar(13+6*(numcycle),'-');printf("\n"); 
        printf("\n\t%-12s|","Player M1");
        for(i = 0; i<numcycle;i++) printf("%5.0f|",randomz[0][i]);
        printf("\n\t%-12s|","Percent M1");
        for(i = 0;i<numcycle;i++) printf("%5.2f|",randomz[1][i]);
        printf("\n\t%-12s|","Player M2");
        for(i = 0; i<numcycle;i++) printf("%5.0f|",randomz[2][i]);
        printf("\n\t%-12s|","Percent M2");
        for(i = 0;i<numcycle;i++) printf("%5.2f|",randomz[3][i]);
        printf("\n\t%-12s|","Player M3");
        for(i = 0; i<numcycle;i++) printf("%5.0f|",randomz[4][i]);
        printf("\n\t%-12s|","Percent M3");
        for(i = 0;i<numcycle;i++) printf("%5.2f|",randomz[5][i]);
        printf("\n");
    }
    else {
        printf("\n\t");  repchar(13+6*(numcycle/2),'-');printf("\n"); 
        printf("\t|           |");
        for(i = 0; i< numcycle/2;i++) printf("%5d|",i+1);
          printf("\n\t");  repchar(13+6*(numcycle/2),'-');printf("\n"); 
        printf("\n\t%-12s|","Player M1");
        for(i = 0; i<numcycle/2;i++) printf("%5.0f|",randomz[0][i]);
        printf("\n\t%-12s|","Percent M1");
        for(i = 0;i<numcycle/2;i++) printf("%5.2f|",randomz[1][i]);
        printf("\n\t%-12s|","Player M2");
        for(i = 0; i<numcycle/2;i++) printf("%5.0f|",randomz[2][i]);
        printf("\n\t%-12s|","Percent M2");
        for(i = 0;i<numcycle/2;i++) printf("%5.2f|",randomz[3][i]);
        printf("\n\t%-12s|","Player M3");
        for(i = 0; i<numcycle/2;i++) printf("%5.0f|",randomz[4][i]);
        printf("\n\t%-12s|","Percent M3");
        for(i = 0;i<numcycle/2;i++) printf("%5.2f|",randomz[5][i]);
        if(numcycle%2 == 0) z = numcycle/2; 
            else  z = numcycle/2+1;
        printf("\n\t");  repchar(13+6*z,'-');printf("\n"); 
        printf("\t|           |");
        for(i = numcycle/2; i< numcycle;i++) printf("%5d|",i+1);
          printf("\n\t");  repchar(13+6*z,'-');printf("\n"); 
        printf("\n\t%-12s|","Player M1");
        for(i =numcycle/2; i<numcycle;i++) printf("%5.0f|",randomz[0][i]);
        printf("\n\t%-12s|","Percent M1");
        for(i =numcycle/2;i<numcycle;i++) printf("%5.2f|",randomz[1][i]);
        printf("\n\t%-12s|","Player M2");
        for(i =numcycle/2; i<numcycle;i++) printf("%5.0f|",randomz[2][i]);
        printf("\n\t%-12s|","Percent M2");
        for(i= numcycle/2;i<numcycle;i++) printf("%5.2f|",randomz[3][i]);
        printf("\n\t%-12s|","Player M3");
        for(i =numcycle/2; i<numcycle;i++) printf("%5.0f|",randomz[4][i]);
        printf("\n\t%-12s|","Percent M3");
        for(i =numcycle/2;i<numcycle;i++) printf("%5.2f|",randomz[5][i]);
    }
}

void resetr(float ran[][MAXMATCH]){
    int i,j;
    i = j = 0;
    for (i=0;i<6;i++)
        for(j = 0;j<MAXMATCH;j++)
            ran[i][j]=0;
}