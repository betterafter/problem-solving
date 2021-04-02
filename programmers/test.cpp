#include <string>
#include <vector>
#include <math.h>
#include <queue>
#include <iostream>
#include <map>

using namespace std;

int nn[8];

queue<int> q;
map<int, int> dp;

int solution(int N, int number) {

    int answer = 0;
    
    int n = 0;
    for(int i = 0; i < 8; i++){
        n = n * 10 + N;
        cout << n << '\n';
        nn[i] = n; q.push(n); dp[n] = i + 1;
    }
    for(int i =0; i < 8; i++){
        cout << nn[i] << " ";
    }
    cout << dp.size() << '\n';

    
    return answer;
}

int main(){

    solution(5, 12);

    return 0;
}