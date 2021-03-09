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

pair<int, pair<int, int> > dp[1011][1011];

int main(){

    ios::sync_with_stdio(false);
	cin.tie(NULL);
    cout.tie(NULL);

    string s1, s2; cin >> s1 >> s2; 
    for(int i = 0; i <= 1001; i++){
        for(int j = 0; j <= 1001; j++){
            dp[i][j] = make_pair(0, make_pair(0, 0));
        }
    }
    

    for(int i = 0; i < s2.size(); i++){
        for(int j = 0; j < s1.size(); j++){
            if(s2[i] != s1[j]){
                dp[i + 1][j + 1].first = max(dp[i][j].first, dp[i + 1][j].first);
            }
            else if(s2[i] == s1[j]){
                if(dp[i + 1][j + 1].first > dp[i + 1][j].first){
                    dp[i + 1][j + 1].first = dp[i][j].first + 1;    
                    dp[i + 1][j + 1].second = make_pair(i, j);
                }
                else{
                    dp[i + 1][j + 1].first = dp[i + 1][j].first + 1;    
                    dp[i + 1][j + 1].second = make_pair(i + 1, j);
                }
            }
        }
    }
    for(int i = 0; i < s2.size(); i++){
        for(int j = 0; j < s1.size(); j++){
            cout << dp[i + 1][j + 1].first << " ";
        }
        cout << '\n';
    }
    return 0;
}

