//
//  DownPath.cpp
//  test
//
//  Created by 신기열 on 31/05/2019.
//  Copyright © 2019 신기열. All rights reserved.
//
#include <stdio.h>
#include <iostream>

using namespace std;

int M, N;
int dir[4][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };
int map[501][501];
int dp[501][501];

int DFS(int x, int y){
    
    if(x == N && y == M) return 1;
    // 현재 전부 탐색하지 않았던 노드 상태. (-1이 탐색하지 않은 노드를 의미) 쭉 가다가 -1이 아닌 노드가 나왔다 -> 이미 탐색했다
    // ->길이 합쳐졌다는 뜻 -> 그 길에 저장되어 있던 dp[y][x]를 그대로 들고가서(return dp[y][x]로) 부모노드에 합쳐줌
    if(dp[y][x] != -1) return dp[y][x];
    
    dp[y][x] = 0;
    
    for(int i = 0; i < 4; i++){
        int next_x = x + dir[i][1], next_y = y + dir[i][0];
        
        if(next_x > 0 && next_y > 0 && next_x <= N && next_y <= M && map[next_y][next_x] < map[y][x]){
            dp[y][x] += DFS(next_x, next_y);
        }
    }
    return dp[y][x];
}

int main(){
    
    cin >> M >> N;
   
    for(int i = 1; i <= M; i++){
        for(int j = 1; j <= N; j++){
            cin >> map[i][j];
            dp[i][j] = -1;
        }
    }

    cout << DFS(1, 1);
    return 0;
}
