//
//  13458.cpp
//  test
//
//  Created by 신기열 on 28/06/2019.
//  Copyright © 2019 신기열. All rights reserved.
//
#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

int n;

int main(){
    
    cin >> n;
    vector<int> room(n);
    long long sum = 0;
    int A, B;
    
    for(int i = 0; i < n; i++){
        cin >> room[i];
    }
    cin >> A >> B;
    
    for(int i = 0; i < n; i++){
        if(room[i] <= A){
            sum += 1;
        }
        else{
            if((room[i] - A) % B != 0){
                sum += 1 + (room[i] - A) / B + 1;
            }
            else{
                sum += 1 + (room[i] - A) / B;
            }
        }
    }
    
    cout << sum;
    return 0;
}
