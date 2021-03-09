//
//  15685.cpp
//  BJ
//
//  Created by 신기열 on 29/10/2019.
//  Copyright © 2019 신기열. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

int map[101][101];
int order[21][4];
int n;
int answer;

// 드래곤 커브 90도로 돌리기
pair<int, int> drotate(int x, int y, int sx, int sy){
    // 위에서 언급했다시피 좌표는 배열의 좌표 기준이다. 이것은 제4사분면(x > 0, y < 0)에 해당되는 것과 같으므로 시계 방향 90도는 배열 좌표 상에선
    // 반시계 방향 90도, 즉 270도를 돌린 것과 같다. 따라서 ([cos270, -sin270], [sin270, cos270])의 회전변환을 적용시켜야한다.
    // 이 때 회전의 중심은 (0, 0)이 아닌 (sx, sy)가 되므로 (sx, sy)를 (0, 0)으로 움직여서 회전시켜주고, 다시 (sx, sy)로 움직여주자.
    // "카카오 2020 블라인드 채용 - 3. 키와 열쇠" 와 같은 방식으로 생각할 수 있다.
    int tx, ty;
    tx = -y + sy + sx;
    ty = x - sx + sy;
    
    return make_pair(tx, ty);
}


void BFS(int x, int y, int bx, int by, int gen){
    
    // 드래곤 커브를 시작점 (x, y), 끝점 (bx, by)인 0세대부터 지정한 gen세대까지 직접 만들어서 이 드래곤 커브에 포함되는 모든 좌표를
    // 벡터 v에 저장할 것이다.
    vector<pair<pair<int, int>, int> > v;
    // 일단 0세대의 시작점과 끝점을 v에 넣어준다.
    v.push_back(make_pair(make_pair(x, y), 0));
    v.push_back(make_pair(make_pair(bx, by), 0));
    // 0세대의 해당 드래곤 커브의 시작점과 끝점의 좌표를 배열 평면에 기록해준다.
    map[y][x] = 1;
    map[by][bx] = 1;
    
    // 문제를 분석해보면 알겠지만, 드래곤 커브 각 세대의 회전 기준점은 각 세대의 끝점이 된다. 따라서 우리는 벡터 v의 가장 마지막에 끝점을 넣도록
    // 만들어 줄 것이다. 또한 각 세대에서 새로 만들어지는 좌표와 몇세대인지 같이 묶어서 저장할 것이다.
    // 문제 예시의 (0,0), (1,0)은 0세대, (1,-1)은 1세대에 새로 생성, (0,-1),(0,-2)는 2세대에 새로 생성 되었다.
    
    // 현재 가장 최신 세대를 lastgen으로 표현해준다.
    int lastgen = v[v.size() - 1].second;
    
    // 가장 최신 세대가 만들고자 하는 세대까지 도달할 때 까지 반복해준다.
    while(lastgen < gen){
        // 드래곤 커브 좌표를 담은 벡터의 크기
        int s = (int)(v.size() - 1);
        // 해당 세대의 드래곤 커브의 끝점 좌표
        int ex = v[s].first.first;
        int ey = v[s].first.second;
        
        int g = lastgen;
        
        // 벡터의 맨 마지막은 끝점이 오게 만들어준다고 얘기했으며, 문제를 분석해보면 끝점의 좌표는 회전의 중심이므로 변하지 않는다. (직접 돌려보자!)
        // 따라서 끝점을 제외한 나머지만 회전시켜준다.
        for(int i = (int)(v.size() - 2); i >= 0; i--){
            
            // 이 때, 문제의 예시를 살펴보자. (0,0), (1,0), (1,-1), (0,-1), (0,-2)는 2세대 드래곤 커브인데, (0,0)이 시작점, (0,-2)
            // 가 끝점이 되며, (1,0)의 회전이 (0,-1)이 되고, (0,0)의 회전이 (0,-2)가 된다. 이 말은 즉 현재 세대의 이전 세대에서,
            // 끝점 바로 뒤에 나오는 좌표가 끝점의 다음 점이 되고, 끝점의 뒤의 뒤 좌표가 끝점의 다음의 다음 좌표가 된다. 따라서 끝점의 이전 좌표
            // 부터 시작해서 벡터의 맨 처음 좌표 순서로 회전시킨 좌표를 벡터에 넣어줘야 드래곤 커브의 시작점이 다음 세대의 끝점으로 만들어질 것이다.
            int tx = v[i].first.first;
            int ty = v[i].first.second;
            
            // 같은 세대의 좌표는 같은 끝점을 가지며, 이 끝점은 즉 회전의 중심좌표가 된다. 세대가 변하기까지 회전 좌표를 유지해서 각 좌표를 돌려주자.
            v.push_back(make_pair(drotate(tx, ty, ex, ey), g + 1));
        }
        // 현재 세대의 좌표를 전부 맵에 넣어주자.
        for(int i = 0; i < v.size(); i++){
            map[v[i].first.second][v[i].first.first] = 1;
        }
        lastgen++;
    }
    
//    cout << "-----------------------------" << '\n';
//    for(int i = 0; i < v.size(); i++){
//        cout << v[i].first.first << " " << v[i].first.second << " " << v[i].second << '\n';
//    }
}
// 맵은 최대 100 * 100까지 가능하므로 그냥 맵 전체를 다 탐색해서 (x,y),(x+1,y),(x,y+1),(x+1,y+1)이 모두 1이면 이 사각형의 모든 꼭짓점은
// 드래곤 커브의 좌표를 가지고 있으므로 개수를 1 올려준다.
void PathFind(){
    for(int i = 0; i < 100; i++){
        for(int j = 0; j < 100; j++){
            if(map[i][j] == 1 && map[i + 1][j] == 1 && map[i][j + 1] == 1 && map[i + 1][j + 1] == 1){
                answer++;
            }
            
        }
    }
}

int main(){
    
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> order[i][0];
        cin >> order[i][1];
        cin >> order[i][2];
        cin >> order[i][3];
    }
    
    for(int i = 0; i < n; i++){
        int d = order[i][2];
        // 시작점 대비 방향에 따라 x방향으로 1 더할지 뺄지, 또는 y방향으로 1 더할지 뺄지 정해준다.
        if(d == 0){
            BFS(order[i][0], order[i][1], order[i][0] + 1, order[i][1], order[i][3]);
        }
        else if(d == 1){
            BFS(order[i][0], order[i][1], order[i][0], order[i][1] - 1, order[i][3]);
        }
        else if(d == 2){
            BFS(order[i][0], order[i][1], order[i][0] - 1, order[i][1], order[i][3]);
        }
        else if(d == 3){
            BFS(order[i][0], order[i][1], order[i][0], order[i][1] + 1, order[i][3]);
        }
    }
    
    PathFind();
    cout << answer;
    return 0;
}
