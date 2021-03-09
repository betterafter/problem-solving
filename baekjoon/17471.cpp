//
//  17471.cpp
//  BJ
//
//  Created by 신기열 on 11/11/2019.
//  Copyright © 2019 신기열. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>
#include <math.h>
#define MAX 1000000

using namespace std;


int n;
int num[11];
int map[11][11];
vector<int> v1, v2;
int answer = MAX;

void BFS(vector<int> v1, vector<int> v2){
    
//    for(int i = 0; i < v1.size(); i++){
//        cout << v1[i] << " " ;
//    }
//    cout << "          ";
//    for(int i = 0; i < v2.size(); i++){
//        cout << v2[i] << " " ;
//    }
    //cout << '\n';
    queue<int> q;
    int visited[11] = { 0, }, visited2[11] = { 0, };
    
    // 1번 선거구에 지역이 하나도 없거나 || 모든 지역이 다 들어가 있으면 return
    if(v1.size() == 0 || v1.size() == n) return;
    // 1번 선거구에 들어간 지역 중에 그냥 첫번째부터 탐색해준다. (어차피 다 인접해있으니까)
    // people1은 1번 선거구에 들어간 모든 인원 수
    q.push(v1[0]); int people1 = 0;
    while(!q.empty()){
        // 현재 구역부터 모든 점에 대하여 탐색하면서 인접한 것이 있는지 체크하고, 인접한 것은 queue에 다시 넣어준다. 이 때, 이미 탐색한 구역은 방문 완료 표시 해준다. (visited)
        int curr = q.front(); q.pop(); visited[curr] = 1;
        for(int i = 0; i < v1.size(); i++){
            if(map[curr][v1[i]] == 1 && visited[v1[i]] == 0){
                q.push(v1[i]);
            }
        }
    }
    // 1번 선거구 중에서 탐색이 한 번도 안 된 구역이 있으면 어떤 것과도 인접하지 않았다는 말이므로 return해준다. 모두 인접 해 있다면 계속 연산했던 인구 수를 쓰게 될 것이다.
    for(int i = 0; i < v1.size(); i++){
        people1 += num[v1[i]];
        if(visited[v1[i]] == 0) return;
    }

    
    // 2번 선거구도 1번 선거구와 완전 똑같이 해주자.
    if(v2.size() == 0 || v2.size() == n) return;
    q.push(v2[0]); int people2 = 0;
    while(!q.empty()){
        int curr = q.front(); q.pop(); visited2[curr] = 1;
        for(int i = 0; i < v2.size(); i++){
            if(map[curr][v2[i]] == 1 && visited2[v2[i]] == 0){
                q.push(v2[i]);
            }
        }
    }
    for(int i = 0; i < v2.size(); i++){
        people2 += num[v2[i]];
        if(visited2[v2[i]] == 0) return;
    }

    //cout << people1 << " " << people2 << '\n';
    //cout << abs(people1 - people2) << '\n';
    // 중간에 return이 안되어 있으면 구역이 적절하게 나눠져 들어간 것이므로 둘의 차와 answer를 비교해준다.
    answer = min(answer, abs(people1 - people2));
}

// 각 구역이 어떤 선거구에 들어갈 지 결정하는 탐색
void DFS(int idx, vector<int> v1, vector<int> v2){
    
    if(idx > n){
        BFS(v1, v2);
        return;
    }
    
    // 1번 선거구에 넣고 DFS
    v1.push_back(idx);
    DFS(idx + 1, v1, v2);
    v1.pop_back();
    
    // 1번에서 빼고 2번 선거구에 넣고 DFS
    v2.push_back(idx);
    DFS(idx + 1, v1, v2);
    v2.pop_back();
}

int main(){
    
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> num[i];
    }
    for(int i = 1; i <= n; i++){
        int t; cin >> t;
        for(int j = 0; j < t; j++){
            int tmp; cin >> tmp;
            map[i][tmp] = 1;
        }
    }
    DFS(1, v1, v2);
    if(answer == MAX) cout << -1;
    else cout << answer;
    return 0;
}
