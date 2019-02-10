#include<stdio.h>
#include<string.h>
#include<cmath>
int main(){
	// tinh tong cac so tu 1 den 100
	int sum = 0;
	for(int i=1; i<=100; i++){
		sum += i;
	}
	printf("\n sum : %d ", sum);
	
	// tinh giai thua. n!, voi n nhap vao tu ban phim.
	int n;
	printf("\nSo giai thua can tinh: ");
	scanf("%d", &n);
	int gt = 1;
	for(int i=1; i<=n; i++){
		gt *= i;
	}
	printf("\nso giai thua: %d", gt );
	return 0;
}
