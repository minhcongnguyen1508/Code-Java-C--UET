//
# include <iostream>
# include <algorithm>
# include <string>
# include <vector>
using namespace std;
struct capso{
	int a;
	int b;
	void input(){
		cin>> a >> b;
	}
};
long long giaithua(int n){
	if(n <= 1)
	return 1;
	else
	return n*giaithua(n-1);
}
long long tohop(int n, int k){
	return giaithua(n)/(giaithua(k)*giaithua(n-k));
}
int main(){
	vector <capso> a;
	capso x;
	x.input();
	while(x.a != -1 && x.b != -1){
		a.push_back(x);
		x.input();
	}
	for(int i = 0; i < a.size(); i++){
		cout<< tohop(a[i].a, a[i].b)<<endl;
	}
	return 0;
}

