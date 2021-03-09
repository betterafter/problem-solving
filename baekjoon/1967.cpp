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
vector<vector<pair<int, int> > > tree(10001);
pair<int, int> res;

int check(int idx){

    pair<int, int> length = make_pair(0, 0);
    for(int i = 0; i < tree[idx].size(); i++){
        int tlen = check(tree[idx][i].first) + tree[idx][i].second;
        if(tlen > length.first){
            length.second = length.first;
            length.first = tlen;
        }
        else if(tlen > length.second){
            length.second = tlen;
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
    for(int i = 0; i < N - 1; i++){
        int a, b, c; cin >> a >> b >> c;
        tree[a].push_back(make_pair(b, c));
    }
    check(1);
    cout << res.first + res.second;
    return 0;
}
