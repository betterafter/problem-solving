#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>
#include <queue>
#include <set>
#include <stack>
#include <map>
#include <string>

using namespace std;

int main(){
    
    ios::sync_with_stdio(false);
	cin.tie(NULL);
    cout.tie(NULL);

    string ss; cin >> ss;
    vector<string> v;
    for(int i = 0; i < ss.size(); i++){
        string s = ss;
        reverse(s.begin(), s.end());
        for(int j = 0; j < i; j++){
            s.pop_back();
        }
        reverse(s.begin(), s.end());
        v.push_back(s);
    }
    sort(v.begin(), v.end());
    for(int i = 0; i < v.size(); i++){
        cout << v[i] << '\n';
    }
    return 0;
}
    
    

