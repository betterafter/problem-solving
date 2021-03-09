#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>
#include <queue>
#include <set>
#include <stack>
#include <map>

using namespace std;

int visited[101];
int t, n;
pair<int, int> home; 
vector<pair<int, int> > conv;
pair<int, int> goal;
string res = "sad";

void check(int x, int y, int visited[101]){

    if(abs(goal.first - x) + abs(goal.second - y) <= 1000){
        res = "happy"; return;
    }
    if(res == "happy") return;

    
    for(int i = 0; i < conv.size(); i++){
        int xx = conv[i].first, yy = conv[i].second;
        if(abs(xx - x) + abs(yy - y) <= 1000 && visited[i] == 0){
            visited[i] = 1;
            check(xx, yy, visited);
            //visited[i] = 0;
            // i를 거치는 지점에서 happy가 발생하지 않으면 어차피 i를 다시 거쳐봤자 무조건 sad 상태니까 다시 방문해줄 필요가 없다.
            // 따라서 visited[i] = 0; 으로 방문 상태를 초기화해주는 것은 별 의미가 없는 시간낭비이다.
            // 다만 이 경우 visited에 기록이 남으니까 매 테스트케이스가 끝날 때 마다 visited를 초기화해 주어야 한다.
        }
        if(res == "happy") return;
    }
}

int main(){

    ios::sync_with_stdio(false);
	cin.tie(NULL);
    cout.tie(NULL);

    int testcase; cin >> testcase;
    for(int i = 0; i < testcase; i++){
        cin >> n;
        cin >> home.first >> home.second;

        for(int i = 0; i < n; i++){
            int a, b; cin >> a >> b;
            conv.push_back(make_pair(a, b));
        }
        cin >> goal.first >> goal.second;

        check(home.first, home.second, visited);
        cout << res << '\n';
        for(int i = 0; i < n; i++){
            visited[i] = 0;
        }
        res = "sad";
        conv.clear();
    }
    return 0;
}
