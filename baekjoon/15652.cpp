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

int N, M; 
vector<vector<int> > ans;

void dfs(int cnt, int curr, vector<int> v){

    if(cnt == M){
        ans.push_back(v); return;
    }

    for(int i = curr; i <= N; i++){
        v.push_back(i);
        dfs(cnt + 1, i, v);
        v.pop_back();
    }
}


int main(){

    ios::sync_with_stdio(false);
	cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;

    vector<int> v;

    dfs(0, 1, v);
    
    for(int i = 0; i < ans.size(); i++){
        for(int j = 0; j < ans[i].size(); j++){
            cout << ans[i][j] << " ";
        }
        cout << '\n';
    }
    return 0;
}

