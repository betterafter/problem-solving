//
//  KakaoCoding2.cpp
//  study
//
//  Created by 신기열 on 2019. 3. 19..
//  Copyright © 2019년 신기열. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <math.h>

using namespace std;

int main(){
    
    int DollNum, SelectDollNum;
    int Buffer[510];
    double Average = 0.0;
    double StandardDeviation = 0.0;
    double result = 1000000.0;
    
    scanf("%d %d", &DollNum, &SelectDollNum);
    
    if(SelectDollNum == 0 || DollNum == 0){
        printf("wrong number");
    }
    
    else{
        for(int i = 0; i < DollNum; i++){
            scanf("%d", &Buffer[i]);
        }
        
        //sort(Buffer, Buffer + DollNum);
        
        for(int i = 0; i < DollNum - SelectDollNum + 1; i++){
            
            double j = SelectDollNum;
            
            while(i + j < DollNum + 1)
            {
                StandardDeviation = 0.0;
                
                Average = 0;
                
                for(int k = 0; k < j; k++){
                    Average += Buffer[i + k];
                }

                Average = Average / j;

                for(int k = 0; k < j; k++){
                    StandardDeviation += pow(Buffer[i + k] - Average, 2);
                }
                StandardDeviation = StandardDeviation / j;
                StandardDeviation = sqrt(StandardDeviation);

                if(result >= StandardDeviation){
                    result = StandardDeviation;
                }
                j++;
            }
        }
        
        printf("%f", result);

        }
    return 0;
}
