//
//  8320.cpp
//  BJ
//
//  Created by 신기열 on 20/09/2019.
//  Copyright © 2019 신기열. All rights reserved.
//

#include <stdio.h>
#include <iostream>

using namespace std;

int main(){
    
    int N, cnt = 0;
    cin >> N;
    
    for(int i = 1; i <= N; i++){
        for(int j = i; j <= N; j++){
            if(i * j <= N) cnt++;
            else break;
        }
    }
    
    cout << cnt;
    
    return 0;
}
