//
//  16236.cpp
//  BJ
//
//  Created by 신기열 on 02/11/2019.
//  Copyright © 2019 신기열. All rights reserved.
//

#include <stdio.h>
#include <queue>
#include <iostream>

using namespace std;

int map[20][20];
// dist[20][20][0] : 거리, dist[20][20][1] : 사이즈
int dist[20][20][2];
int n;
int dir[4][2] = { {0,1}, {0,-1}, {1,0}, {-1,0} };
int answer;

// 사냥
void eat(int ix, int iy){

    // 초기 몸집과 잡아먹은 물고기의 수
    int size = 2, cnt = 0;
    
    while(1){
        queue<pair<pair<int, int>, int> > q;
        q.push(make_pair(make_pair(ix, iy), 0));
        // 문제가 현재 위치에서 "가장 적은 거리에 떨어져있는 물고기들 중에서 가장 위쪽이면서 가장 왼쪽인 물고기를 잡아먹는 것"이므로 초기 거리와 x, y좌표들을 각각 가장 최대값으로 설정해줘야
        // 비교를 통해 최단 거리 및 최단 거리 내의 물고기 중 가장 x, y가 적은 물고기의 좌표를 파악할 수 있다. "최단거리 & 가장 왼쪽 & 오른쪽이라는 말에 주의해주자."
        int dist = 100000, tx = ix, ty = iy; ix = 21; iy = 21;
        // 현재 위치에서 물고기를 먹는 좌표를 탐색해야한다.
        int visited[20][20] = { 0, };
        visited[iy][ix] = 1;
        while(!q.empty()){
            int x = q.front().first.first;
            int y = q.front().first.second;
            int d = q.front().second;
            q.pop();
            
            // 일단 아기 상어의 현재 좌표와 인접한 4개의 좌표를 탐색해주자.
            for(int i = 0; i < 4; i++){
                int nx = x + dir[i][0], ny = y + dir[i][1];
                // 그 좌표들이 맵 내에 있으며 & 사이즈가 작거나 같으며 (움직이거나 먹을 수 있음) & 방문을 아직 안한 좌표이면
                if(nx >= 0 && ny >= 0 && nx < n && ny < n && map[ny][nx] <= size && visited[ny][nx] == 0){
                    // 방문을 기록해주고
                    visited[ny][nx] = 1;
                    // 만약 0이 아닌 아기 상어보다 작은 물고기라면
                    if(map[ny][nx] < size && map[ny][nx] != 0){
                        // 현재 최단 거리보다 작다면
                        if(dist > d + 1){
                            // 바로 값을 업데이트 해준다.
                            ix = nx; iy = ny; dist = d + 1;
                        }
                        // 현재 최단 거리와 거리가 같다면
                        else if(dist == d + 1){
                            // 현재 y 좌표보다 크다면
                            if(iy > ny){
                                // 값을 업데이트 해준다.
                                ix = nx; iy = ny; dist = d + 1;
                            }
                            // 현재 최단 거리와 같고 y좌표는 같다면
                            else if(iy == ny){
                                // 현재 최단 거리와 같고 y좌표는 같고 더 왼쪽에 있다면
                                if(ix > nx){
                                    // 값을 업데이트 해준다.
                                    ix = nx; iy = ny; dist = d + 1;
                                }
                            }
                        }
                    }
                    // 위의 경우에 해당하지 않는다면 움직일 수 없는 것이거나 가장 왼쪽이 아니거나 가장 위쪽이 아니거나 최단거리가 아니므로 따로 제한을 걸어 줄 필요가 없다.
                    // 또한 이 과정이 끝나면 아기 상어는 그 좌표로 '실제로' 움직인 것이므로 어디로 움직일 수 있는지 파악하기 위한 큐엔 넣어줄 필요가 없다.
                    
                    // 사이즈가 같거나 0이면 (움직일 순 있으나 먹을 순 없음) 큐에 넣어줘서 최단 거리를 뽑아낼 때 까지 계속 탐색해준다.
                    else if(map[ny][nx] == size || map[ny][nx] == 0) q.push(make_pair(make_pair(nx, ny), d + 1));
                }
            }
        }
        // 가장 왼쪽 & 위쪽이 21로 변하지 않았으면 아기 상어가 어떤 방향으로도 움직일 수 없다는 것이므로 종료해준다.
        if(ix == 21 && iy == 21) break;
        // 그게 아니면 물고기를 먹을 수 있는 좌표로 움직인 것이므로 물고기를 하나 먹어주고 원래 아기 상어 좌표의 값은 0으로 만들어준다. (9로 하면 아기 상어 몸집이 9보다 커질 때 무한 루프를 돌게 된다.)
        // 또한 이동한 후 좌표도 아기 상어가 물고기를 먹었으므로 0으로 만들어준다.
        cnt++; answer += dist; map[ty][tx] = 0; map[iy][ix] = 0;
        // 이 때 먹은 물고기의 수 = 아기 상어 사이즈 이면 먹은 물고기 수를 초기화 해주고 사이즈를 1 늘려준다.
        if(cnt == size){
            cnt = 0; size++;
        }
    }
}

int main(){
    
    int x = 0, y = 0;cin >> n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> map[i][j];
            if(map[i][j] == 9){ x = j; y = i; }
        }
    }
    eat(x, y); cout << answer;
    return 0;
}
