//
# include <iostream>
# include <algorithm>
# include <string>
# include <vector>
using namespace std;
struct toado{
	int x;
	int y;
};
bool set(const toado a, const toado b){
	if(a.x == b.x || a.y == b.y || abs(a.x - b.x) == abs(a.y - b.y))
		return true;
	else
		return false;
}
int main(){
	int n;
	cin>> n;
	toado a[n];
	for(int  i=0; i<n; i++){
		cin>> a[i].x>>a[i].y;
	}
	int count=0;
	for(int i=0; i<n; i++){
		for(int j=i+1; j<n; j++){
			if(set(a[i], a[j]))
			count++;
		}
	}
	if(count != 0) cout<< "yes";
	else cout<< "no";
	return 0;
}

