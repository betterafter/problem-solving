//
//  1676.cpp
//  test
//
//  Created by 신기열 on 27/06/2019.
//  Copyright © 2019 신기열. All rights reserved.
//

#include <stdio.h>
#include <iostream>

using namespace std;

long long num[501][2] = { 0, };

int main(){
    
    int n; cin >> n;
    long long num_2 = 0, num_5 = 0;
    
    for(int i = 1; i <= n; i++){
        int j = i;
        while(j % 2 == 0 || j % 5 == 0){
            if(j % 2 == 0){
                num[i][0]++;
                j /= 2;
            }
            if(j % 5 == 0){
                num[i][1]++;
                j /= 5;
            }
        }
        num_2 += num[i][0];
        num_5 += num[i][1];
    }
    
    cout << min(num_2, num_5);
    
    return 0;
}
