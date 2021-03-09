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

int tx, ty; 

int MAX = INT_MAX;
int N, M;
int n[1001][1001];
vector<vector<int> > v(1001);


vector<int> di(int start, int end){

    vector<int> temp(N + 1, MAX);
    queue<pair<int,int> > q; q.push(make_pair(start, 0));
    while(!q.empty()){
        int curr = q.front().first, dist = q.front().second; q.pop();
        if(dist < temp[curr]){
            temp[curr] = dist;
            for(int i = 0; i < v[curr].size(); i++){
                int next = v[curr][i];
                q.push(make_pair(next, dist + n[curr][next]));
            }
        } 
    }
    return temp;
}


int main(){

    ios::sync_with_stdio(false);
	cin.tie(NULL);
    cout.tie(NULL);

    for(int i = 0; i < 1001; i++){
        for(int j = 0; j < 1001; j++){
            n[i][j] = MAX;
        }
    }

    cin >> N >> M;
    for(int i = 0; i < M; i++){
        int a, b, c; cin >> a >> b >> c;
        v[a].push_back(b);
        v[b].push_back(a);
        n[a][b] = min(n[a][b], c);
        n[b][a] = min(n[b][a], c);
    }
    cin >> tx >> ty;
    vector<int> n = di(1, N), a = di(tx, N), b = di(ty, N);
    
    long long aa = (long long)n[tx] + (long long)a[ty] + (long long)b[N];
    long long bb = (long long)n[ty] + (long long)a[N] + (long long)b[tx];

    long long ans = min(aa, bb);

    // for(int i = 1; i <= N; i++){
    //     cout << "a : " << a[i] << "  b : " << b[i] << "  n : " << n[i] << '\n';
    // }
    // cout << '\n';

    if(ans >= MAX || ans < 0) cout << -1;
    else cout << ans;
    return 0;
}

