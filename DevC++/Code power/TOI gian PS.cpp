//
# include <iostream>
# include <algorithm>
# include <string>
# include <vector>
using namespace std;
int UC(int a, int b){
	if(a < 0 && b > 0){
		a = -a;
		if(a==b) return a;
		else if(a > b) return UC(a-b, b);
		else return UC(a, b-a);
	}
	else if (a > 0 && b < 0){
			b = -b;
		if(a==b) return a;
		else if(a > b) return UC(a-b, b);
		else return UC(a, b-a);
	}
	else
	{
		if(a==b) return a;
		else if(a > b) return UC(a-b, b);
		else return UC(a, b-a);
	}
	
}
int main(){
	int a, b, temp;
	cin>> a>> b;
	temp = UC(a,b);
	a = a/temp;
	b = b/temp;
	if( b== 1 || b==-1)
	cout<< a;
	else if(a < 0 && b < 0){
		a = -a;
		b = -b;
		cout<< a<<"/"<< b;
	}
	else if(a > 0 && b < 0){
		b = -b;
		a = -a;
		cout<< a<<"/"<< b;
	}
	else
		cout<< a<<"/"<< b;
	return 0;
}

