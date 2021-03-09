#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>
#include <queue>
#include <set>
#include <stack>

using namespace std;

int main(){

    ios::sync_with_stdio(false);
	cin.tie(NULL);

    set<int> s;
    vector<int> v1, v2;
    int N; cin >> N;
    for(int i = 0; i < N; i++){
        int t; cin >> t;
        //v1.push_back(t);
        //v2.push_back(t);
        s.insert(t);
        v2.push_back(t);
    }

    set<int> :: iterator iter;
    for(iter = s.begin(); iter != s.end(); iter++){
        v1.push_back(*iter);
    }

    for(int i = 0; i < N; i++){
        vector<int> :: iterator low = lower_bound(v1.begin(), v1.end(), v2[i]);
        cout << low - v1.begin() << '\n';
    }


    return 0;
}
