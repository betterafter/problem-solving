//
//  3190.cpp
//  BJ
//
//  Created by 신기열 on 21/10/2019.
//  Copyright © 2019 신기열. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

// 뱀 클래스
class snake{
    public :
    int x;
    int y;
    int dir;
};

// n : 배열의 크기, a : 사과 수, L : 회전 수, t : 시간
int n, a, L, t = 1;
int apple[101][101];
bool isGameOver = false;

// 뱀 벡터. 뱀의 다음 몸통을 클래스에서 포인터로 지정해도 되지만, 그냥 벡터에 다 집어넣어서 뱀의 형태를 저장하게 했다.
vector<snake*> s;

// 벽에 부딪히거나, 몸통에 부딪히면 게임오버
void GameOver(){
    int hx = s[0] -> x;
    int hy = s[0] -> y;
    // 좌표 상을 벗어난다면 = 벽에 부딪힌다면
    if(hx < 1 || hx > n || hy < 1 || hy > n){
        isGameOver = true;
    }
    else{
        // 뱀 벡터 안의 특정 원소와 좌표가 같다면 = 특정 몸통 부분에 부딪힌다면
        for(int i = 1; i < s.size(); i++){
            int tx = s[i] -> x;
            int ty = s[i] -> y;
            if(hx == tx && hy == ty){
                isGameOver = true;
            }
        }
    }
}

// 사과 먹기 함수
void eat(){
    // 일단 현재 꼬리의 좌표를 구해준다.
    int hx = s[s.size() - 1] -> x;
    int hy = s[s.size() - 1] -> y;
    int hdir = s[s.size() - 1] -> dir;
    
    // 사과는 머리가 먹는 것이므로, 머리가 사과가 있는 좌표에 있다면
    if(apple[s[0] -> y][s[0] -> x] == 1){
        // 몸통이 하나 추가된다. 추가 된 몸통은 꼬리 뒤에 붙는다.
        // 일단 몸통을 꼬리 좌표랑 동일하게 놓고, 꼬리가 움직이고 있는 방향 반대편으로 추가된 몸통을 움직여준다.
        snake *body = new snake;
        body -> x = hx;
        body -> y = hy;
        body -> dir = hdir;
        s.push_back(body);
        // up으로 갈 때 꼬리는 down으로 움직여준다.
        if(hdir == 0){
            body -> y++;
        }
        // down으로 갈 때 꼬리는 up으로 움직여준다.
        else if(hdir == 1){
            body -> y--;
        }
        // left로 갈 때 꼬리는 right로 움직여준다.
        else if(hdir == 2){
            body -> x++;
        }
        // right로 갈 때 꼬리는 left로 움직여준다.
        else if(hdir == 3){
            body -> x--;
        }
        // 사과는 먹었으므로 없애준다.
        apple[s[0] -> y][s[0] -> x] = 0;
    }
}

