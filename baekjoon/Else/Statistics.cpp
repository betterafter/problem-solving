//
//  Statistics.cpp
//  test
//
//  Created by 신기열 on 09/06/2019.
//  Copyright © 2019 신기열. All rights reserved.
//
#include <stdio.h>
#include <iostream>
#include <vector>
#include <math.h>
#include <cmath>
#include <algorithm>

using namespace std;


int main(){
    
    int n, num[8010] = { 0, }, mostrecently = 0, MRN = 0, MSN = 0;
    vector<int> v;
    vector<int> Most_Recently;
    float sum = 0;
    cin >> n;
    
    for(int i = 0; i < n; i++){
        int m;
        cin >> m;
        v.push_back(m);
        num[m + 4000]++;
        sum += m;
    }
    
    sort(v.begin(), v.end());
    int middle = n / 2;
    for(int i = 1; i <= 8000; i++){
        if(num[mostrecently] <= num[i]){
            mostrecently = i;
        }
    }
    
    for(int i = 0; i <= 8000; i++){
        if(num[i] == num[mostrecently]){
            Most_Recently.push_back(i - 4000);
        }
    }
    
    for(int i = 0; i <= 8000; i++){
        if(num[i] != 0){
            MSN = i - 4000;
            break;
        }
    }
    
    for(int i = 0; i <= 8000; i++){
        if(num[i] != 0){
            MRN = i - 4000;
        }
    }
    
    float average = floor(sum / n + 0.5);
    int middlenumber = v[middle];
    
    int MostRecentlyNumber;
    if(Most_Recently.size() == 1){
        MostRecentlyNumber = Most_Recently[0];
    }
    else if(Most_Recently.size() >= 2){
        MostRecentlyNumber = Most_Recently[1];
    }
    int difference = MRN - MSN;
    
    cout << average << '\n';
    cout << middlenumber << '\n';
    cout << MostRecentlyNumber << '\n';
    cout << difference << '\n';
    
    return 0;
}

