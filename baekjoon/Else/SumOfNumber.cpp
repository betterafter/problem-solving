//
//  SumOfNumber.cpp
//  test
//
//  Created by 신기열 on 13/06/2019.
//  Copyright © 2019 신기열. All rights reserved.
//
#include <stdio.h>
#include <iostream>
#include <vector>
#include <utility>
#include <math.h>
#include <algorithm>

#define ull unsigned long long

using namespace std;


int main(){
    
    ull n;
    cin >> n;
    
    ull i = 1, sum = 0, cnt = 0;
    
    while(sum <= n){
        sum += i;
        i++;
        cnt++;
    }
    
    cout << --cnt;
    return 0;
}


