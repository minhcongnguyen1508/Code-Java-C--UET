# include <iostream>
# include <algorithm>
# include <string>
# include <vector>
using namespace std;

int main(){
	int a1, b1, c1, a2, b2, c2;
	cin>> a1>> b1>> c1 >> a2>> b2>> c2;
	if((a1 == 0 && a2 == 0))
	cout<< "Vo nghiem";
	else if((a1 == 0 && b1==0 && c1==0) || ((b1*a2/a1 - b2 == 0) && (c1*a2/a1 - c2 == 0)) || ((b1*a2/a1 - b2 != 0) && (c1*a2/a1 - c2 == 0)))
	cout<< "Vo so nghiem";
	else if(((b1*a2/a1 - b2 == 0) && (c1*a2/a1 - c2 != 0)))
	cout<< "Vo nghiem";
	else
	cout<< "x = "<< (c1*b2*a1-b1*c2*a1)/(a1*a1*b2-a1*a2*b1)<<", y = "<< (c2*a1-a2*c1)/(b2*a1-a2*b1);
	return 0;
}


