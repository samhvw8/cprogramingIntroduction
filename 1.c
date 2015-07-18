#include "Ginz.h"
#define MAX 10
typedef struct{
  char  hoten[30];
  int diem[5];
} ketquathidau;

int reg(ketquathidau *vdv);
void print(ketquathidau *vdv,int num,int diem,int stt);
void play(ketquathidau *vdv,int num);
void rank(ketquathidau *vdv,int num);
void superplayer(ketquathidau *vdv,int num);

int main () {
  ketquathidau vdv[MAX];
  int z;
  for(;;){switch(GetMenu("Dang Ky thi dau;Thi dau;Xep Hang;Sieu xa thu;",4,1)){
    case 1 : z = reg(vdv);print(vdv,z,0,1);break;
      case 2:play(vdv,z);mfflush();print(vdv,z,1,0);break;
      case 3:rank(vdv,z);break;
      case 4:superplayer(vdv,z);break;
      case 0:return 0;
      }
  }
}

int reg(ketquathidau *vdv){
  int num,i,j;
  do {
    printf("\tNhap So Van dong Vien :");scanf("%d",&num);
    if(num > 10 || num < 0) printf("\tso van dong vien khong hop le !!\n\tNhap lai !!\n");mfflush();
  }while(num > 10 || num < 0);
  for(i = 0; i < num;i++) {
    printf("\tVan dong vien %d - Ho van ten : ",i+1);
    scanf("%[^\n]",vdv->hoten);mfflush();
    standname(vdv->hoten);
    for(j = 0; j < 5;j++) vdv->diem[j] = 0;
    vdv++;
  }
  return num; 
}

void print(ketquathidau *vdv,int num,int diem,int stt){
  int i,j;
  printf("\n\n\t");if(stt == 1) printf("STT ");
printf("%-20s","Ho van ten");
if(diem == 1) for (i = 0 ; i < 5 ; i++)printf("%-3d",i+1);
  for(i = 0 ; i < num ;i++ ){
    printf("\n\t");if(stt == 1) printf("%-4d",i+1);
    printf("%-20s",vdv[i].hoten);
   if(diem == 1) for(j = 0; j < 5;j++) printf("%-3d",vdv[i].diem[j]);
  }
}

void play(ketquathidau *vdv,int num){
  int i,j,c;
  for(i = 0 ; i < 5;i++){
    printf("\n\tLuot ban %d \n",i+1);
    for(j = 0; j <num;j++){
      printf("\n\tDiem cua %s :",vdv[j].hoten);
      do{
	scanf("%d",&vdv[j].diem[i]);
	if(vdv[j].diem[i]< 0 || vdv[j].diem[i] > 10)printf("\n\tDiem khong hop le !! \n nhap lai \n");
}while(vdv[j].diem[i]< 0 || vdv[j].diem[i] > 10);
      }
   }
}
 
void rank(ketquathidau *vdv,int num){
  int i,j,maxz,rank=0;
  int pplayer[num];
  for( i = 0 ; i < num ; i++) pplayer[i] = 0;

  for( i = 0 ; i < num ; i++) 
    for (j = 0 ; j < 5 ; j++) 
      pplayer[i]+=vdv[i].diem[j];
  
  for(j = 0;j<num;j++){
  maxz = pplayer[0];
  for(i = 0 ; i < num ; i++) if( maxz < pplayer[i] ) maxz =  pplayer[i];
  for(i = 0 ; i< num;i++) if( maxz == pplayer[i]){ printf("\t%-10s",vdv[i].hoten);
      pplayer[i] = 0;j+=i;
  }
  if(rank == 0 ) printf("  Gold");
  if(rank == 1 ) printf("  Silver");
  if(rank == 2 ) printf("  Bronze");
  printf(" %-2d\n", maxz);
  rank++;
  }
}

void superplayer(ketquathidau *vdv,int num){
  int i,j,cc,c;
  cc = c= 0;
  for(i = 0 ;i < num ;i++) 
  	for (j = 0 ; j <5 ;j++){
  		if(vdv[i].diem[j] == 10 && cc == 0 && cc == 0 ) {cc++;c=1;}
  		else if(vdv[i].diem[j] == 10 && cc != 0 && cc != 0 ) cc++;
  		else if(vdv[i].diem[j] != 10 && cc != 0 && cc != 0 ) {cc=0;c=0;}
  		if (cc == 3) printf("\t%s\n",vdv[i].hoten );
  	}
}