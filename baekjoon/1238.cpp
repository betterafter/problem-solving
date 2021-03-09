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
#include <bitset>

using namespace std;

int N, M, X;
long long m[1001][1001];
long long dp[1001][1001];

void floyd(){
    for(int k = 1; k <= N; k++){
        for(int i = 1; i <= N; i++){
            for(int j = 1; j <= N; j++){
                if(dp[i][j] > dp[i][k] + dp[k][j]){
                    dp[i][j] = dp[i][k] + dp[k][j];
                }
            }
        }
    }
}

int main(){

    ios::sync_with_stdio(false);
	cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M >> X;

    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            if(i == j) dp[i][j] = 0;
            else dp[i][j] = INT_MAX;
        }
    }

    for(int i = 0; i < M; i++){
        int a, b, c; cin >> a >> b >> c;
        dp[a][b] = min((int)dp[a][b], c);
    }
    floyd();
    int ans = 0;
    for(int i = 1; i <= N; i++){
        if(dp[i][X] < INT_MAX && dp[X][i] < INT_MAX){
            ans = max(ans, (int)dp[i][X] + (int)dp[X][i]);
        }
    }

    // for(int i = 1; i <= N; i++){
    //     for(int j = 1; j <= N; j++){
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << '\n';
    // }

    cout << ans; 
    return 0;
}

