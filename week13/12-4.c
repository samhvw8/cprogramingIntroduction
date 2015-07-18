#include <stdio.h>
void printsa(int *a,int len);
int main () {
  int a[] = {1,2,3,4,5};
  printsa(a,5);

}
void printsa(int *a,int len){
  int i,j,z;
    for ( i = 0 ; i < len ;i++){
      j = i;
      while(j<len){
	for(z = i;z <=j;z++)printf("%d ",a[z]);
	printf("\n");
	j++;
      }
      printf("\n");
}}
