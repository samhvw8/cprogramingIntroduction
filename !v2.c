#include "Ginz.h"
#define DIEMS 20
#define MAX 40

typedef struct $
{
	char Name[25];
	int Old;
	int Score[5];
} Game;

void inplayer(Game *Player);
int start(Game *arr,char *s);
void print(Game *Player,int num);
void print2(Game *Player,int num,int L);
void play(Game *Player,int num,char *s);
int searchc(char *s,char k);
void lato(char c,char *s,char *ss,int num);
int checkc(char c,char *cc,int pos);

int main(){
	char s[MAX];
	Game Person[5];
	int num,c=0;
	for(;;){
		switch(GetMenu("Start;Play;Score",3,1)){
			case 1:num = start(Person,s);print(Person,num);c = 1;break;
			case 2:if(c != 0 ) {
				indent(1);printf("%s\n","Start Game !!");
				indent(1);printf("%s","O Chu :");repchar(strlen(s),'*');printf("\n");
				play(Person,num,s);
				print2(Person,num,1);
			} else indent(1);printf("%s\n","Start First !!");break;
			case 3:if(c != 0 ) { print2(Person,num,0); } else printf("%s\n","Start First !!");break;
			case 0:return 0;
		}
	}
}

void print(Game *Player,int num){
	int i;
	indent(1);printf("%-15s %5s\n\n","Ho van Ten","Tuoi" );
	for(i = 0 ; i <num ;i++){
		indent(1);printf("%-15s %5d\n",Player->Name,Player->Old);
		Player++;
	}
	printf("\n");
}

void print2(Game *Player,int num,int L){
	int i;
	indent(1);if(L) printf("%-15s %3s %3s %3s %6s\n\n","Ho van Ten","L1","L2","L3","Ketqua" ); 
	else printf("%-15s %6s\n\n","Ho van Ten","Ketqua" ); 
	for(i = 0 ; i <num ;i++){
		indent(1);if(L)printf("%-15s %3d %3d %3d %6d\n\n",Player->Name,Player->Score[0],Player->Name,Player->Score[1],Player->Name,Player->Score[2],Player->Name,Player->Score[4]);
		else printf("%-15s %6d\n\n",Player->Name,Player->Score[4]);
		Player++;
	}
	printf("\n");
}

void inplayer(Game *Player){
	int i;

	indent(1);
	printf("%s","Nhap Ten nguoi choi : ");scanf("%[^\n]",Player->Name);mfflush();
	indent(1);standname(Player->Name);
	do
	{printf("%s %s :","Nhap tuoi ",Player->Name);scanf("%d",&Player->Old);mfflush();if(Player->Old < 0){indent(1);printf("%s\n","Wrong Input !! Input Again !!");}}

	while(Player->Old < 0);
	for(i = 0;i<5;i++) Player->Score[i] = 0;

}
int start(Game *arr,char *s){
	char a[MAX];
	int i,num;

	indent(1);
	printf("%s :","Nhap xau ky tu");scanf("%[^\n]",a);mfflush();
	for(i=0;i<strlen(a);i++) if(a[i] != ' ') {*s = a[i];s++;} *s = '\0';

	indent(1);
	do {
		printf("Nhap so nguoi choi :");scanf("%d",&num);
		if(num < 0 || num > 5) printf("%s\n","Input wrong !! Input Again !!");
	} while(num < 0 || num > 5);
	mfflush();

	for(i = 0;i < num;i++) {indent(1);printf("%s %d\n","Nguoi choi thu",i+1);inplayer(arr);arr++;}

}

int searchc(char *s,char k){
	int c=0;
	while(*s != '\0'){
		if(k == *s) c++;
		s++;
	}
	return c;
}
void lato(char c,char *s,char *ss,int num){
		while(*s != '\0') {
			if(*s == c) *ss = c;
			ss++;s++;
		}
}

int checkc(char c,char *cc,int pos){
	pos --;
	if(pos > 0) if(c == *cc) return 1;
	else {pos --;cc--;return checkc(c,cc,pos); } 
	if(pos == 0) if(c == *cc) return 1; return 0;
}

void play(Game *Player,int num,char *s){
	Game *Playero;
	Playero = Player;
	int i,j,z=0;
	char c[num*3],ss[MAX],sss[MAX];
	for(i = 0 ;i<strlen(s);i++)ss[i] = '*'; ss[strlen(s)] = '\0';

	for (i = 0 ;i < 3; i++){
		indent(1);printf("%s %d\n","Lan doan ",i+1);
		for(j = 0;j < num;j++){
			do{
			indent(1);printf("%s %s : ","Nguoi Choi ",Player->Name);scanf("%c",&c[z]);mfflush();
			if(checkc(c[z],c,z)) {indent(1);printf("%s\n","wrong input input again !!"); 
			// printf("%d\n",checkc(c[z],c,z) );
		}
			}while(checkc(c[z],c,z));
			z++;
			Player->Score[i]+=searchc(s,c[j]);
			lato(c[j],s,ss,num);
			indent(1);printf("%s\n",ss);
			Player++;
		}
		Player = Playero;
	}


	Player = Playero;
	indent(1);
	printf("%s \n","Lan doan Cuoi");

	for(j = 0;j < num;j++){
		indent(1);printf("%s %s : ","Nguoi Choi ",Player->Name);scanf("%s",sss);
		if(strcmp(sss,ss) == 0) Player->Score[i]+=DIEMS;
	}
	Player = Playero;
	indent(1);printf("O chu la : %s\n",s);

	for(j = 0;j < num;j++){
		Player->Score[4] += Player->Score[0] +Player->Score[1] +Player->Score[2] +Player->Score[3];
	}
}
