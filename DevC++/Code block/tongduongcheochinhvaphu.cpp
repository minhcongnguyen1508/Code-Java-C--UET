//
# include <iostream>
# include <algorithm>
# include <ctime>
# include <iomanip>
using namespace std;

int main(){
	srand(time(NULL));
	int n;
	cin >> n;
	int x;
	int sumc = 0, sump = 0;
	int j = 1, k = n;
	for(int i = 1; i <= n*n; i++){
		x = rand()%10+1;
		if(i == j){
			sumc += x;
			j += (n + 1);
		}
		if(i == k && i < n*n){
			sump += x;
			k += (n - 1);
		}	
	}
	cout<< abs(sumc-sump)<< " "<< sumc<<" "<< sump;
	return 0;
}

