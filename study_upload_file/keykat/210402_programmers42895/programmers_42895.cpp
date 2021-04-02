#include <string>
#include <vector>
#include <math.h>
#include <queue>
#include <set>
#include <iostream>
#include <set>
#include <map>
#include <queue>

using namespace std;

int nn[8];

queue<int> q;
map<int, int> dp;

int solution(int N, int number) {

    int answer = 0;
    
    int n = 0;
    for(int i = 0; i < 8; i++){
        n = n * 10 + N;
        nn[i] = n; q.push(n); dp[n] = i + 1;
    }

    while(!q.empty()){
        int curr = q.front(); q.pop();
        //n, nn, nnn, ... nnnnnnnn과 n, nn, nnn, ... nnnnnnnn 결합
        // --> 이렇게 해야 5로 시작하는 경우, 55로 시작하는 경우, 555로 시작하는 경우 .... 로 스타트를 끊을 수 있음
        // 스타트를 끊어놓은 수들을 맵에 전부 넣고 bfs를 돌리게 되면 빠짐없이 다 들어갈 수 있게 됨.
        // 어차피 5로 시작하는 경우를 스타트를 끊고 bfs를 돌린 후에, 55로 시작하는 경우를 다시 스타트를 끊으면, dp 맵에 중복값이든, 처음 들어가는 값이든 다
        // 들어가게 됨. 따라서 5 ~ 55555555를 미리 스타트를 끊고 bfs를 돌릴 필요는 없음. 어차피 무조건 전부 탐색하게 되기는 함.
        for(int i = 0; i < 8; i++){
            // 길이가 8 이하이면서
            int length = dp[curr] + i + 1;
            if(length <= 8){
                int ccalc[4] = { curr + nn[i], curr - nn[i], curr * nn[i], curr / nn[i] };
                for(int ii = 0; ii < 4; ii++){
                    if(dp.find(ccalc[ii]) == dp.end() || (dp.find(ccalc[ii]) != dp.end() && dp[ccalc[ii]] > length) ){
                        dp[ccalc[ii]] = length; q.push(ccalc[ii]);
                    }
                }
            }
        }

        int calc[4] = { 0, };
        map<int, int> :: iterator iter;
        for(iter = dp.begin(); iter != dp.end(); iter++){
            int key = (int)(iter -> first);
            int length = (int)(iter -> second) + dp[curr];
            if(length <= 8){
                calc[0] = curr + key;
                calc[1] = curr - key;
                calc[2] = curr * key;
                if(key != 0) calc[3] = curr / key;
                for(int ii = 0; ii < 4; ii++){
                    if(dp.find(calc[ii]) == dp.end() || (dp.find(calc[ii]) != dp.end() && dp[calc[ii]] > length) ){
                        if(ii == 3 && key == 0) continue;
                        dp[calc[ii]] = length; q.push(calc[ii]);
                    }
                }
            }
        }
    }

    if(dp.find(number) == dp.end() || (dp.find(number) != dp.end() && dp[number] > 8)) return -1;
    answer = dp[number];
    return answer;
}
