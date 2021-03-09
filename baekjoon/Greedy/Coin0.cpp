//
//  Coin0.cpp
//  test
//
//  Created by 신기열 on 24/05/2019.
//  Copyright © 2019 신기열. All rights reserved.
//

#include <stdio.h>
#include <algorithm>
#include <iostream>

using namespace std;

int main(){
    
    int n, value, cnt = 0;
    cin >> n >> value;
    
    int val[n];
    
    for(int i = 0; i < n; i++){
        int v;
        cin >> v;
        val[i] = v;
    }
    

    for(int i = n - 1; i >= 0; i--){
        
        int j = 0;
        while(value - val[i] * (j + 1) >= 0){
            j++;
        }
        value = value - val[i] * j;
        cnt += j;
        
        if(value <= 0) break;
    }
    
    cout << cnt;
    
    return 0;
}

