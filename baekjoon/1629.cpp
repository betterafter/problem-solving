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

unsigned long long check(int A, int B, int C){
    if(B == 0) return 1;
    if(B == 1) return A;
    if(B % 2 != 0){
        return check(A, B - 1, C) * A;
    }
    return ((check(A, B / 2, C) % C) * (check(A, B / 2, C) % C)) % C;
}

int main(){

    ios::sync_with_stdio(false);
	cin.tie(NULL);
    cout.tie(NULL);

    unsigned long long A, B, C; cin >> A >> B >> C;
    // for(int i = 0; i < B; i++){
    //     res *= A; res %= C;
    // }
    
    cout << check(A, B, C) % C;
    return 0;
}
