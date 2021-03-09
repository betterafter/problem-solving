#include <stdio.h>
#include <iostream>
#include <vector>
#define MAX 10000000

using namespace std;

int dir[4][2] = { {0,1}, {0,-1}, {1,0}, {-1,0} };
int answer = MAX, corecnt;

void DFS(int idx, int map[12][12], int size, vector<pair<int, int> > core, int length, int cnt, int visited[12][12]){

    // 모든 코어를 탐색했으면
    if(idx == core.size()){
        
        // 이전에 구했던 연결 된 코어의 개수보다 현재 코어의 개수가 더 많다면
        if(corecnt < cnt){
            // 이번 전선의 길이의 합을 답으로 업데이트한다.
            corecnt = cnt; answer = length; return;
        }
        // 연결 된 코어의 개수가 같다면 전선의 길이가 더 짧은 걸로 답을 정한다.
        else if(corecnt == cnt){ answer = min(answer, length); return; }
        else return;
    }
    
    int x = core[idx].first, y = core[idx].second;
    // 현재 탐색 중인 코어가 보드의 가장자리에 있는 경우
    if(x == 0 || y == 0 || x == size - 1 || y == size - 1){
        // 전선의 길이나 코어의 개수를 추가할 필요 없이 바로 다음 코어를 탐색하면 된다.
        DFS(idx + 1, map, size, core, length, cnt, visited);
    }
    // 현재 코어가 사방이 막혔는지 체크하기 위한 판정
    bool blocked = true;
    // 네가지 방향에 대하여
    for(int i = 0; i < 4; i++){
        bool connected = true; int tx = x, ty = y;
        // 현재 코어의 위치를 기준으로 한 방향으로 쭉 전선을 내려서 중간에 다른 코어가 막고 있거나(map[y][x] = 1) 다른 전선이 막고 있는(visited[y][x] = 1) 경우 연결을 해제한다.
        while(tx + dir[i][0] >= 0 && tx + dir[i][0] < size && ty + dir[i][1] >= 0 && ty + dir[i][1] < size){
            if(visited[ty + dir[i][1]][tx + dir[i][0]] == 1 || map[ty + dir[i][1]][tx + dir[i][0]] == 1){
                connected = false; break;
            }
            tx += dir[i][0]; ty += dir[i][1];
        }
        // 해당 방향으로 연결을 할 수 있으면
        if(connected){
            // 일단 사방이 막힌 경우는 아니다. blocked = false로 바꿔준다.
            blocked = false;
            tx = x; ty = y;
            // 현재 코어에서 현재 방향으로 전선을 쭉 내린 맵 정보를 DFS로 보내준다. 이 때 전선의 길이도 함께 구해준다.
            while(tx + dir[i][0] >= 0 && tx + dir[i][0] < size && ty + dir[i][1] >= 0 && ty + dir[i][1] < size){
                visited[ty + dir[i][1]][tx + dir[i][0]] = 1; length++;
                tx += dir[i][0]; ty += dir[i][1];
            }
            
            DFS(idx + 1, map, size, core, length, cnt + 1, visited);
            
            tx = x; ty = y;
            while(tx + dir[i][0] >= 0 && tx + dir[i][0] < size && ty + dir[i][1] >= 0 && ty + dir[i][1] < size){
                visited[ty + dir[i][1]][tx + dir[i][0]] = 0; length--;
                tx += dir[i][0]; ty += dir[i][1];
            }
        }
    }
    // 어떤 방향으로도 connected = false이면 blocked = true가 유지 될 것이며, 이 경우도 전선의 길이나 코어의 개수의 변화 없이 DFS를
    // 실행하면 된다.
    if(blocked) DFS(idx + 1, map, size, core, length, cnt, visited);
}


int main(){
    
    int T; cin >> T;
    for(int test_case = 0; test_case < T; test_case++){
        
        int n;
        int map[12][12] = { 0, };
        int visited[12][12] = { 0, };
        vector<pair<int, int> > core;
        
        cin >> n;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                cin >> map[i][j];
                if(map[i][j] == 1) core.push_back(make_pair(j, i));
            }
        }
        DFS(0, map, n, core, 0, 0, visited);
        cout << "#" << test_case + 1 << " " << answer << '\n';
        answer = MAX; core.clear(); corecnt = 0;
    }
}




