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
    
    int N, M; cin >> N >> M;
    int m[1001][1001] = { 0, };
    int dp[1001][1001] = { 0, };
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= M; j++){
            cin >> m[i][j];
        }
    }
    dp[1][1] = m[1][1];
    for(int i = 2; i <= M; i++){
        dp[1][i] = dp[1][i - 1] + m[1][i];
    }
    for(int i = 2; i <= N; i++){
        dp[i][1] = dp[i - 1][1] + m[i][1];
    }
    for(int i = 2; i <= N; i++){
        for(int j = 2; j <= M; j++){
            dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            dp[i][j] = max(dp[i][j], dp[i - 1][j - 1]);
            dp[i][j] += m[i][j];
        }
    }
    
    cout << dp[N][M];
    return 0;
}
    
    

