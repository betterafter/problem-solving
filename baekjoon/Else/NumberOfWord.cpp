//
//  NumberOfWord.cpp
//  test
//
//  Created by 신기열 on 03/06/2019.
//  Copyright © 2019 신기열. All rights reserved.
//
#include <stdio.h>
#include <iostream>
#include <string.h>

using namespace std;



int main(){
    
    int cnt = 0;
    string s;
    getline(cin, s);
    
    
    for(int i = 0; i < s.size(); i++){
        if(s[i] == ' '){
            cnt++;
        }
    }
    
    if(s[0] == ' '){
        cnt--;
    }
    if(s[s.size() - 1] == ' '){
        cnt--;
    }
    
    
    
    cout << cnt + 1;
    return 0;
}
