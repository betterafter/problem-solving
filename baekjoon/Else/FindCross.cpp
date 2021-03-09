//
//  FindCross.cpp
//  test
//
//  Created by 신기열 on 18/06/2019.
//  Copyright © 2019 신기열. All rights reserved.
//
#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main(){

    int n, m, cnt = 0, ansx[10001] = { 0, }, ansy[10001] = { 0, }, anssize[10001] = { 0, }, include[110][110] = { 0, }, flag = 0;
    char arr[110][110];
    cin >> n >> m;

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin >> arr[i][j];
        }
    }

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){

            if(i-1 >= 1 && i+1 <= n && j-1 >= 1 && j+1 <= m){
                if(arr[i][j] == '*' && arr[i-1][j] == '*' && arr[i+1][j] == '*' && arr[i][j-1] == '*' && arr[i][j+1] == '*'){

                    int size = 1;
                    include[i][j] = 1; include[i-1][j] = 1; include[i+1][j] = 1; include[i][j-1] = 1; include[i][j+1] = 1;

                    while(i-size >= 1 && i+size <= n && j-size >= 1 && j+size <= m){

                        if(arr[i-size][j] == '*' && arr[i+size][j] == '*' && arr[i][j-size] == '*' && arr[i][j+size] == '*'){
                            include[i-size][j] = 1; include[i+size][j] = 1; include[i][j-size] = 1; include[i][j+size] = 1;

                            size++;
                        }
                        else break;
                    }
                    
                    ansx[cnt] = i; ansy[cnt] = j; anssize[cnt] = size - 1;
                    cnt++;
                }
            }
        }
    }

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(arr[i][j] == '*' && include[i][j] == 0){ cnt = -1; break; }
        }
    }

    if(cnt == -1 || cnt == 0) cout << -1;

    else{
        cout << cnt << '\n';
        for(int i = 0; i < cnt; i++){
            cout << ansx[i] << " " << ansy[i] << " " << anssize[i] << '\n';
        }
    }

    return 0;
}

//////////////////////////////////////////////////////////////////////////////////////////
////////////////////////// 개인적으로 역대 최고로 힘들었던 문제.....................
// 문제를 잘 이해해야했다. 모든 십자가를 구하는게 아니라 좌표에 있는 십자가들 중에 아무거나 뽑아서 입력으로 주어진 좌표를 만들 수 있는가의 문제였다.
// 즉 대충 각 중심마다 만들 수 있는 가장 큰 십자가를 하나씩 출력해줘도 되는 거였다.
// 그리고 n * m 이하의 개수를 가진다고 했으니 그냥 각 중심이 가질 수 있는 가장 큰 십자가들만 쫙 출력해줘도 가능한 문제였다.

