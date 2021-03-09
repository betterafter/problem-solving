//
//  1753.cpp
//  test
//
//  Created by 신기열 on 03/07/2019.
//  Copyright © 2019 신기열. All rights reserved.
//

#include <stdio.h>
#include <utility>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

const int INF = 2e9;

vector<vector<pair<int, int> > > adj; // (u,v,w) -> adj[u] = <v, w> ... :: u -> v 거리가 w임.
int n, m, start;

void Dijkstra(int s){
    
    vector<int> dist(n + 1, INF);
    priority_queue<pair<int, int> > pq; // 노드 거리, 노드 번호 순으로 저장해 줌
    dist[s] = 0; pq.push(make_pair(0, s)); // 시작점 저장
    
    while(!pq.empty()){
        
        int d = -pq.top().first, n = pq.top().second; pq.pop();
        
        // 이전 노드에서 현재 노드까지의 거리가 최단거리에 해당한다면 현재 노드의 인접 노드들을 전부 탐색해준다.
        // d는 이전노드에서 n번노드까지의 거리를 나타내므로, d가 dist[n]보다 크면 시작점부터 n번의 이전 노드까지의 거리가 뭐가 나오든 무조건 dist[n]보다 크게 된다.
        // 물론 d = dist[n]은 시작점부터 탐색할 경우 가능한 얘기이므로 d가 dist[n]을 넘지만 않으면 된다.
        if(d <= dist[n]){
            for(int i = 0; i < adj[n].size(); i++){
                int v = adj[n][i].first, w = adj[n][i].second;
                
                // 현재노드에서 인접노드까지의 거리가 인접노드가 저장하고 있던 최단경로보다 작으면 업데이트 해주고, 우선순위 큐에 그 정보를 저장해준다.

                if(dist[v] > dist[n] + w){
                    dist[v] = dist[n] + w;
                    pq.push(make_pair(-dist[v], v));
                }
            }
        }
    }
    for(int i = 1; i <= n; i++){
        if(dist[i] == INF) cout << "INF" << '\n';
        else cout << dist[i] << '\n';
    }
}

int main(){
    
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m;
    cin >> start;
    adj.resize(n + 1);
    
    for(int i = 0; i < m; i++){
        int u, v, w; cin >> u >> v >> w;
        adj[u].push_back(make_pair(v, w));
    }
    
    Dijkstra(start);
    
    return 0;
}
