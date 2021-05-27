#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
#include <iostream>

using namespace std;

int t[510][510];
long long dp[510][510];

int solution(vector<vector<int> > triangle) {
    long long answer = 0;

    for(int i = 0; i < triangle.size(); i++){
        for(int j = 0; j < triangle[i].size(); j++){
            t[i][j] = triangle[i][j];
        }
    }
    dp[0][0] = t[0][0];
    for(int i = 0; i < triangle.size(); i++){
        for(int j = 0; j < triangle[i].size(); j++){
            dp[i + 1][j] = max(dp[i + 1][j], dp[i][j] + t[i + 1][j]);
            dp[i + 1][j + 1] = max(dp[i + 1][j + 1], dp[i][j] + t[i + 1][j + 1]);
        }
    }

    int last = triangle.size();
    for(int i = 0; i < last; i++){
        answer = max(answer, dp[last][i]);
    }
    return answer;
}