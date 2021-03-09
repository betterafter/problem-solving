//
//  SplitAndMerge.cpp
//  UCPC
//
//  Created by 신기열 on 07/06/2019.
//  Copyright © 2019 신기열. All rights reserved.
//
#include <stdio.h>
#include <vector>
#include <iostream>

using namespace std;

vector<int> calc;

int main(){
    
    int before[3001], after[3001];
    
    int L, n, m, cnt = 0;
    cin >> L;
    cin >> n;
    
    for(int i = 1; i <= n; i++){
        cin >> before[i];
    }
    
    cin >> m;
    
    for(int i = 1; i <= n; i++){
        cin >> after[i];
    }
    
    int T = 0;
    
    while(T <= L){
        if(before[T] < after[T]){
            if(before[T + 1] == 2){
                calc.push_back(3);
                cnt += 2;
                before[T + 1] = 1;
            }
            else{
                
            }
        }
    }
    
    
    return 0;
}
