//
//  Coin1.cpp
//  test
//
//  Created by 신기열 on 31/05/2019.
//  Copyright © 2019 신기열. All rights reserved.
//
#include <stdio.h>
#include <iostream>
#include <math.h>
#include <algorithm>

using namespace std;

int main(){
    
    int N, K, coin[101], dp[100001] = { 1, };
    cin >> N >> K;
    
    for(int i = 1; i <= N; i++){
        cin >> coin[i];
    }
    
    for(int i = 1; i <= N; i++){
        for(int j = coin[i]; j <= K; j++){
            dp[j] += dp[j - coin[i]];
        }
    }
    
    cout << dp[K];
    return 0;
}


// ex) 11 18 27
// dp[11] += dp[11 - 11];               dp[11] += dp[11 - 18];
// dp[12] += dp[12 - 11];               dp[12] += dp[12 - 18];
// dp[13] += dp[13 - 11];               ...
// ...                                  ...
// dp[18] += dp[18 - 11];               dp[18] += dp[18 - 18];
// ...
// dp[22] += dp[22 - 11];

// dp[K] = dp[K-11] + dp[K-18] + dp[K-27]을 구하면 된다.

// 나머지 것들이 뭘로 채워지든 우리는 11 18 27의 합으로 이루어진 수의 경우의 수만 알면 되는 것.
// 덧셈이 어떻게 되든 언급될 일이 없으므로.
