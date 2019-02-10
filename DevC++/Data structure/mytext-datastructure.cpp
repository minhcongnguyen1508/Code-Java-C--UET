//
# include <iostream>
# include <algorithm>
# include <string>
# include <vector>
# include <stack>
using namespace std;
class mytext{
	private:
		string stringStart;
		stack <string> stringted;
	public:
		mytext(){
			stringStart = "";
			stringted.push(stringStart);
		}
		string append(string st){
			stringStart += st;
			stringted.push(stringStart);
			
			return stringStart;
		}
		string deleted(int k){
			for(int i = stringStart.length() - 1; i >= stringStart.length() - k ; i--){
				stringStart[i] = '\0';
			}
			stringted.push(stringStart);
			return stringStart;
		}
		char print(int k){
			return stringStart[k-1];
		}
		string undo(){
			if(!stringted.empty()){
				stringted.pop();
				return stringted.top();
			}
		}
		void printf(){
			cout<< stringStart<<endl;
		}
};
int main(){
	mytext stringStarted;
	string x;
	cin>> x;
	stringStarted.append(x);
	stringStarted.deleted(3);
	stringStarted.append("+demo+");
	stringStarted.printf();

	cout<< stringStarted.print(3)<< endl;
	stringStarted.printf();
	stringStarted.undo();
	stringStarted.undo();
	stringStarted.printf();
	return 0;
}

