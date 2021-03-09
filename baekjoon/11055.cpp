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

    int v[1001] = { 0, };
    int dp[1001] = { 0, };

    int N; cin >> N;
    for(int i = 1; i <= N; i++){
        cin >> v[i];
        dp[i] = v[i];
    }   
    int res = dp[1];
    for(int i = 2; i <= N; i++){
        for(int j = 1; j < i; j++){
            if(v[i] > v[j]){
                dp[i] = max(dp[i], dp[j] + v[i]);
                res = max(dp[i], res);
            }
        }
    }
    // for(int i = 1; i <= N; i++){
    //     cout << dp[i] << " ";
    // }

    cout << res;
    return 0;
}

