//
//  kakao2020_2.cpp
//  Contest
//
//  Created by 신기열 on 23/09/2019.
//  Copyright © 2019 신기열. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <stack>

using namespace std;

// 이 문제는 재귀함수로 해결했다. 애당초 문제도 재귀를 강조하였고, 일단 u, v로 나눠서 올바른 괄호 문자열이 아닌 것들은
// 전부 올바른 괄호 문자열로 바꿔줘야한다.
// ex) ())()( 같은 문자열이 있으면 u = (), v = )()( 로 나눠놓고 u는 올바른 괄호 문자열이니까 그냥 answer 문자열에 붙여주고,
// v는 올바른 괄호 문자열이 아니니까 다시 재귀적으로 돌려서 u = )(, v = )( 로 나눠주고, 둘 다 균형잡힌 괄호 문자열이면서 최소 단위이므로
// 올바른 괄호 문자열로 변환하는 방식으로 변환해주고 answer에 붙여주면 끝.
string solution(string p){

    if(p == "") return p;
    
    int i = 0;
    string answer, u, v, tmp;
    stack<char> s;
    bool IsRight = true;

    // 첫번째 괄호부터 ')' 가 나오면 이미 올바른 괄호 문자열은 아니다. IsRight는 올바른 괄호 문자열인지 파악하기 위한 변수.
    if(p[0] == ')') IsRight = false;
    s.push(p[0]);
    u += p[0];
    i++;

    while(i < p.size()){
        if(p[i] == '('){
            if(s.top() == ')') s.pop();
            else s.push(p[i]);
        }

        else if(p[i] == ')'){

            if(s.empty()) IsRight = false;
            if(s.top() == '(') s.pop();
            else s.push(p[i]);
        }
        // 괄호가 '(' 이든 ')'이든 일단 u에 붙여준다. (u, v로 나눠줘야하기 때문에)
        u += p[i];
        i++;
        // 스택이 비었다는 것은 균형잡힌 괄호 문자열 한개가 완성되었다는 뜻이므로 즉, u에 하나 만들어진 것임
        if(s.empty()) break;
    }

    // u에 균형잡힌 괄호 문자열 하나 만들었으니까 나머지는 v에 다 때려 박아준다.
    while(i < p.size()){
        v += p[i];
        i++;
    }

    // 현재 검사하고자 하는 문자열 (u)가 올바른 괄호 문자열이면 변환할 필요도 없이 그냥 answer에 붙여준다
    if(IsRight == true){
        answer = answer + u + solution(v);
    }
    // 올바른 괄호 문자열이 아니면 변환식을 이용한다.
    else{
        // 변환식은 문제에 주어진 그대로 만들어주면 된다.
        tmp += '(';                             // 4-1. 빈 문자열에 첫 번째 문자로 '('를 붙입니다.
        tmp += solution(v);                     // 4-2. 문자열 v에 대해 1단계부터 재귀적으로 수행한 결과 문자열을 이어 붙입니다.
        tmp += ')';                             // 4-3. ')'를 다시 붙입니다.
        for(int i = 1; i < u.size() - 1; i++){  // 4-4. u의 첫 번째와 마지막 문자를 제거하고, 나머지 문자열의 괄호 방향을 뒤집어서 뒤에 붙입니다.
            if(u[i] == ')') tmp += '(';         // 어차피 앞 뒤 짜르고 사이에 있는 것만 방향 바꿔줘서 붙이는 거니까 index = 1 ~ 마지막 - 1까지
            else tmp += ')';                    // 만 검사하면 됨. 그리고 '('면 ')'로, ')'면 '('로 바꿔주면 됨.
        }
        answer = answer + tmp;                  // 4-5. 생성된 문자열을 반환합니다.
    }                                           // 여기까지가 재귀의 끝. 이제 만든 문자열을 반환하기만 하면 됨.
    return answer;
}


int main(){
    
    string p;
    cin >> p;
    cout << solution(p);

    return 0;
}
