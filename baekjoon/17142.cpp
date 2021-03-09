//
//  17142.cpp
//  BJ
//
//  Created by 신기열 on 04/11/2019.
//  Copyright © 2019 신기열. All rights reserved.
//

#include <stdio.h>
#include <cstring>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m;
int map[50][50];
int tmap[50][50];
// 실수 1. 이 경우 크게 상관 없었지만 변수명은 항상 다른 함수명, 변수명 등과 겹치지 않는지 꼭 확인하자.
int iempty;
int dir[4][2] = { {0,1}, {0,-1}, {1,0}, {-1,0} };
vector<pair<int, int> > virus;
vector<pair<int, int> > v;
// 실수 2. 가장 큰 실수였는데, answer를 100000000으로 적어놓고 main함수에서 if(answer = 100000) 이런 식으로 적어버렸다. 이제부터 #define MAX 1000000 과 같이 미리 정의를 해서 숫자 크기
// 실수를 안하도록 만들어주자.
int answer = 100000000;
queue<pair<int, int> > q;

void BFS(){
    // iempty는 맵에 있는 빈 공간의 개수이며, ans는 현재까지 걸린 시간을 구하기 위한 변수이다.
    int tempty = iempty; int ans = 0;
    while(!q.empty()){
        int x = q.front().first, y = q.front().second;
        q.pop();
        
        for(int i = 0; i < 4; i++){
            int nx = x + dir[i][0], ny = y + dir[i][1];
            // 네 방향이 맵 안에 있으며 & tmap[ny][nx]가 -1이며 (즉 이미 바이러스가 확산 된 위치가 아니며) & 다음 위치가 벽이 아닐 때
            if(nx >= 0 && ny >= 0 && nx < n && ny < n && tmap[ny][nx] == -1 && map[ny][nx] != 1){
                // tmap은 방문했는지 여부를 판단하는 것과 동시에, 시간을 전부 기록하는 배열이다. 이 때 시간을 다 덮어버리면 모든 배열이 바이러스로 차 있는 경우는 체크를 못한다는 문제가 있는데, 아래의
                // if문에서 그 문제점을 해결하였다.
                // 일단 tmap은 시간 기록이 메인인 배열이므로 일단 시간으로 덮어버리자.
                tmap[ny][nx] = tmap[y][x] + 1;
                // 옆으로 확산 되었으므로 일단 이 좌표는 다음에 쓸 수 있도록 한다.
                q.push(make_pair(nx, ny));
                // map[ny][nx] 가 0이라면, 즉 비활성화 바이러스가 활성화된 게 아니라, 원래 빈 공간이었던 곳에 확산시킨 것이라면 그 시간을 가져오자. 비활성화 바이러스 -> 활성화 바이러스인 케이스는
                // 활성화 되기 전까지 얼마나 시간이 걸렸는지는 중요한게 아니다. 어차피 이미 바이러스가 있으니까 그 위치 기준으론 0초인 것이다. 중요한 것은 그 비활성화 바이러스가 활성화 된 후 확산되는
                // 그 시간이 중요한 것이다. 즉 이런 경우다.
                // 0 - | * | -
                // - - - - - -
                // - - - - - 0
                // | | | | | |
                // 0이 활성화 바이러스, *이 비활성화 바이러스, -은 빈공간, |이 벽일 때, 위의 경우 시간은 아래와 같이 된다.
                // 0 1 | * | 2
                // 1 2 3 3 2 1
                // 2 3 3 2 1 0
                // | | | | | |
                // 즉 *에 도달하는 시간은 4이므로 tmap엔 4라고 적혀있지만, 이미 바이러스가 존재했던 위치이므로 저 위치의 시간은 의미가 없다는 뜻이다. 따라서 저 위치의 시간이 어떻든 간에 최종적으로
                // 걸린 시간은 3초가 된다는 뜻이다.
                
                // 참고로 빈 공간에 확산되었으므로 빈공간 개수도 1개 빼주자.
                if(map[ny][nx] == 0){
                    tempty--;
                    ans = tmap[ny][nx];
                }
                // 실수 3. 여기서 ans가 answer보다 크면 그냥 바로 함수를 탈출하게 만들었는데, 이럴 경우 q가 완전히 비워지지 않아서 전역 queue를 사용하게 될 경우 그 안에 빠지지 못한 데이터가
                // 그대로 남아있게 된다. 상황에 따라 달라지겠지만 되도록이면 완전히 다 빼고 return을 어떻게 줄 지 고려해보도록 하자.
            }
        }
    }
    // 빈공간이 하나도 없고 이 BFS 내의 최종 시간보다 answer가 더 크면 answer = ans가 된다.
    if(tempty == 0 && ans < answer) answer = ans;

//
//    for(int i = 0; i < n; i++){
//        for(int j = 0; j < n ;j++){
//            cout << tmap[i][j] << " ";
//        }
//        cout << '\n';
//
//    }
//    cout<<'\n';
    return;
}

// 시간 절약의 가장 중요한 부분이다.
void DFS(int idx){
    // 일단 v 벡터는 활성화 시킬 바이러스를 골라 담은 벡터이다. 그걸 총 고를 개수만큼 골랐으면 방문 & 시간 배열인 tmap은 -1로 전부 초기화해서 사실상 빈공간으로 만들어주고,
    // v벡터에 있는 활성화 바이러스 위치에만 0으로 만들어주자.
    if(v.size() == m){
        memset(tmap, -1, sizeof(tmap));
        for(int i = 0; i < v.size(); i++){
            q.push(v[i]); tmap[v[i].second][v[i].first] = 0;
        }
        // 그 후 BFS를 돌려주자.
        BFS(); return;
    }
    // 다 고르지 못했는데 선택할 인덱스가 이미 총 바이러스 위치를 담은 virus 벡터의 최대 인덱스를 넘어버리게 될 경우는 어차피 안되는 것이므로 그냥 DFS를 끝내주자.
    if(idx >= virus.size()) return;
    // n번을 고르면 다음에 고를건 무조건 n보다 큰 위치에서 시작해야된다. 가령
    // 1 2 3 4 5 6 7 중에서 3개를 뽑는다고 하면
    // 1 2 3과 3 2 1은 같은 것이 된다. 따라서
    // (1 2 3), (1 2 4), (1 2 5), (1 2 6), (1 2 7), (1 3 4), (1 3 5) ... 이런 식으로 중복되는 케이스가 없게 뽑아주자.
    for(int i = idx; i < virus.size(); i++){
        v.push_back(virus[i]);
        DFS(i + 1);
        v.pop_back();
    }
}



int main(){

    
    //cin >> n >> m;
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            //cin >> map[i][j];
            scanf("%d", &map[i][j]);
            if(map[i][j] == 2) virus.push_back(make_pair(j, i));
            else if(map[i][j] == 0) iempty++;
        }
    }

    DFS(0);
    // answer 값에 변화가 없다 = 위에서 말했듯이 빈 공간이 존재하게 되는 경우이다. 빈공간이 존재하면 -1로 출력해준다.
    if(answer == 100000000) cout << -1;
    else cout << answer;

    return 0;
}

