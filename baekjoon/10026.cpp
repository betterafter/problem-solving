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

int N;
char section[101][101];
int dir[4][2] = { {1,0}, {-1,0}, {0,1}, {0,-1} };
int rg, nrg;

void redgreen(){

    int visited[101][101] = { 0, }; 

    for(int y = 0; y < N; y++){
        for(int x = 0; x < N; x++){
            if(visited[y][x] == 0){
                visited[y][x] = 1;
                queue<pair<int, int> > q; q.push(make_pair(x, y)); rg++;
                while(!q.empty()){
                    int xx = q.front().first, yy = q.front().second; q.pop();
                    for(int i = 0; i < 4; i++){
                        int xxx = xx + dir[i][0], yyy = yy + dir[i][1];
                        if(xxx < N && xxx >= 0 && yyy < N && yyy >= 0 && visited[yyy][xxx] == 0){
                            if(section[y][x] == section[yyy][xxx]){
                                visited[yyy][xxx] = 1;
                                q.push(make_pair(xxx, yyy));
                            }
                        }
                    }
                }
            }
        }
    }
}

void noneredgreen(){

    int visited[101][101] = { 0, }; 

    for(int y = 0; y < N; y++){
        for(int x = 0; x < N; x++){
            if(visited[y][x] == 0){
                visited[y][x] = 1;
                queue<pair<int, int> > q; q.push(make_pair(x, y)); nrg++;
                while(!q.empty()){
                    int xx = q.front().first, yy = q.front().second; q.pop();
                    for(int i = 0; i < 4; i++){
                        int xxx = xx + dir[i][0], yyy = yy + dir[i][1];
                        if(xxx < N && xxx >= 0 && yyy < N && yyy >= 0 && visited[yyy][xxx] == 0){
                            if(section[y][x] == 'R' || section[y][x] == 'G'){
                                if(section[yyy][xxx] == 'R' || section[yyy][xxx] == 'G'){
                                    visited[yyy][xxx] = 1;
                                    q.push(make_pair(xxx, yyy));
                                }
                            }
                            else if(section[y][x] == 'B' && section[yyy][xxx] == 'B'){
                                visited[yyy][xxx] = 1;
                                q.push(make_pair(xxx, yyy));
                            }
                        }
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

    cin >> N;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> section[i][j];
        }
    }

    redgreen(); noneredgreen();
    cout << rg << " " << nrg; 
    

    return 0;
}
