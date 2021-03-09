//
//  Turret.cpp
//  test
//
//  Created by 신기열 on 22/03/2019.
//  Copyright © 2019 신기열. All rights reserved.
//

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main(){
    
    int T, t = 0;
    int Jo[10000][2], Baek[10000][2];
    int distance[10000][2];
    int count[10000];
    
    scanf("%d", &T);
    
    for(int i = 0; i < T; i++){
        scanf("%d %d %d %d %d %d", &Jo[i][0], &Jo[i][1], &distance[i][0], &Baek[i][0],
              &Baek[i][1], &distance[i][1]);
    }
    
    while(t < T)
    {
        double pos_x1 = Jo[t][0];
        double pos_y1 = Jo[t][1];
        
        double pos_x2 = Baek[t][0];
        double pos_y2 = Baek[t][1];
        
        double dist1 = distance[t][0];
        double dist2 = distance[t][1];
        
        double Team_dist = sqrt(pow(pos_x1 - pos_x2, 2) + pow(pos_y1 - pos_y2, 2));

        if(Team_dist < dist1 + dist2 && Team_dist > abs(dist1 - dist2)){
            count[t] = 2;
        }
        //원점이 밖에 있고 1점에서 만남 || 원점이 안에 있고 1점에서 만남
        else if(Team_dist == dist1 + dist2 || (Team_dist == abs(dist1 - dist2) && Team_dist != 0)){
            count[t] = 1;
        }
        //원점이 밖에 있고 만나지 않음 || 원점이 안에 있고 만나지 않음
        else if(Team_dist > dist1 + dist2 || Team_dist < abs(dist1 - dist2)){
            count[t] = 0;
        }
        
        else if(Team_dist == 0){
            if(dist1 != dist2){
                count[t] = 0;
            }
            else if(dist1 == dist2){
                count[t] = -1;
            }
        }
        
        t++;
    }
    
    for(int i = 0; i < T; i++){
        printf("%d\n", count[i]);
    }
    
    return 0;
}
