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

int N, M, NC;
vector<vector<int> > party;
vector<int> participant[51];
int know[51] = { 0, };
queue<int> q;
int trueparty[51];

int main(){

    ios::sync_with_stdio(false);
	cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> M;
    cin >> NC;
    for(int i = 0; i < NC; i++){
        int t; cin >> t; know[t] = 1;
    }
    for(int i = 0; i < M; i++){
        vector<int> tmp; party.push_back(tmp);
        int pn; cin >> pn;
        for(int j = 0; j < pn; j++){
            int n; cin >> n;
            party[i].push_back(n);
            participant[n].push_back(i);
            if(know[n] == 1){
                q.push(i);
            } 
        }
    }

    while(!q.empty()){
        int p = q.front(); q.pop();
        trueparty[p] = 1;
        for(int i = 0; i < party[p].size(); i++){
            int member = party[p][i];
            for(int j = 0; j < participant[member].size(); j++){
                int curparty = participant[member][j];
                if(trueparty[curparty] == 0){
                    q.push(curparty);
                }
            }
        }
    }
    int cnt = 0;
    for(int i = 0; i < M; i++){
        if(trueparty[i] == 0) cnt++;
    }
    cout << cnt;
    return 0;
}

