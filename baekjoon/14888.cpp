//
//  14888.cpp
//  BJ
//
//  Created by 신기열 on 24/10/2019.
//  Copyright © 2019 신기열. All rights reserved.
//

#include <stdio.h>
#include <iostream>

using namespace std;

int n;
int num[100];
int calc[4];
// 크기는 -10억 이상 10억 이하이므로 각각 초기화해준다. 단, max가 -10억이고 min이 10억이여야 크기 비교를 해줄 때 최솟값이 minans에,
// 최댓값이 maxans에 들어갈 것이다.
int minans = 1000000001;
int maxans = -1000000001;



void DFS(int calc[4], int res, int nidx){
    // 숫자의 개수가 n개 이므로 index가 n을 넘어가면 res와 크기 비교를 해주고 종료해준다.
    if(nidx >= n){
        minans = min(minans, res);
        maxans = max(maxans, res);
        return;
    }

    int tcalc[4];
    int tres = res;
    
    tcalc[0] = calc[0]; tcalc[1] = calc[1]; tcalc[2] = calc[2]; tcalc[3] = calc[3];
    
    for(int i = 0; i < 4; i++){
        // 더하기 일 때
        if(i == 0){
            // 더하기가 1개 이상 존재하면
            if(tcalc[i] > 0){

                //cout << tres << " + " << num[nidx] << " = " << tres + num[nidx] << '\n';

                // 맨 마지막에 구한 결과값 + 다음 index의 값
                tres = tres + num[nidx];
                // 더하기 연산자를 1개 빼준다.
                tcalc[i]--;

                DFS(tcalc, tres, nidx + 1);
            }
        }
        else if(i == 1){
            // 빼기가 1개 이상 존재하면
            if(tcalc[i] > 0){

                //cout << tres << " - " << num[nidx] << " = " << tres - num[nidx] << '\n';
                
                // 맨 마지막에 구한 결과값 - 다음 index의 값
                tres = tres - num[nidx];
                // 빼기 연산자를 1개 빼준다.
                tcalc[i]--;

                DFS(tcalc, tres, nidx + 1);
            }
        }
        else if(i == 2){
            // 곱하기가 1개 이상 존재하면
            if(tcalc[i] > 0){

                //cout << tres << " * " << num[nidx] << " = " << tres * num[nidx] << '\n';

                // 맨 마지막에 구한 결과값 * 다음 index의 값
                tres = tres * num[nidx];
                // 곱하기 연산자를 1개 빼준다.
                tcalc[i]--;

                DFS(tcalc, tres, nidx + 1);
            }
        }
        else if(i == 3){
            // 나누기가 1개 이상 존재하면
            if(tcalc[i] > 0){

                //cout << tres << " / " << num[nidx] << " = " << tres / num[nidx] << '\n';

                // 맨 마지막에 구한 결과값 / 다음 index의 값. 문제에서 나누기 연산은 정수 나누기 연산이라고 정의했으므로 int형 나누기를 한다.
                tres = tres / num[nidx];
                // 나누기 연산자를 1개 빼준다.
                tcalc[i]--;

                DFS(tcalc, tres, nidx + 1);
            }
        }
        // 초기화
        tcalc[0] = calc[0]; tcalc[1] = calc[1]; tcalc[2] = calc[2]; tcalc[3] = calc[3];
        tres = res;
    }
}



int main(){

    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> num[i];
    }

    for(int i = 0; i < 4; i++){
        cin >> calc[i];
    }

    DFS(calc, num[0], 1);

    cout << maxans << '\n' << minans;

    return 0;
}
