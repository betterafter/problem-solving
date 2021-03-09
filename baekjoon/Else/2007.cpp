//
//  2007.cpp
//  test
//
//  Created by 신기열 on 31/05/2019.
//  Copyright © 2019 신기열. All rights reserved.
//
#include <stdio.h>
#include <iostream>

using namespace std;

int main(){
    
    int x, y, curr = 1, day = 0;
    string week[7] = { "MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN" };
    
    cin >> x >> y;
    
    while(curr != x){
        if(curr == 2){
            day += 28;
        }
        else if(curr == 4 || curr == 6 || curr == 9 || curr == 11){
            day += 30;
        }
        else{
            day += 31;
        }
        curr++;
    }
    
    day = day + y - 1;
    cout << week[day % 7];
    
    return 0;
}
