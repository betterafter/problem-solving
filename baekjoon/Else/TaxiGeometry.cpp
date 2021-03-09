//
//  TaxiGeometry.cpp
//  test
//
//  Created by 신기열 on 13/06/2019.
//  Copyright © 2019 신기열. All rights reserved.
//
#include <stdio.h>
#include <iostream>
#include <vector>
#define _USE_MATH_DEFINES
#include <math.h>
#include <algorithm>

using namespace std;

bool compare(int a, int b){
    return a > b;
}

int main(){
    
    double n;
    cin >> n;

    printf("%.6f\n", n * n * M_PI);
    printf("%.6f\n", n * n * 2);
    return 0;
}

