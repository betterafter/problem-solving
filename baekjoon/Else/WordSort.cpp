//
//  WordSort.cpp
//  test
//
//  Created by 신기열 on 09/06/2019.
//  Copyright © 2019 신기열. All rights reserved.
//
#include <stdio.h>
#include <iostream>
#include <vector>
#include <math.h>
#include <cmath>
#include <algorithm>

using namespace std;

bool compare(string s1, string s2){
    if(s1.size() == s2.size()){
        int i = 0;
        while(i != s1.size()){
            if(s1[i] == s2[i]) i++;
            else return s1[i] < s2[i];
        }
    }
    return s1.size() < s2.size();
}

int main(){
    
    int n;
    cin >> n;
    
    string s[20001];
    
    for(int i = 0; i < n; i++){
        cin >> s[i];
    }
    
    sort(s, s + n, compare);
    
    
    cout << s[0] << '\n';
    for(int i = 1; i < n; i++){
        if(s[i] != s[i - 1]){
            cout << s[i] << '\n';
        }
    }
    
    return 0;
}

