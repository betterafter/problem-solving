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

int n, m, r;
int item[101];
int dp[101][101];
int MAX = 987654321;

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

void print(){
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cout << dp[i][j] << " ";
        }
        cout << '\n';
    }

}

int main(){

    ios::sync_with_stdio(false);
	cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m >> r;

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(i == j) dp[i][j] = 0;
            else dp[i][j] = MAX;
        }
    }
    
    for(int i = 1; i <= n; i++){
        cin >> item[i];
    }
    for(int i = 0; i < r; i++){
        int a, b, c; cin >> a >> b >> c;
        dp[a][b] = min(dp[a][b], c);
        dp[b][a] = min(dp[b][a], c);
    }
    
    floyd();
    //print();
    
    int ans = 0;
    for(int i = 1; i <= n; i++){
        int sum = 0;
        for(int j = 1; j <= n; j++){
            if(dp[i][j] >= 0 && dp[i][j] <= m){
                sum += item[j];
            }
        }
        ans = max(ans, sum);
    }
    cout << ans;
    return 0;
}

