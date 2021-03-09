//
//  BulkHouse.cpp
//  test
//
//  Created by 신기열 on 07/06/2019.
//  Copyright © 2019 신기열. All rights reserved.
//

#include <stdio.h>
#include <iostream>

using namespace std;

int main(){
    
    unsigned long long n, cnt = 1;
    cin >> n;
    
    if(n == 1){
        cout << cnt;
    }
    
    else{
        int curr = 1;
        
        while(1){
            if(n <= curr + 6 * cnt){
                break;
            }
            else{
                curr += 6 * cnt;
                cnt++;
            }
        }
        
        cout << cnt + 1;
    }

    return 0;
}
