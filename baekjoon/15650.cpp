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


void bfs(int idx, int cnt, deque<int> dq){

    if(cnt == M){
        for(int i = 0; i < dq.size(); i++){
            cout << dq[i] << " ";
        }
        cout << '\n';
        return;
    }
    if(N - idx < M - cnt) return;

    for(int i = idx + 1; i <= N; i++){
        dq.push_back(i);
        bfs(i, cnt + 1, dq);
        dq.pop_back();
    }
}


void check(){

    for(int i = 1; i <= N; i++){
        deque<int> dq; dq.push_back(i);
        bfs(i, 1, dq);
        dq.pop_back();
    }
}

int main(){

    ios::sync_with_stdio(false);
	cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    check();

    return 0;
}
