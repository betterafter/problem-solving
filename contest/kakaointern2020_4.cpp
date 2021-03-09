#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int direction[4][2] = { {0, 1}, {1, 0}, {-1, 0}, {0, -1} };
int sval = 100;
int cval = 500;
int res = 1000000000;
int map[26][26][5];

int min(int a, int b){
    if(a < b) return a;
    else return b;
}



void bfs(vector<vector<int> > board){

    int visited[26][26] = { 0, };
    int val[26][26] = { 0, };

    queue<pair<pair<int, int>, pair<int, int> > > q;
    q.push(make_pair(make_pair(0, 0), make_pair(0, 0)));

    for(int i = 0; i < board.size(); i++){
        for(int j = 0; j < board[i].size(); j++){
            for(int k = 0; k < 5; k++){
                map[i][j][k] = res;
            }
        }
    }

    map[0][0][0] = 0;
    map[0][0][1] = 0;
    map[0][0][2] = 0;
    map[0][0][3] = 0;
    map[0][0][4] = 0;

    
    while(!q.empty()){
        int x = q.front().first.first;
        int y = q.front().first.second;
        int value = q.front().second.first;
        int dir = q.front().second.second;
        q.pop();


        // for(int i = 0; i < board.size(); i++){
        //     for(int j = 0; j < board[i].size(); j++){
        //         int min;
        //         for(int k = 1; k < 5; k++){
        //             min = map[i][j][k];
        //         } 
        //         cout << min << " ";
        //     }
        //     cout << '\n';
        // }
        // cout << '\n';


        // dir
        // 0 : 처음   1 : 왼쪽   2 : 오른쪽   3 : 위쪽   4 : 아래쪽
        if(x == board.size() - 1 && y == board.size() - 1){
            res = min(res, value);
        }

        for(int i = 0; i < 4; i++){

            int nx = x + direction[i][0];
            int ny = y + direction[i][1];

            if(nx >= 0 && ny >= 0 && nx < board.size() && ny < board.size() && board[ny][nx] == 0){
                // 처음일 때 
                if(dir == 0){
                    if(x == nx){
                        map[ny][nx][2] = value + sval;
                        q.push(make_pair(make_pair(nx, ny), make_pair(value + sval, 2)));
                    }
                    else if(y == ny){
                        map[ny][nx][4] = value + sval;
                        q.push(make_pair(make_pair(nx, ny), make_pair(value + sval, 4)));
                    }
                }
                // 수평일 때 
                else if(dir == 1 || dir == 2){
                    if(x == nx && map[ny][nx][dir] > value + sval){
                        map[ny][nx][dir] = value + sval;
                        q.push(make_pair(make_pair(nx, ny), make_pair(value + sval, dir)));
                    }
                    else if(y == ny){
                        if(x < nx && map[ny][nx][3] > value + sval + cval){
                            map[ny][nx][3] = value + sval + cval;
                            q.push(make_pair(make_pair(nx, ny), make_pair(value + sval + cval, 3)));
                        }
                        else if(x > nx && map[ny][nx][4] > value + sval + cval){
                            map[ny][nx][4] = value + sval + cval;
                            q.push(make_pair(make_pair(nx, ny), make_pair(value + sval + cval, 4)));
                        }
                    }
                }
                // 수직일 때 
                else if(dir == 3 || dir == 4){
                    if(y == ny && map[ny][nx][dir] > value + sval){
                        map[ny][nx][dir] = value + sval;
                        q.push(make_pair(make_pair(nx, ny), make_pair(value + sval, dir)));
                    }
                    else if(x == nx){
                        if(y < ny && map[ny][nx][1] > value + sval + cval){
                            map[ny][nx][1] = value + sval + cval;
                            q.push(make_pair(make_pair(nx, ny), make_pair(value + sval + cval, 1)));
                        }
                        else if(y > ny && map[ny][nx][2] > value + sval + cval){
                            map[ny][nx][2] = value + sval + cval;
                            q.push(make_pair(make_pair(nx, ny), make_pair(value + sval + cval, 2)));
                        }
                    }
                }
            }
        }

    }
}


int solution(vector<vector<int> > board) {
    int answer = res;

    //dfs(board, 0, 0, 0, 0, visit);
    bfs(board);
    for(int i = 1; i < 5; i++){
        answer = min(answer, map[board.size() - 1][board.size() - 1][i]);
    }

    return answer;
}


int main(){

    vector<vector<int> > board;
    // vector<int> a,b,c,d,e,f,g,h;
    // a.assign(8, 0);
    // b.assign(8, 0);
    // c.assign(8, 0);
    // d.assign(8, 0);
    // e.assign(8, 0);
    // f.assign(8, 0);
    // g.assign(8, 0);
    // h.assign(8, 0);


    // a[7] = 1;
    // c[5] = 1;
    // d[4] = 1;
    // e[3] = 1;
    // e[7] = 1;
    // f[2] = 1;
    // f[6] = 1;
    // g[1] = 1;
    // g[5] = 1;
    // h[0] = 1;

    // board.push_back(a);
    // board.push_back(b);
    // board.push_back(c);
    // board.push_back(d);
    // board.push_back(e);
    // board.push_back(f);
    // board.push_back(g);
    // board.push_back(h);


    // vector<int> a, b, c;
    // a.assign(3, 0);
    // b.assign(3, 0);
    // c.assign(3, 0);
    // board.push_back(a);
    // board.push_back(b);
    // board.push_back(c);


    vector<int> a, b, c, d;
    a.assign(8, 0);
    b.assign(8, 0);
    c.assign(8, 0);
    d.assign(8, 0);

    a[2] = 1;
    c[1] = 1;
    c[3] = 1;
    d[0] = 1;

    board.push_back(a);
    board.push_back(b);
    board.push_back(c);
    board.push_back(d);

    //cout << solution(board);

    return 0;
}






