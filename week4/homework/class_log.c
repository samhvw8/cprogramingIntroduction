#include <stdio.h>

int main () {
	int no,d,m,y;
	char lop[5],subj[15],shour[6],ehour[6];
	printf("no : ");scanf("%d",&no);
	printf("class : ");scanf(" %[^\n]",lop);
	printf("%s's Subject : ",lop);scanf(" %[^\n]",subj);
	printf("date (dd/mm/yyyy) : ");scanf("%d/%d/%d",&d,&m,&y);
	printf("%s's start time : ",lop);scanf(" %[^\n]",shour);
	printf("%s's End time : ",lop);scanf(" %[^\n]",ehour);printf("\n\n");
	printf("%-5s%-12s%-9s%-13s%-9s%-9s\n","STT","Ngay Thang","Ten Lop","Ten Mon Hoc","Bat dau","Ket thuc");
	printf("__________________________________________________________\n");
	printf("%-5d%-2d/%2d/%-6d%-9s%-13s%-9s%-9s\n",no,d,m,y,lop,subj,shour,ehour);
	return 0;
}
