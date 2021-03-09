//
//  MostAlphabet.cpp
//  test
//
//  Created by 신기열 on 14/06/2019.
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
    
    ios_base::sync_with_stdio();
    cin.tie(0);
    
    int alpha[26] = { 0, }, MAX = 0;
    vector<char> v;
    
    string s;
    while(cin >> s){
        
        for(int i = 0; i < s.size(); i++){
            if(s[i] >= 97 && s[i] <= 123){
                alpha[s[i] - 97]++;
                MAX = max(alpha[s[i] - 97], MAX);
            }
        }
        s.clear();
    }
    
    for(int i = 0; i < 26; i++){
        if(alpha[i] == MAX) cout << (char)(i + 97);
    }
    
    return 0;
}

