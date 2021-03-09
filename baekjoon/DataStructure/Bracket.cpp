//
//  Bracket.cpp
//  test
//
//  Created by 신기열 on 10/06/2019.
//  Copyright © 2019 신기열. All rights reserved.
//

#include <stdio.h>
#include <stack>
#include <iostream>

using namespace std;

int main(){
    
    int T;
    cin >> T;
    
    for(int test = 0; test < T; test++){
        
        int flag = 0;
        stack<char> s;
        string str;
        cin >> str;
        
        for(int i = 0; i < str.size(); i++){
            
            if(str[i] == '('){
                s.push('(');
            }
            else if(str[i] == ')'){
                if(!s.empty() && s.top() == '('){
                    s.pop();
                }
                else if(s.empty()){
                    flag = 1;
                    break;
                }
            }
            
            // i가 str의 마지막일 때까지 전부 검사해줬고 for문 탈출할 때인데 스택이 비어있지 않은 경우도 고려해줘야함.
            if(i == str.size() - 1 && !s.empty()){
                flag = 1;
                break;
            }
        }
        
        if(flag == 0){
            cout << "YES" << '\n';
        }
        else if(flag == 1){
            cout << "NO" << '\n';
        }
        
    }
    
    
    
    return 0;
}
