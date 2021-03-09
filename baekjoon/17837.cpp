//
//  17837.cpp
//  BJ
//
//  Created by 신기열 on 06/11/2019.
//  Copyright © 2019 신기열. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>
#include <stack>

using namespace std;


vector<pair<pair<int, int>, int> > horse;
vector<int> v[13][13];
int map[13][13];
int n, k;
int answer;
int isEnd;
//    3
//  2   1
//    4

// 체스말을 움직이는 함수
void move(int x, int y, int nx, int ny, int num){
    //cout << num << " " << x << " " << y << " " << nx << " " << ny << '\n';
    
    // 움직이려는 방향이 흰색인 경우
    if(map[ny][nx] == 0){
        // 현재 좌표의 벡터를 전부 돌면서
        for(int i = 0; i < v[y][x].size(); i++){
            if(v[y][x][i] == num){
                // 현재 인덱스가 움직이고자 하는 말 번호인 경우
                int hn = 0, idx = i, s = (int)v[y][x].size();
                // 현재부터 끝까지 전부 돌면서
                while(idx < s){
                    // 움직이고자 하는 다음 좌표의 벡터에 순서대로 넣어준다 (스택의 방식)
                    v[ny][nx].push_back(v[y][x][idx]);
                    // 이 때, 움직이는 말 + 위에 쌓인 말들도 전부 좌표가 같이 이동하므로, 전부 좌표를 업데이트 해준다.
                    horse[v[y][x][idx] - 1].first.first = nx; horse[v[y][x][idx] - 1].first.second = ny;
                    idx++; hn++;
                }
                // 움직인 말의 개수만큼 원래 좌표에 쌓인 말들을 전부 빼준다.
                while(hn > 0){
                    v[y][x].pop_back(); hn--;
                }
                break;
            }
        }
        // 이 때 다음 좌표에 4개 이상이 쌓여있으면, isEnd = true로 바꿔 좌표를 전부 돌지 않아도 바로 탈출할 수 있게 해준다.
        if(v[ny][nx].size() >= 4) isEnd = true;
    }
    // 움직이려는 방향이 빨간색인 경우
    else if(map[ny][nx] == 1){
        int s = (int)v[y][x].size() - 1;
        // 이번엔 쌓은 순서를 바꿔줘야하므로 맨 위에서부터 차례대로 빼고 넣고를 반복해준다.
        // "다음" 인덱스가 원하는 말 번호가 아닐 때 까지 (움직이고자 하는 말 위에 쌓인 말들만)
        while(v[y][x][s] != num){
            // 위에서부터 차례대로 넣어주고, 좌표를 업데이트하고, 빼준다.
            v[ny][nx].push_back(v[y][x][s]);
            horse[v[y][x][s] - 1].first.first = nx; horse[v[y][x][s] - 1].first.second = ny;
            v[y][x].pop_back();
            s--;
        }
        // 넣어준게 움직이려는 말 위에 쌓인 것들만 넣어줬으므로, 이제 움직이려는 말도 넣어줘야한다.
        v[ny][nx].push_back(v[y][x][s]);
        horse[v[y][x][s] - 1].first.first = nx; horse[v[y][x][s] - 1].first.second = ny;
        v[y][x].pop_back();
        if(v[ny][nx].size() >= 4) isEnd = true;
    }
    // 움직이려는 방향이 파란색인 경우는 turn 함수에서 미리 처리를 해서 따로 처리를 할 필요가 없다.
}

