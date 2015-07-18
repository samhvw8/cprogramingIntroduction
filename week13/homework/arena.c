#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define INVALID -1
#define maxoption 100
#define tabs 8
#define STTALL 6 // 0 : str ; 1 :dex; 2 : HP; 4 win; 5 lose ; 6 draw
#define STT 3
#define WIN 1
#define LOSE 0
#define MAXMATCH 30
#define MAXBONUS 5
#define COL 6

void printran(float randomz[][MAXMATCH],int numcycle);
void createchar(float *player,int num);
void createchar1(float *player,int num);
void cyclearena(float *player1,float *player2,float *player3,float randomz[][MAXMATCH],int cycle);
int arena(float *player1,float *player2);
void rewardarena(float *player1,float *player2,int playerwin,int p1,int p2,float randomz[][MAXMATCH],int cycle,int match);
void reward(float *player,int result);
void rewardran(float *player,float percent);
float ranfloat(int limdown,int limupr);
void printstats(float *player1,float *player2,float *player3);
void printss(float *player);
void reset(float *player);
void resetr(float ran[][MAXMATCH]);
// ==========================================================================================================
int countma(char arr[][maxoption],int num);
int countcs(char arr[]);
void repchar(int times,char c);//print character  c with (times)
int power(int x,int n); // power x^n
int str2numa(char arr[],int length); // convert string to number
int checkan(char arr[],int length); // check array number (int)
int GetMenu(const char *a,int o,int EXIT);
// ==========================================================================================================

