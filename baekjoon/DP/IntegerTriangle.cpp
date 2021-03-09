//
//  IntegerTriangle.cpp
//  test
//
//  Created by 신기열 on 28/05/2019.
//  Copyright © 2019 신기열. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <iostream>
#include <math.h>
#include <algorithm>

using namespace std;

int main(){
    
    int n;
    vector<int> tri[505];
    unsigned long long sum[505][505], ans;
    cin >> n;
    
    for(int i = 1; i <= n; i++){
        for(int j = 0; j < i; j++){
            int t;
            cin >> t;
            tri[i].push_back(t);
        }
    }
    
    sum[1][0] = tri[1][0];
    
    if(n >= 2){
        sum[2][0] = sum[1][0] + tri[2][0];
        sum[2][1] = sum[1][0] + tri[2][1];
        
        for(int i = 3; i <= n; i++){
            for(int j = 0; j < i; j++){
                if(j == 0){
                    sum[i][j] = sum[i - 1][j] + tri[i][j];
                }
                else if(j == i - 1){
                    sum[i][j] = sum[i - 1][j - 1] + tri[i][j];
                }
                else{
                    sum[i][j] = max(sum[i - 1][j - 1], sum[i - 1][j]) + tri[i][j];
                }
            }
        }
    }
    
//    for(int i = 1; i <= n; i++){
//        for(int j = 0; j < i; j++){
//            cout << sum[i][j] << " ";
//        }
//        cout << '\n';
//    }

   
    
    ans = sum[n][0];
    
    for(int i = 1; i < n; i++){
        ans = max(ans, sum[n][i]);
    }
    
    
    cout << ans;
    return 0;
}
