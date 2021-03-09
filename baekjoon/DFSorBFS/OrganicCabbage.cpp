//
//  OrganicCabbage.cpp
//  test
//
//  Created by 신기열 on 18/06/2019.
//  Copyright © 2019 신기열. All rights reserved.
//
#include <stdio.h>
#include <iostream>
#include <vector>
#include <utility>
#include <math.h>
#include <cmath>
#include <algorithm>
#include <queue>

using namespace std;

int M, N, K, cabbage[51][51] = { 0, };
int dir[4][2] = { {0, 1}, {0, -1}, {1, 0}, {-1, 0} };
int visited[51][51] = { 0, };
int cnt = 0;

queue<pair<int, int> > q;

void BFS(){
    
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            if(cabbage[i][j] == 1 && visited[i][j] == 0){
                //cout << i << " " << j << '\n';
                cnt++;
                q.push(make_pair(i, j));
                
                while(!q.empty()){
                    int x = q.front().second, y = q.front().first;
                    q.pop();
                    
                    for(int t = 0; t < 4; t++){
                        int nextX = x + dir[t][1], nextY = y + dir[t][0];
                        if(nextX >= 0 && nextX < M && nextY >= 0 && nextY < N && cabbage[nextY][nextX] == 1 && visited[nextY][nextX] == 0){
                            q.push(make_pair(nextY, nextX));
                            visited[nextY][nextX] = 1;
                        }
                    }
                }
            }
        }
    }
}


int main(){
    
    int T;
    cin >> T;
    
    for(int test = 0; test < T; test++){
        cin >> M >> N >> K;
        
        for(int i = 0; i < K; i++){
            int x, y;
            cin >> x >> y;
            cabbage[y][x] = 1;
        }
        
        BFS();
        
        cout << cnt << '\n';
        
        cnt = 0;
        for(int i = 0; i <= 50; i++){
            for(int j = 0; j <= 50; j++){
                cabbage[i][j] = 0;
                visited[i][j] = 0;
            }
        }
    }
    
    
    
    return 0;
}

