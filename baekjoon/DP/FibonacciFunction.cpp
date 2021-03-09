//
//  FibonacciFunction.cpp
//  test
//
//  Created by 신기열 on 11/05/2019.
//  Copyright © 2019 신기열. All rights reserved.
//
#include <stdio.h>
#include <iostream>
#include <vector>
#include <utility>

using namespace std;

int main() {
    
    vector<pair<int, int> > v;
    int n;
    
    v.resize(40);
    
    v[0].first = 1; v[0].second = 0;
    v[1].first = 0; v[1].second = 1;
    
    for(int i = 2; i < 41; i++){
        v[i].first = v[i - 1].first + v[i - 2].first;
        v[i].second = v[i - 1].second + v[i - 2].second;
    }
    
    cin >> n;
    int buf[n];
    
    for(int i = 0; i < n; i++){
        cin >> buf[i];
    }
    
    for(int i = 0; i < n; i++){
        cout << v[buf[i]].first << " " << v[buf[i]].second << '\n';
    }
    
    return 0;
}
