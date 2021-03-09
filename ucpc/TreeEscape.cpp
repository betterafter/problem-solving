//
//  TreeEscape.cpp
//  UCPC
//
//  Created by 신기열 on 07/06/2019.
//  Copyright © 2019 신기열. All rights reserved.
//

#include <stdio.h>
#include <list>
#include <iostream>

using namespace std;

list<int> tree[500001];
int visited[500001] = { 0, };
int cnt = 0;

void DFS(int x, int count){
    
    visited[x] = 1;
    int flag = 0;
    list<int>::iterator iter;
    
    for(iter = tree[x].begin(); iter != tree[x].end(); iter++){
        
        if(visited[*iter] == 0){
            int c = count;
            flag = 1; c++;
            DFS(*iter, c);
        }
    }
    
    if(flag == 0){
        cnt += count;
    }
}


int main(){
    
    int n;
    cin >> n;
    
    for(int i = 0; i < n - 1; i++){
        int n1, n2;
        cin >> n1 >> n2;
        tree[n1].push_back(n2);
        tree[n2].push_back(n1);
    }
    
    DFS(1, 0);
    
    if(cnt % 2 == 0){
        cout << "No";
    }
    else{
        cout << "Yes";
    }
    
    return 0;
}
