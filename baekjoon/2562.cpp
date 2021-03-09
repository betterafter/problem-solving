#include <iostream>
#include <algorithm>
#include <math.h>

using namespace std;

int main(){
    int n = 0, idx;
    for(int i = 1; i <= 9; i++){
        int a; cin >> a;
        if(n < a){
            n = a; idx = i;
        }
    }
    cout << n << '\n' << idx;
    return 0;
}