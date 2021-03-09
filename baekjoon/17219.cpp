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

    map<string, string> m;
    int N, M; cin >> N >> M;
    for(int i = 0; i < N; i++){
        string s1, s2; cin >> s1 >> s2;
        m[s1] = s2;
    }
    for(int i = 0; i < M; i++){
        string s; cin >> s;
        cout << m[s] << '\n';
    }
    return 0;
}
