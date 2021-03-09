
//
//  14891.cpp
//  BJ
//
//  Created by 신기열 on 26/10/2019.
//  Copyright © 2019 신기열. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <queue>

using namespace std;

// 12시부터 시계 방향 : 0 -> 12시, 2 -> 3시, 4 -> 6시, 6 -> 9시
int gear[5][8];
int order[101][2];
int k;

// 톱니바퀴를 회전시키는 함수. 임시 배열에 담아서 연산해주고 그걸 톱니바퀴 배열에 업데이트해주자.
void rotation(int num, int cgear[], int dir){
    
    int tmp[8];
    // 시계 방향일 때
    if(dir == 1){
        // 앞으로 한 칸씩 이동시켜주면 된다.
        for(int i = 0; i < 7; i++){
            tmp[i + 1] = cgear[i];
        }
        tmp[0] = cgear[7];
    }
    // 반시계 방향일 때
    else if(dir == -1){
        // 뒤로 한 칸씩 이동시켜주면 된다.
        for(int i = 1; i <= 7; i++){
            tmp[i - 1] = cgear[i];
        }
        tmp[7] = cgear[0];
    }
    
    for(int i = 0; i < 8; i++){
        gear[num][i] = tmp[i];
    }
}

void BFS(int cgear, int dir){
    
    // 1 ~ 4번이므로 배열을 5개로 설정해서 똑같이 넘버링 할 수 있게 만들었음.
    int visited[5] = { 0, };
    visited[cgear] = 1;
    
    queue<pair<int, int> > q;
    q.push(make_pair(cgear, dir));
    
    while(!q.empty()){
        int tgear = q.front().first;
        int tdir = q.front().second;
        q.pop();
        
        // 왼쪽 톱니바퀴 넘버가 1 ~ 4이고 && 왼쪽 톱니바퀴가 회전한 적이 없다면
        if(tgear - 1 >= 1 && tgear - 1 <= 4 && visited[tgear - 1] == 0){
            // 회전 준비 끝
            visited[tgear - 1] = 1;
            int ndir = 0;
            
            if(tdir == 1){
                // 다른 극인 상태에서 현재 톱니바퀴가 시계 방향 회전 했을 때 왼쪽 톱니바퀴가 회전하는가?
                // 이 때 현재 톱니바퀴는 이미 회전했다고 가정하고, 옆의 톱니바퀴는 아직 회전한 상태가 아니라고 가정하고 있으므로,
                // 왼쪽 톱니바퀴의 3시 방향과, 현재 톱니바퀴의 돌기 전의 9시 방향, 즉 gear[current_gear_number][7] (시계방향으로
                // 회전했으므로 회전 하기 전의 9시는 회전 한 후의 9시와 12시 사이에 있을 것이다. 이건 각각 회전한 방향과 왼쪽 혹은 오른쪽에 따라
                // 달라지게 되므로 각자 그려보면서 확인해보자.) 가 다른지 같은지 체크 해줘야 한다.
                if(gear[tgear][7] != gear[tgear - 1][2]){
                    // 현재 톱니바퀴가 시계 방향이므로 왼쪽 톱니바퀴는 반시계 방향이다.
                    ndir = -1;
                    int tmp[8];
                    for(int i = 0; i < 8; i++){
                        tmp[i] = gear[tgear - 1][i];
                    }
                    rotation(tgear - 1, tmp, ndir);
                    // 왼쪽 톱니바퀴는 회전했으므로 큐에 집어넣고 다시 체크 (만약 왼쪽 톱니바퀴가 회전하지 않았다면 그 왼쪽 톱니바퀴도 회전하지
                    // 않으므로 큐에 집어넣을 필요가 없다)
                    q.push(make_pair(tgear - 1, ndir));
                }
            }
            // 현재 톱니바퀴가 반시계 방향으로 돈 경우
            else if(tdir == -1){
                // 다른 극인 상태에서 현재 톱니바퀴가 반시계 방향 회전 했을 때 왼쪽 톱니바퀴가 회전하는가?
                if(gear[tgear][5] != gear[tgear - 1][2]){
                    // 왼쪽 톱니바퀴는 시계 방향으로 돌 것이다.
                    ndir = 1;
                    int tmp[8];
                    for(int i = 0; i < 8; i++){
                        tmp[i] = gear[tgear - 1][i];
                    }
                    rotation(tgear - 1, tmp, ndir);
                    // 왼쪽 톱니바퀴는 회전했으므로 큐에 집어넣고 다시 체크
                    q.push(make_pair(tgear - 1, ndir));
                }
            }
        }
        // 오른쪽 톱니바퀴가 1 ~ 4번 사이에 있으며 & 회전한 적이 없는 경우
        if(tgear + 1 >= 1 && tgear + 1 <= 4  && visited[tgear + 1] == 0){
            // 회전 준비 완료
            visited[tgear + 1] = 1;
            int ndir = 0;
            // 현재 톱니바퀴가 시계 방향으로 회전한 경우
            if(tdir == 1){
                // 다른 극인 상태에서 현재 톱니바퀴가 시계 방향 회전 했을 때 오른쪽 톱니바퀴가 회전하는가?
                if(gear[tgear][3] != gear[tgear + 1][6]){
                    // 오른쪽 톱니바퀴는 반시계 방향으로 회전할 것이다.
                    ndir = -1;
                    int tmp[8];
                    for(int i = 0; i < 8; i++){
                        tmp[i] = gear[tgear + 1][i];
                    }
                    rotation(tgear + 1, tmp, ndir);
                    // 오른쪽 톱니바퀴는 회전했으므로 큐에 집어넣고 다시 체크
                    q.push(make_pair(tgear + 1, ndir));
                }
            }
            // 현재 톱니바퀴가 반시계 방향으로 회전한 경우
            else if(tdir == -1){
                // 다른 극인 상태에서 현재 톱니바퀴가 반시계 방향 회전 했을 때 오른쪽 톱니바퀴가 회전하는가?
                if(gear[tgear][1] != gear[tgear + 1][6]){
                    // 오른쪽 톱니바퀴는 시계 방향으로 회전할 것이다.
                    ndir = 1;
                    int tmp[8];
                    for(int i = 0; i < 8; i++){
                        tmp[i] = gear[tgear + 1][i];
                    }
                    rotation(tgear + 1, tmp, ndir);
                    // 오른쪽 톱니바퀴는 회전했으므로 큐에 집어넣고 다시 체크
                    q.push(make_pair(tgear + 1, ndir));
                }
            }
        }
    }
}


