#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>
#include <queue>
#include <set>
#include <stack>
#include <map>

using namespace std;

int main(){
    
    ios::sync_with_stdio(false);
	cin.tie(NULL);
    cout.tie(NULL);
    
    int T; cin >> T;
    for(int i = 0; i < T; i++){
        int a, b; cin >> a >> b;
        int mul = 1;
        for(int k = 0; k < b; k++){
            mul = mul * a; mul = mul % 10;
        }
        if(mul % 10 == 0) cout << 10 << '\n';
        cout << mul % 10 << '\n';
    }

    return 0;
}
    
    

