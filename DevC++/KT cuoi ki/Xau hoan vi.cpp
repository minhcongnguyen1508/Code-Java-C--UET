//
# include <iostream>
# include <algorithm>
# include <string>
# include <vector>
using namespace std;

int main(){
	string st1;
	string st2;
	cin >> st1>> st2;

	for(int i = 0; i < st1.length(); i++){
		for(int j = 0; j< st2.length(); j++){
			if(st1[i] == st2[j]){
				st1[i] = '.';
				st2[j] = '.';
			}
		}
	}
	if(st1 == st2)
		cout<< "YES";
	else
		cout<< "NO";
	return 0;
}

