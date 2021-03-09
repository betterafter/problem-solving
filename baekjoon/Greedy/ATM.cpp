//
//  ATM.cpp
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
    
    int n, sum[1001] = { 0, }, res = 0;
    cin >> n;
    
    int time[n];
    
    for(int i = 0; i < n; i++){
        int p;
        cin >> p;
        time[i] = p;
    }
    
    sort(time, time + n);

    
    for(int i = 0; i < n; i++){
        for(int j = 0; j <= i; j++){
            sum[i] += time[j];
        }
    }
    
    for(int i = 0; i < n; i++){
        res += sum[i];
    }
    
    cout << res;
    
    return 0;
    
}
