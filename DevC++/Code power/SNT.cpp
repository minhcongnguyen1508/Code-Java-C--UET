//
# include <iostream>
# include <algorithm>
# include <string>
# include <vector>
# include <cmath>
using namespace std;
int SNT(int n){
	if(n <= 3) return 1;
	else if(n % 2 == 0){
		return 0;
	}
	else{
		for(int i = 3; i < n; i+=2){
			if(n % i == 0)
			return 0;
		}
	}
	return 1;
}
int main(){
	int n;
	int i = 2;
	cin >> n;
	while (i < n){
			if(SNT(i)) cout<< i<< endl;
			i++;

	}	
	return 0;
}

