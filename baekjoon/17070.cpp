//
//  17070.cpp
//  BJ
//
//  Created by 신기열 on 12/11/2019.
//  Copyright © 2019 신기열. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <queue>

using namespace std;

int map[17][17];
int n, answer;

void DFS(pair<pair<int, int>, pair<int, int> > p){
    
    int bx = p.first.first, by = p.first.second, fx = p.second.first, fy = p.second.second;
    
    // 앞 파이프 좌표가 (n,n) 이면 가능 횟수 + 1 하고 끝낸다.
    if(fx == n && fy == n){
        answer++; return;
    }
    
//    int tmap[17][17];
//
//    for(int i = 1; i <= n; i++){
//        for(int j = 1; j <= n; j++){
//            tmap[i][j] = map[i][j];
//        }
//    }
//    tmap[by][bx] = 2; tmap[fy][fx] = 2;
//
//    for(int i = 1; i <= n; i++){
//        for(int j = 1; j <= n; j++){
//            cout << tmap[i][j] << " ";
//        }
//        cout << '\n';
//    }
//    cout << '\n';
    
    
    // 세로 방향
    if(bx == fx && fy == by + 1){
        for(int i = 0; i < 2; i++){
            // 세로 방향으로만 미는 방법
            if(i == 0){
                // 그림에 나온 방향에 벽이 없고 맵 안에 있으면
                if(fy + 1 <= n && map[fy + 1][fx] == 0){
                    DFS(make_pair(make_pair(bx, by + 1), make_pair(fx, fy + 1)));
                }
            }
            // 세로 방향으로 밀고 대각선으로 회전
            else if(i == 1){
                // 그림에 나온 방향에 벽이 없고 맵 안에 있으면
                if(fx + 1 <= n && fy + 1 <= n && map[fy][fx + 1] == 0 && map[fy + 1][fx + 1] == 0 && map[fy + 1][fx] == 0){
                    DFS(make_pair(make_pair(bx, by + 1), make_pair(fx + 1, fy + 1)));
                }
            }
        }
    }
    // 가로 방향도 역시 마찬가지
    else if(by == fy && fx == bx + 1){
        for(int i = 0; i < 2; i++){
            if(i == 0){
                if(fx + 1 <= n && map[fy][fx + 1] == 0){
                    DFS(make_pair(make_pair(bx + 1, by), make_pair(fx + 1, fy)));
                }
            }
            else if(i == 1){
                if(fx + 1 <= n && fy + 1 <= n && map[fy][fx + 1] == 0 && map[fy + 1][fx] == 0 && map[fy + 1][fx + 1] == 0){
                    DFS(make_pair(make_pair(bx + 1, by), make_pair(fx + 1, fy + 1)));
                }
            }
        }
    }
    // 대각선 방향
    else if(fx == bx + 1 && fy == by + 1){
        for(int i = 0; i < 3; i++){
            if(i == 0){
                if(fy + 1 <= n && map[fy + 1][fx] == 0){
                    DFS(make_pair(make_pair(bx + 1, by + 1), make_pair(fx, fy + 1)));
                }
            }
            else if(i == 1){
                if(fx + 1 <= n && map[fy][fx + 1] == 0){
                    DFS(make_pair(make_pair(bx + 1, by + 1), make_pair(fx + 1, fy)));
                }
            }
            else if(i == 2){
                if(fx + 1 <= n && fy + 1 <= n && map[fy][fx + 1] == 0 && map[fy + 1][fx] == 0 && map[fy + 1][fx + 1] == 0){
                    DFS(make_pair(make_pair(bx + 1, by + 1), make_pair(fx + 1, fy + 1)));
                }
            }
        }
    }
}


int main(){
    
    cin >> n;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin >> map[i][j];
        }
    }
    DFS(make_pair(make_pair(1, 1), make_pair(2, 1)));
    cout << answer;
    return 0;
}
