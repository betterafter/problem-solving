//
//  GoUpStair.cpp
//  test
//
//  Created by 신기열 on 22/03/2019.
//  Copyright © 2019 신기열. All rights reserved.
//

#include <stdio.h>

int main(){
    
    int Num;
    int stair[301];
    int GetScore[301];
    
    scanf("%d", &Num);
    
    for(int i = 1; i <= Num; i++){
        scanf("%d", &stair[i]);
    }
    
    int n = 4;
    
    GetScore[1] = stair[1];
    GetScore[2] = stair[2] + stair[1];
    
    if(stair[1] < stair[2]){
        GetScore[3] = stair[2] + stair[3];
    }
    else if(stair[1] >= stair[2]){
        GetScore[3] = stair[1] + stair[3];
    }

    while(n <= Num){
        
        if(GetScore[n-2] <= stair[n-1] + GetScore[n-3]){
            
            GetScore[n] = stair[n] + stair[n-1] + GetScore[n-3];
        }
        
        else if(GetScore[n-2] > stair[n-1] + GetScore[n-3]){
            
            GetScore[n] = stair[n] + GetScore[n-2];
        }
        n++;
    }
    
    
    
    printf("%d", GetScore[Num]);
    
    return 0;
}
