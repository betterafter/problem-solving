//
//  Rope.cpp
//  test
//
//  Created by 신기열 on 27/05/2019.
//  Copyright © 2019 신기열. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <math.h>

using namespace std;

int main(){
    
    int N, ans = 0;
    cin >> N;
    
    int rope[N];
    
    for(int i = 0; i < N; i++){
        int r;
        cin >> r;
        rope[i] = r;
    }
    
    sort(rope, rope + N);
    
    for(int i = 0; i < N; i++){
        ans = max(ans, rope[i] * (N - i));
    }
    
    cout << ans;
    
    return 0;
}
