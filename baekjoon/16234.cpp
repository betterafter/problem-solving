//
//  16234.cpp
//  BJ
//
//  Created by 신기열 on 31/10/2019.
//  Copyright © 2019 신기열. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <queue>
#include <stdlib.h>
#include <vector>

using namespace std;

int map[50][50];
int dir[4][2] = { {1,0}, {-1,0}, {0,1}, {0,-1} };
int uni[50][50];
int n, l, r;
int answer;

void BFS(){
    
    // 탐색 지점 좌표를 담기 위한 큐
    queue<pair<int, int> > q;
    // 연합의 인구를 업데이트하기 위한 벡터
    vector<pair<int, int> > v;

    int tmp = -1;
    // 인구이동이 끝날 때까지 계속 (이전 상태(answer)와 현재 상태(tmp)가 같으면 종료한다.)
    while(1){
        // 연합은 하루 동안만 지속되므로 다음날이 되면 리셋해 줘야 한다.
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                uni[i][j] = 0;
            }
        }
        // tmp : 현재 상태. 이전 상태 + 1일 수 있고 이전 상태와 같을 수 있다.
        // isMoved : 현재 국가 기준 네 방향의 다른 국가 간의 이동이 가능하다면 true, 아니면 false (이 코드는 다른 국가와 연합을 하지 않았다면 국가 1개 짜리 연합으로 만들도록 유도했는데,
        // 이 경우 isMoved로 제한을 걸지 않고 tmp++ 를 해버리면 무조건 answer != tmp가 되어 버린다. 따라서 네 방향 중 연합을 이룰 수 있는 국가가 있을 때만 isMoved를 true로 해서
        // (인구이동이 일어났다는 뜻) tmp++ 를 해주도록 하자.)
        // curr : 현재 국가가 포함된 연합 번호
        tmp = answer; bool isMoved = false; int curr = 0;
        // 맵을 한바퀴 탐색할 때까지 반복
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                // 현재 탐색 국가가 어떤 연합에도 속하지 않는다면
                if(uni[i][j] == 0){
                    // 탐색 정보 큐와 연합에 속한 국가를 구분하기 위한 벡터에 넣는다.
                    q.push(make_pair(j, i));
                    v.push_back(make_pair(j, i));
                    // unicnt : 연합국 개수
                    // cnt : 현재 연합의 인구수
                    // uni 배열 : 연합 정보 맵
                    int unicnt = 1; int cnt = map[i][j]; curr++; uni[i][j] = curr;
                    while(!q.empty()){
                        int x = q.front().first; int y = q.front().second;
                        q.pop();
                        
                        for(int d = 0; d < 4; d++){
                            int nx = x + dir[d][0]; int ny = y + dir[d][1];
                            // 현재 국가 기준 다음 국가가 배열 안에 위치하며 && 현재 국가와 다음 국가가 l 이상 r 이하이고 && 다른 연합에 속해 있지 않은 상태이면
                            if((nx >= 0 && ny >= 0 && nx < n && ny < n && abs(map[y][x] - map[ny][nx]) >= l && abs(map[y][x] - map[ny][nx]) <= r &&
                                uni[ny][nx] == 0)){
                                // 인구 이동이 발생할 수 있다면
                                isMoved = true;
                                unicnt++;
                                // 인접 국가를 연합에 포함 시켜준다.
                                uni[ny][nx] = uni[y][x];
                                cnt += map[ny][nx];
                                
                                q.push(make_pair(nx, ny));
                                // 인접 국가도 현재 연합의 리스트에 넣어준다.
                                v.push_back(make_pair(nx, ny));
                            }
                        }
                    }
                    // 연합의 인구 수를 분배해준다.
                    int total = cnt / unicnt;
                    // 현재 연합 리스트 v를 돌면서 해당 국가에 분배한 인구를 넣어준다.
                    for(int k = 0; k < v.size(); k++){
                        map[v[k].second][v[k].first] = total;
                    }
                    // 벡터를 초기화해준다.
                    v.clear();
                }
            }
        }
        // 인구이동이 일어났으면 인구이동 횟수 + 1을 해준다.
        if(isMoved) tmp++;
//        cout << "인구이동 " << tmp << "번"<< '\n';
//        for(int t = 0; t < n; t++){
//            for(int c = 0; c < n; c++){
//                cout << map[t][c] << " ";
//            }
//            cout << '\n';
//        }
//        cout << '\n';
        //cout << "연합형태" << '\n';
//        for(int t = 0; t < n; t++){
//            for(int c = 0; c < n; c++){
//                cout << uni[t][c] << " ";
//            }
//            cout << '\n';
//        }
//        cout << '\n';
        if(tmp == answer) break;
        answer = tmp;
    }
    
    
}

int main(){
    
    cin >> n >> l >> r;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> map[i][j];
        }
    }
    BFS();
    cout << answer;
    return 0;
}
