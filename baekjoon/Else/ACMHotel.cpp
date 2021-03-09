//
//  ACMHotel.cpp
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
        int H, W, N;
        cin >> H >> W >> N;
        
        int n = 1;
        
        while(1){
            if(N <= n * H){
                N -= (n - 1) * H;
                break;
            }
            else{
                n++;
            }
        }
        if(n < 10){
            cout << N << 0 << n << '\n';
        }
        else{
            cout << N << n << '\n';
        }
    }
    
    return 0;
}
