//
//  SevenDwarf.cpp
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

int main(){
    
    int tall[9], sum = 0, Iidx = 0, Jidx = 0;
    vector<pair<int, int> > t[9];
    
    for(int i = 0; i < 9; i++){
        cin >> tall[i];
        sum += tall[i];
    }
    
    for(int i = 0; i < 9; i++){
        
        int j = 0;
        while(j != 9){
            if(i != j){
                t[i].push_back(make_pair(tall[i], tall[j]));
            }
            j++;
        }
    }
    
    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){
            if(sum - t[i][j].first - t[i][j].second == 100){
                Iidx = i; Jidx = j;
                break;
            }
        }
    }
    sort(tall, tall + 9);
    
    for(int i = 0; i < 9; i++){
        if(tall[i] != t[Iidx][Jidx].first && tall[i] != t[Iidx][Jidx].second){
            cout << tall[i] << '\n';
        }
    }
    
    return 0;
}

