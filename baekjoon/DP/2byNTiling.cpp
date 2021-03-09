//
//  2byNTiling.cpp
//  test
//
//  Created by 신기열 on 27/05/2019.
//  Copyright © 2019 신기열. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main(){
    
    int tile[1001], n;
    cin >> n;
   
    tile[1] = 1; tile[2] = 2; tile[3] = 3;
    
    for(int i = 4; i < 1001; i++){
        tile[i] = (tile[i - 1] + tile[i - 2]) % 10007;
    }
    
    cout << tile[n] % 10007;
    
    return 0;
}
