//
//  2byNTiling2.cpp
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
    
    int tile[1001], n;
    cin >> n;
    
    tile[1] = 1; tile[2] = 3; tile[3] = 5;
    
    for(int i = 4; i < 1001; i++){
        tile[i] = (tile[i - 1] + tile[i - 2] * 2) % 10007;
    }
    
    cout << tile[n] % 10007;
    
    return 0;
}
