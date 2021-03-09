
//
//  16235.cpp
//  BJ
//
//  Created by 신기열 on 01/11/2019.
//  Copyright © 2019 신기열. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>


using namespace std;

int n, m, k;
int map[11][11];
int nu[11][11];
int tree[120][3];
int dir[8][2] = { {1,0}, {-1,0}, {0,1}, {0,-1}, {1,1}, {1,-1}, {-1,1}, {-1,-1} };
int answer;

deque<int> v[11][11];

void year(){
    
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            // 나무가 존재하는 좌표이면
            if(v[i][j].size() > 0){
                int tmp = 0;
                for(int k = 0; k < v[i][j].size(); k++){
                    // 이 때, 나무가 여러 그루이면 나이가 적은 순으로 양분을 흡수하는데, 가을에서 추가되는 나무는 덱의 앞에 추가되므로 자연스럽게 오름차순 정렬이 된다.
                    // 맵에 남아있는 양분 >= 현재 탐색 중인 나무의 나이 ==> 현재 나무는 자랄 수 있다.
                    if(map[i][j] >= v[i][j][k]){
                        // 맵의 양분을 제거한다.
                        map[i][j] = map[i][j] - v[i][j][k];
                        // 나무의 나이를 늘린다.
                        v[i][j][k]++;
                        tmp++;
                    }
                    // 맵에 남아있는 양분 < 현재 탐색 중인 나무의 나이 ==> 이 나무부터는 다 죽어버림
                    else{
                        // 끝번호 - 맨처음으로 죽은 나무의 번호 = 죽은 나무의 수
                        int cnt = (int)(v[i][j].size() - tmp);
                        while(cnt > 0){
                            // 가장 뒤의 나무부터 하나씩 빼준다.
                            int dead = v[i][j].back();
                            v[i][j].pop_back();
                            
                            // 여름
                            // 여름에는 죽은 나무의 나이 / 2 만큼 양분이 증가하게 된다.
                            map[i][j] = map[i][j] + dead / 2;
                            cnt--;
                        }
                        break;
                    }
                }
            }
            
            // 겨울
            // 겨울에는 로봇이 공급하는 nu 배열 내에서의 각 좌표에 부여 된 영양분 수치만큼 더해준다.
            map[i][j] = map[i][j] + nu[i][j];
        }
    }
    
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            
            // 가을
            // 나이가 5의 배수이면 상, 하, 좌, 우, 각 대각선 방향까지 모두 체크해서 맵 안쪽이면 나이가 1인 나무를 앞에서 추가해준다.
            if(v[i][j].size() > 0){
                for(int k = 0; k < v[i][j].size(); k++){
                    if(v[i][j][k] % 5 == 0){
                        for(int l = 0; l < 8; l++){
                            int nx = j + dir[l][0];
                            int ny = i + dir[l][1];
                            if(nx >= 1 && ny >= 1 && nx <= n && ny <= n){
                                v[ny][nx].push_front(1);
                            }
                        }
                    }
                }
            }
        }
    }
}

int main(){
    
    cin >> n >> m >> k;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin >> nu[i][j];
            map[i][j] = 5;
        }
    }
    for(int i = 0; i < m; i++){
        cin >> tree[i][0] >> tree[i][1] >> tree[i][2];
    }
    
    for(int i = 0; i < m; i++){
        v[tree[i][0]][tree[i][1]].push_back(tree[i][2]);
    }

    for(int i = 0; i < k; i++){
        year();
    }
    
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            answer = answer + (int)(v[i][j].size());
        }
    }
    
    cout << answer;
    return 0;
}
