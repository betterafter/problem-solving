
// 문제 이름 : 예산

#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> d, int budget) {
    int answer = 0;

    sort(d.begin(), d.end());
    int sum = 0; int idx = 0;
    while(budget >= sum){
        sum += d[idx]; 
        if(budget < sum) break;
        answer++; idx++; 
        if(idx > d.size() - 1) break;
    }


    return answer;
}