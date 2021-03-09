//
//  FlyMeToTheAlphaCentauri.cpp
//  test
//
//  Created by 신기열 on 08/06/2019.
//  Copyright © 2019 신기열. All rights reserved.
//
#include <stdio.h>
#include <iostream>

using namespace std;

int main(){
    
    int T;
    cin >> T;
    
    for(int test = 0; test < T; test++){
        long x, y, dist, n = 1, ans = 0;
        cin >> x >> y;
        
        dist = y - x;
        
        if(dist == 1){
            ans = 1;
        }
        
        else{
            while(dist > n * n){
                n++;
            }
            
            if(dist < n * n){
                long curr = 2 * (n - 1);
                if(dist <= (n-1) * (n-1) + n-1){ ans = curr; }
                else{ ans = curr + 1; }
            }
            
            else if(dist == n * n){ ans = 2 * n - 1; }
            
        }
        
        cout << ans << '\n';
    }

    return 0;
}
