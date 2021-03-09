#include <stdio.h>
#include <iostream>
#include <vector>
#include <math.h>
#include <queue>

#define MAX 10000000

using namespace std;

int map[10][10];
int answer = MAX;

void move(vector<pair<int, int> > pos, vector<pair<int, int> > stair, vector<pair<int, int> > select){
    
    vector<int> dist;
    for(int i = 0; i < select.size(); i++){
        int p = select[i].first, st = select[i].second;
        int px = pos[p].first, py = pos[p].second, sx = stair[st].first, sy = stair[st].second;
        dist.push_back(abs(px - sx) + abs(py - sy));
    }
    
    // 이동하는 연산
    queue<int> st1, st2;
    int WaitForst1 = 0, WaitForst2 = 0, time = 0, exit = (int)pos.size();
    int visited[11] = { 0, };
    while(1){
        //cout << WaitForst1 << " " << st1.size() <<'\n';
        
        // 계단을 내려가는 연산
        int st1s = (int)st1.size(), st2s = (int)st2.size();
        
        
        // 1번 계단
        // 계단을 내려가는 모든 사람들이 1칸씩 내려가게 한다.
        for(int i = 0; i < st1s; i++){
            // 아직 완전 다 안내려갔으면 다시 큐에 넣어준다.
            if(st1.front() -  1 > 0) st1.push(st1.front() - 1);
            // 내려간 사람이 있으면 1명 탈출한다.
            else if(st1.front() - 1 == 0) exit--;
            // 탐색한건 빼준다.
            st1.pop();
        }
        // 해당 큐가 자리가 있으며, 대기 인원이 있으면
        if(WaitForst1 > 0 && st1.size() < 3){
            // 큐가 다 찰 때까지 대기 인원에서 큐로 인구 이동해준다.
            while(st1.size() < 3 && WaitForst1 > 0){
                st1.push(map[stair[0].second][stair[0].first]);
                WaitForst1--;
            }
        }
        ////////
        
        
        // 2번 계단
        for(int i = 0; i < st2s; i++){
            if(st2.front() -  1 > 0) st2.push(st2.front() - 1);
            else if(st2.front() - 1 == 0) exit--;
            st2.pop();
        }
        if(WaitForst2 > 0 && st2.size() < 3){
            
            while(st2.size() < 3 && WaitForst2 > 0){
                st2.push(map[stair[1].second][stair[1].first]);
                WaitForst2--;
            }
        }
        //////////
        
        
        ////////////////
        
        // 계단까지 가는 연산
        for(int i = 0; i < dist.size(); i++){
            // 입구에 도착 안했다면 한칸 더 이동
            if(dist[i] > 0) dist[i]--;
            // 입구에 도착했다면
            if(dist[i] == 0 && visited[i] == 0){
                // 어떤 계단을 택했었는지 확인
                int stn = select[i].second;
                visited[i] = 1;
                // 1번 계단이면 : 대기 수 1 증가 (어차피 위에서 대기 인원 만큼 빼주기 때문에 굳이 여기서 빼줄 필요는 없다.)
                if(stn == 0) WaitForst1++;
                // 2번 계단이면 : 대기 수 1 증가
                else if(stn == 1) WaitForst2++;

            }
        }
        // 1초 경과
        time++;
        // 전부 탈출 했으면 종료
        if(exit == 0) break;
    }
    answer = min(answer, time);
}

void DFS(int idx, vector<pair<int, int> > pos, vector<pair<int, int> > stair, vector<pair<int, int> > select){
    
    if(idx == pos.size()){
        move(pos, stair, select); return;
    }
    
    select.push_back(make_pair(idx, 0));
    DFS(idx + 1, pos, stair, select);
    select.pop_back();
    select.push_back(make_pair(idx, 1));
    DFS(idx + 1, pos, stair, select);
}


int main(){
    
    int T; cin >> T;
    for(int test_case = 1; test_case <= T; test_case++){
        
        vector<pair<int, int> > pos;
        vector<pair<int, int> > stair;
        vector<pair<int, int> > select;
        
        int n; cin >> n;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                cin >> map[i][j];
                if(map[i][j] == 1) pos.push_back(make_pair(j, i));
                else if(map[i][j] > 1) stair.push_back(make_pair(j, i));
            }
        }
        DFS(0, pos, stair, select);
        cout << "#" << test_case << " " << answer << '\n';
        pos.clear(); stair.clear(); select.clear(); answer = MAX;
    }
    
    return 0;
}
