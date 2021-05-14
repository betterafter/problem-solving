#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>
#include <math.h>

using namespace std;

int al[201][201];
vector<vector<int> > v(201); 
int val[201];
int dist[201][201];
int MAX = 999999999;

int solution(int n, int s, int a, int b, vector<vector<int> > fares) {
    int answer = MAX;

    for(int i = 1; i <= n; i++){
        val[i] = MAX;
    }
    val[s] = 0;

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(i == j) dist[i][j] = 0;
            else dist[i][j] = MAX;
        }
    }

    for(int i = 0; i < fares.size(); i++){

        dist[fares[i][0]][fares[i][1]] = fares[i][2];
        dist[fares[i][1]][fares[i][0]] = fares[i][2];
    }

    

    // 다익스트라 - 시간 초과
    // 우선 순위 큐를 이용하면 시간 초과가 안난다는 이야기가 있음
    // queue<int> q;
    // for(int i = 1; i <= n; i++){

    //     for(int i = 1; i <= n; i++){
    //         val[i] = MAX;
    //     }
    //     val[i] = 0;

    //     q.push(i);
    //     while(!q.empty()){
    //         int node = q.front(); q.pop();
    //         for(int i = 0; i < v[node].size(); i++){
    //             int next = v[node][i];
    //             if(val[node] + al[node][next] < val[next]){
    //                 val[next] = val[node] + al[node][next];

    //                 q.push(next);
    //             }
    //         }
    //     }

    //     for(int j = 1; j <= n; j++){
    //         dist[i][j] = val[j];
    //     }
    // }

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            for(int k = 1; k <= n; k++){
                // MAX + MAX 하니까 음수로 넘어가버림
                if(dist[j][i] == MAX || dist[i][k] == MAX) continue;
                if(dist[j][k] > dist[j][i] + dist[i][k])
                    dist[j][k] = dist[j][i] + dist[i][k];
            }
        }
    }
    
 
    for(int i = 1; i <= n; i++){
        if(dist[s][i] != MAX && dist[i][a] != MAX && dist[i][b] != MAX)
            answer = min(answer, dist[s][i] + dist[i][a] + dist[i][b]);
    }



    

    return answer;
}