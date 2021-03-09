#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>
#include <queue>
#include <set>
#include <stack>
#include <map>
#include <limits.h>

using namespace std;

int D;

int main(){

    ios::sync_with_stdio(false);
	cin.tie(NULL);
    cout.tie(NULL);

    cin >> D;
    long long dp[8] = { 1, 0, 0, 0, 0, 0, 0, 0 };
    for(int i = 1; i <= D; i++){
        long long t[8] = { 0, 0, 0, 0, 0, 0, 0, 0 };
        t[0] = dp[1] + dp[2];
        t[1] = dp[0] + dp[2] + dp[3];
        t[2] = dp[0] + dp[1] + dp[3] + dp[4];
        t[3] = dp[1] + dp[2] + dp[4] + dp[5];
        t[4] = dp[2] + dp[3] + dp[5] + dp[7];
        t[5] = dp[3] + dp[4] + dp[6]; 
        t[6] = dp[5] + dp[7];
        t[7] = dp[4] + dp[6];

        for(int i = 0; i <= 7; i++){
            dp[i] = t[i] % 1000000007;
            //cout << dp[i] << " ";
        }
       // cout << '\n';

    }

    cout << dp[0] % 1000000007;
    return 0;
}

