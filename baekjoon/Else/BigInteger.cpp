//
//  BigInteger.cpp
//  test
//
//  Created by 신기열 on 17/06/2019.
//  Copyright © 2019 신기열. All rights reserved.
//
#include <stdio.h>
#include <iostream>
#include <vector>
#include <utility>
#include <math.h>
#include <cmath>
#include <algorithm>
#include <deque>

using namespace std;

int main(){
    
    string s1, s2, ans = "";
    cin >> s1 >> s2;
    
    
    int temp, upper = 0;
    reverse(s1.begin(), s1.end());
    reverse(s2.begin(), s2.end());
    
    unsigned long maxSize, minSize;
    
    //maxSize와 minSize를 알아야 두 수를 어느 자리까지 같이 더할 수 있는지 확인할 수 있음
    maxSize = max(s1.size(), s2.size());
    minSize = min(s1.size(), s2.size());
    
    //upper는 10이상일 때 다음자리에 1 더해주는 것을 의미. 처음엔 upper = 0이므로 그냥 더해줘도 무방.
    for(int i = 0; i < minSize; i++){
        
        temp = s1[i] - 48 + s2[i] - 48 + upper;
        
        //upper까지 더한 최종 수가 10 이상이다 -> 자리수인 10 빼주고 올림수가 1 있음
        if(temp >= 10){ upper = 1; temp -= 10; }
        else{ upper = 0; }
        
        //char -> int 할 때 -48 을 해준다. 따라서 int -> char 할 때도 +48을 해준다.
        ans = (char)(temp + 48) + ans;
    }
    
    //위의 for문이 각 자리마다 덧셈이 가능한 경우까지 해준거라면 여기서는 자리 더해줄 필요 없는것. 대신 1 + 99999 같은 경우는 upper가 계속 1씩 생성되므로
    //고려해줘야한다.
    
    //앞의 수가 더 클 때
    if(s1.size() == maxSize && s1.size() != s2.size()){
        for(int i = minSize; i < maxSize; i++){
            temp = s1[i] - 48 + upper;
            
            if(temp >= 10){ upper = 1; temp -= 10; }
            else{ upper = 0; }
            //cout << temp;
            ans = (char)(temp + 48) + ans;
        }
    }
    
    //뒤의 수가 더 클 때
    else if(s2.size() == maxSize && s1.size() != s2.size()){
        for(int i = minSize; i < maxSize; i++){
            
            temp = s2[i] - 48 + upper;
            
            if(temp >= 10){ upper = 1; temp -= 10; }
            else{ upper = 0; }
            
            ans = (char)(temp + 48) + ans;
            
        }
    }
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    
    
    //모든 연산이 끝나고도 upper가 1, 즉 올림수가 있으면 앞에 1 붙여주면 된다.
    if(upper == 1) cout << '1' + ans;
    else cout << ans;
    return 0;
}

