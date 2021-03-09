#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>
#include <queue>
#include <set>
#include <stack>

using namespace std;

int res, N, M;
int visited[1001];
vector<vector<int> > v(1001);

void Check(){

    queue<int> q;
    for(int i = 1; i <= N; i++){
        if(visited[i] == 0){
            q.push(i);
            while(!q.empty()){
                int num = q.front(); q.pop();
                for(int t = 0; t < v[num].size(); t++){
                    if(visited[v[num][t]] == 0){
                        q.push(v[num][t]);
                        visited[v[num][t]] = 1;
                    }
                }
            }
            res++;
        }
    }
}



int main(){

    ios::sync_with_stdio(false);
	cin.tie(NULL);
    
    cin >> N >> M;
    for(int i = 0; i < M; i++){
        int a, b; cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    Check();
    cout << res;
    return 0;
}
