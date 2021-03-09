//
//  MeetingRoomAssignment.cpp
//  test
//
//  Created by 신기열 on 24/05/2019.
//  Copyright © 2019 신기열. All rights reserved.
//

#include <stdio.h>
#include <algorithm>
#include <utility>
#include <vector>
#include <iostream>

using namespace std;

bool compare(const pair<int, int>& a, const pair<int, int>& b){
    
    if(a.second == b.second){
        return a.first < b.first;
    }
    else return a.second < b.second;
}

int main(){
    
    int n, total = 1, curr;
    cin >> n;
    vector<pair<int, int> > v;
    v.resize(n);
    
    for(int i = 0; i < n; i++){
        int p, q;
        cin >> p >> q;
        v[i].first = p; v[i].second = q;
    }
    
   // vector<pair<int, int> > :: iterator it;
    
    sort(v.begin(), v.end(), compare);

//    for(it = v.begin(); it != v.end(); it++){
//        cout << it -> first << " " << it -> second << '\n';
//    }
    
    curr = v[0].second;
    for(int i = 1; i < n; i++){
        
        if(v[i].first >= curr){
            curr = v[i].second;
            total++;
        }
    }

    cout << total;
    
    return 0;
}


