//
//  19872.cpp
//  BJ
//
//  Created by 신기열 on 18/09/2019.
//  Copyright © 2019 신기열. All rights reserved.
//

#include <stdio.h>
#include <iostream>

using namespace std;

int main(){
    
    int N;
    int res = 1;
    
    cin >> N;
    
    for(int i = 1; i <= N; i++){
        res *= i;
    }
    
    cout << res << '\n';
    return 0;
}
