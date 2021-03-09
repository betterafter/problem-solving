#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>

using namespace std;

vector<pair<pair<int, string>, int> > v;

bool compare(pair<pair<int, string>, int> &a, pair<pair<int, string>, int> &b){
    if(a.first.first == b.first.first) return a.second < b.second;
    return a.first.first < b.first.first;
}

int main(){

    int a; cin >> a;
    for(int i = 0; i < a; i++){
        int a; string s; cin >> a >> s;
        v.push_back(make_pair(make_pair(a, s), i));
    }
    sort(v.begin(), v.end(), compare);
    for(int i = 0; i < v.size(); i++){
        cout << v[i].first.first << " " << v[i].first.second << '\n';
    }
    return 0;
}
