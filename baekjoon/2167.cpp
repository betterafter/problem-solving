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

    int m[301][301] = { 0, };
    int dp[301][301] = { 0, };
    int N, M; cin >> N >> M;
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= M; j++){
            cin >> m[i][j];
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1] + m[i][j];
        }
    }

    int K; cin >> K;
    for(int i = 0; i < K; i++){
        int ii, jj, xx, yy; cin >> ii >> jj >> yy >> xx;
        cout << dp[yy][xx] - dp[ii - 1][xx] - dp[yy][jj - 1] + dp[ii - 1][jj - 1] << '\n';
    }

    
    return 0;
}

