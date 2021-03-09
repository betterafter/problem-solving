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

vector<int> v;

void bfs(int cnt, deque<int> dq, int visited[10001]){

    if(cnt == M){
        for(int i = 0; i < dq.size(); i++){
            cout << dq[i] << " ";
        }
        cout << '\n';
        return;
    }

    for(int i = 0; i < N; i++){
        if(visited[v[i]] == 0){
            visited[v[i]] = 1;
            dq.push_back(v[i]);
            bfs(cnt + 1, dq, visited);
            dq.pop_back();
            visited[v[i]] = 0;
        }
    }
}


void check(){

    for(int i = 0; i < N; i++){
        int visited[10001] = { 0, };
        deque<int> dq; dq.push_back(v[i]);
        visited[v[i]] = 1;
        bfs(1, dq, visited);
        dq.pop_back();
        visited[v[i]] = 0;
    }
}

int main(){

    ios::sync_with_stdio(false);
	cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    for(int i = 0; i < N; i++){
        int t; cin >> t;
        v.push_back(t);
    }
    sort(v.begin(), v.end());

    check();

    return 0;
}
