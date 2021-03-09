//
//  kakao2020_6.cpp
//  Contest
//
//  Created by 신기열 on 08/10/2019.
//  Copyright © 2019 신기열. All rights reserved.
//

#include <stdio.h>
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int isWorked[15];
int isCovered[15];
int answer = 9;

// 문제가 어려웠던 것 치곤 상당히 짧다. 일단 DFS로 완전 탐색하면 해결할 수 있다.
int DFS(int human, vector<int> &weak, vector<int> &dist){
    // work가 끝났는지 파악하기 위한 변수
    bool WorkEnd = true;
    
    for(int i = 0; i < weak.size(); i++){
        if(isCovered[i] == 0){
            // 모든 취약 지점이 cover 되지 않았으면 false
            WorkEnd = false;
        }
    }
    // 작업이 끝났고 human이 0보다 크면, (처음 상태에 workend가 true이므로 0일 때도 끝나버릴 수 있다) 최소 인원을 구하자
    if(WorkEnd && human > 0) return answer = min(answer, human);
    // 취약지점 cover가 다 안끝났는데 사람이 다 투입 되었으면 이건 못끝내는 일이다. -1을 return하도록 하자
    else if(!WorkEnd && human > 8) return -1;
    for(int i = 0; i < dist.size(); i++){
        // 현재 사람이 투입 되지 않았으면,
        if(isWorked[i] == 0){
            for(int j = 0; j < weak.size(); j++){
                // 현재 취약 지점이 cover가 안됐으면,
                if(isCovered[j] == 0){
                    int t = 0;
                    // 현재 체크하고 있는 취약지점부터 현재 투입한 사람이 cover할 수 있는 취약지점까지를 구해준다
                    while(j + t < weak.size() && weak[j] + dist[i] >= weak[j + t]){
                        isCovered[j + t] = 1;
                        t++;
                    }
                    break;
                    
                    
                }
            }
            // DFS, 재귀함수로 만들었으므로 일단 현재 먼저 투입된 사람을 작업 중으로 만들어놓고
            isWorked[i] = 1;
            // DFS를 돌린다
            DFS(human + 1, weak, dist);
            // 그리고 다시 이 사람을 작업 중이지 않은 상태로 만들고
            isWorked[i] = 0;
            // 취약지점들을 다시 non-cover 상태로 돌려놓은 다음
            for(int i = 0; i < 15; i++){
                isCovered[i] = 0;
            }
            // 0번 사람부터 일을 시작하는 경우 재귀, 1번 사람부터 일을 시작하는 경우 재귀, ... 이런 식으로 만들었다.
        }
    }
    return answer;
}


int solution(int n, vector<int> weak, vector<int> dist) {
    // 딱히 의미는 없지만 일단 역정렬 해놓았다. 작업량이 큰 사람부터 하는게 금방 끝날 것같아서.. 망한 코드랑도 연관이 있다.
    sort(dist.rbegin(), dist.rend());
    for(int i = 0; i < 15; i++){
        isWorked[i] = 0;
        isCovered[i] = 0;
    }
    // DFS를 돌린다.
    for(int i = 0; i < weak.size(); i++){
        DFS(0, weak, dist);
        // 벽이 원형 모양이기 때문에 시작 지점을 다르게 잡는게 중요한데, 가령 1 3 5 7 9 이라면 1번부터 시작하는 것이고, 그 다음 3 5 7 9 1+n 으로 3번부터
        // 시작하게 만들면서 1번은 3번을 기준으로 한바퀴 돈 위치에 있는 것이므로 벽의 총 길이 n을 더해준 것이다. 그래서 weak를 계속 갱신해준다.
        int start = weak[0] + n;
        for(int p = 1; p < weak.size(); p++){
            weak[p - 1] = weak[p];
        }
        weak[weak.size() - 1] = start;
    }

    if(answer > 8) answer = -1;
    return answer;
}

// 망한 코드. 역방향을 생각안해서 망함. 이렇게 하면 84% 까진 맞더라.
//int solution(int n, vector<int> weak, vector<int> dist) {
//    int answer = 9;
//    sort(dist.rbegin(), dist.rend());
//    for(int k = 0; k < weak.size(); k++){
//        int i = 0, j = 0;
//        // 필요한 인원 구하기
//        while(j < dist.size()){
//            if(weak[i] + dist[j] < weak[i + 1] || i == weak.size() - 1){
//                i++;
//            }
//            // 한 사람이 현재 취약지점과 그 다음 취약지점을 커버 가능할 때
//            else if(weak[i] + dist[j] >= weak[i + 1]){
//                int t = 0;
//                // 이 사람이 커버 가능한 구역 전부 구하기
//                while(i + 1 + t < weak.size() && weak[i] + dist[j] >= weak[i + 1 + t]){
//                    t++;
//                }
//                // 다음 취약지점 위치
//                i = i + 1 + t;
//            }
//
//            j++;
//            if(j >= dist.size() && i < weak.size()) break;
//            if(i >= weak.size()){
//                answer = min(answer, j);
//                break;
//            }
//        }
//        int start = weak[0] + n;
//        for(int p = 1; p < weak.size(); p++){
//            weak[p - 1] = weak[p];
//        }
//        weak[weak.size() - 1] = start;
//    }
//
//    if(answer > 8) answer = -1;
//    return answer;
//}



int main(){

    int n = 12;
    vector<int> weak;
    vector<int> dist;

//    weak.push_back(1);
//    weak.push_back(5);
//    weak.push_back(6);
//    weak.push_back(10);
//
//    dist.push_back(1);
//    dist.push_back(2);
//    dist.push_back(3);
//    dist.push_back(4);

    weak.push_back(1);
    weak.push_back(3);
    weak.push_back(4);
    weak.push_back(9);
    weak.push_back(10);

    dist.push_back(3);
    dist.push_back(5);
    dist.push_back(7);

    cout << solution(n, weak, dist);

    return 0;
}
