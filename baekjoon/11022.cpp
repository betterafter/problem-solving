#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>
#include <queue>
#include <set>
#include <stack>
#include <map>
#include <string>

using namespace std;

int main(){
    
    ios::sync_with_stdio(false);
	cin.tie(NULL);
    cout.tie(NULL);

    int T; cin >> T;
    for(int i = 0; i < T; i++){
        int a, b; cin >> a >> b;
        cout << "Case #" << i + 1 << ": " << a << " + " << b << " = " << a+ b << '\n';
    }
    return 0;
}
    
    

