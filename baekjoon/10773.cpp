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

    stack<int> s;
    double sum = 0;
    int K; cin >> K;
    for(int i = 0; i < K; i++){
        int t; cin >> t;
        if(t == 0) s.pop();
        else s.push(t);
    }

    while(s.size() > 0){
        sum += s.top(); s.pop();
    }
    cout << sum;    
    return 0;
}
