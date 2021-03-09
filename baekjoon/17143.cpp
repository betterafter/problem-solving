//
//  17143.cpp
//  BJ
//
//  Created by 신기열 on 03/11/2019.
//  Copyright © 2019 신기열. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

//    1
// 4     3
//    2
// r, c, s, d, z
int map[101][101][3];
int R, C, M;
int posx;
int answer;
vector<pair<int, int> > spos;

// 낚시왕과 상어가 움직이는 함수
void move(){
    
    // 낚시왕을 오른쪽으로 1칸 이동시킨다.
    posx++;
    // 이동한 위치에서 깊이를 쭉 탐색하면서 제일 먼저 만나는 상어의 몸무게만큼 answer를 늘리고, 그 상어를 없애준다. 이 때, 상어를 찾는 기준은 몸무게이므로, 몸무게가 0이면 상어가 없다고 가정하게 된다.
    // 따라서 다른 건 초기화할 필요 없이 몸무게 정보만 업데이트해주면 된다.
    for(int i = 1; i <= R; i++){
        if(map[i][posx][2] > 0){
            answer += map[i][posx][2];
            map[i][posx][2] = 0;
            break;
        }
    }
    // 순서대로 속도, 이동방향, 몸무게
    int tmap[101][101][3] = { 0, };
    for(int i = 0; i < spos.size(); i++){
        // 상어는 spos에 저장되어 있다.
        int x = spos[i].first, y = spos[i].second;
        // 몸무게가 0보다 클 때 = 상어가 존재할 때
        if(map[y][x][2] > 0){
            // 이 상어의 정보를 따로 기록해둔다.
            int ts = map[y][x][0], td = map[y][x][1], tz = map[y][x][2];
            // tts는 현재까지 이동한 거리를 체크하기 위한 변수. 이동할 거리인 tts가 0일 될 때까지 while문을 돌아준다.
            int tts = ts;
            while(tts > 0){
                // 위로 갈 때
                if(td == 1){
                    // 맵 밖으로 나가게 되면
                    if(y - 1 < 1){
                        // 아래 방향으로 향하고 한 칸 이동한다.
                        td = 2; y++;
                    }
                    // 맵 밖으로 나가는게 아니면 이동방향으로 직진한다.
                    else y--;
                }
                // 다른 방향도 알고리즘은 같다.
                // 아래
                else if(td == 2){
                    if(y + 1 > R){
                        td = 1; y--;
                    }
                    else y++;
                }
                // 오른쪽
                else if(td == 3){
                    if(x + 1 > C){
                        td = 4; x--;
                    }
                    else x++;
                }
                // 왼쪽
                else if(td == 4){
                    if(x - 1 < 1){
                        td = 3; x++;
                    }
                    else x--;
                }
                tts--;
            }
            // 각 상어들은 최종적으로 도착한 위치인 tmap에 저장되는데, 도착한 위치에 자기보다 작은 상어가 있으면 잡아먹고(현재 상어를 기록), 큰 상어가 있으면 잡아먹힌다.(이전 상어 기록을 그대로 냅둠.)
            if(tmap[y][x][2] < tz){ tmap[y][x][0] = ts; tmap[y][x][1] = td; tmap[y][x][2] = tz; }
        }
    }
    // 상어는 먹고 먹히기 때문에 항상 정보가 변한다. 따라서 일단 상어 vector를 전부 비워준다.
    spos.clear();
    // 그 후 맵을 다시 처음부터 돌면서 상어가 어디에 있는지 찾고, 그 상어에 대한 정보를 업데이트 해준다. 그 후, 상어 벡터에 넣어준다.
    for(int i = 1; i <= R; i++){
        for(int j = 1; j <= C; j++){
            map[i][j][2] = 0;
            if(tmap[i][j][2] > 0){
                map[i][j][0] = tmap[i][j][0]; map[i][j][1] = tmap[i][j][1]; map[i][j][2] = tmap[i][j][2];
                spos.push_back(make_pair(j, i));
            }
        }
    }
}


int main(){
    
    cin >> R >> C >> M;
    for(int i = 0; i < M; i++){
        int r, c, s, d, z;
        cin >> r >> c >> s >> d >> z;
        map[r][c][0] = s; map[r][c][1] = d; map[r][c][2] = z;
        spos.push_back(make_pair(c, r));
    }
    
//    cout << "init" << '\n';
//    for(int i = 1; i <= R; i++){
//        for(int j = 1; j <= C; j++){
//            cout<< map[i][j][2];
//        }
//        cout << '\n';
//    }
//    cout << '\n';
    
    posx = 0;
    while(posx < C){
        move();
//        cout << posx << '\n';
//        for(int i = 1; i <= R; i++){
//            for(int j = 1; j <= C; j++){
//                cout << map[i][j][2];
//            }
//            cout << '\n';
//        }
//        cout << '\n';
    }
    
    cout << answer;
    return 0;
}
