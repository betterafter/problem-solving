
//
//  EasyStairNumber.cpp
//  test
//
//  Created by 신기열 on 29/05/2019.
//  Copyright © 2019 신기열. All rights reserved.
//
#include <cstdio>
#include <iostream>
#include <list>
#include <queue>
#include <algorithm>

using namespace std;

int main(){
  
    unsigned long long n, num[101][10], ans = 0;
    cin >> n;
    
    for(int i = 0; i < 101; i++){
        for(int j = 0; j < 10; j++){
            num[i][j] = 0;
        }
    }
    
    for(int i = 1; i <= 9; i++){
        num[1][i]++;
    }
    
    for(int i = 2; i <= n; i++){
        for(int j = 0; j < 10; j++){
            if(j == 0){
                num[i][j] += num[i - 1][j + 1] % 1000000000;
            }
            else if(j == 9){
                num[i][j] += num[i - 1][j - 1] % 1000000000;
            }
            else{
                num[i][j] += num[i - 1][j - 1] % 1000000000;
                num[i][j] += num[i - 1][j + 1] % 1000000000;
            }
        }
    }
    
    for(int i = 0; i < 10; i++){
        ans += num[n][i] % 1000000000;
    }
    
    cout << ans % 1000000000;
    return 0;
}
