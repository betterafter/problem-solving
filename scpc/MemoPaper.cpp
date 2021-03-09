//
//  MemoPaper.cpp
//  SCPC
//
//  Created by 신기열 on 29/06/2019.
//  Copyright © 2019 신기열. All rights reserved.
//
#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

int Answer;

bool compare(pair<int, int>&a, pair<int, int>&b){
    return a.first < b.first;
}

int main(int argc, char** argv)
{
    int T, test_case;
    
    cin >> T;
    for(test_case = 0; test_case  < T; test_case++)
    {
        Answer = 0;
        int n; cin >> n;
        vector<int> EndPoint(n+1);
        vector<pair<int, int> > point;
        
        for(int i = 0; i < n; i++){
            int x, y, h; cin >> x >> y >> h;
            point.push_back(make_pair(y, h));
        }
        sort(point.begin(), point.end(), compare);

        EndPoint[0] = point[0].first;
        for(int i = 1; i < n; i++){
            if(point[i].first < EndPoint[i - 1]){
                Answer++;
                EndPoint[i] = EndPoint[i - 1] + point[i].second;
                //cout << "Case1" << '\n';
            }
            else{
                
                //cout << point[i].first - EndPoint[i - 1] << " " << point[i].second << '\n';
                
                if(point[i].first - EndPoint[i - 1] >= point[i].second){
                    EndPoint[i] = point[i].second;
                    //cout << "Case2" << '\n';
                }
                else{
                    EndPoint[i] = point[i].first + point[i].second - (point[i].first - EndPoint[i - 1]);
                    //cout << "Case3" << '\n';
                }
            }
            //cout << EndPoint[i] << '\n';
        }
        
        cout << "Case #" << test_case+1 << endl;
        cout << Answer << endl;
    }
    
    return 0;
}

//////////// 개어려움. 포기 /////////////////////
// https://algopoket.tistory.com/35?category=339232
// https://blog.kennysoft.kr/2018-07-07-2018-scpc-2r/
