//
//  14500.cpp
//  BJ
//
//  Created by 신기열 on 22/10/2019.
//  Copyright © 2019 신기열. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

int n, m;
int map[500][500];
int answer = 0;

void calc(int x1, int y1, int x2, int y2, int x3, int y3){
    
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(i + y1 >= 0 && j + x1 >= 0 && i + y1 < n && j + x1 < m &&
               i + y2 >= 0 && j + x2 >= 0 && i + y2 < n && j + x2 < m &&
               i + y3 >= 0 && j + x3 >= 0 && i + y3 < n && j + x3 < m){
                
//                int test[500][500] = { 0, };
//                test[i][j] = map[i][j];
//                test[i + y1][j + x1] = map[i + y1][j + x1];
//                test[i + y2][j + x2] = map[i + y2][j + x2];
//                test[i + y3][j + x3] = map[i + y3][j + x3];
//                
//                for(int p = 0; p < n; p++){
//                    for(int q = 0; q < m; q++){
//                        cout << test[p][q] << " ";
//                    }
//                    cout << '\n';
//                }
//                cout << '\n';
                
                answer = max(answer, map[i][j] + map[i + y1][j + x1] + map[i + y2][j + x2] + map[i + y3][j + x3]);
            }
        }
    }
}


int main(){
    
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> map[i][j];
        }
    }
    
    vector<pair<int, int> > v;
    
    for(int i = 0; i < 15; i++){
        v.clear();
        if(i == 1){
            
        }
    }
    
    calc(1, 0, 2, 0, 3, 0);
    calc(0, 1, 0, 2, 0, 3);
    
    calc(1, 0, 0, 1, 1, 1);
    
    calc(0, 1, 0, 2, 1, 2);
    calc(0, 1, 0, 2, -1, 2);
    calc(0, 1, 1, 0, 2, 0);
    calc(1, 0, 2, 0, 2, 1);
    calc(1, 0, 1, 1, 1, 2);
    calc(1, 0, 0, 1, 0, 2);
    calc(0, 1, 1, 1, 2, 1);
    calc(1, 0, 2, 0, 2, -1);
    
    calc(0, 1, 1, 1, 1, 2);
    calc(0, 1, -1, 1, -1, 2);
    calc(1, 0, 1, 1, 2, 1);
    calc(1, 0, 1, -1, 2, -1);
    
    calc(1, 0, 2, 0, 1, 1);     // ㅜ
    calc(0, 1, 0, 2, 1, 1);     // ㅏ
    calc(0, 1, -1, 1, 1, 1);    // ㅗ
    calc(1, -1, 1, 0, 1, 1);    // ㅓ
    
    
    cout << answer;
    return 0;
}
