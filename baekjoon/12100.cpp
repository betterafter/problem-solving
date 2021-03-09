//
//  12100.cpp
//  BJ
//
//  Created by 신기열 on 20/10/2019.
//  Copyright © 2019 신기열. All rights reserved.
//

#include <stdio.h>
#include <iostream>

using namespace std;

int map[21][21];
int n, mxblock = 0, answer = 0;

int dir[4][2] = { {0,1}, {0,-1}, {1,0}, {-1,0} };

// 이동 연산을 위한 함수
void calc(int i, int x, int y, int map[][21], int isCol[][21]){
    
    // 다음 칸을 체크하기 위한 변수
    int nx = x;
    int ny = y;
    
    // 함수는 한 칸만 연산을 하고, 밑의 DFS에서 for문을 돌려서 모든 칸에 대해 calc함수를 적용한다.
    while(1){
        // 다음 칸이 존재하며 & 다음 칸의 숫자가 0이면
        if(nx + dir[i][0] >= 1 && ny + dir[i][1] >= 1 && nx + dir[i][0] <= n && ny + dir[i][1] <= n && map[ny + dir[i][1]][nx + dir[i][0]] == 0){
            // 현재 탐색하는 칸을 다음 칸의 좌표로 이동해준다.
            nx = nx + dir[i][0]; ny = ny + dir[i][1];
        }
        // 더 이상 이동할 수 없으면 이동을 종료한다.
        else break;
    }
    
    // 여기까지 일단 "좌표"만 이동한 것이다. 따라서 배열은 아래에서 업데이트 해준다.
    
    // 이동 방향으로 쭉 움직이고 난 후의 좌표에서, 다음 칸이 존재하는 칸이면,
    if(nx + dir[i][0] >= 1 && ny + dir[i][1] >= 1 && nx + dir[i][0] <= n && ny + dir[i][1] <= n){
        // 만약 다음 칸이랑 현재 탐색 칸의 숫자가 같다면 & 다음 칸이 충돌한 적이 없으면
        if(map[ny + dir[i][1]][nx + dir[i][0]] == map[y][x] && isCol[ny + dir[i][1]][nx + dir[i][0]] == 0){
            // 다음 칸에 합쳐진 숫자를 업데이트해준다.
            map[ny + dir[i][1]][nx + dir[i][0]] = map[ny + dir[i][1]][nx + dir[i][0]] + map[y][x];
            // 이 칸은 충돌도 1로 업데이트 해준다.
            isCol[ny + dir[i][1]][nx + dir[i][0]] = 1;
            // 탐색 칸의 시작 지점은 이동한 후니까 0으로 업데이트 해준다.
            map[y][x] = 0;
        }
        
        // 다음 칸이 존재하긴 하는데 다음 칸과 숫자가 다를 때, 탐색 칸이 움직인 적이 없으면,
        else if(nx == x && ny == y){
            // 그냥 그대로 둔다.
            map[ny][nx] = map[y][x];
        }
        // 다음 칸과 숫자가 다르고 움직인 적은 있으면
        else{
            // 움직임이 끝난 최종 칸에 탐색 칸의 숫자를 업데이트 해주고, 시작 지점은 0으로 업데이트 해준다.
            map[ny][nx] = map[y][x];
            map[y][x] = 0;
        }
    }
    // 다음 칸이 없으면
    else{
        // 움직인 적이 없으면
        if(nx == x && ny == y){
            // 그냥 냅둔다.
            map[ny][nx] = map[y][x];
        }
        // 움직인 적은 있으면
        else{
            // 도착지점과 시작지점을 업데이트 해준다.
            map[ny][nx] = map[y][x];
            map[y][x] = 0;
        }
    }
}

void DFS(int map[21][21], int cnt, int mxblock){
    
    // 5번 탐색 했으면 더 이상 탐색을 해주지 않는다.
    if(cnt >= 5){ answer = max(mxblock, answer); return; }
    
    for(int i = 0; i < 4; i++){
        // 맵은 현재 상태에서 상, 하, 좌, 우로 움직일 수 있으므로 그걸 위한 맵이다.
        int tmpMap[21][21] = { 0, };
        // 충돌은 각 방향마다 계속 리셋해줘야한다. 어차피 한쪽 방향으로 이동했을 때 충돌 체크이므로 한 방향에서의 충돌만 체크해줘야한다. 이걸 리셋
        // 안하면 다른 방향으로 이동했을 때 리셋이 안되서 합쳐지지 않게 될 수도 있다.
        int isCol[21][21] = { 0, };
        // 임시맵을 초기화해준다.
        for(int p = 1; p <= n; p++){
            for(int q = 1; q <= n; q++){
                tmpMap[p][q] = map[p][q];
            }
        }
        // 밑으로 움직일 때
        if(i == 0){
            for(int y = n; y >= 1; y--){
                for(int x = 1; x <= n; x++){
                    calc(i, x, y, tmpMap, isCol);
                }
            }
        }
        // 위로 움직일 때
        else if(i == 1){
            for(int y = 1; y <= n; y++){
                for(int x = 1; x <= n; x++){
                    calc(i, x, y, tmpMap, isCol);
                }
            }
        }
        // 오른쪽으로 움직일 때
        if(i == 2){
            for(int y = 1; y <= n; y++){
                for(int x = n; x >= 1; x--){
                    calc(i, x, y, tmpMap, isCol);
                }
            }
        }
        // 왼쪽으로 움직일 때
        else if(i == 3){
            for(int y = 1; y <= n; y++){
                for(int x = 1; x <= n; x++){
                    calc(i, x, y, tmpMap, isCol);
                }
            }
        }
        // 각 방향으로 이동한 후 맵을 전부 탐색해서 가장 큰 블록의 숫자를 저장한다.
        for(int p = 1; p <= n; p++){
            for(int q = 1; q <= n; q++){
                mxblock = max(tmpMap[p][q], mxblock);
            }
        }
        
        // 최대 5번까지므로 dfs를 돌린다.
        DFS(tmpMap, cnt + 1, mxblock);
    
    }
}


int main(){
    
    cin >> n;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin >> map[i][j];
        }
    }
    DFS(map, 0, 0);
    cout << answer;
    
    return 0;
}
