//
//  15686.cpp
//  BJ
//
//  Created by 신기열 on 29/10/2019.
//  Copyright © 2019 신기열. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

int n, m;
int map[51][51];
int answer = 1000000;
// h : 모든 home의 좌표 벡터, c : 모든 chicken store의 좌표 벡터
vector<pair<int, int> > h;
vector<pair<int, int> > c;

//
void distance(){
    int temp = 0;
    // 모든 집들을 돌면서
    for(int i = 0; i < h.size(); i++){
        // 집의 좌표 (hx, hy), 가장 거리가 가까운 치킨집과의 거리를 임시로 담기위한 tmp 변수
        int hx = h[i].first, hy = h[i].second, tmp = 1000000;
        // 폐업 안 한 모든 치킨집 좌표를 돌면서
        for(int j = 0; j < c.size(); j++){
            // 현재 치킨집 좌표 (cx, cy)
            int cx = c[j].first, cy = c[j].second;
            // 치킨집 x 좌표와 집 x 좌표 사이의 거리를 tx, 치킨집 y 좌표와 집 y 좌표 사이의 거리를 ty
            int tx = 0, ty = 0;
            // 크기가 큰 좌표 - 작은 좌표로 거리를 계산. 절대값을 사용하지 않고 계산하는 방법.
            // 물론 <stdlib.h>의 abs 를 이용해서 절대값을 구해도 상관없다.
            if(hx < cx) tx = cx - hx;
            else tx = hx - cx;
            
            if(hy < cy) ty = cy - hy;
            else ty = hy - cy;
            
            // 거리 중에서 가장 가까운 거리를 구한다.
            tmp = min(tmp, tx + ty);
        }
        // 가장 가까운 거리들의 총합을 원하는 것이므로 temp에 현재 총합을 저장한다.
        temp += tmp;
    }
    // answer에는 총합 중에서 가장 작은 값을 저장해준디.
    answer = min(temp, answer);
}

void DFS(int cnt, int x, int y){
    
    // 치킨집의 개수가 최대이면 종료한다.
    if(cnt == m) return;
    
    // 백준 15684. 사다리 조작과 같은 케이스인데, 현재 치킨집을 포함해서 탐색을 완전히 끝냈다면, 더 이상 이 치킨집을 쓸 필요는 없다.
    // 현재 치킨집의 다음 좌표부터 시작해주자.
    for(int i = y; i <= n; i++){
        for(int j = x + 1; j <= n; j++){
            // 현재 좌표에 치킨집이 있다면
            if(map[i][j] == 2){
                // c 벡터에 넣어주고 이것만 넣은 distance를 구해준다.
                c.push_back(make_pair(j, i));
                distance();
                // 그 후 이 치킨집과 다른 치킨집을 포함해서 돌려주자.
                DFS(cnt + 1, j, i);
                // DFS 탐색이 끝났다면 현재 치킨집은 더 이상 쓸 필요가 없다. 
                c.pop_back();
            }
        }
        // 역시 현재 행이 끝나면 j는 1부터 다시 탐색해야하므로 x = 0으로 만들어서 1부터 탐색할 수 있게 만들어주자.
        x = 0;
    }
}

int main(){
    
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin >> map[i][j];
            if(map[i][j] == 1) h.push_back(make_pair(j, i));
        }
    }
    DFS(0, 0, 0);
    cout << answer;
    return 0;
}
