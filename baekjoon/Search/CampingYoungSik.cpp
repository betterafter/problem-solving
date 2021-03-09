//
//  CampingYoungSik.cpp
//  test
//
//  Created by 신기열 on 14/06/2019.
//  Copyright © 2019 신기열. All rights reserved.
//
#include <stdio.h>
#include <iostream>
#include <vector>
#include <utility>
#include <math.h>
#include <cmath>
#include <algorithm>
#include <deque>

#define ull unsigned long long
#define MAX 3000000000

using namespace std;

int main(){
    
    ull N, T, bus[100000][3], ans = MAX;
    cin >> N >> T;
    
    for(int i = 0; i < N; i++){
        cin >> bus[i][0] >> bus[i][1] >> bus[i][2];
    }
    
    for(int i = 0; i < N; i++){
        if(bus[i][0] > T){
            ans = min(ans, bus[i][0] - T);
        }
    }

    for(int i = 0; i < N; i++){
        int j = 0;
        while(bus[i][0] + bus[i][1] * j < T){
            //cout << bus[i][0] + bus[i][1] * j << " " << T << '\n';
            j++;
        }
        
        //cout << j << '\n';
        if(j + 1 <= bus[i][2]){
            ans = min((bus[i][0] + bus[i][1] * j) - T, ans);
        }
    }
    if(ans == MAX) cout << -1;
    else cout << ans;

    
    return 0;
}

