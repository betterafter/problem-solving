//
//  14502.cpp
//  BJ
//
//  Created by 신기열 on 23/10/2019.
//  Copyright © 2019 신기열. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <queue>

using namespace std;

int map[9][9];
int n, m;
// built[y][x][.][.][.][.] : 벽1
// built[.][.][y][x][.][.] : 벽2
// built[.][.][.][.][y][x] : 벽3
// 벽은 구분이 없으므로 벽1이 벽2와 자리가 바뀐다고 다른게 아니다. 가령
// built[1][2][3][4][5][6]과 built[3][4][1][2][5][6]일 때 어차피 벽이 설치되는 위치는 똑같기 때문에
// 안전구역 개수가 달라질 수가 없다.
int built[9][9][9][9][9][9];
int answer = 0;

// 오염 지역 확산 시키기
void BFS(int tmap[][9]){
    
    int visited[9][9] = { 0, };
    // 상하좌우
    int dir[4][2] = { {0,1}, {0,-1}, {1,0}, {-1,0} };
    queue<pair<int, int> > q;
    
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            // map = 0 : 비확산지역, map = 1 : 벽, map = 2 : 확산지역
            // 오염지역이고 방문한 적이 없으면 (확산되기 전 오염지역 탐색)
            if(tmap[i][j] == 2 && visited[i][j] == 0){
                visited[i][j] = 1;
                q.push(make_pair(i, j));
                
                while(!q.empty()){
                    int x = q.front().second;
                    int y = q.front().first;
                    q.pop();
                    for(int i = 0; i < 4; i++){
                        int nx = x + dir[i][0];
                        int ny = y + dir[i][1];
                        // 맵 안에 있으며 & 벽이 아니며 (이미 확산 되었거나 확산할 수 있으며) & 방문한 적이 없으면
                        // (아직 확산을 안했으면)
                        if(nx >= 1 && ny >= 1 && nx <= m && ny <= n && tmap[ny][nx] != 1 && visited[ny][nx] == 0){
                            visited[ny][nx] = 1;
                            tmap[ny][nx] = 2;
                            q.push(make_pair(ny, nx));
                        }
                    }
                }
            }
        }
    }
    
    int tmp = 0;
    // 완전 확산 후 비오염지역을 찾아 카운트해준다.
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(tmap[i][j] == 0){
                tmp++;
            }
        }
    }
    
    answer = max(answer, tmp);
}

void build(){
    
    int tmap[9][9];
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            tmap[i][j] = map[i][j];
        }
    }
    // 벽이 3개이므로 벽1의 x, y좌표 (j, i), 벽2의 x, y좌표 (l, k), 벽3의 x, y좌표 (y, x)를 전부 돌아준다.
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            for(int k = 1; k <= n; k++){
                for(int l = 1; l <= m; l++){
                    for(int x = 1; x <= n; x++){
                        for(int y = 1; y <= m; y++){
                            // 선택 좌표가 벽을 깔 수 있는 위치이며 & 벽1과 벽2와 벽3의 위치가 전부 달라야 한다.
                            if(tmap[i][j] == 0 && tmap[k][l] == 0 && tmap[x][y] == 0 && built[i][j][k][l][x][y] == 0 && (i != k || j != l) && (i != x || j != y) && (k != x || l != y)){
                                built[i][j][k][l][x][y] = 1;
                                // 벽을 깔아주고 BFS
                                tmap[i][j] = 1; tmap[k][l] = 1; tmap[x][y] = 1;

                                BFS(tmap);
                                // 다시 초기화
                                for(int p = 1; p <= n; p++){
                                    for(int q = 1; q <= m; q++){
                                        tmap[p][q] = map[p][q];
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}




int main(){
    
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin >> map[i][j];
        }
    }
    build();
    cout << answer;
    return 0;
}
