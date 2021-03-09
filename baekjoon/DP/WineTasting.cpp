//
//  WineTasting.cpp
//  test
//
//  Created by 신기열 on 28/05/2019.
//  Copyright © 2019 신기열. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <iostream>
#include <math.h>
#include <algorithm>

using namespace std;

int main(){
    
    vector<int> wine; vector<int> sum;
    int n;
    cin >> n;
    
    sum.resize(10010);
    
    for(int i = 0; i < n; i++){
        int w;
        cin >> w;
        wine.push_back(w);
    }
    
    sum[1] = wine[0];
    sum[2] = wine[0] + wine[1];
    sum[3] = max(wine[0] + wine[1], wine[0] + wine[2]);
    sum[3] = max(sum[3], wine[1] + wine[2]);
    
    

    for(int i = 4; i <= n; i++){
        sum[i] = max(sum[i - 1], sum[i - 3] + wine[i - 2] + wine[i - 1]);
        sum[i] = max(sum[i], sum[i - 2] + wine[i - 1]);
    }
   
    cout << sum[n];
    return 0;
}

// 1. i번째 먹고 (i - 2)번째 중 가장 큰 걸 먹었을 경우
// 2. i번째 + (i - 1)번째 먹고 (i - 3)번째 중 가장 큰 것도 먹었을 경우
// 3. (i - 1)번째 중 가장 큰 걸 먹었을 경우

// 실수 1 : vector.push_back()하면 0번 인덱스부터 들어가는건 상식. 괜히 크기 맞춘다고 간과하지 말자.
// 실수 2 : 이 경우 resize를 이용해서 10010의 공간을 확보했지만, 미리 확보하지 않고 push_back()으로만 늘려줄 경우 index overflow가 발생할 수 있다. 주의하자
