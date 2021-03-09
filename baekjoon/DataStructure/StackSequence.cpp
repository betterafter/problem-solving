//
//  StackSequence.cpp
//  test
//
//  Created by 신기열 on 10/06/2019.
//  Copyright © 2019 신기열. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main(){
    
    stack<int> s;
    vector<int> ans;
    vector<char> op;
    int n, num[100001], curr, flag = 0;
    cin >> n;
    
    for(int i = 0; i < n; i++){
        cin >> num[i];
    }
    
    curr = 0;
    int t = 0;
    
    while(1){
        
        if(t == n) break;
        
        if(curr < num[t]){
            s.push(curr + 1);
            op.push_back('+');
            curr++;
        }
        else if(curr == num[t]){
            ans.push_back(s.top());
            op.push_back('-');
            s.pop();
            t++;
        }
        else if(curr > num[t]){
            if(s.top() == num[t]){
                ans.push_back(s.top());
                op.push_back('-');
                s.pop();
                t++;
            }
            else{
                flag = 1;
                break;
            }
        }
    }
    
    if(flag == 1){
        cout << "NO" << '\n';
    }
    else{
        for(int i = 0; i < op.size(); i++){
            cout << op[i] << '\n';
        }
    }
    
    return 0;
}
