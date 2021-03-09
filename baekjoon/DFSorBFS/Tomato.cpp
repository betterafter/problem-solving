//
//  Tomato.cpp
//  test
//
//  Created by 신기열 on 12/06/2019.
//  Copyright © 2019 신기열. All rights reserved.
//
#include <stdio.h>
#include <queue>
#include <iostream>

using namespace std;

//M은 가로, M은 세로
int M, N;
int Tomato[1001][1001] = { 0, };
int dir[4][2] = { {0, 1}, {0, -1}, {1, 0}, {-1, 0} };
int day = 0;
int cnt, total;

queue<pair<int, int> > q;


void BFS(){

    total = M * N;
    
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= M; j++){
            if(Tomato[i][j] == 1){
                q.push(make_pair(i, j));
                cnt++;
            }
            else if(Tomato[i][j] == -1){
                total--;
            }
        }
    }

    while(!q.empty()){
        
        unsigned long size = q.size();
        for(int i = 0; i < size; i++){
            
            int rx = q.front().second, ry = q.front().first;
            q.pop();
            
            for(int j = 0; j < 4; j++){
                int rnx = rx + dir[j][1], rny = ry + dir[j][0];
                
                if(rnx > 0 && rnx <= M && rny > 0 && rny <= N && Tomato[rny][rnx] == 0){
                    Tomato[rny][rnx] = 1;
                    q.push(make_pair(rny, rnx));
                    cnt++;
                }
            }
        }
        if(!q.empty()) day++;
    }
}

int main(){
    
    cin >> M >> N;
    
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= M; j++){
            cin >> Tomato[i][j];
        }
    }

    BFS();
    
    if(cnt != total) cout << -1;
    else cout << day;
    return 0;
}
