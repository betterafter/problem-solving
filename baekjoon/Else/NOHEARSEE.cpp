//
//  NOHEARSEE.cpp
//  test
//
//  Created by 신기열 on 13/06/2019.
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
#include <deque>

using namespace std;

int main(){
    
    priority_queue<string, vector<string>, less<string> > pq;
    priority_queue<string, vector<string>, greater<string> > str;

    int N, M;
    cin >> N >> M;
    
    for(int i = 0; i < N; i++){
        string s;
        cin >> s;
        pq.push(s);
    }
    
    for(int i = 0; i < M; i++){
        string s;
        cin >> s;
        pq.push(s);
    }
    
    
    while(!pq.empty()){
        string s = pq.top();
        pq.pop();
        if(!pq.empty()){
            if(s == pq.top()){
                str.push(s);
                pq.pop();
            }
        }
    }
    
    cout << str.size() << '\n';
    while(!str.empty()){
        cout << str.top() << '\n';
        str.pop();
    }

    
    return 0;
}

