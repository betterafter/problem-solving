//
//  GCDorLCM.cpp
//  test
//
//  Created by 신기열 on 12/06/2019.
//  Copyright © 2019 신기열. All rights reserved.
//

#include <stdio.h>
#include <iostream>

using namespace std;

int GCD(int a, int b){
    int c;
    
    while(b != 0){
        c = a % b;
        a = b;
        b = c;
    }
    
    return a;
}


int LCM(int a, int b){
    return a * b / GCD(a, b);
}

int main(){
    int a, b;
    cin >> a >> b;
    cout << GCD(a, b) << '\n' << LCM(a, b);
    
    return 0;
}
