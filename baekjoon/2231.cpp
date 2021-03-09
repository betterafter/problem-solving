//
//  2231.cpp
//  test
//
//  Created by 신기열 on 02/07/2019.
//  Copyright © 2019 신기열. All rights reserved.
//

#include <stdio.h>
#include <iostream>

using namespace std;

int main(){
    
    int n; cin >> n;
    
    int i = 1;
    while(i <= n){
        int sum = i, temp = i;
        while(temp > 0){
            sum += temp % 10;
            temp /= 10;
        }
        
        if(sum == n){ cout << i; return 0; }
        i++;
    }
    
    cout << 0;
    return 0;
}
