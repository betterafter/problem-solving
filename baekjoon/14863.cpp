//
//  14863.cpp
//  test
//
//  Created by 신기열 on 30/06/2019.
//  Copyright © 2019 신기열. All rights reserved.
//
#include <stdio.h>
#include <algorithm>
#include <math.h>
#include <iostream>
#include <vector>

using namespace std;

int Walk[100001][2], Cycle[100001][2], DP[101][100001];
int visit[101][100001];
int N, K;

int main(){
    
    cin >> N >> K;
    
    for(int i = 1; i <= N; i++){
        cin >> Walk[i][0] >> Walk[i][1] >> Cycle[i][0] >> Cycle[i][1];
    }

    DP[1][Walk[1][0]] = max(DP[1][Walk[1][0]], Walk[1][1]);
    DP[1][Cycle[1][0]] = max(DP[1][Cycle[1][0]], Cycle[1][1]);
    
    visit[1][Walk[1][0]] = 1; visit[1][Cycle[1][0]] = 1;
    
    for(int i = 2; i <= N; i++){
        for(int j = 1; j <= K; j++){
            if(visit[i - 1][j] == 1 && j + Walk[i][0] <= K){
                
                DP[i][j + Walk[i][0]] = max(DP[i][j + Walk[i][0]], DP[i - 1][j] + Walk[i][1]);
                visit[i][j + Walk[i][0]] = 1;
            }
            if(visit[i - 1][j] == 1 && j + Cycle[i][0] <= K){
                
                DP[i][j + Cycle[i][0]] = max(DP[i][j + Cycle[i][0]], DP[i - 1][j] + Cycle[i][1]);
                visit[i][j + Cycle[i][0]] = 1;
            }
        }
    }

    int ans = 0;
    for(int i = K; i >= 0; i--){
        if(DP[N][i] != 0){ ans = max(ans, DP[N][i]); }
    }
    
    cout << ans;
    return 0;
}
