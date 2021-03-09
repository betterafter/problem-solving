#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>

using namespace std;

vector<pair<int, int> > v;

bool compare(pair<int, int> &a, pair<int, int> &b){
    if(a.first == b.first) return a.second < b.second;
    return a.first < b.first;
}

int main(){

    int n; cin >> n;
    for(int i = 0; i < n; i++){
        int a, b; cin >> a >> b;
        v.push_back(make_pair(a, b));
    }
    sort(v.begin(), v.end(), compare);
    for(int i = 0; i < v.size(); i++){
        cout << v[i].first << " " << v[i].second << '\n';
    }
    return 0;
}
