
// 문제 이름 : 쿠키 구입

#include <string>
#include <vector>
#include <math.h>
#include <iostream>

using namespace std;

int left_cookies_arr[2010][2010];

int solution(vector<int> cookie) {
    int answer = -1;

    int c[2010] = { 0, };
    for(int i = 0; i < cookie.size(); i++){
        c[i + 1] = c[i] + cookie[i];
    }
    // c[0] = 0
    // c[1] = cookies_1
    // c[2] = cookies_1 + cookies_2
    // c[3] = cookies_1 + cookies_2 + cookies_3
    // c[4] = cookies_1 + cookies_2 + cookies_3 + cookies_4
    for(int i = 1; i < cookie.size() + 1; i++){
        for(int j = i; j < cookie.size() + 1; j++){
            // 현재 왼쪽 아들 임시 범위가 answer보다 작으면 애당초 비교를 할 필요가 없다. 맨 마지막 테스트 케이스 7, 8, 9는 3중 for문의 마지막 for문의
            // 회전수를 줄일 수 있는지 확인하기 위한 절차
            if(answer >= c[j] - c[i - 1]) continue;
            for(int k = j + 1; k < cookie.size() + 1; k++){
                if(c[j] - c[i - 1] == c[k] - c[j]){
                    answer = max(c[j] - c[i - 1], answer); break;
                }
                if(c[j] - c[i - 1] <= c[k] - c[j]) break;
            }
        }
    }
    if(answer == -1) answer = 0;
    return answer;
}