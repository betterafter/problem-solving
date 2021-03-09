//
//  kakao2020_5.cpp
//  Contest
//
//  Created by 신기열 on 07/10/2019.
//  Copyright © 2019 신기열. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int poll[102][102];
int plat[102][102];
int build[102][102];

// 문제에서 x, y, 기둥 또는 보 순서대로 오름차순 정렬을 하라고 했다. vector를 문제에서 요구한대로 오름차순 정렬하기 위한 compare 함수
bool compare(vector<int> &a, vector<int> &b){
    if(a[0] != b[0]) return a[0] < b[0];
    else if(a[0] == b[0] && a[1] != b[1]) return a[1] < b[1];
    else return a[2] < b[2];
}

// 보 또는 기둥이 존재할 수 있는지 체크하는 함수
bool isBuilt(int x, int y,  int type){
    
    // 기둥일 경우
    if(type == 0){
        // 바닥에 설치 하거나 || 아래에 기둥이 존재하거나 ((y - 1)이므로 y >= 1이어야한다) || 밑에 오른쪽으로 뻗은 보가 있거나 || 밑에 왼쪽으로 뻗은
        // 보가 있으면 true, 없으면 false
        if(y == 0 || (y >= 1 && poll[y - 1][x] == 1) || plat[y][x] == 1 || (x >= 1 && plat[y][x - 1] == 1)){
            return true;
        }
        else return false;
    }
    // 보일 경우
    else{
        // 왼쪽 모서리에 기둥이 받치고 있거나 || 오른쪽 아래에 기둥이 받치고 있거나 || 양 옆에 보가 있으면 true, 없으면 false
        if((y >= 1 && (poll[y - 1][x] == 1 || poll[y - 1][x + 1] == 1)) || (x >= 1 && plat[y][x - 1] == 1 && plat[y][x + 1] == 1)){
            return true;
        }
        else return false;
    }
}



