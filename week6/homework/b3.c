#include <stdio.h>

int main () {
int sh,sm,eh,em,summ;
summ = 0 ;


printf("%-5s%8s %8s\n","Day","Start","End");
printf("Start hour : Start minutes ; End hour :End minutes in 2  (24h): ");scanf("%d%*c%d;%d%*c%d",&sh,&sm,&eh,&em);
summ = (eh - sh)*60 + (em - sm);

printf("%-5s%2d:%2d %2d:%2d\n","2",sh,sm,eh,em);
(summ > 480 )?(printf("Hay can Bang Giua lam viec va nghi hoi\n")):(printf(""));printf("Start hour : Start minutes ; End hour :End minutes in 3  (24h): ");scanf("%d%*c%d;%d%*c%d",&sh,&sm,&eh,&em);
summ = (eh - sh)*60 + (em - sm);

printf("%-5s%2d:%2d %2d:%2d\n","3",sh,sm,eh,em);
(summ > 480 )?(printf("Hay can Bang Giua lam viec va nghi hoi\n")):(printf(""));printf("Start hour : Start minutes ; End hour :End minutes in 4  (24h): ");scanf("%d%*c%d;%d%*c%d",&sh,&sm,&eh,&em);
summ = (eh - sh)*60 + (em - sm);

printf("%-5s%2d:%2d %2d:%2d\n","4",sh,sm,eh,em);
(summ > 480 )?(printf("Hay can Bang Giua lam viec va nghi hoi\n")):(printf(""));printf("Start hour : Start minutes ; End hour :End minutes in 5  (24h): ");scanf("%d%*c%d;%d%*c%d",&sh,&sm,&eh,&em);
summ = (eh - sh)*60 + (em - sm);

printf("%-5s%2d:%2d %2d:%2d\n","5",sh,sm,eh,em);
(summ > 480 )?(printf("Hay can Bang Giua lam viec va nghi hoi\n")):(printf(""));printf("Start hour : Start minutes ; End hour :End minutes in 6  (24h): ");scanf("%d%*c%d;%d%*c%d",&sh,&sm,&eh,&em);
summ = (eh - sh)*60 + (em - sm);

printf("%-5s%2d:%2d %2d:%2d\n","6",sh,sm,eh,em);
(summ > 480 )?(printf("Hay can Bang Giua lam viec va nghi hoi\n")):(printf(""));printf("Start hour : Start minutes ; End hour :End minutes in 7  (24h): ");scanf("%d%*c%d;%d%*c%d",&sh,&sm,&eh,&em);
summ = (eh - sh)*60 + (em - sm);

printf("%-5s%2d:%2d %2d:%2d\n","7",sh,sm,eh,em);
(summ > 480 )?(printf("Hay can Bang Giua lam viec va nghi hoi\n")):(printf(""));printf("Start hour : Start minutes ; End hour :End minutes in sd (24h) : ");scanf("%d%*c%d;%d%*c%d",&sh,&sm,&eh,&em);
summ = (eh - sh)*60 + (em - sm);

printf("%-5s%2d:%2d %2d:%2d\n","SD",sh,sm,eh,em);
(summ > 480 )?(printf("Hay can Bang Giua lam viec va nghi hoi\n")):(printf(""));


	return 0;
}
