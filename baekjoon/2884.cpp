//
//  2884.cpp
//  BJ
//
//  Created by 신기열 on 18/09/2019.
//  Copyright © 2019 신기열. All rights reserved.
//

#include <stdio.h>
#include <iostream>

using namespace std;

int main(){

    int H, M, time; cin >> H >> M;

    if(H == 0) time = 24 * 60 + M - 45;
    else time = H * 60 + M - 45;
    if(time / 60 == 24) cout << 0 << " " << time % 60;
    else cout << time / 60 << " " << time % 60;
    
    return 0;
}
