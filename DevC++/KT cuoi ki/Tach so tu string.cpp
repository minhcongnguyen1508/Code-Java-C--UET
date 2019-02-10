//
# include <iostream>
# include <algorithm>
# include <string>
# include <vector>
#include <cstdlib> 
using namespace std;

int main(){
	string a;
	cin>> a;
	vector <int> st;
	for(int i = 0; i<a.length(); i++){
		if(48 <= (int)a[i] && (int)a[i] <= 57){
				st.push_back((int)a[i]-48);
		}
		
	}
	for(int i = 0; i<st.size(); i++){
		cout<< st[i]<<" ";
	}
	
	
	return 0;
}

