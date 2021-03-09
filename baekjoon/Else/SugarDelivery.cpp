//
//  SugarDelivery.cpp
//  test
//
//  Created by 신기열 on 05/04/2019.
//  Copyright © 2019 신기열. All rights reserved.
//

#include <stdio.h>
#include <iostream>

using namespace std;

int min(int a, int b){
    if(a >= b){ return b; }
    else{ return a; }
}

int main(){
    
    int total;
    int minW = 50000;
    int i = 0;
    
    cin >> total;
    int first_total = total;

    while(total - 5 * i >= 0){

        total = total - 5 * i;

        if(total % 3 == 0){
            minW = min(minW, i + (total / 3));
        }

        //cout << minW;
        total = first_total;
        i++;
    }
    
    if(minW == 50000){
        cout << -1;
    }
    else{
        cout << minW;
    }
    
    return 0;
}
