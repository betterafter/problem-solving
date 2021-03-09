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

int MAX = 100000000;
int dp[101][101];
int n, m;

void floyd(){
    for(int k = 1; k <= n; k++){
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
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

    cin >> n >> m;

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(i == j) dp[i][j] = 0;
            else dp[i][j] = MAX;
        }
    }

    for(int i = 0; i < m; i++){
        int a, b, c; cin >> a >> b >> c;
        dp[a][b] = min(dp[a][b], c);
    }
    floyd();
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(dp[i][j] == MAX) cout << 0 << " ";
            else cout << dp[i][j] << " "; 
        }
        cout << '\n';
    }
    return 0;
}

