#include <string>
#include <vector>

using namespace std;

int DIV = 1000000007;
int dp[60001];

int solution(int n) {
    int answer = 0;

    dp[1] = 1; dp[2] = 2; dp[3] = 3;
    for(int i = 4; i <= n; i++){
        dp[i] = (dp[i - 1] + dp[i - 2]) % DIV; 
    }

    answer = dp[n] % DIV;
    return answer;
}