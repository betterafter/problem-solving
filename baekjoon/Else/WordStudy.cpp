//
//  WordStudy.cpp
//  test
//
//  Created by 신기열 on 31/05/2019.
//  Copyright © 2019 신기열. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <string.h>
#include <algorithm>

using namespace std;

int main(){
    
    int alpha[130] = { 0, }, m = 0, cnt = 0;
    int c = 0;
    
    string s;
    cin >> s;
    
    for(int i = 0; i < s.size(); i++){
        s[i] = toupper(s[i]);
        alpha[s[i] - 48 + 48]++;
    }
    
    for(int i = 65; i <= 90; i++){
        
        if(m == alpha[i] && alpha[i] != 0){
            cnt++;
        }
        
        if(m < alpha[i]){
            c = i;
            cnt = 1;
        }
        m = max(m, alpha[i]);
    }
    
    if(cnt > 1){
        cout << "?";
    }
    else{
        cout << (char) c;
    }
    //    cout << (char)(c + '0');
    return 0;
}

