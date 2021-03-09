//
//  14503.cpp
//  BJ
//
//  Created by 신기열 on 23/10/2019.
//  Copyright © 2019 신기열. All rights reserved.
//

#include <stdio.h>
#include <iostream>

using namespace std;

int n, m;
int x, y;
int d;
int map[50][50];
int answer;

// 청소구역 찾기 알고리즘
void Search(){
    
    // 현재 위치 기준 동, 서, 남, 북이 청소를 끝냈는지 확인
    bool west = false, east = false, north = false, south = false;
    // 동작이 정지하기 전까지 계속 돈다
    while(1){
        // 현재 위치가 청소를 아직 안했으면 카운트해준다. (뒤로 후진 알고리즘에서 청소한 지역을 밟을 수도 있으므로)        문제 알고리즘
        if(map[y][x] == 0) answer++;                                                 // 1. 현재 위치를 청소한다.
        //map = 0 : 청소를 안한 구역, map = 1 : 벽, map = 2 : 청소한 구역
        map[y][x] = 2;
        // 북쪽을 볼 때
        if(d == 0){                                                               // 2. 현재 위치에서 현재 방향을 기준으로
            // 왼쪽 방향에 청소할 공간이 있을 때                                          // 왼쪽방향부터 차례대로 탐색을 진행한다.
            if(x - 1 >= 0 && x - 1 < m && y >= 0 && y < n && map[y][x - 1] == 0){  // a. 왼쪽 방향에 아직 청소하지
                                                                                   // 않은 공간이 존재한다면,
                d = 3;                                                             // 그 방향으로 한번 회전한 다음
                x = x - 1;                                                         // 한칸을 전진하고
                west = false; east = false; north = false; south = false;          // 1번부터 진행한다.
            }                                                                      //
            else{                                                                  // b. 왼쪽 방향에 청소할 공간이 없다면,
                d = 3;                                                             // 그 방향으로 회전하고
                west = true;                                                       // 2번으로 돌아간다.
                                                                                   //
            }                                                                      //
        }                                                                          //
        // 동쪽을 볼 때                                                               //
        else if(d == 1){                                                           //
            // 왼쪽 방향에 청소할 공간이 있을 때                                            //
            if(x >= 0 && x < m && y - 1 >= 0 && y - 1 < n && map[y - 1][x] == 0){  //
                d = 0;                                                             //
                y = y - 1;                                                         //
                west = false; east = false; north = false; south = false;          //
            }                                                                      //
            else{                                                                  //
                north = true;                                                      //
                d = 0;                                                             //
            }                                                                      //
        }                                                                          //
        // 남쪽을 볼 때                                                               //
        else if(d == 2){                                                           //
            // 왼쪽 방향에 청소할 공간이 있을 때                                           //
            if(x + 1 >= 0 && x + 1 < m && y >= 0 && y < n && map[y][x + 1] == 0){  //
                d = 1;                                                             //
                x = x + 1;                                                         //
                west = false; east = false; north = false; south = false;          //
            }                                                                      //
            else{                                                                  //
                east = true;                                                       //
                d = 1;                                                             //
            }                                                                      //
        }                                                                          //
        // 서쪽을 볼 때                                                               //
        else if(d == 3){                                                           //
            // 왼쪽 방향에 청소할 공간이 있을 때                                            //
            if(x >= 0 && x < m && y + 1 >= 0 && y + 1 < n && map[y + 1][x] == 0){  //
                d = 2;                                                             //
                y = y + 1;                                                         //
                west = false; east = false; north = false; south = false;          //
            }                                                                      //
            else{                                                                  //
                south = true;                                                      //
                d = 2;                                                             //
            }                                                                      //
        }                                                                          //
                                                                                   //
        if(west && east && south && north){                                        // c. 네 방향 모두 청소가 이미                                                                               // 되어있거나 벽인 경우에는,
            // 북쪽                                                                 //
            if(d == 0){                                                            // 바라보는 방향을 유지한 채로
                if(x >= 0 && x < m && y + 1 >= 0 && y + 1 < n && map[y + 1][x] != 1){
                    y++;                                                           // 한 칸 후진을 하고
                    west = false; east = false; north = false; south = false;      //
                    continue;                                                      // 2번으로 돌아간다.
                }                                                                  // 네 방향 모두 청소가 이미 되어있거나                                                                  // 벽이면서, 뒤쪽 방향이 벽이라 후진도 할                                                                // 수 없는 경우에는
                else return;                                                       // 작동을 멈춘다.
                
            }
            // 동쪽
            else if(d == 1){
                if(x - 1 >= 0 && x - 1 < m && y >= 0 && y < n && map[y][x - 1] != 1){
                    x--;
                    west = false; east = false; north = false; south = false;
                    continue;
                }
                else return;
            }
            // 남쪽
            else if(d == 2){
                if(x >= 0 && x < m && y - 1 >= 0 && y - 1 < n && map[y - 1][x] != 1){
                    y--;
                    west = false; east = false; north = false; south = false;
                    continue;
                }
                else return;
            }
            // 서쪽
            else if(d == 3){
                if(x + 1 >= 0 && x + 1 < m && y >= 0 && y < n && map[y][x + 1] != 1){
                    x++;
                    west = false; east = false; north = false; south = false;
                    continue;
                }
                else return;
            }
        }
    }
}



int main(){
    
    cin >> n >> m;
    cin >> y >> x >> d;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> map[i][j];
        }
    }
    Search();
    cout << answer;
    return 0;
}
