//
//  JosephusPermutation.cpp
//  test
//
//  Created by 신기열 on 10/06/2019.
//  Copyright © 2019 신기열. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <queue>

using namespace std;

int main(){
    
    queue<int> q;
    int n, m;
    cin >> n >> m;
    
    cout << "<";
    
    for(int i = 1; i <= n; i++){
        q.push(i);
    }
    
    while(!q.empty()){
        for(int i = 1; i < m; i++){
            int n = q.front();
            q.pop(); q.push(n);
        }
        
        
        if(q.size() > 1){
            cout << q.front() << ", ";
        }
        else if(q.size() == 1){
            cout << q.front();
        }
        
        q.pop();
    }
    
    cout << ">";

    return 0;
}
