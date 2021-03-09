//
//  1018.cpp
//  BJ
//
//  Created by 신기열 on 20/09/2019.
//  Copyright © 2019 신기열. All rights reserved.
//

#include <stdio.h>
#include <iostream>

using namespace std;

int N, M;
int BlackCmp = 2500, WhiteCmp = 2500;

char board[51][51];
char WhiteStartBoard[51][51];
char BlackStartBoard[51][51];

int main(){
    
    string color[51];
    
    cin >> N >> M;
    for(int i = 0; i < N; i++){
        cin >> color[i];
    }
    
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            board[i][j] = color[i][j];
        }
    }
    
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            if((i + j) % 2 == 0){
                WhiteStartBoard[i][j] = 'W';
            }
            else{
                WhiteStartBoard[i][j] = 'B';
            }
        }
    }
    
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            if((i + j) % 2 == 0){
                BlackStartBoard[i][j] = 'B';
            }
            else{
                BlackStartBoard[i][j] = 'W';
            }
        }
    }
    
    
    
    
    for(int i = 0; i <= N - 8; i++){
        for(int j = 0; j <= M - 8; j++){
            int CurrWhite = 0;
            int CurrBlack = 0;
            
            for(int x = i; x < i + 8; x++){
                for(int y = j; y < j + 8; y++){
                    if(board[x][y] != WhiteStartBoard[x - i][y - j]){
                        CurrWhite++;
                    }
                    
                    if(board[x][y] != BlackStartBoard[x - i][y - j]){
                        CurrBlack++;
                    }
                }
            }
            //cout << CurrWhite << " " << CurrBlack << '\n';
            
            WhiteCmp = min(CurrWhite, WhiteCmp);
            BlackCmp = min(CurrBlack, BlackCmp);
            
            //cout << WhiteCmp << " " << BlackCmp << '\n';
        }
    }
    
    cout << min(WhiteCmp, BlackCmp);
    
    return 0;
}
