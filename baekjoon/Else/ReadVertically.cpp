//
//  ReadVertically.cpp
//  test
//
//  Created by 신기열 on 11/04/2019.
//  Copyright © 2019 신기열. All rights reserved.
//

#include <stdio.h>
#include <string>
#include <iostream>

using namespace std;

int main(){
    
    char Buffer[5][16];
    //int t = 0;
    
    for(int i = 0; i < 5; i++){
        scanf("%s", Buffer[i]);
    }
    
    for(int p = 0; p < 15; p++){
        for(int q = 0; q < 5; q++){
            if(p < strlen(Buffer[q])){
                cout << Buffer[q][p];
            }
        }
    }
    
    
    ////////////////// string Buffer[5] 로 만들 수도 있다. /////////////////////
    return 0;
}
