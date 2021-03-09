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

int r, result;
int visited[10001];
string res;


void check(int goal){

    queue<pair<int, string> > q; q.push(make_pair(r, ""));
    
    while(!q.empty()){
        int rr = q.front().first; string how = q.front().second; q.pop();
        // 여기에 visited[rr] = 1을 선언하면 visited[rr] 이 원래 1인 경우에도 1로 값을 넣으므로 중복적으로 넣는 연산을 하게 됨.
        // 따라서 밑에서 D,S,L,R 에 대하여 각각 visited가 0인지 확인하고 0인 경우에만 1로 바꿔주면 되겠음.
        //visited[rr] = 1;
        if(rr == goal){
            res = how; return;
        }
        int lr, Rr, Dr, Sr;

        // D
        Dr = (rr * 2) % 10000;

        // S
        if(rr == 0) Sr = 9999;
        else Sr = rr - 1;

        // L
        lr = (rr % 1000) * 10 + rr / 1000;

        // R
        Rr = (rr % 10) * 1000 + (rr / 10);


        if(visited[lr] == 0){
            visited[lr] = 1;
            q.push(make_pair(lr, how + "L"));
        }
        
        if(visited[Rr] == 0){
            visited[Rr] = 1;
            q.push(make_pair(Rr, how + "R"));
        }
        
        if(visited[Dr] == 0){
            visited[Dr] = 1;
            q.push(make_pair(Dr, how + "D"));
        }
        
        if(visited[Sr] == 0){
            visited[Sr] = 1;
            q.push(make_pair(Sr, how + "S"));
        }
        
    }

}


int main(){

    ios::sync_with_stdio(false);
	cin.tie(NULL);
    cout.tie(NULL);

    int T; cin >> T;
    for(int i = 0; i < T; i++){
        cin >> r; cin >> result;
        check(result);
        cout << res << '\n';
        for(int i = 0; i < 10000; i++){
            visited[i] = 0;
        }
    }  

    

    return 0;
}
