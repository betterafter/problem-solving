//
//  kakao2020_1.cpp
//  Contest
//
//  Created by 신기열 on 23/09/2019.
//  Copyright © 2019 신기열. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <algorithm>

using namespace std;

int solution(string s){
    
    // 문자열 담을 공간
    int ans = (int)s.size();
    
    for(int i = 1; i < s.size(); i++){
        int j = 0, n = 1;
        string answer, prev;

        // 몇 개씩 묶을지 정하기 (j : 문자열 묶을 개수)
        while(j <= s.size()){

            string tmp;
            int k = j;
            // tmp = 묶은 문자열. j개 만큼 묶어준다
            while(k < i + j && k < s.size()){
                tmp += s[k];
                k++;
            }

            // 묶은 문자열 tmp가 같은 개수 만큼 묶인 이전 문자열과 같다면
            // ex) abab일때 prev = 앞의 ab, tmp = 뒤의 ab
            // 개수를 1 올려준다
            if(tmp == prev){
                n++;
            }
            
            // 묶은 문자열 tmp가 같은 개수 만큼 묶인 이전 문자열과 다르다면
            else{
                // 압축한게 1개 이상이면 압축 개수와 압축 문자열을 반환
                // ex) abab -> 2ab
                if(n > 1) answer = answer + to_string(n) + tmp;
                // 압축한게 1개도 없으면 그냥 문자열 그대로 반환
                else answer = answer + tmp;
                n = 1;
            }

            // 이전 문자열은 다시 tmp로 만들어서 다음꺼랑 비교해준다
            prev = tmp;
            j = j + i;
        }

        // 압축 문자열의 길이가 최소이므로 현재까지 가장 작은 것과 방금 구한 것과 길이 비교를 해준다.
        ans = min(ans, (int)answer.size());
    }
    
    
    return ans;
}


int main(){
    
    string s;

    cin >> s;
    cout << solution(s);
    
    return 0;
}
