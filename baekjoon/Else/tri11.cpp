//
//  tri11.cpp
//  test
//
//  Created by 신기열 on 04/06/2019.
//  Copyright © 2019 신기열. All rights reserved.
//
#include <stdio.h>
#include <iostream>

using namespace std;

char triarr[10000][10000];

void tri(int n, int x, int y){
    if(n == 3){
        triarr[y][x] = '*';
        triarr[y + 1][x - 1] = '*';
        triarr[y + 1][x + 1] = '*';
        triarr[y + 2][x - 2] = '*';
        triarr[y + 2][x - 1] = '*';
        triarr[y + 2][x] = '*';
        triarr[y + 2][x + 1] = '*';
        triarr[y + 2][x + 2] = '*';
        
        return;
    }
    
    tri(n / 2, x, y);
    tri(n / 2, x - (n / 2), y + (n / 2));
    tri(n / 2, x + (n / 2), y + (n / 2));
}

int main(){
    
    int n;
    cin >> n;
    
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= 2 * n; j++){
            if(j == 2 * n) triarr[i][j] = '\0';
            else triarr[i][j] = ' ';
        }
    }
    
    tri(n, n, 1);
    
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= 2 * n - 1; j++){
            cout << triarr[i][j];
        }
        cout << '\n';
    }
    
    return 0;
}
