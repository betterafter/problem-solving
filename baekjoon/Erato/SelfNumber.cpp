//
//  SelfNumber.cpp
//  test
//
//  Created by 신기열 on 04/06/2019.
//  Copyright © 2019 신기열. All rights reserved.
//

#include <stdio.h>
#include <iostream>

using namespace std;

int isSelfNumber[10001] = { 0, };

void SelfNumber(int num){

    int sum = num;
    while((float)num / 10 >= 0.1){
        sum += (num % 10);
        num /= 10;

    }
    
    isSelfNumber[sum] = 1;
    //SelfNumber(sum);
}


int main(){
    
    for(int i = 1; i <= 10000; i++){
        SelfNumber(i);
    }
    
    for(int i = 1; i <= 10000; i++){
        if(isSelfNumber[i] == 0){
            cout << i << '\n';
        }
    }
    
    return 0;
}
