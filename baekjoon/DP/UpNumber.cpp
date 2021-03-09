//
//  UpNumber.cpp
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
    
    int n, ans = 0;
    unsigned long long num[1001][10] = { 0, };
    cin >> n;
    
    for(int i = 0; i < 10; i++){
        num[1][i] = 1;
    }
    
    for(int i = 2; i <= n; i++){
        for(int j = 0; j < 10; j++){
            for(int k = j; k >= 0; k--){
                num[i][j] += num[i - 1][k] % 10007;
            }
        }
    }
    
    for(int i = 0; i < 10; i++){
        ans += num[n][i] % 10007;
    }
    
    cout << ans % 10007;
    
    return 0;
}


