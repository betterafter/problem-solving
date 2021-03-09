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
int city[1001];

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
    queue<pair<pair<int,int>, int> > q; q.push(make_pair(make_pair(dx, 0), dx));
    while(!q.empty()){
        int curr = q.front().first.first, dist = q.front().first.second, prev = q.front().second; q.pop();
        if(dist < res[curr]){
            
            res[curr] = dist;
            city[curr] = prev;
            for(int i = 0; i < v[curr].size(); i++){
                int next = v[curr][i];
                if(dist + n[curr][next] < res[next]){
                    
                    q.push(make_pair(make_pair(next, dist + n[curr][next]), curr));
                }
            }
        }
    }

    cout << res[dy] << '\n';
    vector<int> resv;
    int x = dy;
    while(x != dx){
        resv.push_back(x);
        x = city[x];
    }
    resv.push_back(dx);
    cout << resv.size() << '\n';
    for(int i = resv.size() - 1; i >= 0; i--){
        cout << resv[i] << " ";
    }
    
    return 0;
}

