//
# include <iostream>
# include <algorithm>
# include <string>
# include <vector>
# include <ctime>
using namespace std;
void input(int a[], int n);
void print(int a[], int n);
void insert(int a[], int n);
void select(int a[], int n);
void buble(int a[], int n);
void mergeSort(int a[], int n, int m);
void merge(int a[], int n, int m, int c);
int main(){
	srand(time(NULL));
	int a[10];
	input(a, 10);
	print(a, 10);
	mergeSort(a, 0, 9);
	print(a, 10);

	return 0;
}
void input(int a[], int n)
{
	for(int i = 0; i < 10; i++){
		int x;
		x = rand()%10+1;
		a[i] = x;
	}
}
void print(int a[], int n)
{
	for(int i = 0; i < n; i++){
		cout<< a[i]<< " ";
	}
	cout<< endl<<endl;
}
void insert(int a[], int n)
{
	for(int i = 1; i < n; i++){
		for(int k = i; k > 0; k--){
			if(a[k] <  a[k-1]){
				swap(a[k], a[k-1]);
			}
			else
				break;
		}
	}
}
void select(int a[], int n)
{
	for(int i = 0; i < n - 1; i++){
		for(int j = i+1; j < n; j++){
			if(a[i]>a[j]){
				swap(a[i], a[j]);
			}
		}
	}
}
void buble(int a[], int n)
{
	bool sorted;
	int k = n - 1;
	do{
		sorted = true;
		for(int i = 0; i < k; i++){
			if(a[i] > a[i+1]){
				swap(a[i], a[i+1]);
				sorted = false;
			}
		}
		k--;
	}while(!sorted);
}
void mergeSort(int a[], int n, int m){
	if(n < m){
		int c = (n+m)/2;
		mergeSort(a, n, c);
		mergeSort(a, c+1, m);
		merge(a, n, m, c);
	}
}
void merge(int a[], int n, int m, int c){
	int i = n;
	int j = c + 1;
	int k = m - n + 1;
	int t = 0;
	int *b = new int [k];
	while(i <= c  && j <= m){
		if(a[i] > a[j]){
			b[t++] = a[j++];
		}
		else
			b[t++] = a[i++];
	}
	while(i < c + 1){
		b[t++] = a[i++];
	}
	while(j < m + 1){
		b[t++] = a[j++];
	}
	i = n;
	for(t = 0; t < k; t++){
		a[i++] = b[t];
	}
	delete []b;
}
