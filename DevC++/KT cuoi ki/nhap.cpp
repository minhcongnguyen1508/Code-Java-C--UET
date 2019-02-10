//
# include <iostream>
# include <algorithm>
# include <string>
# include <vector>
using namespace std;
int fibonaci(int);
int main(){
	int n;
	string x;
	cin>> n>>x;
	for(int i = 0; i <= n; i++){
		cout<< fibonaci(i)<< ", ";
	}
	return 0;
}
int fibonaci(int n){
	if(n <= 1)
		return 1;
	else
		return fibonaci(n-1) + fibonaci(n-2);
}
//int recursion()
