//
# include <iostream>
# include <algorithm>
# include <string>
# include <vector>
using namespace std;
void printRow(int m, int n){
    for(int i = 0; i < m/2; i++){
        cout<< " ";
    }
    for(int i = 0; i < n; i++){
    	cout<< "*";
	}
	for(int i = 0; i < m/2; i++){
        cout<< " ";
    }
}
int main(){
	int num;
	cin>> num;
	int m = num*2 - 2;
	int n = 1;

	for(int i = 0; i<num; i++){
		printRow(m, n);
		cout<< endl;
		m -= 2;
		n += 2;
	}
	return 0;
}

