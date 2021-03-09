//
//  Teaching.cpp
//  test
//
//  Created by 신기열 on 14/06/2019.
//  Copyright © 2019 신기열. All rights reserved.
//
#include <stdio.h>
#include <iostream>
#include <vector>
#include <utility>
#include <math.h>
#include <cmath>
#include <algorithm>
#include <list>


using namespace std;

int N, K, ans = 0;
int used[26] = { 0, };
string word[50];

void DFS(int last, int cnt){
    
    if(cnt == K){
        
        int curr = 0;
        for(int i = 0; i < N; i++){
            int flag = 0;
            for(int j = 0; j < word[i].size(); j++){
                if(used[word[i][j] - 97] == 0){
                    flag = 1; break;
                }
            }
            if(flag == 0) curr++;
        }
        ans = max(ans, curr);
    }
    
    else if(cnt != K){
        for(int i = last; i < 26; i++){
            if(used[i] == 0){
                used[i] = 1;
                DFS(i, cnt + 1);
                
                used[i] = 0;
            }
        }
    }
    
}

int main(){
    
    cin >> N >> K;

    
    if(K < 5) ans = 0;
    else if(K == 26) ans = N;
    else{
        K -= 5;
        
        for(int i = 0; i < N; i++){
            cin >> word[i];
        }
        used[0] = 1; used[2] = 1; used[8] = 1; used[13] = 1; used[19] = 1;
        DFS(0, 0);
    }
    cout << ans;
    return 0;
}