int main(){
    
    for(int i = 1; i <= 4; i++){
        string s;
        cin >> s;
        for(int j = 0; j < s.size(); j++){
            gear[i][j] = s[j] - 48;
        }
    }
    
    cin >> k;
//    회전을 아예 안한 초기 상태의 톱니바퀴 배열 상태이다. 궁금하면 이것과 아래의 회전한 후의 톱니바퀴 상태를 표현한 출력을 주석처리 해제하고 출력해보자.
//    cout << "--------- init : " << 0 << "------------------" << '\n';
//    cout << ".." << gear[1][0] << "...." << gear[2][0] << "...." << gear[3][0] << "...." << gear[4][0] << ".." << '\n';
//    cout << "." << gear[1][7] << "." << gear[1][1] << "." << "." << gear[2][7] << "." << gear[2][1] << "." << "." << gear[3][7] << "." << gear[3][1] << "." << "." << gear[4][7] << "." << gear[4][1] << "." << '\n';
//    cout << gear[1][6] << "..." << gear[1][2] << gear[2][6] << "..." << gear[2][2] << gear[3][6] << "..." << gear[3][2] << gear[4][6] << "..." << gear[4][2] << '\n';
//    cout << "." << gear[1][5] << "." << gear[1][3] << "." << "." << gear[2][5] << "." << gear[2][3] << "." << "." << gear[3][5] << "." << gear[3][3] << "." << "." << gear[4][5] << "." << gear[4][3] << "." << '\n';
//    cout << ".." << gear[1][4] << ".." << ".." << gear[2][4] << ".." << ".." << gear[3][4] << ".." << ".." << gear[4][4] << ".." << '\n';
//    cout << '\n' << '\n';
    
    for(int i = 0; i < k; i++){
        cin >> order[i][0];
        cin >> order[i][1];
    }
    
    for(int i = 0; i < k; i++){
        int num = order[i][0];
        int dir = order[i][1];
        
        int tmp[8];
        for(int i = 0; i < 8; i++){
            tmp[i] = gear[num][i];
        }
        
        rotation(num, tmp, dir);
        BFS(num, dir);
   
        // 매 회전에 따른 톱니바퀴 배열 상태이다. 궁금하면 주석 해제하고 확인해보자.
//        cout << "--------- test : " << i + 1<< "------------------" << '\n';
//        cout << ".." << gear[1][0] << "...." << gear[2][0] << "...." << gear[3][0] << "...." << gear[4][0] << ".." << '\n';
//        cout << "." << gear[1][7] << "." << gear[1][1] << "." << "." << gear[2][7] << "." << gear[2][1] << "." << "." << gear[3][7] << "." << gear[3][1] << "." << "." << gear[4][7] << "." << gear[4][1] << "." << '\n';
//        cout << gear[1][6] << "..." << gear[1][2] << gear[2][6] << "..." << gear[2][2] << gear[3][6] << "..." << gear[3][2] << gear[4][6] << "..." << gear[4][2] << '\n';
//        cout << "." << gear[1][5] << "." << gear[1][3] << "." << "." << gear[2][5] << "." << gear[2][3] << "." << "." << gear[3][5] << "." << gear[3][3] << "." << "." << gear[4][5] << "." << gear[4][3] << "." << '\n';
//        cout << ".." << gear[1][4] << ".." << ".." << gear[2][4] << ".." << ".." << gear[3][4] << ".." << ".." << gear[4][4] << ".." << '\n';
//        cout << '\n' << '\n';
    }
    
    // 점수 환산 방식은 문제에 따라준다.
    int answer = 0;
    if(gear[1][0] == 0) answer += 0;
    else answer++;
    
    if(gear[2][0] == 0) answer += 0;
    else answer += 2;
    
    if(gear[3][0] == 0) answer += 0;
    else answer += 4;
    
    if(gear[4][0] == 0) answer += 0;
    else answer += 8;
    
    cout << answer;
    return 0;
}
