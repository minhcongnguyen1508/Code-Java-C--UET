#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct Student {
	string hoten;
	float toan, van, trungbinh;
};

void printStudents(Student students[], int n) {
	for(int i = 0; i < n; i++) {
		cout<<students[i].hoten<<" "<<students[i].trungbinh<<endl;
	}
}

int main() {
	ifstream fin;
	fin.open("students.txt");
	
	int k; 
	//cin>>k;
	fin>>k;
	
	//string hoten;
	string temp;
//	getline(cin, temp);
	getline(fin, temp);
	
	float toan, van;
	//string hoten[k];
//	float tb[k];
	Student students[k];
	
	for(int i = 0; i < k; i++){
		getline(fin, students[i].hoten);
			
		fin>>students[i].toan>>students[i].van;
		students[i].trungbinh = (students[i].toan+students[i].van)/2;
		getline(fin, temp);
	}
	
	ofstream fout;
	fout.open("out.txt");
	
	printStudents(students, k);
}
