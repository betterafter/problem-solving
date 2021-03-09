//
//  LongestIncreasingSequence.cpp
//  test
//
//  Created by 신기열 on 29/05/2019.
//  Copyright © 2019 신기열. All rights reserved.
//
#include <stdio.h>
#include <iostream>
#include <math.h>
#include <algorithm>

using namespace std;

int main(){
    
    int n, ans = 0;
    cin >> n;
    
    int seq[1001] = { 0, }, sum[1001] = { 0, };
    
    for(int i = 1; i <= n; i++){
        int m;
        cin >> m;
        seq[i] = m;
    }
    for(int i = 1; i <= n; i++){
        for(int j = 0; j < i; j++){
            if(seq[j] < seq[i]){
                sum[i] = max(sum[i], sum[j]);
            }
        }
        sum[i]++;
        ans = max(sum[i], ans);
    }
    
    cout << ans;
    return 0;
}
