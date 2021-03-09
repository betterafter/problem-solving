//
//  SimpleTest2.cpp
//  test
//
//  Created by 신기열 on 31/05/2019.
//  Copyright © 2019 신기열. All rights reserved.
//
#include <stdio.h>
#include <iostream>
#include <vector>
#include <utility>
#include <math.h>
#include <cmath>
#include <algorithm>
#include <deque>

using namespace std;

int main(){
    
    string s[50];
    int n;
    cin >> n;
    cin >> s[0];
    
    for(int i = 1; i < n; i++){
        cin >> s[i];
        
        for(int j = 0; j < s[0].size(); j++){
            if(s[0][j] != s[i][j]){
                s[0][j] = '?';
            }
        }
    }
    cout << s[0];
    return 0;
}

