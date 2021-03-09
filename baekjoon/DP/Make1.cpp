//
//  Make1.cpp
//  test
//
//  Created by 신기열 on 22/03/2019.
//  Copyright © 2019 신기열. All rights reserved.
//

#include <iostream>
#include <stdio.h>

using namespace std;


int main(int argc, const char * argv[]) {
    
    int X;
    int i = 4;
    int count[1000001];
    
    int div_2 = 0, div_3 = 0;

    scanf("%d", &X);
    
    count[2] = 1;
    count[3] = 1;
    
    while(i <= X)
    {
        
        count[i] = count[i-1] + 1; //1을 빼줄 때의 개수
        
        if(i % 2 == 0)
        {
            div_2 = count[i / 2] + 1;
            if(div_2 <= count[i]){
                
                count[i] = div_2;
            }
        }
        
        if(i % 3 == 0)
        {
            div_3 = count[i / 3] + 1;
            if(div_3 <= count[i]){
                
                count[i] = div_3;
            }
        }
        i++;
    }

    printf("%d", count[X]);
    
    return 0;
}
