#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>
#include <queue>

using namespace std;


int main(){

    while(true){
        int a[3]; cin >> a[0] >> a[1] >> a[2];
        if(a[0] == 0 && a[1] == 0 && a[2] == 0) break;
        sort(a, a + 3);
        if(a[0] * a[0] + a[1] * a[1] == a[2] * a[2]) cout << "right" << '\n';
        else cout << "wrong" << '\n';
    }
    return 0;
}
