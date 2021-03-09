#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

vector<int> solution(int n) {
    vector<int> answer;

    if(n == 1){
        answer.push_back(0);
    }
    else{
        string prevs = "0", right = "1";
        for(int i = 2; i <= n; i++){
            string tmp = prevs + '0', rtmp = prevs + '1';
            tmp = tmp + right; rtmp = rtmp + right;
            prevs = tmp; right = rtmp;
        }
        for(int i = 0; i < prevs.size(); i++){
            answer.push_back(prevs[i] - 48);
        }
    }

    return answer;
}

