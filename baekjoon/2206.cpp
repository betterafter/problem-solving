#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>
#include <queue>
#include <set>
#include <stack>
#include <map>

using namespace std;

int N, M;
int m[1001][1001];
int dir[4][2] = { {0,1}, {0,-1}, {1,0}, {-1,0} };
int visited[1001][1001];
int res = 987654321;

bool check(){
    bool chk = false;
    // 좌표쌍, 벽을 부쉈는지 여부, 이동 횟수
    queue<pair<pair<int, int>, pair<bool, int> > > q; q.push(make_pair(make_pair(1, 1), make_pair(false, 1)));
    int visited[1001][1001][2] = { 0, };
    visited[1][1][0] = 1;
    while(!q.empty()){
        int x = q.front().first.first, y = q.front().first.second; 
        int broke = q.front().second.first, move = q.front().second.second;
        q.pop();
        if(x == M && y == N){
            res = min(res, move); chk = true;
        }
        for(int i = 0; i < 4; i++){
            int xx = x + dir[i][0], yy = y + dir[i][1];
            if(xx >= 1 && xx <= M && yy >= 1 && yy <= N){
                if(visited[yy][xx][broke] == 0 && m[yy][xx] == 0){
                    visited[yy][xx][broke] = visited[yy][xx][broke] + 1; 
                    q.push(make_pair(make_pair(xx, yy), make_pair(broke, move + 1)));
                    //cout << "move! " << xx << " " << yy << "   bool : " << broke <<  '\n';
                }
                else if(broke == 0 && m[yy][xx] == 1){
                    visited[yy][xx][1] = visited[yy][xx][broke] + 1;
                    q.push(make_pair(make_pair(xx, yy), make_pair(true, move + 1)));
                    //cout << "broke! " << xx << " " << yy << "   bool : " << true <<  '\n';
                }
            }
        }
    }
    return chk;
}


void check2(int x, int y, int visited[1001][1001], bool broke, int move){

    if(x == M && y == N){
        res = min(move, res); return;
    }
    if(move > res) return;

    for(int i = 0; i < 4; i++){
            int xx = x + dir[i][0], yy = y + dir[i][1];
            if(xx >= 1 && xx <= M && yy >= 1 && yy <= N){
                if(visited[yy][xx] == 0 && m[yy][xx] == 0){
                    //cout << "move! " << xx << " " << yy << "   bool : " << broke <<  '\n';
                    visited[yy][xx] = 1; 
                    check2(xx, yy, visited, broke, move + 1);
                    visited[yy][xx] = 0;
                }
                else if(visited[yy][xx] == 0 && m[yy][xx] == 1){
                    if(!broke){
                        //cout << "broke! " << xx << " " << yy << "   bool : " << true <<  '\n';
                        visited[yy][xx] = 1;
                        check2(xx, yy, visited, true, move + 1);
                        visited[yy][xx] = 0;
                    }
                }
            }
        }
}

int main(){

    ios::sync_with_stdio(false);
	cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    for(int i = 1; i <= N; i++){
        string s; cin >> s;
        for(int j = 1; j <= M; j++){
            m[i][j] = s[j - 1] - '0';
        }
    }

    // for(int i = 1; i <= N; i++){
    //     for(int j = 1; j <= M; j++){
    //        cout <<  m[i][j] << " ";
    //     }
    //     cout << '\n';
    // }

    if(check()) cout << res;
    else cout << -1;
    return 0;
}
