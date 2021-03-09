//
//  11054.cpp
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
    int up_dp[1001] = { 0, }, down_dp[1001] = { 0, }, dp[1001];
    
    for(int i = 1; i <= n; i++){
        cin >> arr[i];
    }
    
    for(int i = 1; i <= n; i++){
        for(int j = 1; j < i; j++){
            if(arr[i] > arr[j]) up_dp[i] = max(up_dp[i], up_dp[j]);
        }
        up_dp[i]++;
    }

    for(int i = n; i >= 1; i--){
        for(int j = n; j > i; j--){
            if(arr[i] > arr[j]) down_dp[i] = max(down_dp[i], down_dp[j]);
        }
        down_dp[i]++;
    }
    
//    for(int i = 1; i <= n; i++){
//        cout << up_dp[i] << " " << down_dp[i] << '\n';
//    }

    int ans = 0;
    for(int i = 1; i <= n; i++){
        dp[i] = up_dp[i] + down_dp[i] - 1;
        ans = max(ans, dp[i]);
        
    }

    cout << ans;
    return 0;
}
