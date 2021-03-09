
// 문제 이름 : 소수 만들기

#include <vector>
#include <iostream>
using namespace std;

bool isPrime(int n){
    int cnt = 0;
    for(int i = 2; i < n; i++){
        if(n % i == 0) cnt++;
    }
    if(cnt > 0) return false;
    else return true;
}

int solution(vector<int> nums) {
    int answer = 0;

    for(int i = 0; i < nums.size(); i++){
        int pick1 = -1, pick2 = -1, pick3 = -1;
        for(int j = i + 1; j < nums.size(); j++){
            for(int k = j + 1; k < nums.size(); k++){
                pick1 = nums[i]; pick2 = nums[j]; pick3 = nums[k];
                if(isPrime(pick1 + pick2 + pick3)) answer++;
            }
        }
    }

    return answer;
}