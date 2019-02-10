//
# include <iostream>
# include <algorithm>
# include <string>
# include <cstdlib>
# include <cmath>
using namespace std;
bool snt(int n){
	if(n == 2 || n == 3) return true;
	else if (n % 2 == 0) return false;
	else {
		for(int i=2; i<n; i++){
			if(n % i == 0)
			return false;
		}
	}
	return true;
}
int main(){
	int n;
	cin>> n;
//	cout<< snt(n);
	for(int i=2; i<=n; i++){
		if(snt(i))
		cout<< i<< " ";
	}
	return 0;
}

