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

vector<vector<int> > v(101);
int N; 
int res[101][101];

bool BFS(int i, int goal){
    queue<int> q; q.push(i);
    int visited[101] = { 0, };

    while(!q.empty()){
        int x = q.front(); q.pop(); 
        for(int ii = 0; ii < v[x].size(); ii++){
            if(visited[v[x][ii]] == 0){
                visited[v[x][ii]] = 1;
                if(v[x][ii] == goal) return true;
                else q.push(v[x][ii]);
            }
        }
    }
    return false;
}

void check(){

    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            bool chk = BFS(i, j);
            if(chk) res[i][j] = 1;
        }
    }
}

int main(){

    ios::sync_with_stdio(false);
	cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            int a; cin >> a;
            if(a == 1){
                v[i].push_back(j);
            }
        }
    }
    check();
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            cout << res[i][j] << " ";
        }
        cout << '\n';
    }
    return 0;
}
