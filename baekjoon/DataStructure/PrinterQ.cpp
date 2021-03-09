//
//  PrinterQ.cpp
//  test
//
//  Created by 신기열 on 10/06/2019.
//  Copyright © 2019 신기열. All rights reserved.
//
#include <stdio.h>
#include <iostream>
#include <queue>
#include <vector>
#include <utility>
#include <string>

using namespace std;

int main(){
    
    int T;
    cin >> T;
    
    for(int test = 0; test < T; test++){
        
        vector<pair<int, int> > v;
        queue<pair<int, int> > q;
        priority_queue<int, vector<int>, less<int> > pq;
        
        int N, M, cnt = 0, curr = -1;
        cin >> N >> M;
        
        for(int i = 0; i < N; i++){
            int n;
            cin >> n;
            
            if(i == M){
                q.push(make_pair(n, 1));
                curr = n;
            }
            else if(i != M){
                q.push(make_pair(n, 0));
            }

            pq.push(n);
        }
        
        while(!q.empty()){
            int MAX = pq.top();
            
            //cout << "IS : " << q.front().first << " " <<  q.front().second << '\n';
            if(q.front().first != MAX){
                pair<int, int> p = q.front();
                q.pop(); q.push(p);
            }
            
            else if(q.front().first == MAX && curr != MAX){
                q.pop(); pq.pop(); cnt++;
            }
            
            else if(q.front().first == MAX && curr == MAX){
                if(q.front().second == 1){
                    q.pop(); pq.pop(); cnt++; break;
                }
                else{
                    q.pop(); pq.pop(); cnt++;
                }
            }
        }
        
        cout << cnt << '\n';
    }
    
    return 0;
}
