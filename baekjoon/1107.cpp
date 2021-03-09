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


int main(){

    ios::sync_with_stdio(false);
	cin.tie(NULL);
    cout.tie(NULL);

    int N; cin >> N;
    int b; cin >> b;
    int broken[11] = { 0, }; 
    for(int i = 0; i < b; i++){
        int bb; cin >> bb; broken[bb] = 1;
    }

    if(N == 100){
        cout << 0; return 0;
    }


    bool allbroken = true;
    for(int i = 0; i < 10; i++){
        if(broken[i] == 0){
            allbroken = false; break;
        }
    }
    if(allbroken){
        cout << abs(N - 100); return 0;
    }

    int res = abs(N - 100);
    for(int i = 0; i <= 1000000; i++){
        string s = to_string(i); bool ispush = true;
        for(int ii = 0; ii < s.size(); ii++){
            if(broken[s[ii] - '0'] == 1){
                ispush = false; break;
            }
        }
        if(ispush){
            res = min(res, abs(N - i) + (int)s.size());
           // cout << i << " : " << abs(N - i) << '\n';
        }
    }
    cout << res;
    return 0;
}
