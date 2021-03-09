//
//  1904.cpp
//  test
//
//  Created by 신기열 on 03/07/2019.
//  Copyright © 2019 신기열. All rights reserved.
//

#include <stdio.h>
#include <iostream>

using namespace std;

int main(){
    
    int n; cin >> n;
    long long dp[n + 1];
    
    dp[1] = 1; dp[2] = 2;
    for(int i = 3; i <= n; i++){
        dp[i] = (dp[i - 1] + dp[i - 2]) % 15746;
    }
    
    cout << dp[n] % 15746;
    return 0;
}
