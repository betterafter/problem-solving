//
//  KakaoCoding1.c
//  study
//
//  Created by 신기열 on 2019. 3. 19..
//  Copyright © 2019년 신기열. All rights reserved.
//

#include <stdio.h>
#include <string.h>

int chart(int first, int second){
    
    int GetFirstPrize = 0, GetSecondPrize = 0;
    
    if(first == 1){ GetFirstPrize = 5000000; }
    else if(first >= 2 && first <= 3){ GetFirstPrize = 3000000; }
    else if(first >= 4 && first <= 6){ GetFirstPrize = 2000000; }
    else if(first >= 7 && first <= 10){ GetFirstPrize = 500000; }
    else if(first >= 11 && first <= 15){ GetFirstPrize = 300000; }
    else if(first >= 16 && first <= 21){ GetFirstPrize = 100000; }
    else { GetFirstPrize = 0; }
    
    if(second == 1){ GetSecondPrize = 5120000; }
    else if(second >= 2 && second <= 3){ GetSecondPrize = 2560000; }
    else if(second >= 4 && second <= 7){ GetSecondPrize = 1280000; }
    else if(second >= 8 && second <= 15){ GetSecondPrize = 640000; }
    else if(second >= 16 && second <= 31){ GetSecondPrize = 320000; }
    else { GetSecondPrize = 0; }
 
    return GetFirstPrize + GetSecondPrize;
}


int main(){
    
    int predict;
    int Buffer[1000][2];
    
    scanf("%d", &predict);
    
    for(int i = 0; i < predict; i++){
        scanf("%d %d", &Buffer[i][0], &Buffer[i][1]);
    }
    
    for(int i = 0; i < predict; i++){
        printf("%d\n", chart(Buffer[i][0], Buffer[i][1]));
    }
    
    return 0;
}
