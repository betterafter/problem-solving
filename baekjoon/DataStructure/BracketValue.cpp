//
//  BracketValue.cpp
//  test
//
//  Created by 신기열 on 10/06/2019.
//  Copyright © 2019 신기열. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <stack>

using namespace std;

int main() {
    
    int ans = 0, mul = 1, flag = 0;
    string str;
    stack<char> s;
    cin >> str;
    
    if(str[0] == '('){
        mul = 2;
        s.push(str[0]);
    }
    else if(str[0] == '['){
        mul = 3;
        s.push(str[0]);
    }
    else flag = 1;
    
    if(flag == 0){
        for (int i = 1; i < str.size(); i++) {
            if(str[i] == '('){
                mul *= 2;
                s.push(str[i]);
            }
            else if(str[i] == '['){
                mul *= 3;
                s.push(str[i]);
            }
            else if(str[i] == ')'){
                if(str[i - 1] == '('){ ans += mul; }
                else if(str[i - 1] == '[' || s.empty() || s.top() != '('){ flag = 1; break; }
        
                s.pop();
                mul /= 2;
            }
            else if(str[i] == ']'){
                if(str[i - 1] == '['){ ans += mul; }
                else if(str[i - 1] == '(' || s.empty() || s.top() != '['){ flag = 1; break; }
                
                s.pop();
                mul /= 3;
            }
            if(i == str.size() - 1 && !s.empty()){
                flag = 1; break;
            }
        }
    }
    
    
    if(flag == 1){
        cout << 0;
    }
    else cout << ans;
    
    return 0;
}
