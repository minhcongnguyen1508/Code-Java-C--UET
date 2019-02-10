//
# include <iostream>
# include <algorithm>
# include <string>
# include <vector>
using namespace std;

int main(){
	string s;
	cin>> s;
	vector <string> st;
	vector <int> st1;
	for(int i = 0; i < s.length() - 1; i++){
		for(int j = i + 1; j < s.length(); j++){
			swap(s[i], s[j]);
			st.push_back(s);
			swap(s[i], s[j]);
		}
	}
	for(int i = 0; i < st.size(); i++){
		st1.push_back(atoi(st[i].c_str()));
	}
	sort(st1.begin(), st1.end());
	for(int i = 0; i < st.size(); i++){
		cout<< st1[i]<< endl;
	}
	
	return 0;
}

