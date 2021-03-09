//
//  SWEA8859.cpp
//  SCPC
//
//  Created by 신기열 on 24/09/2019.
//  Copyright © 2019 신기열. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, M, D;
int monster[101][3];
int map[101][101];
int MaxExp;


int DFS(int time, int exp, int position){
    
    if(time <= 0){
        MaxExp = max(exp, MaxExp);
        return MaxExp;
    }
    
    for(int i = 0; i < N; i++){
        if(map[position][i] == 1){
            DFS(time - monster[position][1], exp - monster[position][0], i);
        }
    }
    return exp;
}


int main(int argc, char** argv)
{
    int test_case;
    int T;

    cin>>T;

    for(test_case = 1; test_case <= T; ++test_case)
    {
        
        for(int i = 0; i <= 100; i++){
            for(int j = 0; j <= 100; j++){
                map[i][j] = 0;
            }
        }
        
        cin >> N >> M >> D;
        
        for(int i = 1; i <= N; i++){
            cin >> monster[i][0] >> monster[i][1] >> monster[i][2];
        }
        
        for(int i = 0; i < M; i++){
            int x, y;
            cin >> x >> y;
            map[y][x] = 1;
        }
        
        DFS(D, 0, <#int position#>)
        
    }
    return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
