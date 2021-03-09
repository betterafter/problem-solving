//
//  13460.cpp
//  BJ
//
//  Created by 신기열 on 18/10/2019.
//  Copyright © 2019 신기열. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

char map[11][11];
int dir[4][2] = { {0,1}, {1,0}, {0,-1}, {-1,0} };
int n, m;
int answer = 11;

// 빨간 구슬과 파란 구슬의 위치를 동시에 저장
int isDirVisited[11][11][11][11];


void BFS(int rx, int ry, int bx, int by, int cnt){
    
    queue<pair<pair<pair<int, int>, pair<int, int> >, int> > q;
    q.push(make_pair(make_pair(make_pair(rx, ry), make_pair(bx, by)), cnt));
    
    while(!q.empty()){
        
        int Rx = q.front().first.first.first;
        int Ry = q.front().first.first.second;
        int Bx = q.front().first.second.first;
        int By = q.front().first.second.second;
        int c = q.front().second;
        
        int x1 = Rx, y1 = Ry, x2 = Bx, y2 = By;
        
        q.pop();
        // 10회 이하로 탐색이므로 10이 넘어가버리면 탐색을 중단한다.
        if(c >= 11) continue;

        for(int i = 0; i < 4; i++){
            Rx = x1; Ry = y1; Bx = x2; By = y2;               // 상,하,좌,우 탐색이므로 초기화를 위한 코드
            bool isBlueIn = false; bool isRedIn = false;      // 구슬이 홀에 들어갔는지 확인
            int isBlueMove = true; int isRedMove = true;      // 구슬이 움직일 수 있는지 확인
            

            while(1){
                // 빨간 구슬이 좌표 상에 있으며 & 움직이는 방향에 #이 없으며 & 홀에 들어간 상태가 아닐 경우
                if(Rx + dir[i][0] > 1 && Ry + dir[i][1] > 1 && Rx + dir[i][0] < m && Ry + dir[i][1] < n
                   && map[Ry + dir[i][1]][Rx + dir[i][0]] != '#' && isRedIn == false){
                    // 일단 움직일 수 있는 상태임
                    isRedMove = true;

                    // 움직이고자 하는 칸에 파란 구슬이 없으며 & 파란 구슬이 위치한 것이긴 한데 홀에 들어간 것이면
                    if(Rx + dir[i][0] != Bx || Ry + dir[i][1] != By ||
                       (Rx + dir[i][0] == Bx && Ry + dir[i][1] == By && isBlueIn)){
                        // 빨간 구슬도 한칸 이동해주자.
                        Rx = Rx + dir[i][0]; Ry = Ry + dir[i][1];
                    }
                    // 여기서 파란 구슬이 홀에 들어간걸 체크를 해주지 않으면, 코드는 좌표 상으로만 체크해주는 것이므로 앞에 파란 구슬이
                    // 홀에 빠지건 말건 앞에 있다고 치부해버려서 빨간 구슬이 움직이지 않는다. 홀에 들어간 건 없는 상태이므로 앞으로 움직일
                    // 수 있게 해주자.
                    
                    
                    // 그게 아니라면 빨간 구슬은 움직일 수 없는 상태이다.
                    else isRedMove = false;
                    
                    // 움직인 후의 빨간 구슬이 홀에 들어간 상태이면 isRedin을 true로 만든다.
                    if(map[Ry][Rx] == 'O') isRedIn = true;
                }
                // 빨간 구슬이 좌표 상에 없거나, #이 있거나, 홀에 들어가있으면 움직일 수 없는 상태이다.
                else isRedMove = false;
                // 여기도 위와 똑같다. 단지 파란 구슬이 움직이냐 빨간구슬이 움직이냐 차이.
                if(Bx + dir[i][0] > 1 && By + dir[i][1] > 1 && Bx + dir[i][0] < m && By + dir[i][1] < n
                   && map[By + dir[i][1]][Bx + dir[i][0]] != '#' && isBlueIn == false){
                    isBlueMove = true;

                    if(Bx + dir[i][0] != Rx || By + dir[i][1] != Ry ||
                       (Bx + dir[i][0] == Rx && By + dir[i][1] == Ry && isRedIn)){
                        Bx = Bx + dir[i][0]; By = By + dir[i][1];
                    }
                    else isBlueMove = false;
                    
                    if(map[By][Bx] == 'O') isBlueIn = true;
                }
                else isBlueMove = false;
                
                if(!isBlueMove && !isRedMove) break;
            }
            // 참고로 빨간 구슬과 파란 구슬이 움직이는 순서는 마음대로 해도 된다. 어차피 누가 먼저 움직이든 '더 이상 움직일 수 없는 상태'가 되기
            // 전까지 계속 움직이는 것이기 때문에 앞에 다른 색의 구슬이 있으면 잠깐 멈췄다가 그 구슬이 움직이면 다음부터 다시 움직일 수 있는 상태가
            // 되니까.

            // 파란색이 안들어가고, 빨간색만 들어간 '성공' 상태이면 횟수를 업데이트 해준다.
            if(!isBlueIn && isRedIn) { answer = min(answer, c + 1); }
            // 파란 구슬, 빨간 구슬 둘 중 아무것도 홀에 안들어 가고, 현재 두 구슬의 동시로 위치한 적이 있지 않았으면 q에 넣고, 있었으면 다시
            // 여기서부터 탐색할 필요가 없어진다.
            else if(!isBlueIn && !isRedIn && isDirVisited[Ry][Rx][By][Bx] == 0){
                q.push(make_pair(make_pair(make_pair(Rx, Ry), make_pair(Bx, By)), c + 1));
                isDirVisited[Ry][Rx][By][Bx] = 1;
            }
        }
    }
}

int main(){

    cin >> n >> m;

    string s[11];
    int rx = 0, ry = 0, bx = 0, by = 0;

    for(int i = 0; i < n; i++){
        cin >> s[i];
    }

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            map[i][j] = s[i - 1][j - 1];
            if(map[i][j] == 'B'){
                bx = j; by = i;
            }
            else if(map[i][j] == 'R'){
                rx = j; ry = i;
            }
        }
    }

    BFS(rx, ry, bx, by, 0);
    if(answer >= 11) cout << -1;
    else cout << answer;
    
    return 0;
}
