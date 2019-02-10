//
# include <iostream>
# include <algorithm>
# include <string>
# include <vector>
using namespace std;
int bcnn(int a, int b);
bool test(vector <int> b, int m, int a);
int main(){
	int n, m, x;
	cin>> n>> m;
	vector <int> a;
	vector <int> b;
	for(int i = 0; i < n; i++){
		cin>> x;
		a.push_back(x);
	}
	for(int i = 0; i < m; i++){
		cin>> x;
		b.push_back(x);	
	}
	for(int i = 0; i < n-1; i++){
		a[i+1] = bcnn(a[i], a[i+1]);
	}// bcnn of array = a[n-1]
	int count1 = 1, count2 = 1;
	sort(b.begin(), b.end());
	while(a[n-1]*count2 <= b[0]){
		if(test(b, m, (a[n-1]*count2)))
		count1++;
		count2++;
	}
	cout<< count1-1;
	return 0;
}
int bcnn(int a, int b){
	int i=1;
	if(a > b){
		while(a*i % b != 0){
			i++;
		}
		return a*i;
	}
	else{
		while(b*i % a != 0){
			i++;
		}
		return b*i;
	}
}
bool test(vector <int> b, int m, int a){
		for(int i = 0; i < m; i++){
			if(b[i] % (a) != 0)
			return false;
		}
		return true;
		
}