vector<vector<int> > solution(int n, vector<vector<int> > build_frame) {
    vector<vector<int> > answer;
    
    // 전체 맵 배열에 기둥, 보가 하나도 없는 상태로 초기화. build 배열은 따로 답을 내기 위한 임시 저장 배열. build가 1이면 기둥만 있는 경우, 2이면 보만
    // 있는 경우, 3이면 둘 다 있는 경우이다.
    for(int i = 0; i <= 101; i++){
        for(int j = 0; j <= 101; j++){
            build[i][j] = 0;
            poll[i][j] = 0;
            plat[i][j] = 0;
        }
    }
    
    for(int i = 0; i < build_frame.size(); i++){
        
        int x = build_frame[i][0];
        int y = build_frame[i][1];
        int type = build_frame[i][2];
        int isBuild = build_frame[i][3];
        // 생성일 경우
        if(isBuild == 1){
            // 생성하고자 하는 오브젝트가 기둥일 경우
            if(type == 0){
                //기둥이 존재할 수 있는 위치이면
                if(isBuilt(x, y, type)){
                    // 기둥이므로 1증가
                    build[y][x] += 1;
                    // 해당 위치의 기둥 배열에 기둥이 존재하게 되므로 1로 만들어줌
                    poll[y][x] = 1;
                }
            }
            // 생성하고자 하는 오브젝트가 보일 경우
            else if(type == 1){
                // 똑같은 처리를 해준다.
                if(isBuilt(x, y, type)){
                    // 보이므로 2 증가
                    build[y][x] += 2;
                    plat[y][x] = 1;
                }
            }
        }
        // 삭제일 경우
        else if(isBuild == 0){
            // 삭제하고자 하는 오브젝트가 기둥일 경우
            if(type == 0){
                // 일단 기둥을 지울 수 있다고 가정하자
                poll[y][x] = 0;
                // 기둥을 지웠는데 만약 바로 위에 다른 기둥이 있으며, 이 기둥이 존재할 수 있지 않으면,
                if(poll[y + 1][x] == 1 && !isBuilt(x, y + 1, 0)){
                    // 다시 기둥을 냅두고 삭제를 못하니까 그냥 작업을 무시한다.
                    poll[y][x] = 1;
                }
                // 위에 왼쪽으로 뻗은 보가 있고 이 보가 존재할 수 없다면,
                else if(x >= 1 && plat[y + 1][x - 1] == 1 && !isBuilt(x - 1, y + 1, 1)){
                    // 역시 다시 되돌림
                    poll[y][x] = 1;
                }
                // 위에 오른쪽으로 뻗은 보가 있는 경우
                else if(plat[y + 1][x] == 1 && !isBuilt(x, y + 1, 1)){
                    poll[y][x] = 1;
                }
                // 위의 케이스에 해당되지 않으면 지울 수 있다. 기둥이므로 -1 해주자.
                else build[y][x] -= 1;
            }
            // 삭제하고자 하는 오브젝트가 보일 경우
            else if(type == 1){
                // 역시 일단 보를 지울 수 있다고 가정하자
                plat[y][x] = 0;
                // 왼쪽 모서리 위에 기둥이 있을 경우
                if(poll[y][x] == 1 && !isBuilt(x, y, 0)){
                    plat[y][x] = 1;
                }
                // 오른쪽 모서리에 기둥이 있을 경우
                else if(poll[y][x + 1] == 1 && !isBuilt(x + 1, y, 0)){
                    plat[y][x] = 1;
                }
                // 왼쪽에 보가 있을 경우
                else if(x >= 1 && plat[y][x - 1] == 1 && !isBuilt(x - 1, y, 1)){
                    plat[y][x] = 1;
                }
                // 오른쪽에 보가 있을 경우
                else if(plat[y][x + 1] == 1 && !isBuilt(x + 1, y, 1)){
                    plat[y][x] = 1;
                }
                // 해당하지 않으면 삭제. 보이므로 -2 해주자.
                else build[y][x] -= 2;
            }
        }
    }

    // answer에 넣는 과정
    for(int y = 0; y <= n; y++){
        for(int x = 0; x <= n; x++){
            //build가 0이 아닌, 즉 보든 기둥이든 뭐가 존재할 경우
            if(build[y][x] != 0){
                // 기둥만 있을 경우 현재 answer의 현재 좌표에 (x, y, 0)을 넣어주자
                if(build[y][x] == 1){
                    vector<int> tmp;
                    tmp.push_back(x);
                    tmp.push_back(y);
                    tmp.push_back(0);
                    answer.push_back(tmp);
                }
                // 보만 있을 경우 현재 answer의 현재 좌표에 (x, y, 1)을 넣어주자
                else if(build[y][x] == 2){
                    vector<int> tmp;
                    tmp.push_back(x);
                    tmp.push_back(y);
                    tmp.push_back(1);
                    answer.push_back(tmp);
                }
                // 기둥, 보 둘 다 있을 경우 현재 answer의 현재 좌표에 (x, y, 0)와 (x, y, 1)을 넣어주자
                else if(build[y][x] == 3){
                    vector<int> tmp;
                    tmp.push_back(x);
                    tmp.push_back(y);
                    tmp.push_back(0);
                    answer.push_back(tmp);
                    
                    vector<int> tmp2;
                    tmp2.push_back(x);
                    tmp2.push_back(y);
                    tmp2.push_back(1);
                    answer.push_back(tmp2);
                }
            }
        }
    }
    // 오름차순 정렬
    sort(answer.begin(), answer.end(), compare);
    
    return answer;
}
//
//int main(){
//
//    vector<vector<int> > test;
//    vector<int> tmp;
//    tmp.push_back(1);
//    tmp.push_back(0);
//    tmp.push_back(0);
//    tmp.push_back(1);
//    test.push_back(tmp);
//
//    vector<int> tmp2;
//    tmp2.push_back(1);
//    tmp2.push_back(1);
//    tmp2.push_back(1);
//    tmp2.push_back(1);
//    test.push_back(tmp2);
//
//    vector<int> tmp3;
//    tmp3.push_back(2);
//    tmp3.push_back(1);
//    tmp3.push_back(0);
//    tmp3.push_back(1);
//    test.push_back(tmp3);
//
//    vector<int> tmp4;
//    tmp4.push_back(2);
//    tmp4.push_back(2);
//    tmp4.push_back(1);
//    tmp4.push_back(1);
//    test.push_back(tmp4);
//
//    vector<int> tmp5;
//    tmp5.push_back(5);
//    tmp5.push_back(0);
//    tmp5.push_back(0);
//    tmp5.push_back(1);
//    test.push_back(tmp5);
//
//    vector<int> tmp6;
//    tmp6.push_back(5);
//    tmp6.push_back(1);
//    tmp6.push_back(0);
//    tmp6.push_back(1);
//    test.push_back(tmp6);
//
//    vector<int> tmp7;
//    tmp7.push_back(4);
//    tmp7.push_back(2);
//    tmp7.push_back(1);
//    tmp7.push_back(1);
//    test.push_back(tmp7);
//
//    vector<int> tmp8;
//    tmp8.push_back(3);
//    tmp8.push_back(2);
//    tmp8.push_back(1);
//    tmp8.push_back(1);
//    test.push_back(tmp8);
//
//    //solution(5, test);
//
//    vector<vector<int> > test2;
//    vector<int> temp;
//    temp.push_back(0);
//    temp.push_back(0);
//    temp.push_back(0);
//    temp.push_back(1);
//
//    vector<int> temp2;
//    temp2.push_back(0);
//    temp2.push_back(1);
//    temp2.push_back(0);
//    temp2.push_back(1);
//
//    vector<int> temp3;
//    temp3.push_back(0);
//    temp3.push_back(1);
//    temp3.push_back(1);
//    temp3.push_back(1);
//
//    vector<int> temp4;
//    temp4.push_back(0);
//    temp4.push_back(1);
//    temp4.push_back(1);
//    temp4.push_back(0);
//
//    test2.push_back(temp);
//    test2.push_back(temp2);
//    test2.push_back(temp3);
//    //test2.push_back(temp4);
//
//    //solution(10, test2);
//
//    for(int i = 0; i < solution(5, test2).size(); i++){
//        cout << solution(5, test2)[i][0] << " " << solution(5, test2)[i][1] << " " << solution(5, test2)[i][2] << '\n';
//    }
//
//    return 0;
//}
