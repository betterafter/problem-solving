//
//  17406.cpp
//  BJ
//
//  Created by 신기열 on 11/11/2019.
//  Copyright © 2019 신기열. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <vector>
#define MAX 1000000

using namespace std;

int n, m, k;
int map[51][51];
int order[6][3];
int visited[6];
vector<int> v;
int answer = MAX;

// 배열 회전 함수
void rotation(vector<int> v, int map[51][51]){
    
    for(int num = 0; num < v.size(); num++){
        int visited[51][51] = { 0, };
        int r = order[v[num]][0], c = order[v[num]][1], s = order[v[num]][2];
        int tmap[51][51] = { 0, };
        // 시작 점을 si, sj 로 둔다.
        int i = r - s, j = c - s, si = r - s, sj = c - s;
        // 개인적인 실수 ::: else if 로 쓰면 visited[i][j] != 0 이 되므로 다시 while문 안에 안들어가니까 안되는거임
        // 탐색 점이 정중앙이 나올 때까지 계속 돌려준다.
        // 회전 순서는 윗쪽 가로변 -> 오른쪽 세로변 -> 아랫쪽 가로변 -> 왼쪽 세로변
        while(visited[i][j] == 0){
            // 왼쪽 위 꼭짓점일 때 : 윗쪽 가로변과 왼쪽 세로변이 탐색이 안 된 케이스
            if(visited[i][j + 1] == 0 && visited[i + 1][j] == 0){
                // 변의 모든 점을 탐색하는데, 현재 점의 다음 점이 회전시키는 부분 배열을 벗어나거나, 이미 탐색한 겉 정사각형의 변이면 옆으로 이동하는 것을 중지한다.
                while(j + 1 <= c + s && visited[i][j + 1] == 0){
                    tmap[i][j + 1] = map[i][j]; visited[i][j + 1] = 1; j++;
                }
            }
            // 오른쪽 위 꼭짓점일 때 : 윗쪽 가로변이 탐색 됐고, 오른쪽 세로변이 탐색이 안 된 케이스
            if(visited[i][j - 1] == 1 && visited[i + 1][j] == 0){
                while(i + 1 <= r + s && visited[i + 1][j] == 0){
                    tmap[i + 1][j] = map[i][j]; visited[i + 1][j] = 1; i++;
                }
            }
            // 오른쪽 아래 꼭짓점일 때 : 오른쪽 세로변이 탐색 됐고, 아래쪽 가로변이 탐색이 안 된 케이스
            if(visited[i - 1][j] == 1 && visited[i][j - 1] == 0){
                while(j - 1 >= c - s && visited[i][j - 1] == 0){
                    tmap[i][j - 1] = map[i][j]; visited[i][j - 1] = 1; j--;
                }
            }
            // 왼쪽 아래 꼭짓점일 때 : 아래쪽 가로변이 탐색 됐고, 왼쪽 세로변이 탐색이 안 된 케이스
            if(visited[i - 1][j] == 0 && visited[i][j + 1] == 1){
                while(i - 1 >= r - s && visited[i - 1][j] == 0){
                    tmap[i - 1][j] = map[i][j]; visited[i - 1][j] = 1; i--;
                }
            }
            // 이렇게 돌리면 탐색 점이 맨 처음의 시작점으로 돌아가는데, 이 때 현재의 점이 시작점이면 한바퀴 돌린 것이므로 안쪽 정사각형의 왼쪽 위 꼭짓점으로 탐색점을 이동하자.
            // 만약 이동한 점이 정 중앙의 (r,c)이면 tmap에 그 점의 값을 넣어주고 탐색을 종료한다.
            if(i == si && j == sj){
                i++; j++; si = i; sj = j;
                if(i == r && j == c){
                    tmap[i][j] = map[i][j]; visited[r][c] = 1;
                }
            }
        }
        // 맵의 모양이 회전으로 바꼈으므로 map의 바뀐 일부분을 tmap의 그 위치의 배열로 바꿔준다.
        for(int y = r - s; y <= r + s; y++){
            for(int x = c - s; x <= c + s; x++){
                map[y][x] = tmap[y][x];
            }
        }
    }
//    for(int y = 1; y <= n; y++){
//        for(int x = 1; x <= m; x++){
//            cout << map[y][x] << " ";
//        }
//        cout << '\n';
//    }
//    cout << '\n';
//
    int ans = MAX;
    // 이 배열의 값을 구한다.
    for(int y = 1; y <= n; y++){
        int tmp = 0;
        for(int x = 1; x <= m; x++){
            tmp += map[y][x];
        }
        ans = min(ans, tmp);
    }
    // 최솟값을 구한다.
    answer = min(ans, answer);
}

// 회전 연산 순서를 결정
void DFS(int idx, int visited[6], vector<int> v, int map[51][51]){
    
    if(idx == k){
        int tmap[51][51];
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                tmap[i][j] = map[i][j];
            }
        }
        rotation(v, tmap); return;
    }
    
    for(int i = 0; i < k; i++){
        if(visited[i] == 0){
            visited[i] = 1;
            v.push_back(i);
            DFS(idx + 1, visited, v, map);
            visited[i] = 0;
            v.pop_back();
        }
    }
}

int main(){
    
    cin >> n >> m >> k;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin >> map[i][j];
        }
    }
    for(int i = 0; i < k; i++){
        cin >> order[i][0] >> order[i][1] >> order[i][2];
    }
    DFS(0, visited, v, map);
    cout << answer;
    
    return 0;
}



