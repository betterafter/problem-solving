//
//  1159.cpp
//  BJ
//
//  Created by 신기열 on 20/09/2019.
//  Copyright © 2019 신기열. All rights reserved.
//

#include <stdio.h>
#include <iostream>

using namespace std;

int main(){
    
    int N, IsExist = 0;
    string name[151];
    char FirstName[26] = { 0, };
    
    cin >> N;
    
    for(int i = 0; i < N; i++){
        cin >> name[i];
    }
    
    for(int i = 0; i < N; i++){
        FirstName[name[i][0] - 97]++;
    }
    
    for(int i = 0; i < 26; i++){
        if(FirstName[i] >= 5){
            IsExist = 1;
            cout << (char)(i + 97);
        }
    }
    if(IsExist == 0) cout << "PREDAJA" << '\n';
    
    return 0;
}
