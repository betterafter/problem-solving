//
//  SWEA8741.cpp
//  SCPC
//
//  Created by 신기열 on 28/10/2019.
//  Copyright © 2019 신기열. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

int main(){
    
    int n;
    cin >> n;
    vector<string> s;
    string str;
    
    cin.ignore();
    for(int i = 0; i < n; i++){
        getline(cin, str);
        s.push_back(str);
    }
    
    for(int i = 0; i < n; i++){
        string ans;
        ans = ans + (char)(s[i][0] - 32);
        int j = 1;
        while(j < s[i].size()){
            if(s[i][j] == ' '){
                j++;
                ans = ans + (char)(s[i][j] - 32);
            }
            j++;
        }
        cout << "#" << i + 1 << " " << ans << '\n';
    }
    
    return 0;
}
