//
//  Virus.cpp
//  test
//
//  Created by 신기열 on 12/06/2019.
//  Copyright © 2019 신기열. All rights reserved.
//
#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <math.h>
#include <cmath>
#include <algorithm>
#include <list>
#include <deque>

using namespace std;

int visited[101] = { 0, }, cnt = 0;
list<int> li[101];
int N, conn;

queue<int> q;

void BFS(){
    
    q.push(1);
    visited[1] = 1;
    
    while(!q.empty()){
        
        int idx = q.front();
        q.pop();
        
        list<int>::iterator iter;
        for(iter = li[idx].begin(); iter != li[idx].end(); iter++){
            if(visited[*iter] == 0){
                cnt++;
                visited[*iter] = 1;
                q.push(*iter);
            }
        }
    }
}


int main(){
    
    cin >> N >> conn;
    
    for(int test = 0; test < conn; test++){
        int n, m;
        cin >> n >> m;
        li[n].push_back(m);
        li[m].push_back(n);
    }
    
    BFS();
    cout << cnt;
    return 0;
}

