#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

// 43162 - 네트워크

int net[201][201];
int visited[201];

int solution(int n, vector<vector<int> > computers) {
    int answer = 0;

    for(int i = 0; i < computers.size(); i++){
        for(int j = 0; j < computers[i].size(); j++){
            net[i + 1][j + 1] = computers[i][j];
            net[j + 1][i + 1] = computers[i][j];
        }
    }

    queue<int> q;
    for(int i = 1; i <= n; i++){
        if(visited[i] == 0){
            answer++; q.push(i); visited[i] = 1;
            while(!q.empty()){
                int node = q.front(); q.pop(); visited[node] = 1;
                for(int i = 1; i <= n; i++){
                    if(visited[i] == 0 && net[node][i] == 1){
                        q.push(i);
                    }
                }
            }
        }
    }


    return answer;
}