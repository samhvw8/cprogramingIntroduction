#include <stdio.h>

void getJudgeData();
void calcScore();
float mx();
float mn();
float j2,j3,j4,j5,j,p;
int main () {
  getJudgeData();
  calcScore();
  return 0;
}
void getJudgeData() {
  do {
    printf("Insert Score of judge 1 :");scanf("%f",&j);
    if (j> 10||j <0) printf("Wrong Insert !");
  }
  while (j > 10||j <0); 
  do {
    printf("Insert Score of judge 2 :");scanf("%f",&j2);
    if (j2 > 10||j2 <0) printf("Wrong Insert !");
  }
  while (j2 > 10||j2 <0); 
  do {
    printf("Insert Score of judge 3 :");scanf("%f",&j3);
    if (j3 > 10||j3 <0) printf("Wrong Insert !");
  }
  while (j3 > 10||j3 <0); 
  do {
    printf("Insert Score of judge 4 :");scanf("%f",&j4);
    if (j4 > 10||j4 <0) printf("Wrong Insert !");
  }
  while (j4 > 10||j4 <0); 
  do {
    printf("Insert Score of judge 5 :");scanf("%f",&j5);
    if (j5 > 10||j5 <0) printf("Wrong Insert !");
  }
  while (j5 > 10||j5 <0); 
 
}
void calcScore(){
  p = (j + j2 + j3 + j4 + j5 - mn() - mx())/3 ;
  printf("\nPoint :%.2f\n",p);
}

float mx(){
  float a;
  a = j; if (a >= j2 && a >= j3 && a>= j4 && a>= j5) return a;
  a = j2; if (a >= j && a >= j3 && a>= j4 && a>= j5) return a;
  a = j3; if (a >= j && a >= j2 && a>= j4 && a>= j5) return a;
  a = j4; if (a >= j && a >= j2 && a >= j3 && a>= j5) return a;
  a = j5; if (a >= j && a >= j2 && a >= j3 && a>= j4 ) return a;
   
}
float mn(){
  float a;
  a = j ; if ( a < j2 && a < j3 && a< j4 && a< j5) return a;
  a = j2  ;if (a < j && a < j3 && a< j4 && a< j5) return a;
  a = j3 ; if (a < j && a < j2 && a< j4 && a< j5) return a;
  a = j4 ; if (a < j && a < j2 && a < j3 && a< j5) return a;
  a = j5 ; if (a < j && a < j2 && a < j3 && a< j4 ) return a;
  
}
