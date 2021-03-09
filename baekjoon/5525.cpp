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

    int N, S; string s; cin >> N >> S >> s;
    string p = "";
    for(int i = 0; i < N; i++){
        p += "IO";
    }  
    p += "I";

    if(s.find(p) == string::npos){
        cout << 0; return 0;
     } 
    
    int res = 1;
    int idx = s.find(p); idx += 2 * N + 1;
    while(true){
        if(s[idx] == 'O' && s[idx + 1] == 'I'){
            res++; idx += 2;
        }
        else{
            if(s.find(p, idx) == string::npos){
                cout << res; return 0;
            }
            idx = s.find(p, idx); res++; idx += 2 * N + 1;
        }
    }

    return 0;
}
