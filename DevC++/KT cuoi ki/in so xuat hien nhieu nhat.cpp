# include <iostream>
#include <vector>
using namespace std;
struct arr{
	int val = 0;
	int count = 0;
};
int main(){
    int n;
    cin>> n;
   	arr a[n];
   	for(int i = 0; i < n; i++){
   		int x;
   		cin>> x;
   		if(i == 0) a[i].count ++;
   		for(int j = 0; j <= i; j++){
   			if(x == a[j].val){
   				a[j].count++;	
			}	
			else{
				a[i].val = x;
			}
		}
	}
	
	int max = 0;
	for(int i = 0; i < n; i++){
		if(a[i].count > max)
			max = a[i].count;
	}
	for(int i = 0; i < n; i++){
		if(a[i].count == max)
		cout<< a[i].val<<" ";
	}

    return 0;
}
