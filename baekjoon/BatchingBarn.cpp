//
//  BatchingBarn.cpp
//  test
//
//  Created by 신기열 on 14/04/2019.
//  Copyright © 2019 신기열. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <string.h>
#include <vector>


using namespace std;

int main(){

    int N, M, count = 2, cow = 0;
    vector<vector<int> > v;

    cin >> N >> M;
    int Barn[10000];

    v.resize(N);
    
    for(int i = 0; i < N; i++){

        int cnt;
        cin >> cnt;
        v[i].push_back(cnt);

        for(int j = 0; j < v[i][0]; j++){

            int barnNum;
            cin >> barnNum;

            v[i].push_back(barnNum);
            Barn[barnNum-1]++;
        }
    }
 
    for(int i = 0; i < M; i++){
        if(v[i][0] == 1){

            if(Barn[v[i][1] - 1] != 10000){
                Barn[v[i][1] - 1] = 10000;
                cow++;

            }
        }
    }

    // i번째 소가 들어가고자 하는 축사를 체크하면서 경우의 수 확인하기
    for(int i = 0; i < M; i++){

        for(int r = 0; r < M; r++){
            // count개의 축사를 들어가고 싶어하는 소
            if(v[r][0] == count){
                
                // 현재 소가 들어가고자 하는 축사를 null로 표현
                int temp = 1000;
                
                // "2: "1: count개의 축사를 들어가고 싶어하는" 소가 원하는 축사"가" 들어갈 수 있는 축사인지 확인
                for(int j = 1; j <= count; j++){
                    
                    // 그 축사에 들어가고자 하는 소가 가장 적을 경우를 찾음 + 비어있는 축사여야함.
                    if(Barn[v[r][j] - 1] <= temp && Barn[v[r][j] - 1] != 10000){
                        
                        // 임시 배정
                        temp = v[r][j] - 1;
                    }
                }
                
                if(temp != 1000){
                    Barn[temp] = 10000;
                    cow++;
                }
            }

        }
        count++;
    }

    cout << cow;

    return 0;

}
