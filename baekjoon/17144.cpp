//
//  17144.cpp
//  BJ
//
//  Created by 신기열 on 02/11/2019.
//  Copyright © 2019 신기열. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int r, c, t;
int map[50][50];
// dust는 미세먼지가 있는 있는 곳의 좌표를 따로 담기 위한 공간이다.
vector<pair<int, int> > dust;
vector<pair<int, int> > cleaner;
int dir[4][2] = { {0,1}, {0,-1}, {1,0} ,{-1,0} };
int answer;

// 인접한 좌표'만' 탐색해주면 된다. (BFS가 아닌데 딱 보기에 BFS인 줄 알아서 함수명을 이렇게 적어버렸다.)
void BFS(){
    // 어느 좌표에서의 미세먼지의 최종량은 확산으로 인해 줄어든 양 + 인접한 곳에서 받은 미세먼지 양이다. 즉 미세먼지를 받아서 확산하는 것이 아니라, 원래 가지고 있던 미세먼지 양으로만 확산을 각각 진행해주고,
    // 나중에 받은 미세먼지를 따로 더해줘야한다. 따라서 tmap은 인접한 곳에서 받은 미세먼지들의 총량을 따로 저장하기 위한 배열이다.
    int tmap[50][50] = { 0, };
    
    // 미세먼지가 있는 좌표를 탐색하면서
    for(int i = 0; i < dust.size(); i++){
        int x = dust[i].first, y = dust[i].second;
        // tmp 벡터는 인접한 곳에 미세먼지가 확산 될 수 있는 곳의 좌표를 담기 위한 배열이다.
        vector<pair<int, int> > tmp;
        // 사방을 체크해서
        for(int j = 0; j < 4; j++){
            int nx = x + dir[j][0], ny = y + dir[j][1];
            // 인접한 곳이 맵 안에 있으며 & 공기 청정기가 아닐 때
            if(nx >= 0 && ny >= 0 && nx < c && ny < r && map[ny][nx] != -1){
                // tmp에 넣어주자.
                tmp.push_back(make_pair(nx, ny));
            }
        }
        // 확산될 수 있는 곳의 개수는 tmp의 사이즈이므로 그만큼 돌면서 각 tmap의 좌표에 현재 좌표에서 퍼트리는 미세먼지의 양을 추가해주자.
        for(int j = 0; j < tmp.size(); j++){
            tmap[tmp[j].second][tmp[j].first] = tmap[tmp[j].second][tmp[j].first] + map[y][x] / 5;
        }
        // 퍼트린 후엔 현재 좌표의 미세먼지의 양을 줄여주자.
        map[y][x] = map[y][x] - (map[y][x] / 5) * (int)(tmp.size());
    }
    // 이렇게 되면 (j,i)에는 확산으로 인해 얻어온 미세먼지의 양 & 확산의 결과로 남은 미세먼지의 양이 tmap과 map에 각각 담겨 있을 것이다. 이제 둘이 합쳐주자.
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            map[i][j] = map[i][j] + tmap[i][j];
        }
    }
    // 현재 존재하는 미세먼지의 위치는 다 사용했으므로 dust 벡터를 비워주자.
    dust.clear();
    // 확산을 확인하기 위한 출력이다. 궁금하면 해제해서 확인해보자.
