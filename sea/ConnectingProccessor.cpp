//
//  ConnectingProccessor.cpp
//  SEA
//
//  Created by 신기열 on 02/06/2019.
//  Copyright © 2019 신기열. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <vector>
#include <utility>

using namespace std;

vector<pair<int, int> > v;
int N, cell[13][13];
int dir_x[4] = { 1, 0, -1, 0 };
int dir_y[4] = { 0, 1, 0, -1 };

int DFS(int core, int core_num, int circuit_length){
    
    for(int i = 0; i < 4; i++){
        int flag = 0;
        int curr_x = v[core].second + dir_x[i];
        int curr_y = v[core].first + dir_y[i];
        
        while(1){
            if(cell[curr_y][curr_x] == 0){
                curr_x = curr_x + dir_x[i];
                curr_y = curr_y + dir_y[i];
            }
            else break;
            
            if(curr_x == 0 || curr_x == N || curr_y == 0 || curr_y == N){
                flag = 1;
                break;
            }
        }
        
        if(flag == 1){
            
        }
        
        
    }
    
    
    
    
}


int main(){
    
    int T;
    cin >> T;
    
    for(int test = 0; test < T; test++){
        
        cin >> N;
        
        for(int i = 1; i <= N; i++){
            for(int j = 1; j <= N; j++){
                cin >> cell[i][j];
            }
        }
        
        for(int i = 2; i <= N; i++){
            for(int j = 2; j <= N; j++){
                if(cell[i][j] == 1){
                    v.push_back(make_pair(i, j));
                }
            }
        }
        
        DFS(0, 0, 0);
        
        
        
        
    }
    
    
    
    
    
    
    return 0;
}
