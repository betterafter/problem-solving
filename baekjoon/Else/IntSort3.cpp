//
//  IntSort3.cpp
//  test
//
//  Created by 신기열 on 09/06/2019.
//  Copyright © 2019 신기열. All rights reserved.
//
#include <stdio.h>
#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>

using namespace std;


int main(){
    
    int n, num[10001] = { 0, }, MAX = 0;
    vector<int> v;
    cin >> n;
    
    for(int i = 0; i < n; i++){
        int m;
        scanf("%d", &m);
        num[m]++;
        MAX = max(MAX, m);
    }
    
    for(int i = 1; i <= MAX; i++){
        if(num[i] != 0){
            for(int j = 0; j < num[i]; j++){
                printf("%d\n", i);
            }
        }
    }
    
    return 0;
}

