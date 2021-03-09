//
//  14697.cpp
//  test
//
//  Created by 신기열 on 30/06/2019.
//  Copyright © 2019 신기열. All rights reserved.
//
#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

int flag = 0;


void Room(int a, int b, int c, int n){
    
    
    for(int i = 0; i <= n / a; i++){
        for(int j = 0; j <= n / b; j++){
            for(int k = 0; k <= n / c; k++){
                if(a * i + b * j + c * k == n){ cout << 1; return; }
            }
        }
    }
    
    flag = 1;
}


using namespace std;

int n;

int main(){
    
    int A, B, C, N; cin >> A >> B >> C >> N;
    Room(A, B, C, N);
    
    if(flag == 1) cout << 0;
    
    return 0;
}
