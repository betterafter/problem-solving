//
//  2019_summer_winder_coding_1.cpp
//  BJ
//
//  Created by 신기열 on 12/11/2019.
//  Copyright © 2019 신기열. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <math.h>
using namespace std;


long long solution(int w,int h)
{
    long long answer = 0;
    
    for(int i = 1; i < w; i++){
        // 직선 방정식의 해를 전부 더해준다. (사각형의 개수 전부 더해주는 과정)
        answer = answer + (int)(-(h / (double)w * i) + h);
    }
    // 위, 아래 2세트이므로 2배
    return answer * 2;
}

