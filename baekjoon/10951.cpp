#include <iostream>
#include <algorithm>
#include <math.h>

using namespace std;

int main(){
    int a, b;
    while(true){
        cin >> a >> b;
        if(cin.eof()) break;
        cout << a + b << '\n';
    }
    return 0;

}