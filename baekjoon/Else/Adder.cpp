//
//  Adder.cpp
//  test
//
//  Created by 신기열 on 17/06/2019.
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

using namespace std;

int main(){
    
    int T;
    cin >> T;
    
    for(int test = 0; test < T; test++){
        queue<int> q;
        int n, flag = 0;
        cin >> n;
        
        while(1){
            int cnt = 1, sum = 0;
            q.push(cnt);

            while(sum < n){
                sum += cnt;
                cnt++;
                if(sum < n) q.push(cnt);
            }
           
            if(sum == n){
                break;
            }
            else{
                while(sum > n){
                    sum -= q.front();
                    q.pop();
                    cout << sum << '\n';
                }
            }
            
            if(sum != n) flag = 1;
            break;
        }
        if(flag == 1) cout << "IMPOSSIBLE" << '\n';
        else{
            int s = q.size();
            for(int i = 0; i < s; i++){
                if(q.size() == 1) cout << q.front();
                else cout << q.front() << " + ";
                q.pop();
            }
            cout << '\n';
        }
    }
    
    
    return 0;
}

