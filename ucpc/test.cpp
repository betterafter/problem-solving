//
//  test.cpp
//  UCPC
//
//  Created by 신기열 on 06/06/2019.
//  Copyright © 2019 신기열. All rights reserved.
//

#include <stdio.h>
#include <iostream>

using namespace std;

int test[200000][200000];

int main(){

    for(int i = 0; i < 200000; i++){
        for(int j = 0; j < 200000; j++){
            test[i][j] = -1;
        }
    }


    for(int i = 0; i < 200000; i++){
        for(int j = 0; j < 200000; j++){
            cout << test[i][j];
        }
    }
    










    return 0;
}
