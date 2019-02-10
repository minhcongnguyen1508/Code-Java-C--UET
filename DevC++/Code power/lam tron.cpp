//
# include <iostream>
# include <algorithm>
# include <string>
# include <vector>
using namespace std;
int rnd(double a){
	if(a < 0){
		a = -a;
			if((a-(int)a) < 0.5)
				return  -(int)a;
			else return -(int)a-1;
	}
	else{
			if((a-(int)a) < 0.5)
			return  (int)a;
			else return (int)a+1;
	}
}
int main(){
	double a;
	cin>> a;
	cout<< rnd(a);
	return 0;
}

