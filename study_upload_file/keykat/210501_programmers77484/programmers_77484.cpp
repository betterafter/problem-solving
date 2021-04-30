#include <string>
#include <vector>
#include <iostream>
#include <math.h>
#include <algorithm>

using namespace std;

// 로또의 최고순위와 최저순위

int trans(int n){
    if(n == 6) return 1;
    if(n == 5) return 2;
    if(n == 4) return 3;
    if(n == 3) return 4;
    if(n == 2) return 5;
    if(n == 1 || n == 0) return 6;
}

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> answer;

    int cnt = 0;
    int zero = 0;
    for(int i = 0; i < lottos.size(); i++){
        if(lottos[i] == 0){
            zero++;
        }
        else{
            for(int j = 0; j < win_nums.size(); j++){
                if(lottos[i] == win_nums[j]){
                    cnt++; break;
                }
            }
        }
    }
    answer.push_back(trans(cnt));
    answer.push_back(trans(cnt + zero));
    sort(answer.begin(), answer.end());
    return answer;
}