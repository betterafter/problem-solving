//
//  RGBDistance.cpp
//  test
//
//  Created by 신기열 on 11/05/2019.
//  Copyright © 2019 신기열. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    
    int n;
    cin >> n;
    int color[n][3], price[n][3], p[1000];
    
    for(int i = 0; i < n; i++){
        cin >> color[i][0] >> color[i][1] >> color[i][2];
    }
    
    price[0][0] = color[0][0]; price[0][1] = color[0][1]; price[0][2] = color[0][2];
    price[1][0] = min(color[1][0] + color[0][1], color[1][0] + color[0][2]);
    price[1][1] = min(color[1][1] + color[0][0], color[1][1] + color[0][2]);
    price[1][2] = min(color[1][2] + color[0][0], color[1][2] + color[0][1]);
    
    p[0] = min(price[0][0], price[0][1]);
    p[0] = min(p[0], price[0][2]);
    
    p[1] = min(price[1][0], price[1][1]);
    p[1] = min(p[1], price[1][2]);
    
    for(int i = 2; i < n; i++){
        
        price[i][0] = min(color[i][0] + price[i-1][1], color[i][0] + price[i-1][2]);
        price[i][1] = min(color[i][1] + price[i-1][0], color[i][1] + price[i-1][2]);
        price[i][2] = min(color[i][2] + price[i-1][0], color[i][2] + price[i-1][1]);
        
        p[i] = min(price[i][0], price[i][1]);
        p[i] = min(p[i], price[i][2]);
    }
    
    cout << p[n-1];
    
    return 0;
}
