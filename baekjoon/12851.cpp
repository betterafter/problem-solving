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

    int dp[300001] = { INT_MAX, };
    int cnt[300001] = { INT_MAX, };

    for(int i = 0; i < 200001; i++){
        dp[i] = INT_MAX; cnt[i] = INT_MAX;
    }

    int N, K; cin >> N >> K;

    dp[N] = 0; cnt[N] = 1;
    queue<pair<int, int> > q; q.push(make_pair(N, 0));
    while(!q.empty()){
        int curr = q.front().first, cost = q.front().second; q.pop();
        
        if(curr + 1 <= K * 2){
            if(dp[curr + 1] == dp[curr] + 1) cnt[curr + 1] += cnt[curr];
            else if(dp[curr + 1] > dp[curr] + 1){
                dp[curr + 1] = dp[curr] + 1; cnt[curr + 1] = cnt[curr]; q.push(make_pair(curr + 1, cost + 1));
            }
        }

        if(curr - 1 >= 0){
            if(dp[curr - 1] == dp[curr] + 1) cnt[curr - 1] += cnt[curr];
            else if(dp[curr - 1] > dp[curr] + 1){
                dp[curr - 1] = dp[curr] + 1; cnt[curr - 1] = cnt[curr]; q.push(make_pair(curr - 1, cost + 1));
            }
        }
        if(curr * 2 <= K * 2){
            if(dp[curr * 2] == dp[curr] + 1) cnt[curr * 2] += cnt[curr];
            else if(dp[curr * 2] > dp[curr] + 1){
                dp[curr * 2] = dp[curr] + 1; cnt[curr * 2] = cnt[curr]; q.push(make_pair(curr * 2, cost + 1));
            }
        }
    }
   
    cout << dp[K] << '\n' << cnt[K];
    return 0;
}

