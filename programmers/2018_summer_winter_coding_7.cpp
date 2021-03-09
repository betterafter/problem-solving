
// 문제 이름 : 기지국 설치

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int solution(int n, vector<int> stations, int w)
{
    int answer = 0;

    queue<int> q;
    q.push(stations[0]);
    while(!q.empty()){
        int pos = q.front(); q.pop();
        if(pos <= 1) continue;
        if(pos - 1 - w >= 1){
            pos = pos - w - w - 1;
            //cout << pos << " ";
            q.push(pos); answer++;
        }
    }

    for(int i = 0; i < stations.size() - 1; i++){
        q.push(stations[i]);
        while(!q.empty()){
            int pos = q.front(); q.pop();
            if(pos + 1 + w < stations[i + 1] - w){
                pos = pos + w + w + 1;
                //cout << pos << " ";
                q.push(pos); answer++;
            }
        }
    }

    q.push(stations[stations.size() - 1]);
    while(!q.empty()){
        int pos = q.front(); q.pop();
        if(pos >= n) continue;
        if(pos + 1 + w <= n){
            pos = pos + w + w + 1;
            //cout << pos << " ";
            q.push(pos); answer++;
        }
    }

    return answer;
}
