#include <stdio.h>
double kie (double velocity,double mass);

int main () {
  double v,m;
  printf("Insert velocity :");scanf("%lf",&v);
  printf("Insert Mass :");scanf("%lf",&m);
  printf("Kinetic engergy : %.2f (J)\n",kie(v,m));

}
double kie (double velocity,double mass){ return mass*velocity*velocity/2;}
