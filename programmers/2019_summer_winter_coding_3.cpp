#include <stdio.h>
#include <iostream>
#include <math.h>
#include <queue>
#include <set>
#include <map>

using namespace std;

int section[301][301];
int visited[301][301];
int primvisited[1000010];
int vertex[10011][10011];
set<int> vertset[1000010];
vector<pair<int, int> > vertvec[1000010];
int dir[4][2] = { {0,1}, {0,-1}, {1,0}, {-1,0} };
int n, height, answer;

// Prim Algorithm을 사용하였다.
void MST(){
    
    int start = 1; primvisited[start] = 1;
    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
    
    for(int i = 0; i < vertvec[start].size(); i++){
        int next = vertvec[start][i].first, nextvalue = vertvec[start][i].second;
        pq.push(make_pair(nextvalue, next));
    }
    
    
    while(!pq.empty()){
        int curr = pq.top().second, currvalue = pq.top().first; pq.pop();
        if(primvisited[curr] == 1) continue;
        primvisited[curr] = 1; answer += currvalue;
        
        for(int i = 0; i < vertvec[curr].size(); i++){
            int next = vertvec[curr][i].first, nextvalue = vertvec[curr][i].second;
            pq.push(make_pair(nextvalue, next));
        }
    }
}


void vertexCalculation(vector<vector<int> > map){
    
    for(int y = 0; y < map.size(); y++){
        for(int x = 0; x < map.size(); x++){
            
            for(int k = 0; k < 4; k++){
                int nx = x + dir[k][0], ny = y + dir[k][1];
                // 한 구역에서 다른 구역으로 넘어가는 것 중에 섹션 간 이동인 한 쌍의 구역을 찾는다. 이 때, 탐색 지점이 맵 밖을 벗어나지 않게 한다.
                if(nx >= 0 && nx < map.size() && ny >= 0 && ny < map.size() && section[y][x] != section[ny][nx]){
                    
                    // 어차피 우선순위 큐에 의해서 한 쌍의 노드 간의 이동 통로 중 가장 작은 방법을 택해서 이동할 것이기 떼문에 갈 수 있는 방법을 그냥 다 저장해버리자.
                    vertvec[section[ny][nx]].push_back(make_pair(section[y][x], abs(map[y][x] - map[ny][nx])));
                    vertvec[section[y][x]].push_back(make_pair(section[ny][nx], abs(map[y][x] - map[ny][nx])));
                }
            }
        }
    }
    
    MST();
}



void BFS(vector<vector<int> > map, int height){
    
    // 모든 맵을 돌면서 사다리 없이 갈 수 있는 지역을 전부 같은 섹션으로 묶고, 방문 하지 않는 지점은 섹션으로 묶이지 않은 구역이므로 새로운 섹션으로 만들어준다.
    int secn = 0;
    queue<pair<int, int> > q;
    for(int i = 0; i < map.size(); i++){
        for(int j = 0; j < map.size(); j++){
            // 방문 하지 않은 곳은 다른 section의 시작 지점으로 취급해서 BFS를 돌려준다.
            if(visited[i][j] == 0){
                secn++; section[i][j] = secn; visited[i][j] = 1;
                q.push(make_pair(j, i));
                // 현재 탐색 지점과 사다리 없이 이동할 수 있는 모든 지역을 전부 같은 섹션으로 묶어버린다.
                while(!q.empty()){
                    int x = q.front().first, y = q.front().second; q.pop();
                    for(int k = 0; k < 4; k++){
                        int nx = x + dir[k][0], ny = y + dir[k][1];
                        if(nx >= 0 && nx < map.size() && ny >= 0 && ny < map.size() && visited[ny][nx] == 0 && abs(map[y][x] - map[ny][nx]) <= height){
                            section[ny][nx] = secn; visited[ny][nx] = 1; q.push(make_pair(nx, ny));
                        }
                    }
                }
            }
        }
    }

    vertexCalculation(map);
}


int solution(vector<vector<int>> land, int height) {
    
    BFS(land, height);
    
    return answer;
}
