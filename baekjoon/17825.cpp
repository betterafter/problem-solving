#include <stdio.h>
#include <iostream>

using namespace std;

int map[71], ismap[71];
pair<int, int> h[4];
int order[10], answer;

// 루트를 찾는 함수이다.
// 10에서 시작하는 루트는 31 ~ 33 (왼쪽 루트)
// 20에서 시작하는 루트는 41 ~ 42 (아래쪽 루트)
// 30에서 시작하는 루트는 51 ~ 53 (오른쪽 루트)
// 25에서 시작하는 루트는 61 ~ 64 (최종 루트)
// 0에서 시작하는 루트는 1 ~ 20 (외곽 루트)
// 이렇게 나눠 준 이유는, 각각의 배열로 나눠버리면 동기화를 해줄 수 없기 때문에 특정 루트의 끝점에 도달했으면, 연결 된 다음 루트의 시작점에 도달했다는 것으로 표현하도록 했다.
int find(int ismap[], int dice, int i, pair<int, int> horse[]){
    // pos는 말의 현재 위치
    int pos = horse[i].first;
    // tpos는 이동하고자 하는 위치를 저장하기 위함. 시작은 pos에서 시작해서 dice 만큼 1씩 이동할 것이다.
    int tpos = pos;
    // 이 때, 현재 시작 위치가 5이면, tpos를 30에서 시작한다고 가정하자 (10에서 시작하는 루트는 배열 인덱스 31, 32, 33에 저장되어 있으므로)
    if(pos == 5) tpos = 30;
    // 10, 15에 대해서도 각각 저장해주자.
    else if(pos == 10) tpos = 40;
    else if(pos == 15) tpos = 50;
    
    for(int j = 0; j < dice; j++){
        // tpos를 1씩 증가하면서 (말이 한 칸씩 이동함)
        tpos++;
        // 만약 현재 지점이 10, 20, 30 루트의 각각의 끝점일 경우, (어차피 모든 루트의 인덱스는 숫자가 겹치는 일이 없이 다 따로 떨어져있으므로 이렇게 한꺼번에 체크해도 문제 없음)
        if(tpos == 34 || tpos == 43 || tpos == 54){
            // 최종루트의 시작 지점으로 진입한다.
            tpos = 61;
        }
        // 만약 현재 지점이 외곽 루트의 끝점인 경우 최종 루트의 마지막 점으로 이동한다. (그림에서 38 다음에 40 (최종 루트 끝지점) 이므로)
        else if(tpos == 20) tpos = 64;
        
        
        // 이렇게 배열을 따로 나눠서 각 지점으로 진입하게끔 설정하는 것은 해당 위치에 말이 있는지 확인하는 동기화를 위해서다.
    }
    
    //cout << "horse : " << i << " horse pos : " << pos << " dice :  " << dice << " horse next pos : "  << tpos <<'\n';
    
    // 만약 이동하고자 하는 위치가 64가 넘어가면 = 최종 루트의 끝점을 넘어가면 = 말이 도착점에 도착했다면
    if(tpos > 64){
        // 도착점인 인덱스 70으로 보내버리고 말이 있던 위치는 0으로 만들어준다. (참고로 horse[i].second는 말이 움직였는지 아닌지를 판단하는 값이다.)
        horse[i].first = 70; horse[i].second = 0; ismap[pos] = 0; return 0;
    }
    // 64를 안 넘었으면 = 맵 내부 어딘가에 아직 있다면
    else if(tpos <= 64){
        // 다음 위치에 다른 말이 존재하지 않는다면,
        if(ismap[tpos] == 0){
            // 그 지점으로 이동하고 현재 위치는 말이 없음으로 바꿔준다.
            horse[i].first = tpos; horse[i].second = 0; ismap[pos] = 0; ismap[tpos] = 1; return map[tpos];
        }
        // 다음 위치에 다른 말이 존재한다면
        else if(ismap[tpos] == 1){
            // 움직일 수 없음으로 변환해준다.
            horse[i].second = 1; return 0;
        }
    }
    return 0;
}

void DFS(int idx, int ismap[], pair<int, int> horse[4], int total){
    
    // 10회가 넘어가면 크기 비교 후 끝낸다.
    if(idx >= 10){
        answer = max(answer, total);
        return;
    }
    
    int tmap[71]; pair<int, int> th[4];
    for(int i = 0; i < 71; i++){
        tmap[i] = ismap[i];
    }
    for(int i = 0; i < 4; i++){
        th[i] = horse[i];
    }
    // 말 4개를 모두 각 순서에 대입해준다.
    for(int i = 0; i < 4; i++){
        // 만약 현재 말이 이미 도착점에 도착한 경우는 사용하지 않는다.
        if(horse[i].first != 70){
            // find함수로 이 말이 도착한 위치의 점수를 가져온다.
            int sum = find(tmap, order[idx], i, th);
            // 이 말이 움직였다면 DFS를 다시 돌려준다.
            if(th[i].second == 0){
                DFS(idx + 1, tmap, th, total + sum);
                
                for(int i = 0; i < 71; i++){
                    tmap[i] = ismap[i];
                }
                for(int i = 0; i < 4; i++){
                    th[i] = horse[i];
                }
            }
        }
    }
}

int main(){
    
    for(int i = 0; i < 10; i++){
        cin >> order[i];
    }
    
    for(int i = 1; i <= 20; i++){
        map[i] = i * 2;
    }
    map[31] = 13; map[32] = 16; map[33] = 19;
    map[41] = 22; map[42] = 24;
    map[51] = 28; map[52] = 27; map[53] = 26;
    map[61] = 25; map[62] = 30; map[63] = 35; map[64] = 40;
    
    DFS(0, ismap, h, 0);
    cout << answer;
    return 0;
}
