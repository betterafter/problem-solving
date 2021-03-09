
// 문제 이름 : 배달

#include <iostream>
#include <vector>
#include <queue>
#include <math.h>
using namespace std;

int map[51][51];
vector<vector<int> > vmap(51); 

int solution(int N, vector<vector<int> > road, int K) {
    int answer = 0;

    for(int i = 0; i < 51; i++){
        for(int j = 0; j < 51; j++){
            map[i][j] = 987654321;
        }
    }

    for(int i = 0; i < road.size(); i++){
        map[road[i][0]][road[i][1]] = min(road[i][2], map[road[i][0]][road[i][1]]);
        map[road[i][1]][road[i][0]] = min(road[i][2], map[road[i][1]][road[i][0]]);

        vmap[road[i][0]].push_back(road[i][1]);
        vmap[road[i][1]].push_back(road[i][0]);
    }

    int dist[51];
    for(int i = 0; i <= N; i++){
        dist[i] = 987654321;
    }
    dist[1] = 0;

    queue<int> q;
    q.push(1);

    while(!q.empty()){
        int node = q.front();
        q.pop();
        for(int i = 0; i < vmap[node].size(); i++){
            int nextNode = vmap[node][i];
            if(dist[nextNode] > dist[node] + map[node][nextNode]){
                dist[nextNode] = dist[node] + map[node][nextNode];
                q.push(nextNode);
            }
        }
    }
    
    for(int i = 1; i <= N; i++){
        cout << dist[i] << " ";
        if(dist[i] <= K){
            answer++;
        }
    }

    return answer;
}