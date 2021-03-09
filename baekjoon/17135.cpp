//
//  17135.cpp
//  BJ
//
//  Created by 신기열 on 12/11/2019.
//  Copyright © 2019 신기열. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <vector>
#include <math.h>
#include <queue>

using namespace std;

int n, m, d;
int map[16][16];
int answer;
vector<pair<int, int> > v;

void attack(vector<pair<int, int> > v){
    
    int tmap[16][16] = { 0, };
    deque<pair<int, int> > enemy;
    
    // 일단 이번 궁수 위치에서만 쓸 맵을 하나 생성한다. 적이 있는 위치는 따로 잡아준다.
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            tmap[i][j] = map[i][j];
            if(tmap[i][j] == 1) enemy.push_back(make_pair(j, i));
        }
    }
    
    int enemykill = 0;
    
    while(1){
        vector<pair<int, int> > kill;
        
        // 모든 궁수에 대하여
        for(int i = 0; i < v.size(); i++){
            
            int posx = v[i].first, posy = v[i].second;
            // 죽일 적의 위치이다. 일단 초기 위치는 크게 아무렇게나 잡는다.
            pair<int, int> tkill = make_pair(20, 20);
            
            // 좌표 내의 모든 적 위치와 비교해서
            for(int j = 0; j < enemy.size(); j++){
                int ex = enemy.front().first, ey = enemy.front().second; enemy.push_back(make_pair(ex, ey)); enemy.pop_front();
                // 현재 궁수 위치와 적 위치가 d 이하 일 경우
                if(abs(posx - ex) + abs(posy - ey) <= d){
                    // 이전에 구했던 가장 가까운 적의 위치보다 현재 적의 위치의 거리가 더 짧으면 적의 위치를 바꿔준다.
                    if(abs(posx - ex) + abs(posy - ey) < abs(tkill.first - posx) + abs(tkill.second - posy)){
                        tkill = make_pair(ex, ey);
                    }
                    // 같으면 더 왼쪽에 있는걸로 정해준다.
                    else if(abs(posx - ex) + abs(posy - ey) == abs(tkill.first - posx) + abs(tkill.second - posy) && tkill.first > ex){
                        tkill = make_pair(ex, ey);
                    }
                }
            }
            // 현재 궁수가 죽일 적의 위치를 넣어주자. 이 때, 같은 적을 선택할 수도 있는데, 이 경우는 아래에서 처리해 준다.
            if(tkill.first != 20) kill.push_back(make_pair(tkill.first, tkill.second));
        }
        
        // kill 벡터에서 죽일 적의 위치가 0이면 (이미 죽였으면) enemykill을 세줄 필요가 없고, 1인 경우만 아직 안 죽인 것이므로 enemykill을 1 증가시켜준다.
        for(int i = 0; i < kill.size(); i++){
            if(tmap[kill[i].second][kill[i].first] == 1){
                tmap[kill[i].second][kill[i].first] = 0;
                enemykill++;
            }
        }
        
        int size = (int)enemy.size();
        // 맵을 전부 돌면서 (이 때, 성과 가장 가까운 적부터 탐색해준다.)
        for(int i = 0; i < size; i++){
            // 적의 위치가 있는 곳이 1인 경우 (안 죽은 적의 위치인 경우)
            if(tmap[enemy.back().second][enemy.back().first] == 1){
                // 이 적이 밑으로 내려 갔을 때 성에 부딪히지 않는 경우
                if(enemy.back().second + 1 <= n){
                    // 밑으로 내려간 위치는 1로, 현재 위치는 0으로 바꿔서 위치 이동 시켜준다.
                    tmap[enemy.back().second + 1][enemy.back().first] = 1;
                    enemy.push_front(make_pair(enemy.back().first, enemy.back().second + 1));
                }
                tmap[enemy.back().second][enemy.back().first] = 0;
            }
            // 현재 적의 위치가 바뀌므로 현재 적의 위치는 빼주고, 업데이트 된 적의 위치는 뒤에 다시 넣어준다.
            enemy.pop_back();
        }

        if(enemy.size() == 0) break;
    }
    
    answer = max(answer, enemykill);
}

// 궁수의 3명의 위치를 결정한다.
void DFS(int idx, vector<pair<int, int> > v){
    
    if(v.size() == 3){
        attack(v); return;
    }
    if(v.size() < 3 && idx >= m) return;
    
    for(int i = idx + 1; i <= m; i++){
        v.push_back(make_pair(i, n + 1));
        DFS(i, v);
        v.pop_back();
    }
    
    
}

int main(){
    
    cin >> n >> m >> d;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin >> map[i][j];
        }
    }
    DFS(0, v);
    cout << answer;
    return 0;
}
