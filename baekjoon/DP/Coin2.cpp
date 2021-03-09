//
//  Coin2.cpp
//  test
//
//  Created by 신기열 on 02/06/2019.
//  Copyright © 2019 신기열. All rights reserved.
//
#include <stdio.h>
#include <iostream>
#include <math.h>
#include <algorithm>
#include <set>

using namespace std;

int main(){
    
    int N, K, coin[101], dp[100001] = { 10001, }, t = 1;
    set<int> s;
    cin >> N >> K;
    
    for(int i = 0; i < N; i++){
        int k;
        cin >> k;
        s.insert(k);
    }
    
    for(int i = 0; i <= K; i++){
        dp[i] = 10001;
    }
    
    set<int> :: iterator iter;
    for(iter = s.begin(); iter != s.end(); iter++){
        coin[t] = *iter;
        t++;
    }
    
    dp[0] = 0;
    for(int i = 1; i <= s.size(); i++){
        for(int j = coin[i]; j <= K; j++){
            dp[j] = min(dp[j], dp[j - coin[i]] + 1);
            
            //cout << coin[i] << " : " <<  dp[j] << '\n';
        }
    }
    
    
    
    
    if(dp[K] == 10001){
        dp[K] = -1;
    }
    cout << dp[K];
    
    return 0;
}
