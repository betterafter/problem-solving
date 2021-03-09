#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>
#include <queue>

using namespace std;


int main(){

    deque<int> dq;
    int n; cin >> n;
    for(int i = 1; i <= n; i++){
        dq.push_back(i);
    }
    while(dq.size() != 1){
        dq.pop_front();
        if(dq.size() == 1) break;
        int t = dq.front(); dq.pop_front();
        dq.push_back(t);
    }
    cout << dq.front();
    return 0;
}
