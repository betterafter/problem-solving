//
//  Tree.cpp
//  test
//
//  Created by 신기열 on 18/06/2019.
//  Copyright © 2019 신기열. All rights reserved.
//
#include <stdio.h>
#include <iostream>
#include <vector>
#include <utility>
#include <math.h>
#include <cmath>
#include <algorithm>
#include <queue>
#include <list>

using namespace std;

int leafcnt = 0;
list<int> tree[51];
int deleted[51] = { 0, };
int childSize[51];
queue<int> q;

void BFS(int d){
    
    q.push(d);
    
    if(tree[q.front()].empty()){ deleted[q.front()] = 1; return; }
    
    while(!q.empty()){
        
        int curr = q.front();
        deleted[curr] = 1;
        q.pop();
        
        list<int>::iterator iter;
        for(iter = tree[curr].begin(); iter != tree[curr].end(); iter++){
            //cout << curr << " : " << *iter << '\n';
            deleted[*iter] = 1;
            if(!tree[*iter].empty()) q.push(*iter);
        }
    }
    return;
}

int main(){
    
    int n, deleteNode, root = 0;
    cin >> n;
    
    for(int i = 0; i < n; i++){
        double parent;
        cin >> parent;
        
        if(parent == -1) root = i;
        if(parent != -1) tree[(int)parent].push_back(i);
    }
    
    for(int i = 0; i < n; i++){
        childSize[i] = tree[i].size();
    }
    
    cin >> deleteNode;
    BFS(deleteNode);
    
    for(int i = 0; i < n; i++){
        if(deleted[i] == 0){
            list<int>::iterator iter;
            for(iter = tree[i].begin(); iter != tree[i].end(); iter++){
                if(deleted[*iter] == 1) childSize[i]--;
            }
        }
        
        if(childSize[i] == 0 && deleted[i] == 0) leafcnt++;
    }

    
    if(deleteNode == root) cout << 0;
    else if(!tree[root].empty() && leafcnt == 0) cout << 1;
    else cout << leafcnt;
    return 0;
}

