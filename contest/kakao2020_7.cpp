//
//  kakao2020_7.cpp
//  Contest
//
//  Created by 신기열 on 10/10/2019.
//  Copyright © 2019 신기열. All rights reserved.
//

#include <stdio.h>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>

using namespace std;

// 로봇의 2개의 부위를 저장하기 위한 구조체
struct node {
    int x;
    int y;
    struct node* p;
};


int dir[4][2] = { {0,1}, {1,0}, {-1,0}, {0,-1} };               // 로봇의 평행이동
int rvertical[4][2] = { {1,1}, {1,-1}, {-1,1}, {-1,-1} };       // 수평 상태의 로봇의 회전이동
int rhorizontal[4][2] = { {1,1}, {-1,1}, {1,-1}, {-1,-1} };     // 수직 상태의 로봇의 회전이동
int n;
int answer = 99999999;
vector<vector<vector<int> > > dirvisited;                       // 현재 상태 로봇이 해당 좌표에서 같은 모양을 한 적이 있는지 체크
// dirvisited는 조금 복잡한데, 좌표평면 상의 특정 점을 기준으로 각각 길이가 4인 벡터를 가지고 있는데, 그 중 index가 0이면 현재 좌표에 노드가 있고 그 위에
// 노드가 하나 있었던 적이 있는 것을 의미하며, 1이면 현재 + 왼쪽 모양으로, 2면 현재 + 아래 모양으로, 3이면 현재 + 오른쪽이다. 그림으로 표현하면 이런 모양이다.
//
//        ( 1 )
// ( 0 ) (node) ( 3 )
//        ( 2 )
//

