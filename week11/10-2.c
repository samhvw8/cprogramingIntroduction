#include <stdio.h>
#define max 10

int cmax(int p,int arr[],int len);
int suml(int arr[],int len);
int main() {
  int num[max],i;
  for(i = 0 ; i <max ;i++) {
    printf("Insert number %d :",i+1);scanf("%d",&num[i]);
}
  printf("\nsum of local is %d\n",suml(num,max));
    return 0;
} 


int suml(int arr[],int len){
  int i,sum = 0;
  for (i = 0;i < len ; i++ ) if(cmax(i,arr,len)) sum += arr[i];
  return sum; 
}
int cmax(int p,int arr[],int len){
  if (p == 0 || p == (len - 1))  return 0; 
else if((arr[p] > arr[p+1]) && (arr[p] > arr[p-1])) return 1;
  
  return 0;

}
