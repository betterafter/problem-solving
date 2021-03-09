//
//  ToyAssemble.cpp
//  test
//
//  Created by 신기열 on 14/06/2019.
//  Copyright © 2019 신기열. All rights reserved.
//
#include <stdio.h>
#include <iostream>
#include <vector>
#include <utility>
#include <math.h>
#include <list>
#include <algorithm>

using namespace std;

int N, M;
list<pair<int, int> > toy[101];
vector<int> base;

int IsBase[101] = { 0, };
int baseCnt[101][101] = { 0, };
int visited[101] = { 0, };


void DFS(int part){
    
    if(IsBase[part] == 1){
        return;
    }
    
    list<pair<int, int> >::iterator iter;
    for(iter = toy[part].begin(); iter != toy[part].end(); iter++){
        if(visited[iter -> first] == 0){
            DFS(iter -> first);
            visited[iter -> first] = 1;
        }
        if(IsBase[iter -> first] == 1){
            baseCnt[part][iter -> first] += iter -> second;
        }
        else{
            for(int i = 1; i <= base.size(); i++){
                baseCnt[part][base[i - 1]] += baseCnt[iter -> first][base[i - 1]] * (iter -> second);
            }
        }
    }
}


int main(){

    cin >> N >> M;

    for(int i = 0; i < M; i++){
        int a, b, c;
        cin >> a >> b >> c;
        toy[a].push_back(make_pair(b, c));
    }

    for(int i = 1; i <= N; i++){
        if(toy[i].empty()){
            IsBase[i] = 1;
            base.push_back(i);
        }
    }

    for(int i = 1; i <= N; i++){
        if(IsBase[i] == 1){
            baseCnt[i][base[i]] = 1;
        }
    }


    DFS(N);
    
    for(int i = 0; i < base.size(); i++){
        if(baseCnt[N][base[i]] > 0)
        cout << base[i] << " " << baseCnt[N][base[i]] << '\n';
    }


    return 0;
}


/////////////////////////////////////////////////////////////////////////////////////////////////////////
// 처음에 DP로 풀었을 때 문제점은 : dp[2]와 dp[1]의 연관성이 없을 수도 있다는 것이다. 즉 dp[2]가 dp[1]을 가지지 않을 수도 있고,
// 뭐가됐든 연속적인 인덱스의 dp가 연관이 없다는 것. 그래서 dp[n]을 dp[n-1]을 통해 알아낼 수 없다는 것.
// 결국 dfs로 풀어서 쫙 훝어봐야됨.
