#include <stdio.h>
#define Giatri "30/06/2018"
#define NPH "10/09/2013"
#define khoa "K58"

int main () {
  // int d,m,y;
  char date[10];
  char name[25],stdn[18],lop[10],address[15],major[30],gender[4];
printf("Insert the student name : ");scanf("%[^\n]",name);
printf("Insert %s's Birthday (dd/mm/yyyy) : ",name);
scanf(" %[^\n]",date);
// scanf("%d/%d/%d",&d,&m,&y);
printf("Insert the %s's student gender : ",name);scanf("%s",gender);
printf("Insert the %s's student number : ",name);scanf("%s",stdn);
printf("Insert the %s's student class : ",name);scanf(" %[^\n]",lop);
printf("Insert the %s's student address : ",name);scanf(" %[^\n]",address);
printf("Insert the %s's student major : ",name);scanf(" %[^\n]",major);
printf("\n\n");
  printf(" _________________________________________________\n");
  printf("|%-11s%-38s|\n","|   |","Truong Dai hoc Bach Khoa Ha Noi");
  printf("|%-20s%-29s|\n","|   |","THE SINH VIEN");
  printf("|%-49s|\n","|___|");
  printf("| _______                                         |\n");
  printf("||       | MSSV: %-18s Lop: %-9s|\n",stdn,lop);
  printf("||       | Ho Ten: %-31s|\n",name);
  // printf("||       | Ngay Sinh: %02d/%02d/%-7d%-15s|\n",d,m,y,gender);
  printf("||       | Ngay Sinh: %-13s%-15s|\n",date,gender);
  printf("||       | Ho khau: %-30s|\n",address);
  printf("||       | Nhom nganh:%-28s|\n",major);
  printf("||_______| Khoa hoc: %-29s|\n",khoa);
  printf("|                       Co Gia tri Den:%-11s|\n",Giatri);
  printf("|                   ||||||||||||||||||||||||||||| |\n");
  printf("|NPH:%-15s||||||||||||||||||||||||||||| |\n",NPH    );
  printf("|_________________________________________________|\n");
return 0;
}
