//
//  Leave.cpp
//  test
//
//  Created by 신기열 on 31/05/2019.
//  Copyright © 2019 신기열. All rights reserved.
//
#include <stdio.h>
#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    
    int n, T, P, dp[16] = { 0, }, ans = 0;
    cin >> n;
    vector<pair<int, int> > work;
    
    for(int i = 0; i < n; i++){
        cin >> T >> P;
        work.push_back(make_pair(T, P));
    }

    dp[1] = work[0].second;
    if(work[0].first == 1) ans = dp[1];
    
    for(int i = 2; i <= n; i++){
        
        int prev = 0;
        for(int j = 0; j < i; j++){
            if(j + work[j].first < i){
                prev = max(prev, dp[j + 1]);
            }
        }
        if(work[i - 1].first + i - 1 <= n){
            dp[i] = work[i - 1].second + prev;
        }
        else{
            dp[i] = prev;
        }
        ans = max(ans, dp[i]);
    }
    
    cout << ans;
    
    return 0;
}


