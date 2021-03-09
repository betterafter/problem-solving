#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>
#include <queue>
#include <set>
#include <stack>

using namespace std;




int main(){

    ios::sync_with_stdio(false);
	cin.tie(NULL);
    cout.tie(NULL);

    int N; cin >> N;
    int DP[50001] = { 0, };
    int mul[224];
    for(int i = 1; i <= 223; i++){
        mul[i] = i * i;
    }
    DP[1] = 1;
    for(int i = 2; i <= N; i++){

        int res = 999999999;
        for(int j = 1; j <= sqrt(i); j++){
            res = min(res, DP[i - mul[j]]);
        }
        DP[i] = res + 1;
    }
    cout << DP[N];
    return 0;
}