void BFS(vector<vector<int> > &board){
    // 로봇의 상대적 작은 부위와 큰 부위의 노드. 귀찮으니까 큰애, 작은애라고 명명한다.
    node left, right;
    // 작은애는 (1,1), 큰애는(2,1) 고정
    left.x = 1; left.y = 1; right.x = 2; right.y = 1;
    queue<pair<pair<node, node>, int> > q;
    
    q.push(make_pair(make_pair(left, right), 0));
    
    while(!q.empty()){
        node l, r;
        int t;
        l = q.front().first.first;
        r = q.front().first.second;
        t = q.front().second;
        q.pop();
        // 큰애 또는 작은애가 (n,n) 위치에 들어가기만 하면 끝. 최소 이동을 찾아서 작업을 계속 진행해준다.
        if((l.x == n && l.y == n) || (r.x == n && r.y == n)){
            answer = min(answer, t);
            continue;
        }
        // 로봇이 움직이는 경우는 상, 하, 좌, 우의 4가지 수평이동과 작은애 기준 시계, 반시계의 2가지 회전이동, 큰애 기준 시계, 반시계의 2가지 회전이동이다.
        
        // 이 for문은 수평이동에 대한 4가지 방향 탐색이다
        for(int i = 0; i < 4; i++){
            int x = dir[i][0];
            int y = dir[i][1];
            // 큰애의 x와 작은애의 x가 같지 않고 y는 같은 경우 = 수평상태일 경우
            if(l.x != r.x && l.y == r.y){
                // 1 ~ n 범위 사이에 있으며 && 작은애 기준으로 오른쪽에 큰애가 있던 적이 없으며 && 움직이려는 방향으로 벽이 없는 경우
                // 참고로 작은애 기준으로 오른쪽애 큰애가 없다는 얘기는 큰애 기준으로 왼쪽에 작은애가 없었다는 얘기가 된다. 따라서 굳이 2가지를 구할필요가
                // 없다. 필요충분조건이니까.
                if((l.x + x >= 1 && l.x + x <= n && r.x + x >= 1 && r.x + x <= n && l.y + y >= 1 && l.y + y <= n && r.y + y >= 1 && r.y + y <= n) && dirvisited[l.y + y][l.x + x][3] == 0 && board[l.y + y][l.x + x] == 0 && board[r.y + y][r.x + x] == 0){
                    node tmp1, tmp2;
                    // 움직인 상태를 현재상태로 갱신하고 방문상태도 갱신하고 q에 넣어준다
                    tmp1.x = l.x + x; tmp1.y = l.y + y; tmp2.x = r.x + x; tmp2.y = r.y + y;
                    dirvisited[l.y + y][l.x + x][3] = 1; dirvisited[r.y + y][r.x + x][1] = 1;
  
                    q.push(make_pair(make_pair(tmp1, tmp2), t + 1));
                }
            }
            // 수직상태일 경우
            else if(l.x == r.x && l.y != r.y){
                // 위와 똑같다. 방향만 위-아래가 된 케이스
                if((l.x + x >= 1 && l.x + x <= n && r.x + x >= 1 && r.x + x <= n && l.y + y >= 1 && l.y + y <= n && r.y + y >= 1 && r.y + y <= n) && dirvisited[l.y + y][l.x + x][2] == 0 && board[l.y + y][l.x + x] == 0 && board[r.y + y][r.x + x] == 0){
                    node tmp1, tmp2;
                    tmp1.x = l.x + x; tmp1.y = l.y + y; tmp2.x = r.x + x; tmp2.y = r.y + y;
                    dirvisited[l.y + y][l.x + x][2] = 1; dirvisited[r.y + y][r.x + x][0] = 1;

                    q.push(make_pair(make_pair(tmp1, tmp2), t + 1));
                }
            }
        }
        // 이번엔 회전이동에 대한 탐색이다.
        // 수평상태일 경우
        if(l.x != r.x && l.y == r.y){
            for(int i = 0; i < 4; i++){
                int rx = rvertical[i][0];
                int ry = rvertical[i][1];
                // 작은애가 도는 경우
                if(i < 2){
                    // i가 0, 1이라는 것은 작은애 기준 회전이라는 뜻. 0은 시계회전, 1은 반시계 회전
                    int direction;
                    if(i == 0) direction = 2; else direction = 0;
                    // 한 애가 1 ~ n 범위를 벗어나지 않으며 && 회전한 상태에 있던 적이 없으며 && 회전 방향과 회전 후 위치에 벽이 없다면
                    if((l.x + rx >= 1 && l.x + rx <= n && l.y + ry >= 1 && l.y + ry <= n) && (dirvisited[r.y][r.x][direction] == 0) && board[l.y + ry][l.x] == 0 && board[l.y + ry][l.x + rx] == 0){
                        // 회전시키고 상태 저장 후 q에 넣어준다
                        node tmp, tmp3;
                        tmp.x = l.x + rx; tmp.y = l.y + ry; tmp3 = r;
                        dirvisited[r.y][r.x][direction] = 1;

                        if(tmp.x > tmp3.x || tmp.y > tmp3.y) q.push(make_pair(make_pair(tmp3, tmp), t + 1));
                        else q.push(make_pair(make_pair(tmp, tmp3), t + 1));
                    }
                }
                // 큰애가 도는 경우
                else{
                    // 역시 마찬가지. 2은 시계회전, 3은 반시계회전. 이에 대한 설정은 rvertical과 rhorizontal에 설정을 해두었다.
                    int direction;
                    if(i == 2) direction = 2; else direction = 0;
                    // 이 역시 마찬가지. 큰애가 도는지 작은애가 도는지만 다를 뿐이다
                    if((r.x + rx >= 1 && r.x + rx <= n && r.y + ry >= 1 && r.y + ry <= n) && (dirvisited[l.y][l.x][direction] == 0 && board[r.y + ry][r.x] == 0 && board[r.y + ry][r.x + rx] == 0)){
                        node tmp, tmp3;
                        tmp.x = r.x + rx; tmp.y = r.y + ry; tmp3 = l;
                        dirvisited[l.y][l.x][direction] = 1;

                        if(tmp.x > tmp3.x || tmp.y > tmp3.y) q.push(make_pair(make_pair(tmp3, tmp), t + 1));
                        else q.push(make_pair(make_pair(tmp, tmp3), t + 1));
                    }
                }
            }
        }
        // 수직상태일 때
        else if(l.x == r.x && l.y != r.y){
            for(int i = 0; i < 4; i++){
                int rx = rhorizontal[i][0];
                int ry = rhorizontal[i][1];
                // 작은애가 도는 경우
                if(i < 2){
                    // 이 역시 수직상태라는 것만 감안하면 완전히 같은 코드이다. 더 이상 주석은 필요없을 듯 하다. 어차피 같은 알고리즘이라..
                    int direction;
                    if(i == 0) direction = 3; else direction = 1;
                    if((l.x + rx >= 1 && l.x + rx <= n && l.y + ry >= 1 && l.y + ry <= n) && (dirvisited[r.y][r.x][direction] == 0) && board[l.y][l.x + rx] == 0 && board[l.y + ry][l.x + rx] == 0){

                        node tmp, tmp3;
                        tmp.x = l.x + rx; tmp.y = l.y + ry; tmp3 = r;
                        dirvisited[r.y][r.x][direction] = 1;

                        if(tmp.x > tmp3.x || tmp.y > tmp3.y) q.push(make_pair(make_pair(tmp3, tmp), t + 1));
                        else q.push(make_pair(make_pair(tmp, tmp3), t + 1));
                    }
                }
                else{
                    int direction;
                    if(i == 0) direction = 3; else direction = 1;
                    if((r.x + rx >= 1 && r.x + rx <= n && r.y + ry >= 1 && r.y + ry <= n) && ((dirvisited[l.y][l.x][direction] == 0) && board[r.y][r.x + rx] == 0 && board[r.y + ry][r.x + rx] == 0)){
                        node tmp, tmp3;
                        tmp.x = r.x + rx; tmp.y = r.y + ry; tmp3 = l;
                        dirvisited[l.y][l.x][direction] = 1;

                        if(tmp.x > tmp3.x || tmp.y > tmp3.y) q.push(make_pair(make_pair(tmp3, tmp), t + 1));
                        else q.push(make_pair(make_pair(tmp, tmp3), t + 1));
                    }
                }
            }
        }
    }
}



