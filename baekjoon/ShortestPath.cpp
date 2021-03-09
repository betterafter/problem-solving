//
//  ShortestPath.cpp
//  test
//
//  Created by 신기열 on 19/06/2019.
//  Copyright © 2019 신기열. All rights reserved.
//
#include <stdio.h>
#include <iostream>
#include <utility>
#include <cmath>
#include <algorithm>
#include <list>
#include <queue>

#define MAX 2e9

using namespace std;

unsigned long value[20001] = { 0, };
list<pair<int, int> > path[20001];
int visit[20001] = { 0, };

queue<int> q;

//void DFS(int start){
//
//    list<pair<int, int> >::iterator iter;
//    for(iter = path[start].begin(); iter != path[start].end(); iter++){
////        if(value[iter -> first] == MAX) value[iter -> first] = value[start];
////            cout << value[iter -> first];
//        value[iter -> first] = min(value[start] + iter -> second, value[iter -> first]);
//        DFS(iter -> first);
//    }
//}

void BFS(int start){
    
    q.push(start);
    
    while(!q.empty()){
        int curr = q.front();
        visit[curr] = 1;
        q.pop();
        
        list<pair<int, int> >::iterator iter;
        for(iter = path[curr].begin(); iter != path[curr].end(); iter++){
            value[iter -> first] = min(value[curr] + iter -> second, value[iter -> first]);
            if(visit[iter -> first] == 0) q.push(iter -> first);
        }
    }
}




int main(){
    
    int V, E, K;
    
    cin >> V >> E;
    cin >> K;
    
    for(int i = 1; i <= V; i++){
        value[i] = MAX;
    }
    
    value[K] = 0;
    
    for(int i = 0; i < E; i++){
        int u, v, w;
        cin >> u >> v >> w;
        
        path[u].push_back(make_pair(v, w));
    }
    
    //DFS(K);
    BFS(K);
    
    for(int i = 1; i <= V; i++){
        if(value[i] == MAX) cout << "INF" << '\n';
        else cout << value[i] << '\n';
    }
    
    return 0;
}

//DP로 풀어보자

/////////////////////다익스트라 공부하고 풀어보자///////////////////////
