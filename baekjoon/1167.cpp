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

int N;
vector<vector<pair<int, int> > > tree(100001);
pair<int, int> res;

int check(int idx, int visited[100001]){

    visited[idx] = 1;
    pair<int, int> length = make_pair(0, 0);
    for(int i = 0; i < tree[idx].size(); i++){
        if(visited[tree[idx][i].first] == 0){
            int tlen = check(tree[idx][i].first, visited) + tree[idx][i].second;
            if(tlen > length.first){
                length.second = length.first;
                length.first = tlen;
            }
            else if(tlen > length.second){
                length.second = tlen;
            }
        }
    }
    if(res.first + res.second < length.first + length.second){
        res = length;
    }
    return length.first;
}

int main(){

    ios::sync_with_stdio(false);
	cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for(int i = 1; i <= N; i++){
        int a, b, c; cin >> a;
        while(true){
            cin >> b;
            if(b == -1) break;
            cin >> c;
            tree[a].push_back(make_pair(b,c));
        }
    }
    int visited[100001] = { 0, };
    check(1, visited);
    cout << res.first + res.second;
    return 0;
}

