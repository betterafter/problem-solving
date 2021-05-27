#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int res[101][101];
int MAX = 999999999;

int solution(int n, vector<vector<int> > results) {
    int answer = 0;

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(i == j) res[i][j] = 0;
            else res[i][j] = MAX;
        }
    }

    for(int i = 0; i < results.size(); i++){
        res[results[i][0]][results[i][1]] = 1;
    }

    for(int k = 1; k <= n; k++){
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                if(res[i][k] == MAX || res[k][j] == MAX) continue;
                if(res[i][j] > res[i][k] + res[k][j]){
                    res[i][j] = res[i][k] + res[k][j];
                }
            }
        }
    }

    // bfs로 찾으면 왜인지 시간초과가 난다. (100개 밖에 없어서 될 거 같은데..)
    // 그래서 플로이드-와샬로 node-to-node 거리를 찾고 (거리 길이는 중요하지 않다. 연결된 것이 중요한 거지. 거리가 MAX면 연결 안된것이고
    // 그 외의 경우라면 연결이 되는 것으로 판별)
    // 그 중에서 i-to-j 또는 j-to-i가 MAX가 아닌 애들은 어찌저찌 연결이 된 것. 하나의 노드에 대해서 모든 노드에 연결이 된 애들을 찾으면 끝.

    // queue<int> q;
    // for(int i = 1; i <= n; i++){
    //     q.push(i); res[i][i] = 1;
    //     while(!q.empty()){
    //         int node = q.front(); q.pop();
    //         for(int j = 0; j < v[node].size(); j++){
    //             res[  i  ][  v[node][j]  ] = 1;
    //             res[  v[node][j]  ][  i  ] = 1;
    //             q.push(v[node][j]);
    //         }
    //     }
    // }

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(res[i][j] == MAX && res[j][i] == MAX) break;
            if(j == n) answer++;
        }
    }

    return answer;
}