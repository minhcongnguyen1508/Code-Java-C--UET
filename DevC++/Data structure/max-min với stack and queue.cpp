//
# include <iostream>
# include <algorithm>
# include <string>
# include <vector>
# include <stack>
# include <queue>
using namespace std;
int isMax(int a, int b){
	if(a >= b) return a;
	return b;
}
int isMin(int a, int b){
	if(a >= b) return b;
	return a;
}
int main(){
	int n;
	cin>> n;
	vector <int> a;
	int x;
	stack <int> b;
	queue <int> c;
	for(int i = 0; i < n; i++){
		cin>> x;
		a.push_back(x);
	}
	for(int i = 0; i < n; i++){
		b.push(a[i]); // set stack	
		c.push(a[i]); // set queue
	}
	int max, min;
	max =  b.top();
	min =  b.top();
	while(!c.empty()){
		if(max < isMax(b.top(), c.front()))
		max = isMax(b.top(), c.front());
		if(min > isMin(b.top(), c.front()))
		min = isMin(b.top(), c.front()); 
		c.pop();
	}
	cout<< "Max = "<< max<<endl;
	cout<< "Min = "<< min<<endl;
	return 0;
}

