//
//  SWEA8500.cpp
//  SCPC
//
//  Created by 신기열 on 24/09/2019.
//  Copyright © 2019 신기열. All rights reserved.
//

#include <stdio.h>
#include<iostream>

using namespace std;

int main(int argc, char** argv)
{
    int test_case;
    int T;

    cin>>T;

    for(test_case = 1; test_case <= T; ++test_case)
    {
        int N, ans;
        cin >> N;
        int people[N];
        for(int i = 0; i < N; i++){
            cin >> people[i];
        }

        sort(people, people + N);
        ans = people[0] * 2 + 1;
        
        for(int i = 1; i < N; i++){
            if(people[i] > people[i - 1]){
                ans += people[i] - people[i - 1] + 1 + people[i];
            }
            else if(people[i] <= people[i - 1]){
                ans += people[i] + 1;
            }
        }
        
         cout << "#" << test_case << " " << ans << '\n';
    }
    return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
