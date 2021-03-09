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

int main(){

    ios::sync_with_stdio(false);
	cin.tie(NULL);
    cout.tie(NULL);

    int n; cin >> n;
    int dp[1000001] = { 0, };
    for(int i = 0; i < n; i++){
        dp[i] = 987654321;
    }
    int res[1000001] = { 0, };
    
    queue<int> q; q.push(n);
    while(!q.empty()){
        int x = q.front(); q.pop();
        if(x % 3 == 0){
            if(dp[x / 3] > dp[x] + 1){
                dp[x / 3] = dp[x] + 1;
                res[x / 3] = x;
                q.push(x / 3);
            }
        }
        if(x % 2 == 0){
            if(dp[x / 2] > dp[x] + 1){
                dp[x / 2] = dp[x] + 1;
                res[x / 2] = x;
                q.push(x / 2);
            }
        }
        if(dp[x - 1] > dp[x] + 1){
            dp[x - 1] = dp[x] + 1;
            res[x - 1] = x;
            q.push(x - 1);
        }
    }


    // cout << "dp " << '\n';
    // for(int i = 1; i <= n; i++){
    //     cout << dp[i] << " ";
    // }
    // cout << '\n';

    // cout << "Res " << '\n';
    // for(int i = 1; i <= n; i++){
    //     cout << res[i] << " ";
    // }
    // cout << '\n';

    cout << dp[1] << '\n';
    int x = 1; vector<int> resv; 
    while(x != n){
        resv.push_back(x);
        x = res[x];
    }
    resv.push_back(n);
    for(int i = resv.size() - 1; i >= 0; i--){
        cout << resv[i] << " ";
    }
    return 0;
}

