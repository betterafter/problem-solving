//
//  SearchingMaze.cpp
//  test
//
//  Created by 신기열 on 01/06/2019.
//  Copyright © 2019 신기열. All rights reserved.
//

#include <stdio.h>
#include <queue>
#include <iostream>

using namespace std;

int dir[4][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };
int maze[101][101];
queue<pair<int, int> > q;
int N, M;

void BFS(){
    
    q.push(make_pair(1, 1));
    
    while(!q.empty()){
        int curr_x = q.front().second, curr_y = q.front().first;
        q.pop();
        
        for(int i = 0; i < 4; i++){
            
            int next_x = curr_x + dir[i][1], next_y = curr_y + dir[i][0];
            
            //maze[next_y][next_x] = 1 일 때만 지나간다 -> 간선의 방향이 한방향인 너비 우선 탐색
            //예제 입력 2에서 보면 처음에 오른쪽과 밑쪽으로 이동할 수 있는데, 이 때 둘 중 먼저 연산 한 것에 의해 (이 경우 밑쪽이 연산이 먼저됨)
            //인접한 값들도 2로 변경되면서 다음 노드가 탐색을 하지 못하게 되므로 억지로 멀리 돌아가서 계산하는 경우는 고려할 필요가 없어짐
            //그냥 순서대로 연산하다보면 결국 최소 거리가 나오게 됨
            if(next_x > 0 && next_y > 0 && next_x <= M && next_y <= N && maze[next_y][next_x] == 1){
                q.push(make_pair(next_y, next_x));
                maze[next_y][next_x] = maze[curr_y][curr_x] + 1;
            }
        }
    }
    
}

int main(){
    
    cin >> N >> M;
    
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= M; j++){
            //어떤 정수가 주어졌을 때, 한자리씩 띄어서 저장. 즉 치는 즉시 저장이 된다. (공백 빼고)
            scanf("%1d", &maze[i][j]);
        }
    }
    
    BFS();
    cout << maze[N][M];
    
    return 0;
}
