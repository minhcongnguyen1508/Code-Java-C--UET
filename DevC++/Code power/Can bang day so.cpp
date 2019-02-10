//
# include <iostream>
# include <algorithm>
# include <string>
# include <vector>
using namespace std;

int main(){
	vector <int> a;
	int n, x;
	cin>> n;
	for(int i = 0; i < n; i++){
		cin>> x;
		a.push_back(x);
	}
	
	sort(a.begin(), a.end());
	
	int max = 0, begin = 0, end = 0;
	for(int i = 0; i < n; i++){
		if(a[i] != a[i+1]){
			if(max < (i + 1 - begin)){
				max = i + 1 - begin;
				
			}
			begin = i + 1;
		}
	}
	cout<< n - max;
	return 0;
}

