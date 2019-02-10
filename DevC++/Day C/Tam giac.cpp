#include<stdio.h>
#include<string.h>
#include<cmath>
int main(){
	// Nhap vao 3 canh cua tam giac;
	// Tinh xem no co phai tam giac khong, neu co thi la tam giac gi.
	int a, b, c;
	printf("\nBa canh cua tam giac\n");
	scanf("%d %d %d", &a, &b, &c);
	
	// Cau truc dieu khien
	if(a + b >c &&  b+c>a && a+c>b){
		printf("\la tam giac");
		// neu thoa man dieu kien tren thi moi chay xuong
		if(a*a == b*b + c*c || b*b == a*a + c*c || c*c == b*b + a*a){
			if(a == b || c == a || b == c){
				printf("\nLa tam giac vuong can\n");
			}
			else
				printf("\nLa tam giac vuong\n");
			}
		else if(a == b || c == a || b == c){
			if(a == b && c == a && b == c)
				printf("\nLa tam giac deu\n");
			else{
				printf("\nLa tam giac can\n");
			}
		}
		
		else 
		printf("\nLa tam giac thuong\n");
	}
	// nguoc lai. Chu y ngoac nhon {...} Dong khoi
	else{
		printf("\nkhong la tam giac");
	}
	
	return 0;
}
