#include <iostream>
#include <algorithm>
#include <math.h>

using namespace std;

int main(){

    int n; cin >> n;
    int m = 1000000, M = -1000000;
    for(int i = 0; i < n; i++){
        int a; cin >> a;
        m = min(m, a);
        M = max(M, a);
    }


    cout << m << " " << M;
    return 0;

}