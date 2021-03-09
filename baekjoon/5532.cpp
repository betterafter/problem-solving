//
//  5532.cpp
//  BJ
//
//  Created by 신기열 on 20/09/2019.
//  Copyright © 2019 신기열. All rights reserved.
//

#include <stdio.h>
#include <iostream>

using namespace std;

int main(){
    
    int L, A, B, C, D, res1, res2;
    cin >> L >> A >> B >> C >> D;
    
    if(A % C == 0) res1 = A / C;
    else res1 = A / C + 1;
    
    if(B % D == 0) res2 = B / D;
    else res2 = B / D + 1;
    
    cout << L - max(res1, res2);
    
    
    return 0;
}
