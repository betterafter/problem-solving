//
//  14890.cpp
//  BJ
//
//  Created by 신기열 on 25/10/2019.
//  Copyright © 2019 신기열. All rights reserved.
//

#include <stdio.h>
#include <iostream>

using namespace std;

int map[101][101];
int answer;
int visited[101];
int n, L;

int main(){

    cin >> n >> L;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> map[i][j];
        }
    }
    answer = n * 2;
    // 모든 행에 대하여
    for(int i = 0; i < n; i++){
        //cout << i << "행   :   ";
        int flag = 0;
        // 가로 한줄 쭉 훑어볼 떄
        int j = 1;
        for(int i = 0; i < n; i++){
            visited[i] = 0;
        }
        while(j < n){
            //cout << j << "번째 탐색" << '\n';
            // 높이 : 탐색 기준 왼쪽
            int h = map[i][j - 1];
            // 높이가 같지 않다면
            if(map[i][j] != h){
                // 오른쪽이 왼쪽보다 1 높을 때
                if(map[i][j] == h + 1){
                    for(int k = 1; k <= L; k++){
                        if(j - k < 0 || j - k >= n || (j - k >= 0 && j - k < n && (map[i][j - k] != h || visited[j - k] == 1))){
                            answer--;
                            flag = 1;
                            break;
                        }
                    }
                    if(flag == 0){
                        for(int k = 1; k <= L; k++){
                            visited[j - k] = 1;
                        }
                        j++;
                    }
                }
                // 오른쪽이 왼쪽보다 1 낮을 때
                else if(map[i][j] == h - 1){
                    int ch = map[i][j];
                    for(int k = 0; k < L; k++){
                        if(j + k < 0 || j + k >= n || (j + k >= 0 && j + k < n && (map[i][j + k] != ch || visited[j + k] == 1))){
                            answer--;
                            flag = 1;
                            break;
                        }
                    }
                    if(flag == 0){
                        for(int k = 0; k < L; k++){
                            visited[j + k] = 1;
                        }
                        j += L;
                    }
                }
                else{
                    answer--;
                    break;
                }
            }
            else j++;
            if(flag == 1){
                j++;
                //cout << "길이 아닙니다.   answer : " << answer <<  '\n';
                break;
            }
        }
    }

    // 모든 열에 대하여
    for(int i = 0; i < n; i++){
        
        //cout << i << "열  :  ";
        int flag = 0;
        // 가로 한줄 쭉 훑어볼 떄
        int j = 1;
        for(int i = 0; i < n; i++){
            visited[i] = 0;
        }
        while(j < n){
            //cout << j << "번째 탐색 : ";
            // 높이 : 탐색 기준 왼쪽
            int h = map[j - 1][i];
            // 높이가 같지 않다면
            if(map[j][i] != h){
                // 오른쪽이 왼쪽보다 1 높을 때
                if(map[j][i] == h + 1){
                    for(int k = 1; k <= L; k++){
                        if(j - k < 0 || j - k >= n || (j - k >= 0 && j - k < n && (map[j - k][i] != h || visited[j - k] == 1))){
                            answer--;
                            flag = 1;
                            break;
                        }
                    }
                    if(flag == 0){
                        for(int k = 1; k <= L; k++){
                            visited[j - k] = 1;
                        }
                        j++;
                    }
                }
                // 오른쪽이 왼쪽보다 1 낮을 때
                else if(map[j][i] == h - 1){
                    int ch = map[j][i];
                    for(int k = 0; k < L; k++){
                        if(j + k < 0 || j + k >= n || (j + k >= 0 && j + k < n && (map[j + k][i] != ch || visited[j + k] == 1))){
                            answer--;
                            flag = 1;
                            break;
                        }
                    }
                    if(flag == 0){
                        for(int k = 0; k < L; k++){
                            visited[j + k] = 1;
                        }
                        j += L;
                    }
                }
                else{
                    answer--;
                    break;
                }
            }
            else j++;

            if(flag == 1){
                j++;
                //cout << "길이 아닙니다.   answer : " << answer << '\n';
                break;
            }
        }
    }
    
    cout << answer;
    return 0;
}
