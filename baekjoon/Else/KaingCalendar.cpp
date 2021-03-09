//
//  KaingCalendar.cpp
//  test
//
//  Created by 신기열 on 09/06/2019.
//  Copyright © 2019 신기열. All rights reserved.
//
#include <stdio.h>
#include <iostream>

using namespace std;


int main(){
    
    int T;
    cin >> T;
    
    for(int test = 0; test < T; test++){
        
        int M, N, x, y, cnt = 0, sum = 0;
        cin >> M >> N >> x >> y;
        
        
        if(M == N){
            if(x != y){ cnt = -1; }
            else{ cnt = x; }
        }
        
        else{
            int count = 0;
            
            // (x + M * count) % N 이 0이 나올 수도 있음.
            // x + M * count는 y의 상대적인 값을 나타냄. 가령 3 -> 13 -> 23 -> 33 -> ... 을 12로 나누면 3 -> 1 -> 11 -> 9 -> ...
            // 그런데 x + N * count가 N으로 나누어 떨어지게 되면 y랑 같아질 수 없게 됨. (y는 0보다 크니까)
            // 이상한 오차값들은 이 비교 과정에서 위의 식이 0이 되어 상대적인 y를 찾아주지 못해서 헤매는 경우임.
            // 따라서 y 또한 N으로 나눠준 나머지랑 비교해줘야함. 이 때가 y = N인 경우가 될 것임. (나눈 나머지가 0이라는 것이니까)
            // :: (x + M * count) % N != y % N
            while((x + M * count) % N != y % N){
                if((M * count + M) % N == 0){
                    sum = count * M + M;
                    break;
                }
                count++;
            }
            
            cnt = count * M + x;
            if (sum >= cnt) cnt = -1;
        }
        
        cout << cnt << '\n';
    }
    
    return 0;
}



//
//        long xcnt = 1, ycnt = 1;
//
//        while(xcnt != x || ycnt != y){
//            if(xcnt < M) xcnt++;
//            else xcnt = 1;
//
//            if(ycnt < N) ycnt++;
//            else ycnt = 1;
//
//            cnt++;
//
//            if(xcnt == M && ycnt == N){
//                cnt = -1;
//                break;
//            }
//        }
