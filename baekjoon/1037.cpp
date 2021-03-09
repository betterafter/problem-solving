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

    int N; cin >> N;
    long long nn[51] = { 0, };
    for(int i = 0; i < N; i++){
        cin >> nn[i];
    }
    sort(nn, nn + N);

    cout << nn[0] * nn[N - 1];
    return 0;
}
    
    

