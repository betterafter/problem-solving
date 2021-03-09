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


void dfs(int cnt, int curr, vector<int> v, int idx){

    if(cnt == M){
        ans.insert(v); return;
    }

    for(int i = idx; i < N; i++){

        v.push_back(t[i]); 
        dfs(cnt + 1, t[i], v, i);
        v.pop_back();   
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
    dfs(0, 0, v, 0);
    
    set<vector<int> > :: iterator iter;
    for(iter = ans.begin(); iter != ans.end(); iter++){
        for(int j = 0; j < (iter->size()); j++){
            cout << iter->at(j) << " ";
        }
        cout << '\n';
    }
    return 0;
}

