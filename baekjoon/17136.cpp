//
//  17136.cpp
//  BJ
//
//  Created by 신기열 on 13/11/2019.
//  Copyright © 2019 신기열. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <vector>
#define MAX 10000000

using namespace std;

vector<pair<int, int> > one;
int visited[10][10];
int paper[6];
int map[10][10];
int answer = MAX;

void DFS(vector<pair<int, int> > one, int visited[10][10], int cnt, int paper[6]){

    // 전체를 돌면서 색종이가 다 붙어있으면 answer 업데이트, 안 붙어 있는게 하나라도 있으면 다시 탐색 시작
    bool Allvisited = true;
    for(int i = 0; i < one.size(); i++){
        if(visited[one[i].second][one[i].first] == 0) Allvisited = false;
    }
    if(Allvisited){
        answer = min(answer, cnt);
    }
    
    //DFS에 보낼 visited와 paper 생성
    int tvisited[10][10] = { 0, };
    for(int y = 0; y < 10; y++){
        for(int x = 0; x < 10; x++){
            tvisited[y][x] = visited[y][x];
        }
    }
    int tpaper[6] = { 0, };
    for(int i = 1; i <= 5; i++){
        tpaper[i] = paper[i];
    }
    //
    // 1이 있는 위치를 전부 돌면서
    for(int i = 0; i < one.size(); i++){
        int x = one[i].first, y = one[i].second;
        // 그 위치가 색종이가 안 붙어 있으면
        if(visited[y][x] == 0){
            // 1 ~ 5 길이의 색종이로 각각 덮을 수 있는 지 확인. 참고로 가령 길이가 5인 색종이의 경우 curr, curr + 1, curr + 2, curr + 3, curr + 4 이렇게 길이가 4다.
            // 따라서 0 ~ 4까지 더하는 수를 정해주면 된다.
            for(int n = 0; n <= 4; n++){
                // 붙이려고 하는 색종이의 종류가 아직 다 안 쓰였을 때
                if(paper[n + 1] > 0){
                    bool iscovered = true;
                    // 이 색종이를 붙이려고 했을 때, 0인 곳도 덮어버리거나 || 이미 색종이가 붙어 있는 곳을 겹쳐버리거나 || 맵 밖을 벗어나면
                    // 붙이지 말고 뗀다.
                    for(int ny = y; ny <= y + n; ny++){
                        for(int nx = x; nx <= x + n; nx++){
                            //cout << nx << " " << ny << '\n';
                            if(map[ny][nx] == 0 || visited[ny][nx] == 1 || nx < 0 || nx > 9 || ny < 0 || ny > 9){
                                iscovered = false; break;
                            }
                        }
                        if(!iscovered) break;
                    }
                    // 이 색종이를 붙였으면
                    if(iscovered){
                        tpaper[n + 1]--;
                        // DFS에 보낼 맵 생성
                        for(int ny = y; ny <= y + n; ny++){
                            for(int nx = x; nx <= x + n; nx++){
                                tvisited[ny][nx] = 1;
                            }
                        }
                        // 이 색종이가 덮은 위치에 대한 정보를 업데이트하고, 사용한 색종이의 수에 대한 정보를 업데이트 해서 DFS로 보낸다.
                        DFS(one, tvisited, cnt + 1, tpaper);
                        for(int i = 1; i <= 5; i++){
                            tpaper[i] = paper[i];
                        }
                        for(int ny = y; ny <= y + n; ny++){
                            for(int nx = x; nx <= x + n; nx++){
                                tvisited[ny][nx] = 0;
                            }
                        }
                    }
                }
            }
            break;
        }
    }
}


int main(){
    
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            cin >> map[i][j];
            if(map[i][j] == 1) one.push_back(make_pair(j, i));
        }
    }
    for(int i = 1; i <= 5; i++){
        paper[i] = 5;
    }
    DFS(one, visited, 0, paper);
    if(answer == MAX) cout << -1;
    else cout << answer;
    return 0;
}
