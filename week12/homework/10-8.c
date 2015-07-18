#include <stdio.h>
#define max 100

void reverse(float num[],int l);
int main () {
	float num[max];
	int i,l;
	float c;
	i = 0;
	printf("how many number you want to input ?  Your as : ");scanf("%d",&l);
	printf("Input array  : ");
	for (i = 0; i < l; ++i)	scanf("%f",&num[i]);
	printf("\n");
	reverse(num,l);
	for (i = 0; i < l; ++i) printf("%f ",num[i]);
	printf("\n");

}
void reverse(float num[], int l) {
	int i,tem;
	for(i = 0 ;i <l/2 ; i++) {
		tem = num[i];
		num[i] = num[l-i-1];
		num[l-i-1] = tem;
	}
}