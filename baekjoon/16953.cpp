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

long long A, B; 
priority_queue<pair<long long, long long> > q;

long long bfs(){

    q.push(make_pair(0, A));
    while(!q.empty()){
        long long cnt = q.top().first, x = q.top().second; q.pop();
        if(x == B) return cnt;
        if(x * 2 <= B){
            q.push(make_pair(cnt + 1, x * 2));
        }
        if(x * 10 + 1 <= B){
            q.push(make_pair(cnt + 1, x * 10 + 1));
        }
    }
    return -1;
}

int main(){

    ios::sync_with_stdio(false);
	cin.tie(NULL);
    cout.tie(NULL);

    cin >> A >> B;
    int ans = bfs();
    if(ans != -1) cout << ans + 1;
    else cout << ans;
    
    return 0;
}

