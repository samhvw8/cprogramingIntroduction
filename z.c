#include <stdio.h>
#include <string.h>
#define MAX 8
typedef struct{
    char hoten[30];
    int diem[5];
} ketqua;

int main(){
    ketqua vdv[MAX];
    int choice;
    int n,i,j;
    for(;;){
        printf("1. Register\n2. Game\n3. Classification\n4. Super star\n5. Quit\n Your choice:");
        scanf("%d", &choice);
        switch(choice){
        case 1:
            printf("Nhap so vdv:");
            scanf("%d", &n);
            for(i=0;i<n;i++){
            printf("Nhap ten vdv thu %d:", i+1);
            scanf("%[^\n]", &vdv[i].hoten);
            }
            printf("Danh sach thi sinh\n");
            for(i=0;i<n;i++){
                printf("%d   %s\n", i+1, vdv[i].hoten);
            }
            break;

        case 2:
            for(j=0;j<5;j++){
                printf("Diem luot ban thu %d:\n", j+1);
                for(i=0;i<n;i++){
                    printf("Nhap diem cua vdv %s:", vdv[i].hoten);
                    scanf("%d", &vdv[i].diem[j]);
                }
            }
            printf("%-30s-10d%-10d%-10d%-10d%-10d\n", "Ho ten", 1, 2, 3, 4, 5);
            for (i=0; i<n; i++)
            printf("%-30s%-10d%-10d%-10d%-10d%-10d\n", vdv[i].hoten, vdv[i].diem[1], vdv[i].diem[2], vdv[i].diem[3], vdv[i].diem[4], vdv[i].diem[5]);
            break;

        case 3:

            break;

        case 4:
            break;

        case 5:
            return 0;
            break;

        }

    }
    return 0;
}

