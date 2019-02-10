//
# include <iostream>
# include <algorithm>
# include <string>
# include <vector>
using namespace std;
int fi(int n){
	if(n <= 2)
	return 1;
	else
		return fi(n-1) + fi(n-2); 
}
int main(){
	int n;
	cin>> n;
	bool check = false;
	{
		int i = 1;
		while(fi(i) <= n){
			if(fi(i) == n) check = true;
			i++;
		}
	}
	
	if(check) {
		int i = 1;
		cout<< "Thuoc day Fibonacci"<<endl;
		do{
			cout<< fi(i)<< " ";
			i++;
		}while(fi(i)<=n);
	}
	
	else 
	{	int i=1;
		cout<< "Khong thuoc day Fibonacci"<<endl;
		do{
			cout<< fi(i)<< " ";
			i++;
		}while(fi(i)<=n);
	}
	return 0;
}

