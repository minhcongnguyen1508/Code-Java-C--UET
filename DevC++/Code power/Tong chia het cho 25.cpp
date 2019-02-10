#include <iostream>
#include <cmath>
#include <ctime>
#include <cstdlib>
using namespace std;

int* genNumbers(int n){
	int *a;
	a = new int [n];
	for(int i = 0; i < n; i++){
		a[i] = rand() % 49 + 0;
	}
	for(int i = 0; i < n; i++){
		for(int j = i; j< n; j++){
			if(a[i] > a[j]) swap(a[i], a[j]);
		}
	}
	return a;
}
void printNumbers(int *a, int n){
	for(int i = 0; i < n; i++){
		cout<< a[i]<< " ";
	}
	cout<< endl;
		for(int i = 0; i < n-2; i++){
			for(int j = i+1; j < n-1; j++){
				for(int k = j+1; k < n; k++){
					if((a[i] + a[j] + a[k]) % 25 == 0)
					cout<< a[i]<<" "<< a[j]<< " "<< a[k]<<endl;
				}
			}
		}
}

int main() {
    int seed = 1; //Test cases use different seed numbers 
    srand(seed);
    int n;
    cin >> n;
    int *a = genNumbers(n);
    printNumbers(a, n);
    delete []a;
}
