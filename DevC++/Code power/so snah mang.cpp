#include <iostream>
using namespace std;

bool eq(int arr1[], int arr2[], int n){
    int count = 0;
    for(int i = 0; i < n; i++){
        if(arr1[i] != arr2[i])
        count++;
    }
    if(count != 0)
    return false;
    return true;
}

int main() {
    int n; cin>>n;
    int arr1[n], arr2[n];
    for(int i = 0; i < n; i++) {
        cin>>arr1[i];
    }

    for(int i = 0; i < n; i++) {
        cin>>arr2[i];
    }

    bool result = eq(arr1, arr2, n);
    if(result) {
        cout<<"true";
    } else {
        cout<<"false";
    }
    return 0;
}
