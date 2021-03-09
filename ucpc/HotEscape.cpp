//
//  HotEscape.cpp
//  UCPC
//
//  Created by 신기열 on 06/06/2019.
//  Copyright © 2019 신기열. All rights reserved.
//

#include <stdio.h>
#include <iostream>

using namespace std;

int hottime;
int hx, hy, relsx, relsy, relmx, relmy;
int pos[401][401] = { 0, };
int dir[4][2] = { {0,1}, {1,0}, {0,-1}, {-1,0} };
unsigned long long cnt = 0;

void DFS(int x, int y, int time){
    
    if(x == hx && y == hy && time >= 0){
        cnt++;
    }
    
    for(int i = 0; i < 4; i++){
        
        int nx = x + dir[i][1], ny = y + dir[i][0];
        int curr_time = time;
        
        if(nx >= 0 && ny >= 0 && nx <= 400 && ny <= 400){
            if(pos[ny][nx] != -1 && curr_time > 0){
                curr_time--;
                DFS(nx, ny, curr_time);
            }
        }
    }
}

int main(){
    
    int x, y, obs, movex = 0, movey = 0;
    cin >> x >> y;
    cin >> hottime;
    cin >> hx >> hy;
    cin >> obs;
    
    relmx = x + 200; relmy = y + 200; relsx = x - 200; relsy = y - 200;
    
    movex = 0 - relsx;
    movey = 0 - relsy;
    x += movex; y += movey;
    hx += movex; hy += movey;
    
    for(int i = 0; i < obs; i++){
        int X, Y;
        cin >> X >> Y;
        
        X += movex; Y += movey;
        if(Y <= 400 && Y >= 0 && X <= 400 && X >= 0){
            pos[Y][X] = -1;
        }
    }
    
    DFS(x, y, hottime);
    
    cout << cnt % 1000000007;
    return 0;
}
