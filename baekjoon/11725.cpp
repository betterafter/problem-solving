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

vector<vector<int> > v(100001);
int res[100001];

void check(){
    int visited[100001] = { 0, };
    queue<int> q; q.push(1); visited[1] = 1;
    while(!q.empty()){
        int x = q.front(); q.pop(); visited[x] = 1;
        for(int i = 0; i < v[x].size(); i++){
            if(visited[v[x][i]] == 0){
                res[v[x][i]] = x;
                q.push(v[x][i]);
            }
        }
    }
}


int main(){

    ios::sync_with_stdio(false);
	cin.tie(NULL);
    cout.tie(NULL);

    int N; cin >> N;
    for(int i = 0; i < N - 1; i++){
        int a, b; cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    check();
    
    for(int i = 2; i <= N; i++){
        cout << res[i] << '\n';
    }
    return 0;
}
