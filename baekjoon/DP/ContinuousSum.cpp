//
//  ContinuousSum.cpp
//  test
//
//  Created by 신기열 on 28/05/2019.
//  Copyright © 2019 신기열. All rights reserved.
//

#include <cstdio>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int main(){
    
    int n, ans = -1000;
    cin >> n;
    
    vector<int> num(n, 0);
    vector<int> sum(n, 0);
    
    for(int i = 0; i < n; i++){
        int m;
        cin >> m;
        num[i] = m;
    }
    
    sum[0] = num[0];
    ans = sum[0];
    
    for(int i = 1; i < n; i++){

        sum[i] = max(sum[i - 1] + num[i], num[i]);
        ans = max(ans, sum[i]);
    }
    
    cout << ans;
    return 0;
}
