//
//  Olympic.cpp
//  test
//
//  Created by 신기열 on 12/06/2019.
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

bool compare(pair<pair<int, int>, pair<int, int> > &a, pair<pair<int, int>, pair<int, int> > &b){
    if(a.first.second != b.first.second) return a.first.second > b.first.second;
    else if(a.second.first != b.second.first) return a.second.first > b.second.first;
    else return a.second.second > b.second.second;
}

int main(){
    
    vector<pair<pair<int, int>, pair<int, int> > > v;
    int N, K, order = 1, common = 0;
    cin >> N >> K;
    
    for(int i = 0; i < N; i++){
        int n, g, s, b;
        cin >> n >> g >> s >> b;
        v.push_back(make_pair(make_pair(n, g), make_pair(s, b)));
        
    }
    
    sort(v.begin(), v.end(), compare);
    
//    for(int i = 0; i < v.size(); i++){
//        cout << v[i].first.first << " " << v[i].first.second << " " << v[i].second.first << " " << v[i].second.second << '\n';
//    }
    
    if(v[0].first.first == K) cout << order;
    else{
        for(int i = 1; i < v.size(); i++){
            
            //cout << v[i].first.first << '\n';
            
            int g1 = v[i].first.second, s1 = v[i].second.first, b1 = v[i].second.second;
            int g2 = v[i - 1].first.second, s2 = v[i - 1].second.first, b2 = v[i - 1].second.second;
            
            if(g1 != g2 || s1 != s2 || b1 != b2){
                order++; order += common; common = 0;
            }
            else if(g1 == g2 && s1 == s2 && b1 == b2) common++;
            if(v[i].first.first == K) break;
        }
        
        cout << order;
    }
    return 0;
}

