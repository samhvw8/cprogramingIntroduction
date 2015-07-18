#include <stdio.h>
#define max 100
int compare(int arr[],int arr2[],int l);
int reverse(int arr[],int arr2[],int l);
int equal(int arr[],int arr2[],int l);

int main () {
  int num[max],num1[max];
  int i,c,l,l2;
  for (i = 0; i< max;i++)num[i] = num1[i]= 0;
  i =0;
  printf("Insert array 1 : ");
  
  while((c = getchar()) != '\n') {c = c - '0';num[i] = c;i++ ;}
  l = i-1;i=0;printf("\n");
 printf("Insert array 2 : ");

  while((c = getchar()) != '\n') {c = c - '0';num1[i] = c;i++ ;}
  l = i-1;i=0;printf("\n");
 printf("arr vs arr2 is  %d\n", compare(num,num1,l));


  return 0;




}
int reverse(int arr[],int arr2[],int l){
  int i,j;
  for(i = 0,j = l; i<=l ; i++ , j--)  if ( arr[i] != arr2[j] ) return 0;
  return 1;
}
int equal(int arr[],int arr2[],int l){
  int i;
  for(i = 0; i<=l;i++) if(arr[i]!=arr2[i])return 0;
  return 1;
}
int compare(int arr[],int arr2[],int l){
  if(reverse(arr,arr2,l) == 1) return -1;
  if(equal(arr,arr2,l) == 1) return 1; else if(equal(arr,arr2,l) == 0) return 0;
}
