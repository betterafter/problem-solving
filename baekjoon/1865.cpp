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

int N, M, W;

vector<vector<pair<int, int> > > v(510);
int res[510];


bool check(){

    for(int i = 0; i <= 500; i++){
        res[i] = 99999999;
    }
    res[1] = 0;
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            for(int k = 0; k < v[j].size(); k++){
                if(res[j] + v[j][k].second < res[v[j][k].first]){
                    res[v[j][k].first] = res[j] + v[j][k].second;
                    if(i == N) return true;
                }
            }
        }
    }

    return false;
}

int main(){

    ios::sync_with_stdio(false);
	cin.tie(NULL);
    cout.tie(NULL);

    int T; cin >> T;
    for(int i = 0; i < T; i++){
        cin >> N >> M >> W;
        v.resize(510);

        for(int j = 0; j < M; j++){
            int s, e, t; cin >> s >> e >> t;
            v[s].push_back(make_pair(e, t));
            v[e].push_back(make_pair(s, t));
        }
        for(int j = 0; j < W; j++){
            int s, e, t; cin >> s >> e >> t;
            v[s].push_back(make_pair(e, -t));
        }

        if(check()) cout << "YES" << '\n';
        else if(!check()) cout << "NO" << '\n';
        v.clear();
    }
    
    return 0;
}
