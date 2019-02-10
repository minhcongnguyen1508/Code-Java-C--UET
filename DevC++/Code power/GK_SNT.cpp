//
# include <iostream>
# include <algorithm>
# include <string>
# include <vector>
# include <cmath>
using namespace std;
bool SNT(int n){
	if(n == 2) return true;
	else if(n > 2){
		for(int i = 2; i <= sqrt(n); i++){
			if(n%i==0)
			return false;
		}
		return true;
	}
	return false;
}
int* test(int n, int*&p){
	switch(n){
		case 0: p[0]++; break;
		case 1: p[1]++; break;	
		case 2: p[2]++; break;
		case 3: p[3]++; break;	
		case 4: p[4]++; break;
		case 5: p[5]++; break;	
		case 6: p[6]++; break;
		case 7: p[7]++; break;	
		case 8: p[8]++; break;
		case 9: p[9]++; break;			
	}
	return p;
}
int main(){
	int a, b;
	cin>> a>> b;
	vector <int> num;
	int *p;
	p = new int [10];
	for(int i = 0; i < 10; i++)
		p[i] = 0;
	for(int i = a; i <= b; i++){
		if(SNT(i))
		num.push_back(i);
	}
	for(int i = 0; i < num.size(); i++){
		cout<< num[i]<< " ";
	}
	cout<< endl;
	for(int i = 0; i < num.size(); i++){
			int number;
			number = num[i];
			int x;
			do{
				x = number % 10;
				test(x, p);
				number = number/10;
			}while(number!=0);
	}

	for(int i = 0; i < 10; i++)
		cout<< p[i]<< " ";
	
		int index = 0;
		int max = p[index];
	for(int i = 0; i < 10; i++){
		if(p[i] > max)
		{
			index = i;
			max = p[i];
		}
	}
	cout<< endl<< "Chu so co nhieu nhat la: "<< index;
	delete []p;
	return 0;
}

