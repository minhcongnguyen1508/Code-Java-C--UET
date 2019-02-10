//
# include <iostream>
# include <algorithm>
# include <string>
# include <vector>
# include <stack>
# include <cmath>
using namespace std;

int main(){
	string st;
	cin>> st;
	vector <int> n;
	stack <int> a;
	for(int i = 0; i < st.length(); i++){
		if((int)st[i] >= 48 && (int)st[i] <= 57){
			n.push_back((int)st[i] - 48);
		}else{
			n.push_back(-1);
		}
	}
	vector <int> b;
	{
		for(int i = n.size()-1; i >= 0; i--){
			if(n[i] == -1){
				if(a.empty())
				continue;
				else{
					int sum = 0;
					while(!a.empty()){
					sum += a.top()*pow(10, a.size()-1);
					a.pop();	
					}
					b.push_back(sum);
				}		
			}	
			else{
				a.push(n[i]);	
			}
		}
	}
	for(int i = 0; i < n.size(); i++){
			cout<< n[i]<<" ";
		}
		cout<< endl;
	for(int i = 0; i < b.size(); i++){
			cout<< b[i]<<" ";
		}
	return 0;
}

