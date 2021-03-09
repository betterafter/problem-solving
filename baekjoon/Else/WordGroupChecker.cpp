//
//  SimpleTest2.cpp
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
    
    int T, ans = 0;
    cin >> T;
    
    for(int test = 0; test < T; test++){
        
        int isUsed[130] = { 0, }, alpha[130] = { 0, }, flag = 0;
        string s;
        cin >> s;
        
        
        for(int i = 0; i < s.size(); i++){
            int idx = s[i];
            alpha[idx]++;
        }
        
        for(int i = 0; i < s.size() - 1; i++){
            
            //            cout << s[i] << s[i+1] << '\n';
            //            cout << isUsed[s[i]] << alpha[s[i]] << '\n';
            
            if(s[i] == s[i + 1]){
                int idx = s[i];
                isUsed[idx]++;
            }
        }
        
        for(int i = 97; i <= 122; i++){
            
            //cout << isUsed[i] << " " << alpha[i] << '\n';
            
            if(alpha[i] - isUsed[i] != 1 && alpha[i] != 0){
                
                flag = 1;
            }
        }
        if(flag == 0){
            ans++;
        }
        //cout << '\n';
    }
    
    cout << ans;
    return 0;
}
