//
//  CardComb.cpp
//  UCPC
//
//  Created by 신기열 on 07/06/2019.
//  Copyright © 2019 신기열. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <queue>

using namespace std;

int main(){
    
    priority_queue<unsigned long long, vector<unsigned long long>, greater<unsigned long long> > pq;
    
    int n, m;
    unsigned long long ans = 0;
    cin >> n >> m;
    
    for(int i = 0; i < n; i++){
        int k;
        cin >> k;
        pq.push(k);
    }
    
    for(int i = 0; i < m; i++){
        unsigned long long x = pq.top();
        pq.pop();
        unsigned long long y = pq.top();
        pq.pop();
        
        unsigned long long sum = x + y;
        pq.push(sum);
        pq.push(sum);
    }
    
    while(!pq.empty()){
        unsigned long long x = pq.top();
        pq.pop();
        
        ans += x;
    }
    
    cout << ans;
    return 0;
}
