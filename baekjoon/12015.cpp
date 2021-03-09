//
//  12015.cpp
//  test
//
//  Created by 신기열 on 03/07/2019.
//  Copyright © 2019 신기열. All rights reserved.
//
#include <stdio.h>
#include <algorithm>
#include <math.h>
#include <vector>
#include <iostream>

using namespace std;

int main(){
    
    int n; cin >> n;
    vector<int> v;
    vector<int> ans;
    for(int i = 1; i <= n; i++){
        int t; cin >> t;
        v.push_back(t);
    }

    for(int i = 0; i < v.size(); i++){
        if(ans.size() == 0){
            ans.push_back(v[i]);
        }

        else if(v[i] > ans[ans.size() - 1]){
            ans.push_back(v[i]);
        }

        else if(v[i] < ans[ans.size() - 1]){
            vector<int> :: iterator lb;
            lb = lower_bound(ans.begin(), ans.end(), v[i]);
            *lb = v[i];
        }
    }

    cout << ans.size();    
    return 0;
}
