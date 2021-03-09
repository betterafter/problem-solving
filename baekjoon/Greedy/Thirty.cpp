//
//  Thirty.cpp
//  test
//
//  Created by 신기열 on 27/05/2019.
//  Copyright © 2019 신기열. All rights reserved.
//


#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <math.h>

using namespace std;

bool compare(int a, int b){
    return a > b;
}

int main(){
    
    //문제에서 string의 길이가 매우 기므로 unsinged long long으로 표현
    unsigned long long pos, sum = 0, size;
    
    string s;
    cin >> s;
    
    //string 의 길이 구하기
    size = s.length();
    
    //s에 0이 포함되어 있으면 0 한개 지워주기 (30의 배수이므로 10의 배수이기도 하니까)
    if(s.find("0") != string::npos){
        pos = s.find("0");
        s.erase(pos, 1);
        
        //그 후 각 자리를 모두 더해서 3의 배수인지 확인 (3의 배수인 수는 각 자리를 모두 더한 합이 3의 배수가 됨)
        for(int i = 0; i < s.size(); i++){
            int n = s[i] - 48;
            sum += n;
        }
        
        //3의 배수라면 compare 함수로 내림차순 정렬하고 마지막에 아까 지워준 0을 붙여서 출력, 3의 배수가 아니면 30의 배수도 아니므로 -1 출력
        if(sum % 3 == 0){
            sort(s.begin(), s.end(), compare);
            cout << s + "0";
        }
        else{
            cout << -1;
        }
    }
    
    //s에 0이 포함되어 있지 않으면 30의 배수가 아니므로 -1 출력
    else{
        cout << -1;
    }

    return 0;
}