//    cout << "spread" << '\n';
//    for(int i = 0; i < r; i++){
//        for(int j = 0; j < c; j++){
//            cout << map[i][j] << " " ;
//        }
//        cout << '\n';
//    }
}
// 미세먼지를 바람으로 청소하기 위한 함수이다.
void clean(){
    // 공기청정기의 2개의 위치는 cleaner에 담겨있다. 어차피 맨위 + 맨왼쪽부터 도는 것이며 공기청정기는 세로로 배치되어 있으므로 그냥 순서대로 저장해주면 되겠다. (main함수에서 찾아 저장해줬다.)
    int fx = cleaner[0].first, fy = cleaner[0].second, sx = cleaner[1].first, sy = cleaner[1].second;
    // tmap은 이동한 후의 미세먼지 양을 저장해주기 위한 배열이다.
    int tmap[50][50] = { 0, };
    // tmap도 공기청정기를 배치해주자.
    tmap[fy][fx] = -1; tmap[sy][sx] = -1;
    // 첫번째 공기청정기 위치에서부터 탐색해준다.
    int tx = fx, ty = fy;
    // 문제에서 위쪽 공기청정기는 반시계방향으로 돌고, 아래쪽 공기청정기는 시계방향으로 돈다고 명시해놓았다. 그대로 만들어주자.
    // 일단 공기청정기의 오른쪽으로 한칸 이동하자.
    tx++;
    // 오른쪽을 탐색하면서
    while(tx < c){
        // 먼지가 있고, 먼지가 다음으로 이동할 좌표도 맵 안에 있으면, tmap에 이동한 후의 좌표에 먼지를 이동시켜 저장해주자.
        if(map[ty][tx] > 0 && tx + 1 < c) tmap[ty][tx + 1] = map[ty][tx];
        tx++;
    }
    // 한 칸 이동시켜 맵 밖으로 좌표가 탈출했으므로 탐색을 위해 다시 뒤로 한칸 이동해주자.
    tx--;
    // 나머지도 같은 알고리즘이다. 오른쪽 -> 위쪽 -> 왼쪽 -> 아래쪽 순으로 돌게 만들어주면 된다.
    while(ty >= 0){
        if(map[ty][tx] > 0 && ty - 1 >= 0) tmap[ty - 1][tx] = map[ty][tx];
        ty--;
    }
    ty++;
    while(tx >= 0){
        if(map[ty][tx] > 0 && tx - 1 >= 0) tmap[ty][tx - 1] = map[ty][tx];
        tx--;
    }
    tx++;
    while(ty < fy){
        if(map[ty][tx] > 0 && ty + 1 < fy) tmap[ty + 1][tx] = map[ty][tx];
        ty++;
    }
    // 이번엔 아래쪽 공기청정기에서 시작해주자.
    tx = sx; ty = sy;
    // 역시 같은 알고리즘으로 만들어주면 된다. 오른쪽 -> 아래쪽 -> 왼쪽 -> 위쪽으로 이동해주면 된다.
    tx++;
    while(tx < c){
        if(map[ty][tx] > 0 && tx + 1 < c) tmap[ty][tx + 1] = map[ty][tx];
        tx++;
    }
    tx--;
    while(ty < r){
        if(map[ty][tx] > 0 && ty + 1 < r) tmap[ty + 1][tx] = map[ty][tx];
        ty++;
    }
    ty--;
    while(tx >= 0){
        if(map[ty][tx] > 0 && tx - 1 >= 0) tmap[ty][tx - 1] = map[ty][tx];
        tx--;
    }
    tx++;
    while(ty > sy){
        if(map[ty][tx] > 0 && ty - 1 > sy) tmap[ty - 1][tx] = map[ty][tx];
        ty--;
    }
    // 먼지는 어차피 1번 공기청정기와 같은 행 or 같은 열(0열) or 1번 공기청정기와 같은 행 or 같은 열(0열) or 0행 or r행 or c열에서만 돌게 되므로 여기에 해당하는 위치만 탐색해주면 된다.
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            // 이 위치에 해당한다면
            if(i == cleaner[0].second || i == cleaner[1].second || j == cleaner[0].first || j == cleaner[1].first ||
               i == 0 || i == r - 1 || j == 0 || j == c - 1){
                // map의 좌표의 값을 전부 tmap으로 바꿔준다.
                map[i][j] = tmap[i][j];
            }
        }
    }
    
    // 다음 확산을 위해 맵 전체를 탐색해서 먼지가 있는 좌표들은 다시 dust에 넣어주자.
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            if(map[i][j] > 0) dust.push_back(make_pair(j, i));
        }
    }
//    clean을 확인하기 위한 출력이다. 궁금하면 해제해서 확인해보자.
//    cout << "clean" << '\n';
//    for(int i = 0; i < r; i++){
//        for(int j = 0; j < c; j++){
//            cout << map[i][j] << " " ;
//        }
//        cout << '\n';
//    }
}

int main(){
    
    cin >> r >> c >> t;
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            cin >> map[i][j];
            if(map[i][j] > 0){
                dust.push_back(make_pair(j, i));
            }
            else if(map[i][j] == -1){
                cleaner.push_back(make_pair(j, i));
            }
        }
    }

    for(int i = 0; i < t; i++){
        BFS(); clean();
    }
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            if(map[i][j] != -1) answer += map[i][j];
        }
    }
    cout << answer;
    return 0;
}
