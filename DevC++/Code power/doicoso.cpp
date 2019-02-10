
# include <iostream>
# include <algorithm>
# include <string>
# include <vector>
using namespace std;

int main(){
	long long n;
	cin>> n;
	vector <int> a;
	if(n < 0) n = -n;
	while(n!=0){
		a.push_back(n%2);
		n=n/2;
	}
	for(int i = a.size() - 1; i >= 0; i--){
		cout<< a[i];
	}
	return 0;
}

