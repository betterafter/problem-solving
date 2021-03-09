//
//  RotateQ.cpp
//  test
//
//  Created by 신기열 on 11/06/2019.
//  Copyright © 2019 신기열. All rights reserved.
//
#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>
#include <deque>
#include <algorithm>
#include <math.h>

using namespace std;



int main(){
    
    vector<int> order;
    int N, M, cnt = 0;
    cin >> N >> M;
    
    deque<int> dq;
    
    for(int i = 0; i < M; i++){
        int n;
        cin >> n;
        order.push_back(n);
    }

    for(int i = 1; i <= N; i++){
        dq.push_back(i);
    }
    
    for(int i = 0; i < M; i++){
        
        int index = 1;
        
        deque<int>::iterator iter;
        for(iter = dq.begin(); iter != dq.end(); iter++){
            if(*iter != order[i]) index++;
            else break;
        }
        
        int f = index - 1;
        unsigned long b = dq.size() - index;
        
        //cout << i << " : " << f << "  " << b << '\n';
        
        if(f <= b){
            while(dq.front() != order[i]){
                int n = dq.front();
                dq.push_back(n);
                dq.pop_front();
                cnt++;
            }
            dq.pop_front();
        }
        
        else{
            while(dq.back() != order[i]){
                int n = dq.back();
                dq.pop_back();
                dq.push_front(n);
                cnt++;
            }
            dq.pop_back();
            cnt++;
        }
        
//        for(iter = dq.begin(); iter != dq.end(); iter++){
//            cout << *iter << " ";
//        }
//        cout << '\n' << cnt << '\n';
        
    }
    
    cout << cnt;
    return 0;
}
