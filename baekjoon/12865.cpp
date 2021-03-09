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

int N, K; 
vector<pair<int, int> > v;
int res;

int weight[101];
int value[101];
int dp[100001];

void check(int idx, int value, int weight){

    if(weight == 0){
        res = max(res, value); return;
    }

    for(int i = idx + 1; i < v.size(); i++){
        int wei = v[i].first, val = v[i].second;
        if(weight - wei >= 0){
            check(idx + 1, value + val, weight - wei);
        }
    }

    res = max(res, value);
    return;
}

void check2(){

    for(int i = 0; i < N; i++){
        for(int j = K; j >= 0; j--){
            if(j - weight[i] >= 0){
                dp[j] = max(dp[j], dp[j - weight[i]] + value[i]);
            }
        }
    }
}


int main(){

    ios::sync_with_stdio(false);
	cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> K;
    for(int i = 0; i < N; i++){
        int a, b; cin >> a >> b;
        //v.push_back(make_pair(a, b));
        weight[i] = a;
        value[i] = b;
    }
    //check(-1, 0, K);
    check2();

    cout << dp[K];
    return 0;
}
