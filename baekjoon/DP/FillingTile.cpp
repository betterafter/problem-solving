//
//  FillingTile.cpp
//  test
//
//  Created by 신기열 on 02/06/2019.
//  Copyright © 2019 신기열. All rights reserved.
//
#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

int main(){
    
    int n;
    int dp[31] = { 0, };
    cin >> n;
    
    dp[0] = 1; dp[1] = 0; dp[2] = 3; dp[3] = 0; dp[4] = 11;
    
    for(int i = 5; i <= n; i++){
        if(i % 2 == 0){
            dp[i] = dp[i - 2] * 3;
            for(int j = 2; j * 2 <= i; j++){
                dp[i] += dp[i - 2 * j] * 2;
            }
        }
    }
    
    cout << dp[n];
    
    return 0;
}
