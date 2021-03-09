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

struct compare{
    bool operator()(int a, int b){
        if(abs(a) == abs(b)) return a > b;
        return abs(a) > abs(b);
    }
};  


priority_queue<int, vector<int>, compare> pq;




int main(){

    ios::sync_with_stdio(false);
	cin.tie(NULL);
    cout.tie(NULL);

    int N; cin >> N;
    for(int i = 0; i < N; i++){
        int t; cin >> t;
        if(t == 0){
            if(pq.empty()) cout << 0 << '\n';
            else{
                cout << pq.top() << '\n';
                pq.pop();
            }
        }
        else{
            pq.push(t);
        }
    }
    
    return 0;
}
