//
//  2490.cpp
//  BJ
//
//  Created by 신기열 on 18/09/2019.
//  Copyright © 2019 신기열. All rights reserved.
//

#include <stdio.h>
#include <iostream>

using namespace std;

int main(){
    
    for(int test = 0; test < 3; test++){
        
        int stick[4];
        int front = 0;
        int back = 0;
        
        cin >> stick[0] >> stick[1] >> stick[2] >> stick[3];
        for(int i = 0; i < 4; i++){
            if(stick[i] == 0) front++;
            else back++;
        }
        if(front == 0) cout << "E" << '\n';
        else if(front == 1) cout << "A" << '\n';
        else if(front == 2) cout << "B" << '\n';
        else if(front == 3) cout << "C" << '\n';
        else if(front == 4) cout << "D" << '\n';
    }
    
    
    
    return 0;
}
