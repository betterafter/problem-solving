//
//  14864.cpp
//  test
//
//  Created by 신기열 on 01/07/2019.
//  Copyright © 2019 신기열. All rights reserved.
//
#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

int main(){
    
    int N, M; cin >> N >> M;
    vector<vector<int> > parent(N+1), child(N+1);
    int visit[N+1];
    int res[N+1];
    
    for(int i = 0; i < M; i++){
        int n, m; cin >> n >> m;
        
        parent[m].push_back(n);
        child[n].push_back(m);
    }
    
    for(int i = 1; i <= N; i++){
        visit[i] = 0;
    }
    
    for(int i = 1; i <= N; i++){
        
        res[i] = 1 + ((i - 1 - parent[i].size()) + child[i].size());
        visit[res[i]] = 1;
    }

    for(int i = 1; i <= N; i++){
        if(visit[i] == 0){ cout << -1; return 0; }
    }
    for(int i = 1; i < N; i++){
        cout << res[i] << " ";
    }
    cout << res[N];
    
    return 0;
}
