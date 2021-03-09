//
//  17281.cpp
//  BJ
//
//  Created by 신기열 on 11/11/2019.
//  Copyright © 2019 신기열. All rights reserved.
//

#include <stdio.h>
#include <iostream>

using namespace std;

int n;
int inning[50][10];
int order[10];
int visited[10];
int answer;


int calc(int order[10]){

    // turn은 이닝이 바뀌어도 순서는 유지해야 되므로 그걸 위한 변수이다. 따라서 이닝 밖에 선언해준다.
    int ans = 0; int turn = 1;
    
    // 모든 이닝을 돌면서
    for(int i = 0; i < n; i++){
        // 이닝이 바뀔 때마다 out, 야구장은 초기화 된다. 또한 out이 될 때 선수가 다 로테이션되기 전에 종료 되므로 turn을 다음 순서로 정해준다.
        int out = 0; int map[4] = { 0, }; int tturn = turn;
        
        // 3 아웃이 될 때까지 계속한다.
        while(out < 3){
            // 선수 9명에 대해 탐색한다.
            for(int j = tturn; j <= 9; j++){

                // 현재 이닝에 대해 현재 순서의 타자가 1 안타인 경우
                if(inning[i][order[j]] == 1){
                    // 3루에 사람이 있다면 홈으로 가고 1점 추가
                    if(map[3] == 1){
                        ans++; map[3] = 0;
                    }
                    // 2루는 3루로
                    if(map[2] == 1){
                        map[2] = 0; map[3] = 1;
                    }
                    // 1루는 2루로
                    if(map[1] == 1){
                        map[1] = 0; map[2] = 1;
                    }
                    // 타자는 1루로
                    map[1] = 1;
                }
                // 2 안타인 경우
                else if(inning[i][order[j]] == 2){
                    // 3루는 홈으로 가고 1점 추가
                    if(map[3] == 1){
                        ans++; map[3] = 0;
                    }
                    // 2루는 홈으로 가고 1점 추가
                    if(map[2] == 1){
                        ans++; map[2] = 0;
                    }
                    // 1루는 3루로
                    if(map[1] == 1){
                        map[1] = 0; map[3] = 1;
                    }
                    // 타자는 2루로
                    map[2] = 1;
                }
                // 3 안타일 경우
                else if(inning[i][order[j]] == 3){
                    // 3루는 홈으로 가고 1점 추기
                    if(map[3] == 1){
                        ans++; map[3] = 0;
                    }
                    // 2루는 홈으로 가고 1점 추가
                    if(map[2] == 1){
                        ans++ ;map[2] = 0;
                    }
                    // 1루는 홈으로 가고 1점 추가
                    if(map[1] == 1){
                        ans++; map[1] = 0;
                    }
                    //타자는 3루로
                    map[3] = 1;
                }
                // 홈런이면
                else if(inning[i][order[j]] == 4){
                    // 전부 홈으로 가고 1점 추가
                    if(map[3] == 1){
                        ans++; map[3] = 0;
                    }
                    if(map[2] == 1){
                        ans++ ;map[2] = 0;
                    }
                    if(map[1] == 1){
                        ans++; map[1] = 0;
                    }
                    ans++;
                }
                // 아웃이면 1아웃 추가
                else if(inning[i][order[j]] == 0){
                    out++;
                }
                // 이닝 시작 시에 다음 순서 타자 ~ 마지막 타자까지 돌았는데, 그 후로부턴 다시 1번부터 9번까지 돌아야하므로 tturn (다음 타자를 의미) = 1로 바꿔준다.
                // 그리고 turn은 이닝이 바뀌어도 유지되는 순서이므로 다음 타자가 바뀔 때마다 1씩 오르며, 다음 타자가 9를 넘어가버리면 다시 1번 타자로 바꿔준다.
                tturn = 1; turn++;
                if(turn > 9) turn = 1;
                // 3아웃이면 이닝 끝
                if(out >= 3) break;
            }
        }
    }

    return answer = max(answer, ans);
}

// 1번은 무조건 4번 타자로 가면 되게끔 순서를 정해주면 된다.
void DFS(int idx, int order[10], int visited[10]){
    
    if(idx > 9){
        answer = max(answer, calc(order)); return;
    }
    
    for(int i = 1; i <= 9; i++){
        if(i == 1){
            order[4] = i; visited[i] = 1;
        }
        // 다음 타순이 4번이면 건너 뛰어서 5번에 넣어주고, 아니면 그냥 다음 타순에 넣어주면 된다.
        else if(visited[i] == 0){
            order[idx] = i; visited[i] = 1;
            if(idx + 1 == 4) DFS(idx + 2, order, visited);
            else DFS(idx + 1, order, visited);
            order[idx] = 0; visited[i] = 0;
        }
    }
    
}



int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        for(int j = 1; j <= 9; j++){
            cin >> inning[i][j];
        }
    }
    DFS(1, order, visited);
    
    cout << answer;
    return 0;
}
