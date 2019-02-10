#include <iostream>
#include <stack>
#include <queue>
#include <string>

using namespace std;


void removeStack(stack<int> s) {
    if(s.empty()) return;
    else {
        s.pop();
        removeStack(s);
    }
}

// [{(}}]

bool isOpenParenthesis(char c) {
    if(c == '[' || c == '{' || c == '(')
        return true;
    return false;
}

bool kiemTraBoNgoac(char open, char close) {
    if(close == ')' && open == '(')
        return true;
    else if(close == '}' && open == '{')
        return true;
    else if(close == ']' && open == '[')
        return true;
    return false;
}

bool kiemTraNgoac(string s) {
    stack<char> moNgoac;
    for(int i = 0; i < s.length(); i++) {
        if(isOpenParenthesis(s[i]) {
            moNgoac.push(s[i]);
        } else {
            if(moNgoac.empty()) {
                return false;
            } else {
                if(kiemTraBoNgoac(moNgoac.top(), s[i])) {
                    moNgoac.pop();
                } else {
                    return false;
                }
            }
        }
    }

    return moNgoac.empty();
}

int main() {
//    int n;
//    cin>>n;
//    stack<int> mystack;
//    queue<int> myqueue;
//    int temp, x;
//    for(int i = 0; i < n; i++) {
//        cin>>temp;
//        mystack.push(x);
//    }
//    int x; cin>>x;
//
//    bool check = false;
//
//    while(!mystack.empty()) {
//        if(mystack.top() == x) {
//            cout<<"YES"<<endl;
//            check = true;
//        } else {
//            myqueue.push(mystack.top());
//            mystack.pop();
//        }
//    }
//
//    if(!check) {
//        cout<<"NO"<<endl;
//    }
//
//    while(!myqueue.empty()) {
//        mystack.push(myqueue.front());
//        myqueue.pop();
//    }
//
//    while(!mystack.empty()) {
//        if(mystack.top() != x) {
//            myqueue.push(mystack.top());
//            mystack.pop();
//        }
//    }
//
//    while(!myqueue.empty()) {
//        mystack.push(myqueue.front());
//        myqueue.pop();
//    }

    string s;
    getline(cin, s);
    if(kiemTraNgoac(s)){
        cout<<"YES"<<endl;
    } else {
        cout<<"NO"<<endl;
    }
}
