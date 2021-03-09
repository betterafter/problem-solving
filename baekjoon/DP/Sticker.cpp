//
//  Sticker.cpp
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
    
    int n, sticker[2][100001], score[2][100001], ans;
    cin >> n;
    
    for(int test = 0; test < n; test++){
        int m;
        cin >> m;
        
        for(int i = 0; i < 2; i++){
            for(int j = 1; j <= m; j++){
                cin >> sticker[i][j];
            }
        }
        
        score[0][1] = sticker[0][1];
        score[1][1] = sticker[1][1];
        
        for(int i = 2; i <= m; i++){
            score[0][i] = max(max(score[1][i - 1], score[1][i - 2]), score[0][i - 2]) + sticker[0][i];
            score[1][i] = max(max(score[0][i - 1], score[0][i - 2]), score[1][i - 2]) + sticker[1][i];
        }
        ans = max(score[0][m], score[1][m]);
        cout << ans << '\n';
    }
    
    return 0;
}
