//
//  Degururu.cpp
//  test
//
//  Created by 신기열 on 17/06/2019.
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

    while(1){
        
        int n, cnt = 0, idx = 0;
        cin >> n;
        
        cin.ignore();
        if(n == 0) break;
 
        while(cnt < n){
            string s = "";

            getline(cin, s);
            for(int i = 0; i < s.size(); i++){
                if(s[i] == ' ' && i >= idx){
                    idx = i; break;
                }
                else if(i == s.size() - 1 && s.size() >= idx){
                    idx = s.size();
                    break;
                }
            }
            cnt++;
        }
        cout << idx + 1 << '\n';
    }
    
    
    return 0;
}

