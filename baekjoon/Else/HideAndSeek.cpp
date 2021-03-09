
//
//  HideAndSeek.cpp
//  test
//
//  Created by 신기열 on 12/06/2019.
//  Copyright © 2019 신기열. All rights reserved.
//
#include <cstdio>
#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <queue>
#include <math.h>

using namespace std;

int N, K, ans;
int Visited[100001] = { 0, };
queue<int> pos;

int BFS(){

    pos.push(N);
    Visited[N] = 1;

    while(1){

        int curr = pos.front();
        pos.pop();
        if(curr == K) { ans = curr; break; }
        
        for(int i = 0; i < 3; i++){

            if(i == 0 && curr - 1 >= 0){
                if(Visited[curr - 1] == 0){
                    Visited[curr - 1] = Visited[curr] + 1;
                    pos.push(curr - 1);
                }
            }

            else if(i == 1 && curr + 1 <= 100000){
                if(Visited[curr + 1] == 0){
                    Visited[curr + 1] = Visited[curr] + 1;
                    pos.push(curr + 1);
                }
            }

            else if(i == 2 && curr * 2 <= 100000){
                if(Visited[curr * 2] == 0){
                    Visited[curr * 2] = Visited[curr] + 1;
                    pos.push(curr * 2);
                }
            }
        }
    }
    return Visited[ans] - 1;
}

int main(){

    cin >> N >> K;
    cout << BFS();
    return 0;
}

///////////////////////////////////////////////////////////////////
// 중요포인트 : while문안에서 return 할 때 while(!q.empty()) ... if() return 이런 식으로 썼었는데,
// 만약 q.empty == 1 인 경우에서 if문의 조건에 만족하지 않아버리면 return이 되지 않을 수 있음. 따라서 처음부터 무한정 돌다가 return으로 빠져나가던가,
// empty에 대한 정보를 계속 갱신하는 방향으로 가면 return에 만족하게 될 거임.
// curr + 1 도 100000을 벗어나면 더 더해줄 필요가 없어짐. 그다음부턴 빼주기만 하면 되니까. 따라서 여기도 범위를 설정해줘야함.
