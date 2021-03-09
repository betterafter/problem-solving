//
//  15683.cpp
//  BJ
//
//  Created by 신기열 on 27/10/2019.
//  Copyright © 2019 신기열. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

// 카메라 좌표 모음
vector<pair<int, int> > camera;
int initmap[8][8];
int n, m;
int answer = 1000000;

// 왼쪽 감시. 감시하는 부분을 8이라고 해준다.
void searchLeft(int x, int y, int tmap[][8]){
    // 현재 카메라 기준 왼쪽을 전부 8로 업데이트 해준다.
    // 카메라 좌표는 x
    // x 좌표를 1씩 작아지게 만든다.
    while(x - 1 >= 0){
        // 현재 구역이 벽이 아니면
        if(tmap[y][x - 1] != 6){
            // 아무것도 없을 때
            if(tmap[y][x - 1] == 0){
                // 감시가능 구역으로 변경해준다.
                tmap[y][x - 1] = 8;
            }
            // 만약 tmap이 1 ~ 5이면 이건 카메라 이므로 업데이트는 하지 말고 그냥 넘어가준다.
        }
        // 현재 구역이 벽이면 벽을 뚫고 감시를 못하므로 그냥 종료해준다.
        else break;
        x--;
    }
}

// 다른 방향도 알고리즘은 완전 같으므로 따로 설명을 하지 않겠다.
// 오른쪽 감시
void searchRight(int x, int y, int tmap[][8]){
    // 현제 카메라 기준 오른쪽을 전부 8로 업데이트 해준다.
    while(x + 1 < m){
        if(tmap[y][x + 1] != 6){
            if(tmap[y][x + 1] == 0){
                tmap[y][x + 1] = 8;
            }
        }
        else break;
        x++;
    }
}

// 위쪽 감시
void searchUp(int x, int y, int tmap[][8]){
    // 현재 카메라 기준 위쪽 (y - n)을 전부 8로 업데이트 해준다.
    while(y - 1 >= 0){
        if(tmap[y - 1][x] != 6){
            if(tmap[y - 1][x] == 0){
                tmap[y - 1][x] = 8;
            }
        }
        else break;
        y--;
    }
}

// 아래쪽 감시
void searchDown(int x, int y, int tmap[][8]){
    // 현재 카메라 기준 아래쪽 (y + n)을 전부 8로 업데이트 해준다.
    while(y + 1 < n){
        if(tmap[y + 1][x] != 6){
            if(tmap[y + 1][x] == 0){
                tmap[y + 1][x] = 8;
            }
        }
        else break;
        y++;
    }
}

void init(int tmp[][8], int init[][8]){
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            tmp[i][j] = init[i][j];
        }
    }
}

void DFS(int cnum, int map[][8]){
    // 현재 카메라 넘버가 카메라 벡터의 크기와 같거나 넘어서면, 즉 카메라가 더 없으면
    if(cnum >= camera.size()){
        int tmp = 0;
        // 안전 구역을 세주고 answer를 업데이트 해준다.
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(map[i][j] == 0) tmp++;
            }
        }
//        혹시 몰라 체크하려고 만든 출력. 궁금하면 주석 해제하고 확인해보자.
//        for(int i = 0; i < n; i++){
//            for(int j = 0; j < m; j++){
//                cout << map[i][j];
//            }
//            cout << '\n';
//        }
//        cout << '\n';
        answer = min(answer, tmp);
        return;
    }
    
    int tmap[8][8];
    init(tmap, map);
    
    int x = camera[cnum].first;
    int y = camera[cnum].second;
    
    // 각각 감시하는 방향들을 정해서 감시를 가정해서 가정한 맵배열을 다음 카메라로 넘겨준다. 즉 현재 카메라로 감시하는 맵정보를 DFS로 다음 카메라 번호
    // 와 현재 카메라에 대한 맵배열을 같이 넘겨준다. DFS탐색이 끝나면 현재 방향에 대한 감시 맵배열은 방향 결정 전 맵배열로 다시 초기화해준다.
    // 초기화 하지 않으면 왼쪽 감시일 때 감시구역에 대한 정보가 오른쪽 감시일 때 그대로 남아서 여러 방향 감시가 되어버린다.
    // 상, 하, 좌, 우 1방향 감시
    if(map[y][x] == 1){
        // 왼쪽 감시
        searchLeft(x, y, tmap);
        DFS(cnum + 1, tmap);
        init(tmap, map);
        // 오른쪽 감시
        searchRight(x, y, tmap);
        DFS(cnum + 1, tmap);
        init(tmap, map);
        // 위쪽 감시
        searchUp(x, y, tmap);
        DFS(cnum + 1, tmap);
        init(tmap, map);
        // 아래쪽 감시
        searchDown(x, y, tmap);
        DFS(cnum + 1, tmap);
        init(tmap, map);
    }
    // 상하, 좌우 2방향 감시
    else if(map[y][x] == 2){
        // 좌우 감시
        searchLeft(x, y, tmap);
        searchRight(x, y, tmap);
        DFS(cnum + 1, tmap);
        init(tmap, map);
        // 상하 감시
        searchUp(x, y, tmap);
        searchDown(x, y, tmap);
        DFS(cnum + 1, tmap);
        init(tmap, map);
    }
    // 상좌, 상우, 하좌, 하우 2방향 감시
    else if(map[y][x] == 3){
        // 상-좌
        searchUp(x, y, tmap);
        searchLeft(x, y, tmap);
        DFS(cnum + 1, tmap);
        init(tmap, map);
        // 상-우
        searchUp(x, y, tmap);
        searchRight(x, y, tmap);
        DFS(cnum + 1, tmap);
        init(tmap, map);
        // 하-좌
        searchDown(x, y, tmap);
        searchLeft(x, y, tmap);
        DFS(cnum + 1, tmap);
        init(tmap, map);
        // 하-우
        searchDown(x, y, tmap);
        searchRight(x, y, tmap);
        DFS(cnum + 1, tmap);
        init(tmap, map);
    }
    // 상좌우, 하좌우, 상하좌, 상하우 3방향 감시
    else if(map[y][x] == 4){
        //상-좌-우
        searchUp(x, y, tmap);
        searchLeft(x, y, tmap);
        searchRight(x, y, tmap);
        DFS(cnum + 1, tmap);
        init(tmap, map);
        //하-좌-우
        searchDown(x, y, tmap);
        searchLeft(x, y, tmap);
        searchRight(x, y, tmap);
        DFS(cnum + 1, tmap);
        init(tmap, map);
        //상-하-좌
        searchUp(x, y, tmap);
        searchDown(x, y, tmap);
        searchLeft(x, y, tmap);
        DFS(cnum + 1, tmap);
        init(tmap, map);
        //상-하-우
        searchUp(x, y, tmap);
        searchDown(x, y, tmap);
        searchRight(x, y, tmap);
        DFS(cnum + 1, tmap);
        init(tmap, map);
    }
    // 상하좌우 4방향 감시
    else if(map[y][x] == 5){
        searchUp(x, y, tmap);
        searchDown(x, y, tmap);
        searchLeft(x, y, tmap);
        searchRight(x, y, tmap);
        DFS(cnum + 1, tmap);
        init(tmap, map);
    }
}

int main(){
    
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> initmap[i][j];
            if(initmap[i][j] >= 1 && initmap[i][j] <= 5){
                camera.push_back(make_pair(j, i));
            }
        }
    }
    DFS(0, initmap);
    cout << answer;
    return 0;
}
