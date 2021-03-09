//
//  LittlePrince.cpp
//  test
//
//  Created by 신기열 on 12/05/2019.
//  Copyright © 2019 신기열. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <math.h>

using namespace std;

int main(){
    
    int n, x1, y1, x2, y2;
    cin >> n;
    
    int result[n];
    
    for(int i = 0; i < n; i++){
        cin >> x1 >> y1 >> x2 >> y2;
        
        int nn, cnt = 0;
        cin >> nn;
        
        int cx, cy, r;
        
        for(int j = 0; j < nn; j++){
            
            cin >> cx >> cy >> r;
            
            if(pow((cx - x1), 2) + pow((cy - y1), 2) < pow(r, 2)){
                if(pow((cx - x2), 2) + pow((cy - y2), 2) > pow(r, 2)){
                    cnt++;
                }
            }
            
            else if(pow((cx - x2), 2) + pow((cy - y2), 2) < pow(r, 2)){
                if(pow((cx - x1), 2) + pow((cy - y1), 2) > pow(r, 2)){
                    cnt++;
                }
            }
        }
        result[i] = cnt;
    }
    
    for(int i = 0; i < n; i++){
        cout << result[i] << '\n';
    }
    
    
    
    
    return 0;
}
