//
//  10974.cpp
//  BJ
//
//  Created by 신기열 on 18/09/2019.
//  Copyright © 2019 신기열. All rights reserved.
//

#include <stdio.h>
#include <iostream>


using namespace std;

int N;
int per[9];
int visited[9];

void DFS(int num, int idx){
    
    per[idx] = num;
    
    if(idx == N){
        for(int i = 1; i <= N; i++){
            cout << per[i] << " ";
        }
        cout << '\n';
    }
    
    else{
        for(int i = 1; i <= N; i++){
            if(visited[i] == 0){
                
                visited[i] = 1;
                DFS(i, idx + 1);
                visited[i] = 0;
            }
        }
    }

}


int main(){
    
    cin >> N;
    for(int i = 1; i <= N; i++){
        if(visited[i] == 0){
            visited[i] = 1;
            DFS(i, 1);
            visited[i] = 0;
        }
    }
    
    
    
    
    return 0;
}
