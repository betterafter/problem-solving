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

vector<int> res;

vector<int> getParr(string p){
    vector<int> parr(p.size(), 0); int n = 0;
    for(int k = 1; k < p.size(); k++){
        while(n > 0 && p[k] != p[n]){
            n = parr[n - 1];
        }
        if(p[k] == p[n]){
            n++;
            parr[k] = n;
        }
    }
    return parr;
}

void check(string s, string p){

    vector<int> pp = getParr(p); int idx = 0;
    for(int i = 0; i < s.size(); i++){
        while(idx > 0 && s[i] != p[idx]){
            idx = pp[idx - 1];
        }
        if(s[i] == p[idx]){
            if(idx == p.size() - 1){
                res.push_back(i - (p.size() - 1) + 1);
                idx = pp[idx];
            }
            else{
                idx++;
            }
        }
    }
}


int main(){

    ios::sync_with_stdio(false);
	cin.tie(NULL);
    cout.tie(NULL);

    string s; getline(cin, s);
    string p; getline(cin, p);

    check(s, p);
    cout << res.size() << '\n';
    for(int i = 0; i < res.size(); i++){
        cout << res[i] << " ";
    }

    return 0;
}

