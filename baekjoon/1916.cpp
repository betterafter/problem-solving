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

int MAX = INT_MAX;
int N, M;
int n[1001][1001];
int res[1001];
int visited[1001];
vector<vector<int> > v(1001);

int main(){

    ios::sync_with_stdio(false);
	cin.tie(NULL);
    cout.tie(NULL);

    for(int i = 0; i < 1001; i++){
        res[i] = MAX;
        for(int j = 0; j < 1001; j++){
            n[i][j] = MAX;
        }
    }

    cin >> N >> M;
    for(int i = 0; i < M; i++){
        int a, b, c; cin >> a >> b >> c;
        v[a].push_back(b);
        n[a][b] = min(n[a][b], c);
    }
    int dx, dy; cin >> dx >> dy;



    int ans = MAX;
    queue<pair<int,int> > q; q.push(make_pair(dx, 0));
    while(!q.empty()){
        int curr = q.front().first, dist = q.front().second; q.pop();
        if(dist < res[curr]){
            res[curr] = dist;
            for(int i = 0; i < v[curr].size(); i++){
                int next = v[curr][i];
                q.push(make_pair(next, dist + n[curr][next]));
            }
        }
    }

    cout << res[dy];
    return 0;
}

