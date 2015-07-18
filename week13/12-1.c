#include <stdio.h>
int counteven(int *a,int len);
int max(int *a,int len);
int main() {
  int a[] = {7,1,2,3,4,5,6,8};
  printf("number of even is %d\nMax of array is %d\n",counteven(a,7),max(a,7));
}
int max(int *a,int len){
  int max,i;
  max = *a;
  for(i = 1;i< len;i++) if(max < *(a+i))max = *(a+i);
  return max;
}
int counteven(int *a,int len){
  int i,output = 0;
  for(i = 0 ;i < len ;i++) if(*(a+i)%2 == 0) output++;
  return output;
}