int main(){
    float player1[STTALL],player2[STTALL],player3[STTALL],randomz[COL][MAXMATCH];
    int i,times,k,z1,z=0,c;
    z1 = 0;
 
    for(;;){
        switch(GetMenu("Create character;Cycle Match;Print Stats of player and reward random;Reset stats;Reset reward random table",5,1))
        {
            case 1:z++;srand(time(NULL));
            for(;;){c = GetMenu("Create character with Random Stats;Create character with Manual Stats",2,0);
            if(c == 1){createchar(player1,1);createchar(player2,2);createchar(player3,3);break;}
            if(c == 2){createchar1(player1,1);createchar1(player2,2);createchar1(player3,3);break;}
            } while((k=getchar())!='\n');break;
            case 2:if(z != 0){z1++;
                do{ 
                    printf("\n\t%s %d: ","How many times you want to match cycle < ",MAXMATCH);
                    scanf("%d",&times);
                    if(times>MAXMATCH) printf("%s %d :\n","Wrong input ! Please Input <",MAXMATCH);
                } while(times>MAXMATCH);
                    resetr(randomz);
                    for(i = 0;i< times;i++)  cyclearena(player1,player2,player3,randomz,i); while((k=getchar())!='\n');
                    }else {printf("\n%s\n","Create character first !");}break;
            case 3:if(z != 0&& z1!=0){
                printran(randomz,times);
                printf("\n");
                printstats(player1,player2,player3);        
            }else if(z == 0)printf("\n\t%s\n","Create character first !");
                else if(z1 == 0)printf("\n\t%s\n","Take part in arena first !");
            break;
            case 4:reset(player1);reset(player2);reset(player3);break;
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
void reset(float *player){
    int i;
    for(i = 0 ; i <STTALL;i++){
        player[i] = 0;
     }
}
/**
 * Create character with manual stats
 * @param player array stats of player
 */
void createchar1(float *player,int num){
    int i;
    int choice,c;
    reset(player);
        printf("%s%d :\n","Create character for player ",num);
        printf("Input STR : ");scanf("%d",&c);player[0] = c;
        printf("Input DEX : ");scanf("%d",&c);player[1] = c;
        printf("Input HP  : ");scanf("%d",&c);player[2] = c;
     
}
/**
 * Create character with random stats
 * @param player array stats of player
 */
void createchar(float *player,int num){
    int i;
    int choice,c; c = INVALID;
    reset(player);
    do
    {
        printf("\n\tCreate character for player %d\n",num);
        for(i = 0 ; i < STT ;i++) player[i] = ranfloat(1,10);
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
int arena(float *player1,float *player2){
    if((player1[2]-player2[0]*player2[1])>(player2[2]-player1[0]*player1[1])) return 1;
    else if((player1[2]-player2[0]*player2[1])<(player2[2]-player1[0]*player1[1])) return 2;
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
void rewardarena(float *player1,float *player2,int playerwin,int p1,int p2,float randomz[][MAXMATCH],int cycle,int match){
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
        player1[5]++;
        player2[5]++;
        reward(player1,WIN);
        reward(player2,WIN);
    }
    if(playerwin == 1) {
        player1[3]++;
        player2[4]++;
        reward(player1,WIN);
        reward(player2,LOSE);
    }
    if(playerwin == 2) {
        player1[4]++;
        player2[3]++;
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

void reward(float *player,int result){
    int i;
    // for player win
    if(result == WIN ) for (i = 0;i < STT;i++) {
        *player += *player*2/100;
        player++;
    }
    // for player lose
    if (result == LOSE ) for (i = 0;i < STT;i++) {
        *player += *player*1/100;
        player++;
    }
}
/**
 * reward random player after match with percent random
 * @param player  player's array stats
 * @param percent percent increase
 *
 * increase player's stats after match
 */
void rewardran(float *player,float percent){
    int i;
    for (i = 0;i < STT;i++) {
        *player += *player*percent/100;
        player++;
    }
}
/**
 * cyclearena description
 * @param player1 [player1's stats ]
 * @param player2 [player2's stats ]
 * @param player3 [player3's stats ]
 */
void cyclearena(float *player1,float *player2,float *player3,float randomz[][MAXMATCH],int cycle){
    rewardarena(player1,player2,arena(player1,player2),1,2,randomz,cycle,1);
    rewardarena(player1,player3,arena(player1,player3),1,3,randomz,cycle,2);
    rewardarena(player3,player2,arena(player3,player2),3,2,randomz,cycle,3);
}



/**
 * random Floating-point numbers
 * @param  limdown [limit downer]
 * @param  limupr  [limit upper]
 * @return         [Floating-point numbers]
 */
float ranfloat(int limdown,int limupr){
    int range = limdown - limupr;
    float a,b;

    a = rand()%range+1;
    b = rand()%99+1;
    return limdown+a+b/100;
}

void printstats(float *player1,float *player2,float *player3){
    printf("\n\tPlayer's stats\n");
    printf("\n\t----------------------------------\n\t|      %-8s|%-8s|%-8s|\n\t----------------------------------\n","player 1","player 2","player 3");
    printf("\t|%-4s: %-8.3f|%-8.3f|%-8.3f|\n","STR",player1[0],player2[0],player3[0]);
    printf("\t|%-4s: %-8.3f|%-8.3f|%-8.3f|\n","DEX",player1[1],player2[1],player3[1]);
    printf("\t|%-4s: %-8.3f|%-8.3f|%-8.3f|\n","HP",player1[2],player2[2],player3[2]);
    printf("\t|%-4s: %-8.0f|%-8.0f|%-8.0f|\n","WIN",player1[3],player2[3],player3[3]);
    printf("\t|%-4s: %-8.0f|%-8.0f|%-8.0f|\n","LOSE",player1[4],player2[4],player3[4]);
    printf("\t|%-4s: %-8.0f|%-8.0f|%-8.0f|\n\t----------------------------------\n","DRAW",player1[5],player2[5],player3[5]);
    printf("\n");
}

void printss(float *player){
    printf("\n");
    printf("\t%-5s:%-8.3f\n","STR",player[0]);
    printf("\t%-5s:%-8.3f\n","DEX",player[1]);
    printf("\t%-5s:%-8.3f\n","HP",player[2]);
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
int GetMenu(const char *a,int o,int EXIT){
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
        {     if(countma(matrix,o)%2!=0) {printf("\n\t.");repchar(((countma(matrix,o)+4)/2),'=');printf(" Menu ");repchar(((countma(matrix,o)+4)/2-1),'=');printf(".\n");}
        else {printf("\n\t.");repchar(((countma(matrix,o)+4)/2-1),'=');printf(" Menu ");repchar(((countma(matrix,o)+4)/2-1),'=');printf(".\n");}
                for(id2 = 0 ; id2 < o;id2++)printf("\t||%3d. %-*s||\n",id2+1,countma(matrix,o)+1,matrix[id2]);

                if(EXIT == 1)printf("\t||  0. %-*s||\n",(countma(matrix,o)+1),"Exit");
                printf("\t.");repchar(((countma(matrix,o)+7)*2)/2+1,'=');printf(".\n"); printf("\t\tYour choice:   ");}
        else
        {
            printf("\n\t.");repchar(countma(matrix,o)+4,'=');printf(" Menu ");repchar(countma(matrix,o)+4,'=');printf(".\n");
                for(id2 = 0 ; id2 < o;id2++){if(flag == 0){printf("\t||%3d. %-*s",id2+1,countma(matrix,o)+1,matrix[id2]);flag++;}
                 else {printf("%3d. %-*s||\n",id2+1,countma(matrix,o)+1,matrix[id2]);flag=0;}}
                if(EXIT == 1) if(o%2 == 0)printf("\t||  0. %-*s||\n",(countma(matrix,o)+1)*2+5,"Exit"); else printf("  0. %-*s||\n",(countma(matrix,o)+1),"Exit");
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
