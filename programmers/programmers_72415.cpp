#include <string>
#include <vector>
#include <queue>
#include <math.h>
#include <algorithm>
#include <iostream>

using namespace std;

int m[4][4];

int dir[4][2] = { {0,1}, {1, 0}, {0,-1}, {-1,0} };

int bfs(int x, int y, int tx, int ty, vector<vector<int> > removed){

    if(x == tx && y == ty) return 0;
    int visited[4][4];
    int res = 999999999;
    for(int i = 0; i < 4; i++) for(int j = 0; j < 4; j++) visited[i][j] = 99999999;
    visited[y][x] = 0;

    // x좌표, y좌표, 이동 횟수
    queue<pair<int, int> > q;
    q.push(make_pair(x, y));

    while(!q.empty()){
        int xx = q.front().first; int yy = q.front().second; q.pop();
        if(xx == tx && yy == ty) continue;

        // 한칸만 이동
        for(int i = 0; i < 4; i++){
            int nx = dir[i][0] + xx; int ny = dir[i][1] + yy;
            if(nx >= 0 && nx < 4 && ny >= 0 && ny < 4){
                if(visited[ny][nx] > visited[yy][xx] + 1){
                    visited[ny][nx] = visited[yy][xx] + 1;
                    q.push(make_pair(nx, ny));
                }
            }
        }


        // ctrl 이동 : x방향 오른쪽
        int mx = 1;
        while(xx + mx < 4){
            if(removed[yy][xx + mx] == 0){
                if(visited[yy][xx + mx] > visited[yy][xx] + 1){
                    visited[yy][xx + mx] = visited[yy][xx] + 1;
                    q.push(make_pair(xx + mx, yy));
                }
                break;
            }
            else if((xx + mx == 3)){
                if(visited[yy][xx + mx] > visited[yy][xx] + 1){
                    visited[yy][xx + mx] = visited[yy][xx] + 1;
                    q.push(make_pair(xx + mx, yy));
                    break;
                }
            }
            mx++;
        }


        // ctrl 이동 : x방향 왼쪽
        mx = -1;
        while(xx + mx >= 0){
            if(removed[yy][xx + mx] == 0){
                if(visited[yy][xx + mx] > visited[yy][xx] + 1){
                    visited[yy][xx + mx] = visited[yy][xx] + 1;
                    q.push(make_pair(xx + mx, yy));
                    
                }
                break;
            }
            else if((xx + mx == 0)){
                if(visited[yy][xx + mx] > visited[yy][xx] + 1){
                    visited[yy][xx + mx] = visited[yy][xx] + 1;
                    q.push(make_pair(xx + mx, yy));
                    break;
                }
            }
            mx--;
        }


          // ctrl 이동 : y방향 위쪽
        int my = -1;
        while(yy + my >= 0){
            if(removed[yy + my][xx] == 0){
                if(visited[yy + my][xx] > visited[yy][xx] + 1){
                    visited[yy + my][xx] = visited[yy][xx] + 1;
                    q.push(make_pair(xx, yy + my));
                    
                }
                break;
            }
            else if((yy + my == 0)){
                if(visited[yy + my][xx] > visited[yy][xx] + 1){
                    visited[yy + my][xx] = visited[yy][xx] + 1;
                    q.push(make_pair(xx, yy + my));
                    break;
                }
            }
            my--;
        }

        // ctrl 이동 : y방향 아래쪽
        my = 1;
        while(yy + my < 4){
            if(removed[yy + my][xx] == 0){
                if(visited[yy + my][xx] > visited[yy][xx] + 1){
                    visited[yy + my][xx] = visited[yy][xx] + 1;
                    q.push(make_pair(xx, yy + my));
                    
                }
                break;
            }
            else if((yy + my == 3)){
                if(visited[yy + my][xx] > visited[yy][xx] + 1){
                    visited[yy + my][xx] = visited[yy][xx] + 1;
                    q.push(make_pair(xx, yy + my));
                    break;
                }
            }
            my++;
        }

    }

    return visited[ty][tx];
}

int moveToCard(int xx, int yy, int count){

    //cout << x << " " << y << '\n';

    int res = 99999999;
    vector<vector<int> > deleted;
    for(int i = 0; i < 4; i++) {
        vector<int> v;
        for(int j = 0; j < 4; j++) {
            if(m[i][j] == 0) v.push_back(-1);
            else v.push_back(0);
        }
        deleted.push_back(v);
    }


    queue<pair<pair<int, int>, pair<int, vector<vector<int> > > > > q; 
    q.push(make_pair(make_pair(xx, yy), make_pair(0, deleted)));

    while(!q.empty()){
        int x = q.front().first.first;
        int y = q.front().first.second;
        int cnt = q.front().second.first;
        vector<vector<int> > b = q.front().second.second;
        q.pop();

        bool isEnd = true;
        for(int i = 0; i < 4; i++){ 
            for(int j = 0; j < 4; j++){
                if(m[i][j] != 0 && b[i][j] == 0){
                    isEnd = false;
                }
            }
        }

        if(isEnd){ 
            res = min(res, cnt); 
            continue;
        }
        
        for(int i = 0; i < 4; i++){
            for(int j = 0; j < 4; j++){
                if(b[i][j] == 0){
                    int temp = cnt;
 
                    for(int ii = 0; ii < 4; ii++){
                        for(int jj = 0; jj < 4; jj++){
                            if((ii != i || jj != j) && m[i][j] == m[ii][jj]){

                                temp += bfs(x, y, j, i, b);
                                temp += bfs(j, i, jj, ii, b);
                                temp += 2;
                                b[i][j] = 1;
                                b[ii][jj] = 1;
                              
                                q.push(make_pair(make_pair(jj, ii), make_pair(temp, b)));
                                b[i][j] = 0;
                                b[ii][jj] = 0;
                            } 
                        }
                    }
                }
            }
        }
    }

    return res;
}



int solution(vector<vector<int> > board, int r, int c) {
    int answer = 0;

    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            m[i][j] = board[i][j];
        }
    }

    answer = moveToCard(c, r, 0);


    return answer;
}

