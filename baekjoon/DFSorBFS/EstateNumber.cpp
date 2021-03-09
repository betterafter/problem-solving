//
//  EstateNumber.cpp
//  test
//
//  Created by 신기열 on 12/06/2019.
//  Copyright © 2019 신기열. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>
#include <math.h>
#include <iostream>

using namespace std;

vector<int> estate;
int home[26][26] = { 0, };
int dir[4][2] = { {0, 1}, {0, -1}, {1, 0}, {-1, 0} };
int N;

queue<pair<int, int> > q;

void BFS(){
    
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            
            if(home[i][j] == 1){
                
                estate.push_back(1);
                unsigned long num = estate.size() - 1;
                q.push(make_pair(i, j));
                home[i][j] = -1;
                
                while(!q.empty()){
                    int x = q.front().second, y = q.front().first;
                    q.pop();
                    
                    for(int i = 0; i < 4; i++){
                        int nx = x + dir[i][1], ny = y + dir[i][0];
                        if(nx > 0 && nx <= N && ny > 0 && ny <= N && home[ny][nx] == 1){
                            estate[num]++;
                            home[ny][nx] = -1;
                            q.push(make_pair(ny, nx));
                        }
                    }
                }
            }
        }
    }
}


int main(){
    
    string s[25];
    
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> s[i];
    }

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            home[i + 1][j + 1] = s[i][j] - 48;
        }
    }
    
    BFS();
    
    sort(estate.begin(), estate.end());
    
    cout << estate.size() << '\n';
    for(int i = 0; i < estate.size(); i++){
        cout << estate[i] << '\n';
    }
    
    return 0;
}
