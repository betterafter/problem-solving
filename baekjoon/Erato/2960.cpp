//
//  2960.cpp
//  test
//
//  Created by 신기열 on 27/06/2019.
//  Copyright © 2019 신기열. All rights reserved.
//
#include <stdio.h>
#include <iostream>

using namespace std;

int Sieve[1001] = { 0, };

int main(){
    
    int N, K, flag = 0, ans = 0, cnt = 0; cin >> N >> K;
    
    for(int i = 2; i <= N; i++){
        if(Sieve[i] == 0){
            cnt++;
            Sieve[i] = 1;
            
            int j = 1;
            if(flag == 1){ ans = i; break; }
            
            while(i * j <= N){
                
                if(Sieve[i * j] == 0){ Sieve[i * j] = 1; cnt++; }
                if(cnt == K){ ans = i * j; flag = 1; break; }
                j++;
            }
        }
        if(flag == 1) break;
    }
    
    cout << ans;
    return 0;
}
