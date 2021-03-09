//
//  2588.cpp
//  test
//
//  Created by 신기열 on 02/07/2019.
//  Copyright © 2019 신기열. All rights reserved.
//
#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    
    int s1, s2; cin >> s1 >> s2;
    cout << (s2 % 10) * s1 << '\n';
    cout << ((s2 - s2 / 100 * 100) / 10) * s1 << '\n';
    cout << (s2 / 100) * s1 << '\n';
    cout << s1 * s2 << '\n';
    
    
    return 0;
}
