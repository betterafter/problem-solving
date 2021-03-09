//
//  PadovanSequence.cpp
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
    
    int test;
    unsigned long long dp[101];
    cin >> test;
    
    for(int t = 0; t < test; t++){
        int n;
        cin >> n;
        
        dp[0] = 1; dp[1] = 1; dp[2] = 1; dp[3] = 2; dp[4] = 2; dp[5] = 3; dp[6] = 4;
        
        for(int i = 7; i <= n; i++){
            dp[i] = dp[i - 5] + dp[i - 1];
        }
        cout << dp[n - 1] << '\n';
    }
    
    return 0;
}


