#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <math.h>

using namespace std;

int main(){

    while(true){
        string a; cin >> a;
        if(a == "0") break;
        bool t = true;
        for(int i = 0; i < a.size() / 2; i++){
            if(a[i] != a[a.size() - i - 1]){
                cout << "no" << '\n'; t = false; break;
            }
        }
        if(t) cout << "yes" << '\n';
        
    }
    return 0;
}
