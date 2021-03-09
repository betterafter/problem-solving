//
//  KakaoCoding4.cpp
//  study
//
//  Created by 신기열 on 2019. 3. 21..
//  Copyright © 2019년 신기열. All rights reserved.
//

#include <stdio.h>
#include <math.h>
#include <stdlib.h>



int main(){
    
    int HP[250100];
    int Fin_Pos_X, Fin_Pos_Y, Start_Pos_X, Start_Pos_Y, Curr_Pos_X, Curr_Pos_Y;
    int Position[250100][2];
    int Distance[250100][2];
    
    int totalDistance;
    
    bool NeedBooster;
    
    int N, Q; // N = 체크포인트 수 , Q = 질문 수
    int Check = 0;
    
    scanf("%d %d", &N, &Q);
    
    for(int i = 0; i < N; i++){
        scanf("%d %d", &Position[i][0], &Position[i][1]); //체크포인트 i번 x, y 좌표
    }
    
    for(int i = 0; i < Q; i++){
        scanf("%d %d %d", &Distance[i][0], &Distance[i][1], &HP[i]);  //시작 체크포인트 & 도착 체크포인트
    }
    
    
    while(Check < Q){
        
        //Start_Pos_X = Position[Distance[Check][0]][0];
        //Start_Pos_Y = Position[Distance[Check][0]][1];
        
        Curr_Pos_X = Position[Distance[Check][0]][0];
        Curr_Pos_Y = Position[Distance[Check][0]][1];
        
        Fin_Pos_X = Position[Distance[Check][1]][0];
        Fin_Pos_Y = Position[Distance[Check][1]][1];
        
        int num = N;
        
        for(int i = 0; i < num; i++){
            
        }
        
        
        if(abs(Fin_Pos_X - Start_Pos_X) + abs(Fin_Pos_Y - Start_Pos_Y) > HP[Check]){
            
            NeedBooster = true;
        }
        
        else {
            NeedBooster = false;
        }
        
        if(NeedBooster == true){
            
        }
    }
    
    
    
    
    
    
    return 0;
}
