//
//  7568.cpp
//  test
//
//  Created by 신기열 on 02/07/2019.
//  Copyright © 2019 신기열. All rights reserved.
//
#include <stdio.h>
#include <vector>
#include <iostream>

using namespace std;

int main(){
    
    int n; cin >> n;
    vector<pair<int, int> > v;
    int ans[n];
    for(int i = 0; i < n; i++){
        int x, y; cin >> x >> y;
        v.push_back(make_pair(x, y));
        ans[i] = 0;
    }
    
    for(int i = 0; i < v.size(); i++){
        for(int j = 0; j < v.size(); j++){
            if(i != j){
                if(v[i].first < v[j].first && v[i].second < v[j].second) ans[i]++;
            }
        }
    }
    
    for(int i = 0; i < n; i++){
        cout << ans[i] + 1 << " ";
    }
    
    return 0;
}
