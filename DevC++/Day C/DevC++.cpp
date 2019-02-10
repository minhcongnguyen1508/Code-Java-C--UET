#include<stdio.h>
#include<string.h>
#include<cmath>
int main(){
//	int i;
//	float f;
//	printf("Moi nhap so: ");
//	scanf("%d", &i);
//	scanf("%f", &f);
//	printf("So nguyen da nhap: %d \n", i);
//	printf("So thuc da nhap: %f", f);
	int a, b;
	
	printf("Moi\n nhap so\n");
	scanf("%d %d", &a, &b);
	int sum = a + b;
	printf("tong: %d\n", sum);
	
//  Cau truc dieu khien
	int hieu;
	if(a > b){
		hieu = a - b;
		printf("Hieu : %d", hieu);
	}
	else{
		hieu = b - a;
		printf("Hieu : %d", hieu);
	}
	
// Vong lap, while, do~WHILE, for
	int a[10];
// Nhap mang

	for(int i = 0; i < 10; i++){
		scanf("%d", &a[i]);
	}
	for(int i = 0; i < 10; i++){
		printf(" %d ", a[i]);
	}
	return 0;
}
