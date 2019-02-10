//
# include <iostream>
# include <algorithm>
# include <string>
# include <vector>
using namespace std;

int main(){
    
    int a =- 7, b =- 7, c = 7, d = 7, e;
    e = d++ || a++ && b++;
    printf("%d %d %d %d %d", a, b, c, d, e);
}