void turn(){
    
    // answer가 1000이 넘어갈 때까지 계속 탐색해준다.
    while(1){
        // 말을 넣어준 벡터를 전부 돌면서, 끝까지 다 돌 때 1턴 추가한다.
        for(int i = 1; i <= horse.size(); i++){
            int x = horse[i - 1].first.first, y = horse[i - 1].first.second, dir = horse[i - 1].second;
            int nx = 0, ny = 0;
            // 현재 말이 오른쪽으로 갈 때
            if(dir == 1){
                // 다음 좌표를 x방향으로 1 증가하고
                nx = x + 1; ny = y;
                // 증가한 좌표의 칸이 파란색이거나, 맵 밖을 벗어날 때
                if(map[ny][nx] == 2 || nx <= 0 || ny <= 0 || nx > n || ny > n){
                    // 방향을 반대로 해주고, 다음으로 가려는 좌표도 현재에서 1 감소시켜준다.
                    horse[i - 1].second = 2; nx = x - 1; ny = y;
                    // 이 때, 다음으로 가려는 좌표가 다시 파란색이거나 맵 밖을 벗어날 때
                    if(map[ny][nx] == 2 || nx <= 0 || ny <= 0 || nx > n || ny > n){
                        // 방향은 이미 바꿔놨고, 위치는 그대로 해준다.
                        nx = x; ny = y;
                    }
                    // 방향을 바꿔서 이동하려는 다음 좌표가 파란색도 아니고, 맵도 벗어나지 않았으면 move함수를 실행한다.
                    else move(x, y, nx, ny, i);
                }
                // 방향을 바꾸기 전에 이동하려고 했던 좌표가 파란색도 아니고, 맵도 벗어나지 않았으면 그냥 move함수를 실행한다.
                else move(x, y, nx, ny, i);
                // move함수가 끝나고 isEnd가 true가 되었다면, 더 이상 돌 필요가 없다.
                if(isEnd) return;
            }
            // 나머지도 알고리즘은 같다.
            
            // 현재 말이 왼쪽으로 갈 때
            else if(dir == 2){
                nx = x - 1; ny = y;
                if(map[ny][nx] == 2 || nx <= 0 || ny <= 0 || nx > n || ny > n){
                    horse[i - 1].second = 1; nx = x + 1; ny = y;
                    if(map[ny][nx] == 2 || nx <= 0 || ny <= 0 || nx > n || ny > n){
                        nx = x; ny = y;
                    }
                    else move(x, y, nx, ny, i);
                }
                else move(x, y, nx, ny, i);
                if(isEnd) return;
            }
            // 현재 말이 위쪽 (y가 감소하는 방향)으로 갈 때
            else if(dir == 3){
                nx = x; ny = y - 1;
                if(map[ny][nx] == 2 || nx <= 0 || ny <= 0 || nx > n || ny > n){
                    horse[i - 1].second = 4; nx = x; ny = y + 1;
                    if(map[ny][nx] == 2 || nx <= 0 || ny <= 0 || nx > n || ny > n){
                        nx = x; ny = y;
                    }
                    else move(x, y, nx, ny, i);
                }
                else move(x, y, nx, ny, i);
                if(isEnd) return;
            }
            // 현재 말이 아래쪽 (y가 증가하는 방향)으로 갈 때
            else if(dir == 4){
                nx = x; ny = y + 1;
                if(map[ny][nx] == 2 || nx <= 0 || ny <= 0 || nx > n || ny > n){
                    horse[i - 1].second = 3; nx = x; ny = y - 1;
                    if(map[ny][nx] == 2 || nx <= 0 || ny <= 0 || nx > n || ny > n){
                        nx = x; ny = y;
                    }
                    else move(x, y, nx, ny, i);
                }
                else move(x, y, nx, ny, i);
                if(isEnd) return;
            }
//            for(int i = 1; i <= n; i++){
//                for(int j = 1; j <= n; j++){
//                    if(v[i][j].size() == 0) cout << 0;
//                    for(int k = 0; k < v[i][j].size(); k++){
//                        cout << v[i][j][k];
//                    }
//                    cout << " ";
//                }
//                cout << '\n';
//            }
//            cout << '\n';
        }
        answer++;
        
        if(answer > 1000){
            answer = -1; return;
        }
    }
}

int main(){
    
    cin >> n >> k;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin >> map[i][j];
        }
    }
    for(int i = 0; i < k; i++){
        int x, y, d;
        cin >> y >> x >> d;
        horse.push_back(make_pair(make_pair(x, y), d));
        v[y][x].push_back(i + 1);
    }
    isEnd = false; answer = 1;
    turn();
    cout << answer;
    return 0;
}
