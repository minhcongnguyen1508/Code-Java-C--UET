//
# include <iostream>
# include <algorithm>
# include <string>
# include <vector>
using namespace std;

int main(){
	int m, n;
	cin>> m>> n;
	char a[m][n];
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			cin>> a[i][j];
		}
	}
	return 0;
}

