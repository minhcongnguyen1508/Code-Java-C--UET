//
# include <iostream>
# include <algorithm>
# include <string>
# include <vector>
# include <cmath>
using namespace std;

int main(){
	int n;
	cin >> n;
	vector <int> a;
	do{
		int x;
		x = n % 10;
		a.push_back(x);
		n = n / 10;
		
	}while(n !=0 );
	int size = a.size();
	int index = 0;
	int value = a[index];
	for(int i = 0; i < size; i++){
		cout<< a[i]<<" ";
	}
	cout<< endl;
	bool check = false;
	do{
		for(int i = 0; i < size - 1; i++){
			if(value > a[i]){
			value = a[i];
			index = i;
			}
		}
		if(a[size - 1] <= value){
			size = size - 1;
		}
		else{
			swap(a[index], a[size-1]);
			check = true;
		}
	}while(!check);

	cout<< value <<" "<< index<<" ";
	cout<<endl;
	for(int i = 0; i < a.size(); i++){
		cout<< a[i]<<" ";
	}
	cout<< endl;
	n = 0;
	for(int i = 0; i < a.size(); i++){
		n += a[i]*pow(10, i);
	}
	cout<< n<<endl;
	return 0;
}

