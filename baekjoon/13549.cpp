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

int N, K; 
int res; 
void check(){
    int visited[100010] = { 0, };

    // 현재 위치와 그 위치에 도달했을 때 걸린 시간을 저장하는 우선순위 큐를 선언해줍니다.
    // 우선순위 큐에 " 위치 : N, 시간 : 0 " 을 넣고 돌려봅시다.
    // 참고로 일반적인 큐가 아닌 우선순위 큐를 사용하는 이유는 걸린 시간이 짧은 순서대로 재정렬해주기 위함입니다. 경과시간이 짧은 것부터 해줘야 
    // 걸린 시간도 최소로 될테니까요.
    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > q; 
    q.push(make_pair(0, N)); visited[N] = 1;
    while(!q.empty()){
        int time = q.top().first, pos = q.top().second; q.pop();
        // 현재 위치가 목적지라면 time초 만큼 걸린 것입니다.
        if(pos == K){
            res = time; return;
        }
        // 현재 위치가 목적지가 아니라면 현재 위치를 기준으로 +1, -1, *2 했을 때를 각각 구해줍시다.
        // ++ 해당 위치가 100001을 넘어가면 연산하지 맙시다. 문제에서 요구하는 것을 넘어갔으니까요. (이렇게 안하니까 런타임 에러 뜹니다.)
        if(pos * 2 <= 100000 && visited[pos * 2] == 0){
            visited[pos * 2] = 1;
            q.push(make_pair(time, pos * 2));
        }
        if(pos + 1 <= 100000 && visited[pos + 1] == 0){
            visited[pos + 1] = 1;
            q.push(make_pair(time + 1, pos + 1));
        }
        if(pos - 1 >= 0 && visited[pos - 1] == 0){
            visited[pos - 1] = 1;
            q.push(make_pair(time + 1, pos - 1));
        }
    }
}

int main(){

    ios::sync_with_stdio(false);
	cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> K;
    check();
    cout << res;
    return 0;
}
