//
//  OneTwoThree.cpp
//  test
//
//  Created by 신기열 on 22/03/2019.
//  Copyright © 2019 신기열. All rights reserved.
//

#include <stdio.h>


int main(){
    
    int T;
    int t = 4;
    int q[12];
    int count[12];
    
    scanf("%d", &T);
    
    for(int i = 0; i < T; i++){
        scanf("%d", &q[i]);
    }
    
    count[1] = 1;
    count[2] = 2;
    count[3] = 4;
    
    while(t <= 11)
    {
        count[t] = count[t-1] + count[t-2] + count[t-3];
        t++;
    }
    
    for(int i = 0; i < T; i++){
        printf("%d\n", count[q[i]]);
    }
    
    return 0;
}
