//
//  1057.cpp
//  BJ
//
//  Created by 신기열 on 19/09/2019.
//  Copyright © 2019 신기열. All rights reserved.
//

#include <stdio.h>
#include <iostream>

using namespace std;

int main(){
    
    int N, A, B, cnt = 0;
    cin >> N >> A >> B;
    
    if(N == 1){
        cout << - 1;
        return 0;
    }
    
    while(A != B){
        if(A % 2 != 0) A = A / 2 + 1;
        else if(A % 2 == 0) A = A / 2;
        
        if(B % 2 != 0) B = B / 2 + 1;
        else if(B % 2 == 0) B = B / 2;
        
        cnt++;
    }
    cout << cnt;
    
    
    return 0;
}