int main(){
    
    // q는 회전 연산을 저장하기 위한 공간
    queue<pair<int, char> > q;
    // 머리만 하나 만들어준다.
    snake *head = new snake;
    
    /////////// 입력 /////////////
    cin >> n;
    cin >> a;
    for(int i = 0; i < a; i++){
        int N, M;
        cin >> N >> M;
        apple[N][M] = 1;
    }
    cin >> L;
    for(int i = 0; i < L; i++){
        int x; char c;
        cin >> x >> c;
        q.push(make_pair(x, c));
    }
    ////////////////////////////
    
    // 머리는 1, 1에 있고, 오른쪽으로 움직이려고 한다.
    head -> x = 1;
    head -> y = 1;
    head -> dir = 3;
    s.push_back(head);
    
    // 현재상태는 시작 전이므로 일단 0으로 초기화
    t = 0;
    while(1){
        // 움직이니까 1초 증가한다.
        t++;
        int tmx = 0, tmy = 0, tmpdir = 0;
        // move 연산이다.
        for(int i = 0; i < s.size(); i++){
            // i = 0일 때, 즉 머리일 때는 현재 좌표를 저장하고 방향에 따라 움직여준다.
            if(i == 0){
                tmx = s[i] -> x;
                tmy = s[i] -> y;
                tmpdir = s[i] -> dir;
                
                if(s[i] -> dir == 0){
                    s[i] -> y--;
                }
                else if(s[i] -> dir == 1){
                    s[i] -> y++;
                }
                else if(s[i] -> dir == 2){
                    s[i] -> x--;
                }
                else if(s[i] -> dir == 3){
                    s[i] -> x++;
                }
                // 이 게임에서 머리만 움직이고 몸통에 부딪히는지 파악해서 게임오버 여부를 판단하는 알고리즘이므로, 머리를 움직이고
                // 몸통에 부딪히는지 파악해준다.
                GameOver();
                if(isGameOver){ cout << t; return 0; }
            }
            
            // 머리가 아닌 경우
            else if(i != 0){
                // 일단 현재 몸통의 좌표를 저장해준다.
                int tmx2 = s[i] -> x;
                int tmy2 = s[i] -> y;
                int tmpdir2 = s[i] -> dir;
                // 현재 몸통의 좌표를 이 몸통 앞의 이전 좌표로 움직여준다.
                s[i] -> x = tmx;
                s[i] -> y = tmy;
                s[i] -> dir = tmpdir;
                // 현재 몸통의 업데이트 전 좌표를 저장해준다. (이 몸통의 뒤에 따라붙는 몸통이 이 좌표로 와야하므로)
                tmx = tmx2;
                tmy = tmy2;
                tmpdir = tmpdir2;
            }
        }
        // 사과 먹기
        eat();

        // 여기까지 움직이고 먹는 연산이 다 끝난다. 이 연산이 끝난 후, 방향 전환을 해야되면 방향 전환을 해준다.
        if(t == q.front().first){
            // 왼쪽 회전이면
            if(q.front().second == 'L'){
                // 위로 향할 때의 왼쪽은 왼쪽이다.
                if(s[0] -> dir == 0){
                    s[0] -> dir = 2;
                }
                // 아래로 향할 때의 왼쪽은 오른쪽이다.
                else if(s[0] -> dir == 1){
                    s[0] -> dir = 3;
                }
                // 왼쪽으로 향할 때의 왼쪽은 아래쪽이다.
                else if(s[0] -> dir == 2){
                    s[0] -> dir = 1;
                }
                // 오른쪽으로 향할 때의 왼쪽은 위쪽이다.
                else if(s[0] -> dir == 3){
                    s[0] -> dir = 0;
                }
            }
            // 이건 이해가 잘 안되면 그림으로 그려서 뱀이 특정 방향으로 갈 때의 왼쪽과 오른쪽을 각각 확인해보자.
            else if(q.front().second == 'D'){
                if(s[0] -> dir == 0){
                    s[0] -> dir = 3;
                }
                else if(s[0] -> dir == 1){
                    s[0] -> dir = 2;
                }
                else if(s[0] -> dir == 2){
                    s[0] -> dir = 0;
                }
                else if(s[0] -> dir == 3){
                    s[0] -> dir = 1;
                }
            }
            // 현재 회전 연산은 끝냈으므로 빼내준다.
            q.pop();
        }
        GameOver();
        if(isGameOver){ cout << t; return 0; }

//        cout << "T : " << t << '\n';
//        int test[101][101] = { 0, };
//        for(int i = 0; i < s.size(); i++){
//            int tx = s[i] -> x;
//            int ty = s[i] -> y;
//            test[ty][tx] = 1;
//        }
//        for(int i = 1; i <= n; i++){
//            for(int j = 1; j <= n; j++){
//                cout << test[i][j];
//            }
//            cout << '\n';
//        }
//        cout << '\n';
//
    }
    
    return 0;
}


