//
# include <iostream>
# include <algorithm>
# include <string>
# include <vector>
using namespace std;

int main(){
	int n;
	cin>> n;
	string a[n];
	for(int i=0; i<n; i++){
		cin>> a[i];
	}
	int count = 0;
	for(int i = 0; i < n - 1; i++){
		for(int j = i+1; i < n; j++){
			if(a[i].length() == a[j].length()){

				int m = 0, n = a[i].length()-1;
				for(int k = 0; k < a[i].length() ; k++){
					if(a[i][m++]!=a[j][n--])
						break;
					else count++;
				}
			}
		}
	}
	return 0;
}

