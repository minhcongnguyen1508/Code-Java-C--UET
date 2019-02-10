//
# include <iostream>
# include <algorithm>
# include <string>
# include <vector>
using namespace std;
int UCLN(int a, int b){

	if (a == b) return a;
	else if(a > b) return UCLN(a - b, b);
	else return UCLN(a, b-a);
}
int main(){
	int a, b;
	cin>> a>> b;
	
	
	if(UCLN(a,b) == 1) cout<< "YES";
	else cout<< "NO";
	return 0;
}

