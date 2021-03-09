//
//  Histogram.cpp
//  test
//
//  Created by 신기열 on 04/04/2019.
//  Copyright © 2019 신기열. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

int max(int a, int b){
    if(a >= b){ return a; }
    else{ return b; }
}

int main(){
    
    int number;
    int width = 1;
    int maxWidth = 0;
    int t = 0;
    int Index = 1;
    int widthValue;
    
    vector<int> histogram;
    
    cin >> number;
    
    for(int i = 0; i < number; i++){
        cin >> widthValue;
        histogram.push_back(widthValue);
    }
   
    while(t < number){
        
        while(Index < number){
            
            if(histogram[t] <= histogram[Index]){
                width++;
                Index++;
            }
            
            else if(histogram[t] > histogram[Index]){
                
                break;
            }
        }

        int p  = t - 1;
        
        while(histogram[t] <= histogram[p] && p >= 0){
            
            width++;
            p--;
        }
        
        maxWidth = max(maxWidth, width * histogram[t]);
        
        t++;
        Index = t + 1;
        width = 1;
    }
    
    cout << maxWidth;
    
    return 0;
}



