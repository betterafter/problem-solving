////
////  595_D.cpp
////  codeforces
////
////  Created by 신기열 on 05/11/2019.
////  Copyright © 2019 신기열. All rights reserved.
////
//
//#include <stdio.h>
//#include <iostream>
//#include <vector>
//#include <algorithm>
//
//using namespace std;
//
//int line[200100];
//int contain[200100];
//bool compare(pair<pair<int, int>, int>&a, pair<pair<int, int>, int>&b){
//    return a.first.second - a.first.first < b.first.second - b.first.first;
//}
//
//
//int main(){
//
//    int n,k;cin>>n>>k;
//    vector<int> ans;
//    vector<pair<pair<int, int>, int> > v;
//    for(int i = 0; i < n; i++){
//        int l,r;cin>>l>>r;
//        if(l == r){
//            line[r]++;
//            if(line[r] > k) contain[i + 1]++;
//        }
//        else{
//            for(int j = l; j <= r; j++){
//                line[j]++; if(line[j] > k) contain[i + 1]++;
//            }
//        }
//        v.push_back(make_pair(make_pair(l, r), i + 1));
//    }
//
//    sort(v.begin(), v.end(), compare);
//
//
//    
//    return 0;
//}
//
