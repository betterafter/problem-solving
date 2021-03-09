#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

int main(){

    int ans = 0;
    int go[1001] = { 0, };
    vector<pair<string, int> > before, after;
    int N; cin >> N;
    for(int i = 0; i < N; i++){
        string s; cin >> s;
        // 터널을 들어가기 전 차에 번호를 붙인다.
        before.push_back(make_pair(s, i));
    }
    for(int i = N; i < N * 2; i++){
        string s; cin >> s;
        for(int j = 0; j < N; j++){
            // before에서 같은 차를 찾아서 번호를 확인한 후 after에 쌍으로 저장해준다. 
            if(before[j].first == s){
                after.push_back(make_pair(s, j));
                break;
            }
        }
    }
    // after를 처음부터 돌면서 현재 탐색 중인 차보다 앞에 있는 차 중에서 들어간 순서 번호가 더 큰 차가 있다면 추월한 차이므로 go[터널을 들어간 순서 번호] = 1로
    // 바꿔준다.
    for(int i = 1; i < N; i++){
        for(int j = 0; j < i; j++){
            if(after[i].second < after[j].second){
                go[after[j].second] = 1;
            }
        }
    }

    for(int i = 0; i < N; i++){
        if(go[i] == 1) ans++;
    }

    cout << ans;
    return 0;
}