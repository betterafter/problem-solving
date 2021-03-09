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
vector<int> t;
set<vector<int> > ans;


void dfs(int cnt, int curr, vector<int> v, int idx[10]){

    if(cnt == M){
        ans.insert(v); return;
    }

    for(int i = 0; i < N; i++){
        if(idx[i] == 0){
            v.push_back(t[i]); idx[i] = 1;
            dfs(cnt + 1, t[i], v, idx);
            v.pop_back(); idx[i] = 0;
        }
    }
}


int main(){

    ios::sync_with_stdio(false);
	cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    for(int i = 0; i < N; i++){
        int k; cin >> k;
        t.push_back(k);
    }
    sort(t.begin(), t.end());



    vector<int> v;
    int idx[10] = { 0, };
    dfs(0, 0, v, idx);
    
    set<vector<int> > :: iterator iter;
    for(iter = ans.begin(); iter != ans.end(); iter++){
        for(int j = 0; j < (iter->size()); j++){
            cout << iter->at(j) << " ";
        }
        cout << '\n';
    }
    return 0;
}
