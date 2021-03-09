//
//  14889.cpp
//  BJ
//
//  Created by 신기열 on 24/10/2019.
//  Copyright © 2019 신기열. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

int n;
int visited[21];
int p[21][21];
int answer = 100000000;

// 각 팀의 능력치를 구하기 위한 함수
void calc(vector<int> v){
    // team1이 v 안에 있고 v 안에 없는 멤버들은 nv 안에 넣는다
    vector<int> nv;
    int team1 = 0, team2 = 0;
    // team1을 제외한 나머지 멤버를 team2에 넣는다.
    for(int i = 1; i <= n; i++){
        bool isExist = false;
        for(int j = 0; j < v.size(); j++){
            if(v[j] == i){
                isExist = true;
                break;
            }
        }
        if(!isExist) nv.push_back(i);
    }
    
//    cout << "{ ";
//    for(int i = 0; i < v.size(); i++){
//        cout << v[i] << " ";
//    }
//    cout << "}";
//
//    cout << "      { ";
//    for(int i = 0; i < v.size(); i++){
//        cout << nv[i] << " ";
//    }
//    cout << "}    answer : ";

    // team1의 능력치를 구한다. team1의 첫번째 멤버 당(v[i]) 두번째 멤버, 세번째 멤버, 네번째 멤버... 의 능력치를 차례로 더해주고,
    // 두번째, 세번째, 네번째, ... 에도 똑같이 계산해준다.
    for(int i = 0; i < v.size(); i++){
        for(int j = 0; j < v.size(); j++){
            team1 = team1 + p[v[i]][v[j]];
        }
    }
    // team2의 능력치를 구한다.
    for(int i = 0; i < nv.size(); i++){
        for(int j = 0; j < nv.size(); j++){
            team2 = team2 + p[nv[i]][nv[j]];
        }
    }
//    cout << "max(" << max(team1, team2) << ") - min(" << min(team1, team2) << ") = " << max(team1, team2) - min(team1, team2) << '\n';
    // max(team1, team2) - min(team1, team2) = |team1 - team2| 의 최솟값을 구해준다.
    answer = min(answer, max(team1, team2) - min(team1, team2));
    
}

void DFS(vector<int> v, int tmp[21]){
    
    int tvisited[21];
    // 한 팀에 들어갈 수 있는 멤버의 수는 n / 2이므로 멤버 벡터에 n / 2개의 원소가 들어가있으면 계산하고 끝낸다.
    if(v.size() == n / 2){
        calc(v);
        return;
    }
    // tv, tvisited 초기화
    vector<int> tv(v.size());
    for(int i = 0; i < v.size(); i++){
        tv[i] = v[i];
    }
    
    for(int i = 1; i <= n; i++){
        tvisited[i] = tmp[i];
    }
    // 특정 멤버에 대해 탐색을 한 적이 없으면, 즉 어떤 팀에 포함되어 있지 않으면 team1에 넣어주고 DFS를 돌려준다. DFS가 끝나면 다시 team1에서
    // 빼준다. 이 때 visited를 초기화하지 않는 이유는 만약 1번 멤버 탐색이 끝났으면 1번 멤버에 대한 모든 케이스 탐색이 끝난 것이므로 다시
    // 1번 멤버를 포함해서 케이스를 구해줄 필요가 없다.
    for(int i = 1; i <= n; i++){
        if(tvisited[i] == 0){
            tvisited[i] = 1;
            tv.push_back(i);
            DFS(tv, tvisited);
            tv.pop_back();
        }
    }
}


int main(){
    
    cin >> n;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin >> p[i][j];
        }
    }
    
    vector<int> v;
    DFS(v, visited);
    cout << answer;
    
    return 0;
}
