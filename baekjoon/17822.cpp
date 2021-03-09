//
//  17822.cpp
//  BJ
//
//  Created by 신기열 on 06/11/2019.
//  Copyright © 2019 신기열. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <queue>

using namespace std;

int n, m, t;
int map[52][52];
int order[50][3];
int dir[4][2] = { {0, 1}, {0, -1}, {1, 0}, {-1, 0} };
int answer;

// 1칸 회전하는 함수. mul은 몇의 배수인지 체크, dir은 시계 혹은 반시계 체크
void rotate(int mul, int dir){
    
    int tmap[52][52] = { 0, };
    
    for(int i = 1; i <= n; i++){
        // mul의 배수이면
        if(i % mul == 0){
            // 시계 방향이면
            if(dir == 0){
                // i -> i+1로 한 칸씩 이동하고 m-1 -> m, m -> 1로 이동하면 되겠다.
                for(int j = 1; j < m; j++){
                    tmap[i][j + 1] = map[i][j];
                }
                tmap[i][1] = map[i][m];
            }
            // 반시계 방향이면
            else if(dir == 1){
                // i -> i-1로 한 칸씩 이동하고 m -> m-1, 1 -> m으로 이동하면 되겠다.
                for(int j = 1; j < m; j++){
                    tmap[i][j] = map[i][j + 1];
                }
                tmap[i][m] = map[i][1];
            }
            for(int j = 1; j <= m; j++){
                map[i][j] = tmap[i][j];
            }
        }
    }
    
    //    cout << "rotation" << '\n';
    //    for(int i = 1; i <= n; i++){
    //        for(int j = 1; j <= m; j++){
    //            cout << map[i][j];
    //        }
    //        cout << '\n';
    //    }
    //    cout << '\n';
}

// 삭제 함수
void deleten(){
    
    int visited[52][52] = { 0, };
    bool isDeleted = false;
    int total = 0; int cnt = 0;
    
    // BFS로 인접한 숫자를 전부 확인할 수 있다. 가령
    //              2
    //              4
    //              1
    //       2 1 3     1 3 2
    //              1
    //              2
    //              1
    // 와 같은 원판은 아래와 같은 2차원 배열로 바꿔줄 수 있다. (안쪽이 가장 작은 행이고 위쪽부터 시계 방향으로)
    //
    // 1 1 1 3
    // 4 3 1 1
    // 2 2 1 2
    //
    // 따라서 (1,1),(1,2),(1,3),(2,3),(2,4),(3,3)은 1로 인접하므로 다 지워지고, (3,1),(3,2)는 2로 다 지워질 것이다.
    queue<pair<int, int> > q;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(visited[i][j] == 0){
                int curr = map[i][j];
                q.push(make_pair(j, i));
                while(!q.empty()){
                    int x = q.front().first, y = q.front().second; q.pop();
                    for(int d = 0; d < 4; d++){
                        int nx = x + dir[d][0], ny = y + dir[d][1];
                        // "첫"번째 원판부터 시작이므로 행번호를 그냥 1부터 시작하게 했다. 따라서 행은 1 ~ n 까지 탐색하면 된다.
                        if(ny > 0 && ny <= n){
                            // 현재 탐색 위치의 왼쪽이 0일 때 -> 탐색 하고자 하는 왼쪽이 m이 되도록 한다. (원판이므로 한바퀴 도니까)
                            if(nx == 0) nx = m;
                            // 현재 탐색 위치의 오른쪽이 m + 1일 때 -> 1이 되도록 한다.
                            else if(nx == m + 1) nx = 1;
                            // 다음 탐색 지점을 체크한 적이 없고 현재 탐색 위치의 숫자와 같으면,
                            // (참고로 현재 숫자와 다른 지점은 visited = 0이 유지되므로 나중에 또 탐색할 수 있다. 현재는 연결되어 있는 같은 값을 가진 부분만 탐색하는 것이라 보면 되겠다.
                            // 위의 배열로 따지면 (1,1),(1,2),(1,3),(2,3),(2,4),(3,3)만 전부 0으로 치환하고 visited = 1로 바꿔주는 것.)
                            if(visited[ny][nx] == 0 && map[ny][nx] == curr){
                                // 한번이라도 지운 적이 있으므로 isDeleted = true
                                if(curr != 0) isDeleted = true;
                                visited[ny][nx] = 1;
                                map[ny][nx] = 0;
                                q.push(make_pair(nx, ny));
                            }
                        }
                    }
                }
            }
            // 탐색하는 동시에 현재 부분이 0이 안 됐으면 = 인접한 부분에 같은 숫자가 있는게 하나도 없다면
            // total에 포함시키도록 한다. (어차피 이 위치는 앞으로도 변할 일이 없으므로)
            if(map[i][j] != 0) cnt++;
            total += map[i][j];
        }
    }
    // 원판에서 어떤 것도 지워진 적이 없으면
    if(!isDeleted){
        // 평균을 구하고
        double average = (double)total / (double)cnt;
        // 맵을 다시 다 돌면서 평균보다 작으면 +1, 크면 -1 해준다.
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                if(map[i][j] != 0){
                    if((double)map[i][j] > average){
                        map[i][j]--;
                    }
                    else if((double)map[i][j] < average){
                        map[i][j]++;
                    }
                }
            }
        }
    }
}

int main(){
    
    cin >> n >> m >> t;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin >> map[i][j];
        }
    }
    for(int i = 0; i < t; i++){
        cin >> order[i][0] >> order[i][1] >> order[i][2];
    }
    for(int i = 0; i < t; i++){
        // 회전은 order[i][2] (k 번) 만큼 해준다.
        for(int j = 0; j < order[i][2]; j++){
            rotate(order[i][0], order[i][1]);
        }
        deleten();
        
        //        cout << "delete" << '\n';
        //        for(int i = 1; i <= n; i++){
        //            for(int j = 1; j <= m; j++){
        //                cout << map[i][j];
        //            }
        //            cout << '\n';
        //        }
        //        cout << '\n';
    }
    
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            answer += map[i][j];
        }
    }
    cout << answer;
    return 0;
}
