//
//  ContestOrIntern.cpp
//  test
//
//  Created by 신기열 on 27/05/2019.
//  Copyright © 2019 신기열. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <math.h>

using namespace std;


int main(){
    
    int M, N, K, cnt = 0, i = 1;
    cin >> M >> N >> K;
    
    while(K > 0){
        if(M >= N * 2){
            M--; K--;
        }
        else if(M < N * 2){
            N--; K--;
        }
    }
 
    while(2 * i <= M || 1 * i <= N){
        if(2 * i <= M && 1 * i <= N){
            cnt++;
        }
        i++;
    }

    cout << cnt;
    
    return 0;
}
