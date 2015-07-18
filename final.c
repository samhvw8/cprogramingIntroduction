#include "Ginz.h"
#define MAX 30
#define NOITRU 150000


typedef struct {
  double noitru;
  double phauthuat;
  double thuoc;
  double giatri;
}vienphi;

typedef struct {
  char hoten[30];
  char loaithe;
  vienphi vp;
} Benhnhan;
Benhnhan bn[MAX];

double floor(double num);
int  input();
void thanhtoan(int num);
void report(int num);


int main () {
  int num;
  for(;;) {
    switch(GetMenu("Nhap Thong Tin co Ban;Thanh Toan Vien Phi;Bao Cao Chung;Benh Nhan Huong Loi Nhieu Nhat;Benh nhan Nam vien Lau nhat",5,1)){
    case 1: num = input();break;
    case 2: thanhtoan(num);break;
    case 3: report(num);break;
    case 0: return 0;
    }

  }
}
double floor(double num){
	double o=num;
	while(o >= 1) {
	    o-=1;
	}
	return num -o;
}

int  input(){
  int num,i;

  do {indent(1);
    printf("So benh nhan can nhap du lieu : ");scanf("%d",&num);mfflush();
    if(num < 0 || num > MAX) {indent(1);printf("Du lieu khong hop le !! nhap lai !! \n");}
  } while(num < 0 || num > MAX);

  for ( i = 0; i < num ; i++)  {
    indent(1);printf("Nhap ten benh nhan %d : ",i+1);scanf("%[^\n]",bn[i].hoten);standname(bn[i].hoten);mfflush();
    do{
      indent(1);printf("loai the cua benh nhan %s : ",bn[i].hoten);scanf("%c",&bn[i].loaithe);mfflush();
      if(bn[i].loaithe != 'G' && bn[i].loaithe != 'S' && bn[i].loaithe != 'C') {indent(1);printf("Du lieu khong hop le !! nhap lai !! \n");}
    }while(bn[i].loaithe != 'G' && bn[i].loaithe != 'S' && bn[i].loaithe != 'C');

  }

  indent(1);printf("Danh Sach Benh Nhan !! \n");indent(1);
  printf("%-3s %-30s %-10s\n","STT","Ho va ten","Loai The");

  for( i = 0; i < num ; i++){indent(1);
    printf("%-3d %-30s ",i+1,bn[i].hoten);
    if(bn[i].loaithe == 'G') printf("Gold\n");
    if(bn[i].loaithe == 'S') printf("Silver\n");
    if(bn[i].loaithe == 'C') printf("Citizen\n");
  }
  return num;
}

void thanhtoan(int num){
  int i;
  double day,c;
  double thuoc;
  char choice;
  for(i = 0; i < num ;i++){
    indent(1);printf("Benh nhan %s : \n",bn[i].hoten);

    do {
    indent(2);printf("So ngay noi tru : ");scanf("%lf",&day);mfflush();
    if((day < 0 || day > 10.0) || (day-floor(day)) !=0) {indent(2); printf("Ngay noi tru khong hop le !! nhap lai !! \n");}
    }while((day < 0 || day > 10.0) ||(day-floor(day)) !=0 );

    bn[i].vp.noitru = NOITRU*day;
indent(2);printf("Tien noi tru cua benh nhan %s :",bn[i].hoten); printf(" %.0f ngay x %d (dong/ngay) = %.0f (dong)\n",day,NOITRU,bn[i].vp.noitru );

    do{
      indent(2);printf("Benh Nhan %s co lam phau thuat khong ?? (y : co ;n : khong) : ",bn[i].hoten);scanf("%c",&choice);mfflush();
      if(choice != 'y' && choice != 'n') {indent(2);printf("Chon sai !! Chon lai !! \n");}
    } while(choice != 'y' && choice != 'n');

    if(choice == 'n') bn[i].vp.phauthuat = 0;
    else {
      do{
		indent(2);printf("Tien Phau thuat cua benh nhan %s : ");scanf("%lf",&bn[i].vp.phauthuat);mfflush();
     	 if((bn[i].vp.phauthuat < 0 || bn[i].vp.phauthuat > 2000000.0) || (bn[i].vp.phauthuat-floor(bn[i].vp.phauthuat)) !=0) {indent(2);printf("So tien khong hop le !! yeu cau nhap lai !!\n");}
      }while((bn[i].vp.phauthuat < 0 || bn[i].vp.phauthuat > 2000000.0) || (bn[i].vp.phauthuat-floor(bn[i].vp.phauthuat)) !=0);
    }
     do {
		indent(2);	printf("Tien Thuoc cua benh nhan %s : ");  scanf("%lf",&bn[i].vp.thuoc);mfflush();
		if((bn[i].vp.thuoc < 0 || bn[i].vp.thuoc > 5000000.0) || (bn[i].vp.thuoc-floor(bn[i].vp.thuoc)) !=0) {indent(2);printf("So tien khong hop le !! yeu cau nhap lai !!\n");}
     }while((bn[i].vp.thuoc < 0 || bn[i].vp.thuoc > 5000000.0) || ((bn[i].vp.thuoc-floor(bn[i].vp.thuoc) !=0));

     indent(1);printf("Benh nhan %s co loai the : ",bn[i].hoten);
     if(bn[i].loaithe == 'G'){ printf("Gold (-70%)\n");c= 0.7;}
     if(bn[i].loaithe == 'S') {printf("Silver (-50%)\n");c = 0.5;}
     if(bn[i].loaithe == 'C'){ printf("Citizen (-30%)\n");c = 0.3;}
     bn[i].vp.giatri = bn[i].vp.noitru +bn[i].vp.thuoc + bn[i].vp.phauthuat ;
     indent(1);printf("Tien chua giam tru cua benh nhan %s :",bn[i].hoten);printf("%.0f (dong) + %.0f (dong)+ %.0f(dong) = %.0f(dong)\n",bn[i].vp.noitru,bn[i].vp.thuoc,bn[i].vp.phauthuat);

     indent(1);printf("Tien phai cua benh nhan %s :",bn[i].hoten);
     printf("%.0f (dong) + %.0f (dong) = %.0f(dong)\n",bn[i].vp.giatri,bn[i].vp.giatri-bn[i].vp.giatri*c);

  }
}
void report(int num){
  int i;
  double c;
  indent(1);
  printf("%-30s %-10s %-10s %-10s %-10s \n","Ho ten","Loai the","Chi phi tho","Gia tru","Phai tra");
  for(i = 0 ; i < num ; i++) {
    if(bn[i].loaithe == 'G'){ c= 0.7;}
    if(bn[i].loaithe == 'S') {c = 0.5;}
    if(bn[i].loaithe == 'C'){c = 0.3;}
    indent(1);printf("%-30s %-2c %-10.0f %-10.0f %-10.0f \n",bn[i].hoten,bn[i].loaithe,bn[i].vp.giatri,bn[i].vp.giatri*c,bn[i].vp.giatri-bn[i].vp.giatri*c);
 }
}


