//
//  MakingBridge.cpp
//  test
//
//  Created by 신기열 on 30/05/2019.
//  Copyright © 2019 신기열. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <math.h>
#include <algorithm>

using namespace std;

int main(){
    
    int n, bridge[31][31] = { 0, };
    cin >> n;
    
    for(int test = 0; test < n; test++){
        int N, M;
        cin >> N >> M;
        
        for(int i = 0; i <= 30; i++){
            for(int j = 0; j <= 30; j++){
                bridge[i][j] = 0;
             }
        }
        
        for(int i = 1; i <= 30; i++){
            bridge[1][i] = i;
        }
        
        for(int i = 2; i <= N; i++){
            for(int j = i; j <= M; j++){
                for(int k = i - 1; k < j; k++){
                    bridge[i][j] += bridge[i - 1][k];
                }
            }
        }
        cout << bridge[N][M] << '\n';
    }
    return 0;
}
