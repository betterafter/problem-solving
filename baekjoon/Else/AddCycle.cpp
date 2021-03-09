//
//  AddCycle.cpp
//  test
//
//  Created by 신기열 on 12/05/2019.
//  Copyright © 2019 신기열. All rights reserved.
//

#include <stdio.h>
#include <iostream>

using namespace std;

int main(){
    
    int n, cnt = 1, number[2], tempn;
    cin >> n;
    
    tempn = n;
    
    while(1){
        
        if(n < 10 && n >= 0){
            number[0] = 0; number[1] = n;
        }
        else if(n >= 10 && n <= 99){
            number[0] = n / 10; number[1] = n - number[0] * 10;
            
        }
        
        n = number[1] * 10 + ((number[0] + number[1]) % 10);
    
        if(n == tempn){
            cout << cnt;
            break;
        }
        else{
            cnt++;
        }
    }
    
    
    
    
    return 0;
}
