#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>
#include <queue>
#include <set>

using namespace std;

bool compare(pair<int, int> &a, pair<int, int> &b){
    if(a.second == b.second) return a.first > b.first;
    return a.second < b.second;
}


int main(){

    vector<int> v;
    set<int> s;
    int n; cin >> n;

    for(int i = 0; i < n; i++){
        int t; cin >> t;
        v.push_back(t);
        s.insert(t);

    }
    sort(v.begin(), v.end()); 
    
    // 산술평균 구하기//////////////////////////////////////
    double sum = 0;
    for(int i = 0; i < v.size(); i++){
        sum += v[i];
    }
    if(sum < 0) cout << -round(-sum / v.size()) << '\n';
    else cout << round(sum / v.size()) << '\n';
    ////////////////////////////////////////////////////


    // 중앙값 구하기 //////////////////////////////////////
    cout << v[v.size() / 2] << '\n';
    ///////////////////////////////////////////////////

    // 최빈값 구하기 /////////////////////////////////////
    set<int> :: iterator iter;
    vector<pair<int, int> > smallest;
    for(iter = s.begin(); iter != s.end(); iter++){
        vector<int> :: iterator low, up;
        low = lower_bound(v.begin(), v.end(), *iter);
        up = upper_bound(v.begin(), v.end(), *iter);
        smallest.push_back(make_pair(*iter, up - low));
    }
    sort(smallest.begin(), smallest.end(), compare);
    if(smallest[smallest.size() - 1].second == smallest[smallest.size() - 2].second){
        cout << smallest[smallest.size() - 2].first << '\n';
    }
    else cout << smallest[smallest.size() - 1].first << '\n';
    //////////////////////////////////////////////////

    // 범위 구하기 /////////////////////////////////////
    cout << v[v.size() - 1] - v[0];
    /////////////////////////////////////////////////
    return 0;
}
