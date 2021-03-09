//
//  GoldbachConjecture.cpp
//  test
//
//  Created by 신기열 on 09/06/2019.
//  Copyright © 2019 신기열. All rights reserved.
//
#include <stdio.h>
#include <iostream>
#include <vector>
#include <math.h>
#include <cmath>
#include <algorithm>

using namespace std;



int main(){
    
    int T;
    cin >> T;
    
    for(int test = 0; test < T; test++){
        
        int Prime[10001], MIN = 100000, ans = 0;
        int m;
        cin >> m;
        
        for(int i = 0; i <= 10000; i++){
            Prime[i] = 1;
        }
        
        Prime[0] = 0;
        Prime[1] = 0;
        
        for(int i = 2; i <= m; i++){
            for(int j = 2; j <= sqrt(i); j++){
                if(i % j == 0){
                    Prime[i] = 0;
                    break;
                }
            }
        }
        
        for(int i = 2; i <= m / 2; i++){
            if(Prime[m - i] == 1 && Prime[i] == 1){
                int currmin = abs(i - (m - i));
                if(currmin < MIN){
                    MIN = currmin;
                    ans = i;
                }
            }
        }
        
        
        cout << ans << " " << m - ans << '\n';
    }
    
    
    return 0;
}

