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


vector<pair<string, string> > v;

long long check(){

    long long res = 1;

    map<string, int> m;
    for(int i = 0; i < v.size(); i++){
        if(m.find(v[i].second) == m.end()){
            m[v[i].second] = 1;
        }
        else m[v[i].second]++;
    }
    map<string, int> :: iterator iter;
    for(iter = m.begin(); iter != m.end(); iter++){
        int t = iter -> second;
        res *= (t + 1);
    }
    return res - 1;
}


int main(){

    ios::sync_with_stdio(false);
	cin.tie(NULL);
    cout.tie(NULL);

    int testcase; cin >> testcase;
    for(int i = 0; i < testcase; i++){
        int t; cin >> t;
        for(int j = 0; j < t; j++){
            string s1, s2; cin >> s1 >> s2;
            v.push_back(make_pair(s1, s2));
        }
        cout << check() << '\n';
        v.clear();
    }
    return 0;
}
