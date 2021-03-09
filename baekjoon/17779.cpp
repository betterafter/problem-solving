//
//  17779.cpp
//  BJ
//
//  Created by 신기열 on 05/11/2019.
//  Copyright © 2019 신기열. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int n;
int map[21][21];
int tmap[21][21];
int sum[5];
int answer = 10000000;

void set(int x, int y, int d1, int d2){
    // tmap을 초기화하지 않으면 이전에 있던 지역구 5의 정보가 그대로 남아있게 되어 잘못된 결과가 나온다. 그냥 한번 돌 때 마다 초기화해도 시간 초과가 안나오는 걸 보면 경우의 수가 그렇게 많지는 않은
    // 것 같다. (따로 계산은 안해봐서 얼마나 걸리는지는 자세히 모르겠다.)
    memset(tmap, 0, sizeof(tmap));
    // 1 ~ 5 지역구의 인구 수도 다시 초기화해준다. 안해주면 중첩된다.
    for(int i = 0; i < 5; i++){
        sum[i] = 0;
    }
    // tmap에 5 지역구의 경계선에 해당하는 좌표에 5를 채워준다.
    for(int i = 0; i <= d1; i++){
        tmap[x + i][y - i] = 5;
        tmap[x + d2 + i][y + d2 - i] = 5;
    }
    for(int i = 0; i <= d2; i++){
        tmap[x + i][y + i] = 5;
        tmap[x + d1 + i][y - d1 + i] = 5;
    }

    // tmap에 5지역구의 경계선 안쪽에 해당하는 좌표에 5를 채워준다. 지역구 사각형의 위쪽과 아랫쪽 꼭짓점을 다 빼고 왼쪽의 2개의 변을 따라 열을 쭉 돌면서 5가 나올 때 까지 (이웃한 변에 닿을 때 까지)
    // 5로 채워준다. 가령 아래와 같은 도형에서 (2, 2), (2, 3), (2, 4) 좌표만 열을 따라 이동하면서 0인 부분을 채워주면 되겠다.
    //    1 2 3 4 5 6
    //
    //1        5                           5                                 5                                        5
    //2      5 0 5                       5 5 5                             5 5 5                                    5 5 5
    //3    5 0 0 0 5        ->         5 0 0 0 5             ->          5 5 5 5 5               ->               5 5 5 5 5
    //4      5 0 5                       5 0 5                             5 0 5                                    5 5 5
    //5        5                           5                                 5                                        5
    
    // 이 때 (2, 3) 기준으로 위쪽 변과 아랫쪽 변으로 나눠서 탐색해야하므로 y ~ y + d2 와 y ~ y - d1 2가지 경우로 나눠서 각각 탐색해주면 되겠다.
    for(int i = 0; i < d2; i++){
        int t = 1;
        while(tmap[x + i + t][y + i] != 5){
            tmap[x + i + t][y + i] = 5; t++;
        }
    }
   
    for(int i = 0; i < d1; i++){
        int t = 1;
        while(tmap[x + i + t][y - i] != 5){
            tmap[x + i + t][y - i] = 5; t++;
        }
    }
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    
    // 인구 수를 계산하기 위한 이중 for문이다.
    for(int xx = 1; xx <= n; xx++){
        for(int yy = 1; yy <= n; yy++){
            
            // tmap에 이미 5가 있으면 그냥 바로 sum[4] (5번째 인덱스)에 더해준다.
            if(tmap[yy][xx] == 5) sum[4] = sum[4] + map[yy][xx];
            // tmap에 5가 없으면 문제에서 명시한대로 1 ~ 4 지역구를 구분해준다. 이 때 tmap의 각 좌표에 지역구 번호를 넣어서 다시 탐색할 필요 없이 그 좌표가 몇번 지역구인지 알았으면 바로
            // sum에 인구 수 연산을 해주면 된다. tmap을 업데이트 한 이유는 출력에서 확인해보려고 그냥 넣어봤다.
            else{
                if(yy >= 1 && yy < x + d1 && xx >= 1 && xx <= y) {sum[0] = sum[0] + map[yy][xx]; tmap[yy][xx] = 1;}
                else if(yy >= 1 && yy <= x + d2 && xx > y && xx <= n) {sum[1] = sum[1] + map[yy][xx]; tmap[yy][xx] = 2;}
                else if(yy >= x + d1 && yy <= n && xx >= 1 && xx < y - d1 + d2) {sum[2] = sum[2] + map[yy][xx]; tmap[yy][xx] = 3;}
                else if(yy > x + d2 && yy <= n && xx >= y - d1 + d2 && xx <= n) {sum[3] = sum[3] + map[yy][xx]; tmap[yy][xx] = 4;}
            }
        }
    }
//    cout << "x : " << x << " y : " << y << " d1 : " << d1 << " d2 : " << d2 << '\n';
//    for(int j = 1; j <= n; j++){
//        for(int i = 1; i <=n; i++){
//            cout << tmap[j][i] << " ";
//        }
//        cout << '\n';
//    }
    // sum 배열을 오름차순 정렬해서 마지막 인덱스 (최대 인구수) - 처음 인덱스 (최소 인구수)를 빼줄 수 있도록 한다.
    sort(sum, sum + 5);
    //cout << sum[4] - sum[0] << '\n';
    
    // 인구 수가 가장 적은 것을 answer로 만들어주자.
    answer = min(answer, sum[4] - sum[0]);
}

// 5번 지역구를 만들기 위한 함수
void div(){
    for(int x = 1; x <= n; x++){
        for(int y = 1; y <= n; y++){
            // 모든 좌표 평면에 대하여 d1과 d2를 쭉 따라 만들었을 때, 만든 사각형의 꼭짓점이 모두 좌표평면 안에 들어있는지 확인해주면 된다. 좌표평면 밖으로 나가면 다음 케이스를 돌리고,
            // 좌표평면 내에 있으면 set함수를 돌려서 인구수 차를 구해준다.
            int d1 = 1;
            while(x + d1 <= n && y - d1 > 0){
                int d2 = 1;
                while(x + d2 <= n && y + d2 <= n){
                    if(x + d1 + d2 > n || y - d1 + d2 > n || x + d2 + d1 > n || y + d2 - d1 <= 0) break;
                    set(x, y, d1, d2);
                    d2++;
                }
                d1++;
            }
        }
    }
}


                  

int main(){
    
    cin >> n;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin >> map[i][j];
        }
    }
    div();
    cout << answer;
    return 0;
}
