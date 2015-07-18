// //////////////////////////
// Author : Hoang Van Sam //
// Class :ICT 58 - HUST   //
// //////////////////////////
#include <stdio.h>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#define Dacbiet 1000000000 //7
#define nhat 100000000 //6
#define nhi 50000000 //5 
#define ba 10000000 //4
#define tu 800000 //3
#define nam 100000 //2
#define pt(giai ,ve ,tienthuong) printf("Ban da trung "#giai" o "#ve" voi giai thuong %d\n",tienthuong)
int main () {
unsigned long int v1,v2,v3,v,total,c=0;
// int cv1,cv2,cv3;
// cv1 = cv2 = cv3 = 0;
printf("%s\n","chon 3 ve co 7 chu so va > 1,000,000" );
printf("%s","ve 1 :" );scanf("%lu",&v1);
printf("%s","ve 2 :" );scanf("%lu",&v2);
printf("%s","ve 3 :");scanf("%lu",&v3);
total = 0;
 srand((unsigned)time(NULL));
 v = 1000000 + rand()%9000000;  /*( v = 1,000,000 --- > 9,999,999)*/
 //v = 3019283;
printf("%s%lu\n","So trung thuong la ",v);
// -----v1---------------------------------------------
if (v1 == v) {pt(Dac biet,ve 1,Dacbiet);total = total + Dacbiet;c=1;
} else if (v1%1000000 == v%1000000) {pt(nhat,ve 1,nhat);total = total + nhat;c=1;
} else if (v1%100000 == v%100000) {pt(nhi,ve 1,nhi);total = total + nhi;c=1;
} else if (v1%10000 == v%10000) {pt(ba ,ve 1,ba);total = total + ba;c=1;
} else if (v1%1000 == v%1000) {pt(tu ,ve 1,tu);total = total + tu;c=1;
} else if (v1%100 == v%100) {pt(nam ,ve 1,nam);total = total + nam;c=1;
}
// ---v2------------------------------------------------------
if (v2 == v) {pt(Dac biet,ve 2,Dacbiet);total = total + Dacbiet;c=1;
} else if (v2%1000000 == v%1000000) {pt(nhat,ve 2,nhat);total = total + nhat;c=1;
} else if (v2%100000 == v%100000) {pt(nhi,ve 2,nhi);total = total + nhi;c=1;
} else if (v2%10000 == v%10000) {pt(ba ,ve 2,ba);total = total + ba;c=1;
} else if (v2%1000 == v%1000) {pt(tu ,ve 2,tu);total = total + tu;c=1;
} else if (v2%100 == v%100) {pt(nam ,ve 2,nam);total = total + nam;c=1;
}
// ---v3------------------------------------------------------
if (v3 == v) {pt(Dac biet,ve 3,Dacbiet);total = total + Dacbiet;c=1;
} else if (v3%1000000 == v%1000000) {pt(nhat,ve 3,nhat);total = total + nhat;c=1;
} else if (v3%100000 == v%100000) {pt(nhi,ve 3,nhi);total = total + nhi;c=1;
} else if (v3%10000 == v%10000) {pt(ba ,ve 3,ba);total = total + ba;c=1;
} else if (v3%1000 == v%1000) {pt(tu ,ve 3,tu);total = total + tu;c=1;
} else if (v3%100 == v%100) {pt(nam ,ve 3,nam);total = total + nam;c=1;
}
if (c == 0 ) printf("%s\n","chuc ban may man lan sau \n" ); else printf("%s%lu\n","Tong so tien ban trung la ",total );
// ---------------------------------------------------------
	return 0;
}
