//
//  PrintOut10.cpp
//  test
//
//  Created by 신기열 on 31/05/2019.
//  Copyright © 2019 신기열. All rights reserved.
//
#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

int main(){
    
    string s;
    int i = 0, flag = 0;
    
    cin >> s;
    
    while(i < s.size()){
        
        string temp = "";
        
        for(int j = i; j < i + 10; j++){
            temp += s[j];
            if(j == s.size() - 1){
                flag = 1;
                break;
            }
        }
        cout << temp << '\n';
        if(flag == 1) break;
        i += 10;
    }
}
