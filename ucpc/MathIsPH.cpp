//
//  MathIsPH.cpp
//  UCPC
//
//  Created by 신기열 on 07/06/2019.
//  Copyright © 2019 신기열. All rights reserved.
//

#include <stdio.h>
#include <iostream>

using namespace std;

int main(){
    
    unsigned long long n, ans;
    cin >> n;
    
    if(n == 1){
        ans = 4;
    }
    else{
        ans = 1 + n * 3 + (n - 1);
    }
    
    cout << ans;
    return 0;
}
