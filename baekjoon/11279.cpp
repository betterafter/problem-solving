#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>
#include <queue>
#include <set>
#include <stack>

using namespace std;

priority_queue<int> pq;

void push(int x){
    pq.push(x);
}

void pop(){
    if(pq.size() > 0){
        cout << pq.top() << '\n';
        pq.pop();
    }
    else cout << 0 << '\n';
}

int main(){

    ios::sync_with_stdio(false);
	cin.tie(NULL);

    int N; cin >> N;
    for(int i = 0; i < N; i++){
        int t; cin >> t;
        if(t == 0) pop();
        else push(t);
    }
    return 0;
}
