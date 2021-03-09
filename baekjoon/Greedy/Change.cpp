

//
//  Change.cpp
//  test
//
//  Created by 신기열 on 27/05/2019.
//  Copyright © 2019 신기열. All rights reserved.
//

#include <stdio.h>
#include <iostream>

using namespace std;

int main(){
    
    int c, change, cnt = 0;
    cin >> c;
    
    change = 1000 - c;
    
    while(change > 0){
        if(change >= 500){
            cnt++; change -= 500;
        }
        else if(change >= 100){
            cnt++; change -= 100;
        }
        else if(change >= 50){
            cnt++; change -= 50;
        }
        else if(change >= 10){
            cnt++; change -= 10;
        }
        else if(change >= 5){
            cnt++; change -= 5;
        }
        else if(change >= 1){
            cnt++; change -= 1;
        }
    }
    
    cout << cnt;
    
    return 0;
}
