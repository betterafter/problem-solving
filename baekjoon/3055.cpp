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

int R, C;
char m[51][51];
int dir[4][2] = { {0,1},{0,-1},{1,0},{-1,0} };
int visited[51][51];
int wvisited[51][51];
int sx, sy;
int ans;
queue<pair<pair<int,int>, pair<char,int> > > q;



void bfs(){

    while(!q.empty()){
        int size = q.size();
        for(int i = 0; i < size; i++){
            int x = q.front().first.first, y = q.front().first.second;
            char ch = q.front().second.first;
            int cnt = q.front().second.second;
            q.pop();

            if(ch == '*'){
                for(int i = 0; i < 4; i++){
                    int xx = x + dir[i][0], yy = y + dir[i][1];
                    if(xx >= 0 && xx < C && yy >= 0 && yy < R && m[yy][xx] == '.'){
                        m[yy][xx] = '*';
                        q.push(make_pair(make_pair(xx,yy), make_pair('*', cnt + 1)));
                    }
                }
            }
            else if(ch == 'S'){

                if(m[y][x] == 'D'){
                    ans = cnt; return;
                }
                for(int i = 0; i < 4; i++){
                    int xx = x + dir[i][0], yy = y + dir[i][1];
                    if(xx >= 0 && xx < C && yy >= 0 && yy < R && (m[yy][xx] == '.' || m[yy][xx] == 'D') && visited[yy][xx] == 0){
                        visited[yy][xx] = 1;
                        q.push(make_pair(make_pair(xx,yy), make_pair('S', cnt + 1)));
                    }
                }
            }
        }
    }
    

}   

int main(){

    ios::sync_with_stdio(false);
	cin.tie(NULL);
    cout.tie(NULL);

    cin >> R >> C;

    for(int i = 0; i < R; i++){
        for(int j = 0; j < C; j++){
            cin >> m[i][j];
            if(m[i][j] == '*'){
                q.push(make_pair(make_pair(j,i), make_pair('*', 0)));
            }
        }
    }
    for(int i = 0; i < R; i++){
        for(int j = 0; j < C; j++){
            if(m[i][j] == 'S'){
                m[i][j] = '.';
                q.push(make_pair(make_pair(j,i), make_pair('S', 0)));
            }
        }
    }
    bfs();
    if(ans == 0) cout << "KAKTUS";
    else cout << ans;
    return 0;
}

