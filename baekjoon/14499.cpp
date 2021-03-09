//
//  14499.cpp
//  BJ
//
//  Created by 신기열 on 22/10/2019.
//  Copyright © 2019 신기열. All rights reserved.
//

#include <stdio.h>
#include <iostream>

using namespace std;

int N, M, x, y, order;
int map[21][21];
int dir[1000];

// 주사위 클래스
class dice{
    public :
    // up : 윗면, down : 바닥면, left : 왼쪽면, right : 오른쪽면, front : 정면, back : 후면
    int up;
    int down;
    int left;
    int right;
    int front;
    int back;
    
    // 서쪽으로 굴릴 때
    void west(){
        int tup, tdown, tleft, tright;
        tup = up; tdown = down; tleft = left; tright = right;
        // 윗면이 오른쪽면을, 바닥면이 왼쪽면을, 왼쪽면이 윗면을, 오른쪽면이 바닥면을 향하게 된다. 직접 주사위를 굴려서 확인해보자.
        up = tright; down = tleft; left = tup; right = tdown;
    }
    // 동쪽으로 굴릴 때
    void east(){
        int tup, tdown, tleft, tright;
        tup = up; tdown = down; tleft = left; tright = right;
        up = tleft; down = tright; left = tdown; right = tup;
    }
    // 북쪽으로 굴릴 때
    void north(){
        int tup, tdown, tfront, tback;
        tup = up; tdown = down; tfront = front; tback = back;
        up = tfront; down = tback; front = tdown; back = tup;
    }
    // 남쪽으로 굴릴 때
    void south(){
        int tup, tdown, tfront, tback;
        tup = up; tdown = down; tfront = front; tback = back;
        back = tdown; down = tfront; front = tup; up = tback;
    }
};

// 주사위가 바닥면에 있는 글씨로 찍히거나, 맵이 주사위에 있는 숫자로 찍힌다.
void print(int map[][21], dice *d, int x, int y){
    // 맵에 0이 적혀 있을 때,
    if(map[y][x] == 0){
        // 현재 좌표에 주사위의 바닥면에 적힌 숫자가 찍힌다
        map[y][x] = d -> down;
    }
    // 맵에 0이 아닌 숫자가 적혀 있으면,
    else if(map[y][x] != 0){
        // 주사위에 어떤 숫자가 있건 맵에 있는 숫자로 업데이트 되고 맵은 0으로 바뀐다.
        d -> down = map[y][x];
        map[y][x] = 0;
    }
}

int main(){
    
    cin >> N >> M >> y >> x >> order;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin >> map[i][j];
        }
    }
    
    for(int i = 0; i < order; i++){
        cin >> dir[i];
    }
    
    // 주사위 객체 하나 만들어주기
    dice *d = new dice();
    // 문제에서 주사위의 숫자는 전부 0으로 초기화되어 있다고 나온다.
    d -> up = 0; d-> down = 0; d -> left = 0; d -> right = 0; d -> front = 0; d -> back = 0;
    
    for(int i = 0; i < order; i++){
        
//        cout << "  " << d -> back << '\n';
//        cout << d -> left << " " << d -> down << " " << d -> right << '\n';
//        cout << "  " << d -> front << '\n';
//        cout << "  " << d -> up << '\n';
//        cout << '\n';
        // 1 = east
        if(dir[i] == 1){
            if(x + 1 >= 0 && x + 1 < M){
                // 주사위를 동쪽으로 굴리고 주사위의 좌표도 이동시켜주고 숫자를 찍어준다.
                d -> east();
                x++;
                print(map, d, x, y);
                // 그 후 가장 윗면에 있는 숫자를 출력해준다. 밑에도 다 똑같이 하면 된다.
                cout << d -> up << '\n';
            }
        }
        // 2 = west
        else if(dir[i] == 2){
            if(x - 1 >= 0 && x - 1 < M){
                d -> west();
                x--;
                print(map, d, x, y);
                
                cout << d -> up << '\n';
            }
        }
        // 3 = north
        else if(dir[i] == 3){
            if(y - 1 >= 0 && y - 1 < N){
                d -> north();
                y--;
                print(map, d, x, y);
                
                cout << d -> up << '\n';
             }
        }
        // 4 = south
        else if(dir[i] == 4){
            if(y + 1 >= 0 && y + 1 < N){
                d -> south();
                y++;
                print(map, d, x, y);
                
                cout << d -> up << '\n';
            }
        }
        
    }
    
    
    return 0;
}
