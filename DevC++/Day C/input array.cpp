#include<stdio.h>
#include<string.h>
#include<cmath>
int main(){
	int array[10];
	
	// Tinh tong cac gia tri nhap vao
	
	int sum = 0;
	
	for(int i = 0; i < 10; i++){
		printf("input: ");
		scanf("%d", &array[i]);
		//Yeu cau tinh sum cac so nguyen duong.
		if(array[i] < 0)
			continue;
		else
			sum+=array[i]; // sum = sum + array[i];
	}
	
//	do{
//		printf("input: ");
//		scanf("%d", &array[i]);
//	}
//	while(array[i] > 0);
	
//	while(0){
//		printf("input: ");
//		scanf("%d", &array[i]);
//		if(array[i] < 0)
//			break;
//	}
//	
	printf("%d", sum);		
	return 0;
}
