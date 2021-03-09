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
vector<int> v[10011];
vector<pair<int, long long> > vv;
int visited[10011];

bool compare(pair<int, long long> &a, pair<int, long long> &b){
    if(a.second == b.second) return a.first < b.first;
    return a.second > b.second;
}


void bfs(){

    long long cnt = 1;
    for(int i = 1; i <= N; i++){
        if(v[i].size() > 0){
            queue<int> q; q.push(i); cnt = 1;
            for(int i = 0; i <= N; i++){
                visited[i] = 0;
            }
            visited[i] = 1;
            while(!q.empty()){
                int com = q.front(); q.pop();
                for(int j = 0; j < v[com].size(); j++){
                    if(visited[v[com][j]] == 0){
                        visited[v[com][j]] = 1;
                        q.push(v[com][j]);
                        cnt++;
                    }
                }
            }
            vv.push_back(make_pair(i, cnt));
        }
    }
}

int main(){

    ios::sync_with_stdio(false);
	cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    for(int i = 0; i < M; i++){
        int a, b; cin >> a >> b;
        v[b].push_back(a);
    }
    bfs();
    sort(vv.begin(), vv.end(), compare);
    for(int i = 0; i < vv.size(); i++){
        long long MAX = vv[0].second;
       if(vv[i].second != MAX) break;
        cout << vv[i].first << " ";
    }
    
    return 0;
}

