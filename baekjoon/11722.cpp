//
//  11722.cpp
//  test
//
//  Created by 신기열 on 03/07/2019.
//  Copyright © 2019 신기열. All rights reserved.
//
#include <stdio.h>
#include <algorithm>
#include <math.h>
#include <iostream>

using namespace std;

int main(){
    
    int n; cin >> n;
    int arr[1001] = { 0, };
    int dp[1001] = { 0, };
    
    for(int i = 1; i <= n; i++){
        cin >> arr[i];
    }
    
    for(int i = 1; i <= n; i++){
        for(int j = 1; j < i; j++){
            if(arr[i] > arr[j]) dp[i] = max(dp[i], dp[j]);
        }
        dp[i]++;
    }

    int ans = 0;
    for(int i = 1; i <= n; i++){
        ans = max(ans, dp[i]);
        
    }
    
    cout << ans;
    return 0;
}
