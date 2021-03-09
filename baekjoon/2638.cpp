#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>
#include <queue>
#include <set>
#include <stack>
#include <map>
#include <limits.h>

using namespace std;

int N, M;
int c[101][101];
int visited[101][101];
int dir[4][2] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };
queue<pair<int, int> > q;
queue<pair<int, int> > tmp;
int ans;

// 정확한 이유는 모르지만 지워지는 치즈를 큐 하나에 담아서 bfs를 돌리지 않고 지워지는 치즈마다 bfs를 각각 적용시켜서 시간이 오래 걸린듯 싶다.
void init(int inx, int iny){
    queue<pair<int, int> > qq;
    qq.push(make_pair(inx, iny));
    visited[inx][iny] = 1;
    while(!qq.empty()){
        int x = qq.front().first, y = qq.front().second; qq.pop();
        for(int i = 0; i < 4; i++){
            int xx = x + dir[i][0], yy = y + dir[i][1];
            if(xx >= 0 && xx < M && yy >= 0 && yy < N){
                if(visited[yy][xx] == 0){
                    visited[yy][xx] = 1;
                    qq.push(make_pair(xx, yy));
                }
            }
        }
    }
}

void print(){
    cout << '\n';
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cout << c[i][j] << " ";
        }
        cout << '\n';
    }
    cout << '\n';
}

void print2(){
    cout << '\n';
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cout << visited[i][j] << " ";
        }
        cout << '\n';
    }
    cout << '\n';
}

void remove(vector<pair<int, int> > erase){
    for(int i = 0; i < erase.size(); i++){
        int x = erase[i].first, y = erase[i].second;
        c[y][x] = 0; visited[y][x] = 1; tmp.push(make_pair(x, y));
    }
    while(!tmp.empty()){
        int x = tmp.front().first, y = tmp.front().second; tmp.pop();
        for(int i = 0; i < 4; i++){
            int xx = x + dir[i][0], yy = y + dir[i][1];
            if(xx >= 0 && xx < M && yy >= 0 && yy < N){
                if(visited[yy][xx] == 0){
                    visited[yy][xx] = 1;
                    tmp.push(make_pair(xx, yy));
                }
            }
        }
    }
    
}

void check(){

    vector<pair<int, int> > erase;
    while(!q.empty()){
        int size = q.size();
        for(int i = 0; i < size; i++){
            int x = q.front().first, y = q.front().second; q.pop();
            int cnt = 0;
            for(int i = 0; i < 4; i++){
                int xx = x + dir[i][0], yy = y + dir[i][1];
                if(xx >= 0 && xx < M && yy >= 0 && yy < N){
                    if(visited[yy][xx] == 1) cnt++;
                }
            }
            if(cnt >= 2){
                erase.push_back(make_pair(x, y));
            }
            else q.push(make_pair(x, y));
        }
        if(erase.size() == 0) return;
        remove(erase);
        //print();
        ans++;
    }
}



int main(){

    ios::sync_with_stdio(false);
	cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin >> c[i][j];
            if(c[i][j] == 1){
                q.push(make_pair(j, i)); visited[i][j] = 2;
            }
        }
    }
    init(0, 0);
    check();

    cout << ans;
    return 0;
}

