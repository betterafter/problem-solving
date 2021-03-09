//
//  14865.cpp
//  test
//
//  Created by 신기열 on 01/07/2019.
//  Copyright © 2019 신기열. All rights reserved.
//
#include <stdio.h>
#include <iostream>
#include <math.h>
#include <algorithm>
#include <utility>
#include <vector>
#include <queue>

using namespace std;

bool compare(pair<int, int>&a, pair<int, int>&b){
    return a.first < b.first;
}

int main(){
    
    int n; cin >> n;
    //vector<pair<int, int> > v;
    queue<pair<int, int> > q;
    vector<pair<int, int> > point;
    
    for(int i = 0; i < n; i++){
        int x, y; cin >> x >> y;
        //v.push_back(make_pair(x, y));
        q.push(make_pair(x, y));
    }
    
    while(q.front().second > 0){
        pair<int, int> p = q.front();
        q.pop(); q.push(p);
    }
    
    while(!q.empty()){
        
        if(q.front().second < 0){
            
            pair<int, int> p1 = q.front(); q.pop();
            
            while((p1.first != q.front().first || (long long)p1.second * q.front().second >= 0) && !q.empty()){
                p1 = q.front();
                q.pop();
            }
        }
        else if(q.front().second > 0){

            pair<int, int> p1 = q.front(); q.pop();
            
            int x1 = p1.first, x2 = p1.first;
            while(!q.empty() && (p1.first != q.front().first || (long long)p1.second * q.front().second >= 0)){
                x2 = q.front().first;
                p1 = q.front();
                q.pop();
            }
            if(x1 != x2) point.push_back(make_pair(min(x1, x2), max(x1, x2)));
        }
    }
    
    
    
    
    sort(point.begin(), point.end(), compare);
//
//    for(int i = 0; i < point.size(); i++){
//        cout << point[i].first << " " << point[i].second << '\n';
//    }
    
    int res1 = 0, res2 = 0;
    int MaxX = -2e9;
    
    for(int i = 0; i < point.size(); i++){
        if(MaxX < point[i].first) res1++;
        MaxX = max(MaxX, point[i].second);
        if(point[i + 1].first > point[i].second) res2++;
        else if(i == point.size() - 1) res2++;
    }
    
    cout << res1 << " " << res2;
    return 0;
}





//
//    int i = 0, flag = 0;
//    while(i < n){
//
//        int tempx1, tempx2;
//
//        if(i == 0){
//            if(v[i].first != v[n - 1].first || v[i].second * v[n - 1].second >= 0){
//                flag = 1;
//                int x1 = v[i].first, x2 = v[i].first;
//                while(v[i].first != v[i + 1].first || v[i].second * v[i + 1].second >= 0){
//                    x2 = v[i].first; i++;
//                }
//                tempx1 = min(x1, x2);
//                tempx2 = max(x1, x2);
//            }
//        }
//
//        if(v[i].second < 0){
//            while(v[i].first != v[i + 1].first || v[i].second * v[i + 1].second >= 0){
//                i++;
//                if(i == n) break;
//            } i++;
//        }
//        else if(v[i].second >= 0){
//
//            int x1 = v[i].first, x2 = v[i].first;
//            while(v[i].first != v[i + 1].first || v[i].second * v[i + 1].second >= 0){
//                x2 = v[i].first; i++;
//                if(i == n) break;
//            }
//            x2 = v[i].first;
//            if(flag == 1 && i == n){
//                point.push_back(make_pair(min(min(x1, x2), tempx1), max(max(x1, x2), tempx2)));
//                break;
//            }
//            if(x1 != x2) point.push_back(make_pair(min(x1, x2), max(x1, x2)));
//            i++;
//        }
//
//    }
//
