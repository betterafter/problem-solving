//
//  kakao2018_2.cpp
//  Contest
//
//  Created by 신기열 on 24/09/2019.
//  Copyright © 2019 신기열. All rights reserved.
//
#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

bool cmp(pair<float,int>&a, pair<float,int>&b){
    if(a.first == b.first) return a.second < b.second;
    else return a.first > b.first;
}

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    vector<pair<float, int> > Vanswer;
    int biggerStage[501] = { 0, };
    int numberStage[501] = { 0, };
    float failure[501] = { 0, };
    int maxStage = 0;
    
    // stages를 돌면서,
    for(int i = 0; i < stages.size(); i++){
        // 특정 스테이지에 도달한 사람 + 1
        numberStage[stages[i]]++;
        // 해당 스테이지에 도달했다면 이전 스테이지 역시 도달했으므로 특정 스테이지 도달에 각각 +1
        // 예를 들어 stages[i] = 3 이면, 3에 있는 사람을 numberStage에 넣어서 1명 증가, 도달한 스테이지 1, 2, 3 은 biggerStage에 넣어서 1 증가 
        // numberStage는 해당 스테이지에 몇명이 있는지, biggerStage는 도달 + 클리어한 사람 모두 합친 것을 담는 배열  
        for(int j = 1; j <= stages[i]; j++){
            biggerStage[j]++;
        }
        // 진행 중인 스테이지 중에서 레벨이 가장 높은 스테이지 찾기 
        maxStage = max(maxStage, stages[i]);
    }
    
    for(int i = 1; i <= N; i++){
        // 문제에 나와있는 실패율 구하기
        if(biggerStage[i] != 0) failure[i] = (double)numberStage[i] / (double)biggerStage[i];
        else failure[i] = 0;
        // 해당 스테이지에 대한 실패율을 key & value 형태로 저장
        Vanswer.push_back(make_pair(failure[i],i));
    }
    // 실패율이 같으면 스테이지가 작은 번호 순으로, 아니면 실패율이 높은 순으로 정렬
    sort(Vanswer.begin(), Vanswer.end(), cmp);
    // answer에 넣고 출력
    for(int i = 0; i < Vanswer.size(); i++){
        answer.push_back(Vanswer[i].second);
    }
    
    return answer;
}