int solution(vector<vector<int> > board) {

    n = (int)board.size();
    // 주의할 점이 board는 index가 0 ~ n - 1인데 문제는 좌표가 1 ~ n 이라는 점이다. (왜 이렇게 해놓은거지) 따라서 board를 확장해서 데이터를 옮겨주던가
    // 새로운 벡터를 짜서 데이터를 옮겨줄 필요가 있다.
    vector<vector<int> > temp;
    for(int i = 0; i <= n + 1; i++){
        vector<int> tmp(n + 1);
        temp.push_back(tmp);
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            temp[i][j] = board[i - 1][j - 1];
        }
    }
    // 이것은 dirvisted를 동적할당하기 위한 코드이다.
    for(int i = 0; i <= n + 1; i++){
        vector<vector<int> > temp2;
        for(int j = 0; j <= n + 1; j++){
            vector<int> temp3(4, 0);
            temp2.push_back(temp3);
        }
        dirvisited.push_back(temp2);
    }
    // BFS 돌려주면 끝
    BFS(temp);
    return answer;
}


int main(){

    vector<vector<int> > test;
    vector<int> tmp1;
    tmp1.push_back(0);
    tmp1.push_back(0);
    tmp1.push_back(0);
    tmp1.push_back(1);
    tmp1.push_back(1);

    vector<int> tmp2;
    tmp2.push_back(0);
    tmp2.push_back(0);
    tmp2.push_back(0);
    tmp2.push_back(1);
    tmp2.push_back(0);

    vector<int> tmp3;
    tmp3.push_back(0);
    tmp3.push_back(1);
    tmp3.push_back(0);
    tmp3.push_back(1);
    tmp3.push_back(1);

    vector<int> tmp4;
    tmp4.push_back(1);
    tmp4.push_back(1);
    tmp4.push_back(0);
    tmp4.push_back(0);
    tmp4.push_back(1);

    vector<int> tmp5;
    tmp5.push_back(0);
    tmp5.push_back(0);
    tmp5.push_back(0);
    tmp5.push_back(0);
    tmp5.push_back(0);

    test.push_back(tmp1);
    test.push_back(tmp2);
    test.push_back(tmp3);
    test.push_back(tmp4);
    test.push_back(tmp5);

    cout << solution(test);

    return 0;
}
