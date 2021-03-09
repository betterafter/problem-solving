//
//  17140.cpp
//  BJ
//
//  Created by 신기열 on 03/11/2019.
//  Copyright © 2019 신기열. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int r, c, ridx, cidx;
int n[300][300];
int answer;

// 일단 어차피 배열 안에 들어갈 수 있는 최대 수는 100이며, 무엇보다 행렬이 100이 넘어가게 되면 그냥 짤려버린다. 따라서 배열 크기가 그렇게 클 필요가 없다. 그냥 벡터로 매 순간 업데이트 하는 것보다,
// 미리 공간을 확보하는 것이 시간이 훨씬 절약될 것이다.

// 또한 특정 숫자가 몇 개 들어있는지 저장하는 것은 map보다는 pair 배열을 이용하는게 좀 더 빠를 것이라 생각해서 pair 배열을 이용하기로 했다. 이 점을 참고해서 보도록 하자.

// pair배열을 정렬하기 위한 compare 함수이다. 비교 순서는 몇 개 들어있는지에 대한 오름차순 정렬 후, 같은 개수만큼 들어있으면 작은 수부터 나오도록 하면 된다.
bool compare(pair<int, int> &a, pair<int, int> &b){
    if(a.second != b.second) return a.second < b.second;
    else return a.first < b.first;
}

// cidx는 열의 길이, ridx는 행의 길이이다.
void calc(){
    // 열이 행보다 더 길 때
    if(cidx > ridx){
        // 열에 대하여 탐색해준다.
        for(int i = 1; i <= cidx; i++){
            // pair는 미리 101개 (1 ~ 100이 몇개인지 확인하기 위한 배열) 생성해준다.
            pair<int, int> p[101];
            // 모든 행을 돌면서 각 숫자가 몇개 있는지를 pair로 묶어서 저장해준다. 이 때, 맵 n에 대해 탐색한 현재 위치는 0으로 만들어줘야 하는데, 맵을 새로 할당하는 것은 여러번 할 경우 시간이
            // 많이 걸리기 때문에 미리 할당한 배열을 재활용하는 것이 시간이 훨씬 단축될 것이다. 이 때 초기화를 따로 진행하는 것도 O(2n)이 되므로 평소라면 신경 안 썼지만 0.5초이므로 최대한
            // 한 번의 루프로 초기화도 같이 해버리도록 하자. """이 때 y축에 대해 정렬이므로 j가 앞으로 (n[j][i]) 가야한다. 주의하자."""
            for(int j = 1; j <= ridx; j++){
                int num = n[j][i]; p[num].first = num; p[num].second++; n[j][i] = 0;
            }
            // p에 대하여 오름차순 정렬을 진행한다.
            sort(p, p + 101, compare);
            int tp = 1;
            // p배열 100개 중에 한번이라도 등장한 것은 맵 n에 1번부터 차근차근 넣어주자. n번에 등장한 숫자, n+1번에 그 숫자가 등장한 횟수를 넣어준다.
            for(int t = 1; t <= 100; t++){
                if(p[t].first != 0){
                    n[tp][i] = p[t].first; n[tp + 1][i] = p[t].second;
                    tp += 2;
                }
            }
            // 행이 추가되었으므로 최대값을 업데이트 해주자. 이 때 각 행마다 ridx가 가장 큰 경우를 찾아줘야한다. tp - 1인 이유는 가령 ridx = 2일 때 1번과 2번을 차지하고 tp = 3이 되는데,
            // ridx는 마지막 idx는 2만큼 이동한 후 뒤로 한칸 이동한 것과 같기 때문에 (1시작, 1 숫자, 2 횟수, tp = 3, ... tp - 1 = 2 = 마지막 인덱스) 1을 빼준다.
            ridx = max(ridx, tp - 1);
        }

        
    }
    // 위와 완전히 같은 알고리즘으로 이번엔 행에 대하여 정렬을 해줘야한다. 이번에는 n[i][j]순으로 i가 먼저 들어가야하는 것을 명심하도록 하자.
    else if(cidx <= ridx){
        for(int i = 1; i <= ridx; i++){
            pair<int, int> p[101];
            for(int j = 1; j <= cidx; j++){
                int num = n[i][j]; p[num].first = num; p[num].second++; n[i][j] = 0;
            }
            sort(p, p + 101, compare);
            int tp = 1;

            for(int t = 1; t <= 100; t++){
                if(p[t].first != 0){
                    n[i][tp] = p[t].first; n[i][tp + 1] = p[t].second;
                    tp += 2;
                }
            }
            cidx = max(tp - 1, cidx);
        }
    }
//    cout << ridx << " " << cidx << '\n';
//    for(int i = 1; i <= 10; i++){
//        for(int j = 1; j <= 10; j++){
//            cout << n[i][j] << " ";
//        }
//        cout << '\n';
//    }
//    cout << '\n';
}

int main(){
    
    int r, c, k;
    cin >> r >> c >> k;
    for(int i = 1; i <= 3; i++){
        for(int j = 1; j <= 3; j++){
            cin >> n[i][j];
        }
    }
    
    ridx = 3; cidx = 3;
    while(n[r][c] != k){
        calc(); answer++;
        if(answer > 100){
            answer = -1; break;
        }
    }
    
    cout << answer;
    return 0;
}
