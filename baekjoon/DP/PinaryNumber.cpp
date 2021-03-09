//
//  PinaryNumber.cpp
//  test
//
//  Created by 신기열 on 28/05/2019.
//  Copyright © 2019 신기열. All rights reserved.
//
#include <stdio.h>
#include <iostream>

using namespace std;

int main(){
    
    unsigned long long pn[100][2];
    int n;
    cin >> n;
    
    pn[0][0] = 0; pn[0][1] = 1;
    pn[1][0] = 1; pn[1][1] = 0;
    pn[2][0] = 1; pn[2][1] = 1;
    
    for(int i = 3; i < n; i++){
        pn[i][0] = pn[i - 1][0] + pn[i - 1][1];
        pn[i][1] = pn[i - 1][0];
    }
    
    // 1. 10을 곱하거나 10을 곱하고 1을 더해준 걸 반복한 경우 -> int 범위를 벗어나서 오답
    // 2. 단순히 0, 1을 저장해준 경우 -> vector의 크기가 메모리 크기를 벗어나서 메모리 초과
    // -> 단순히 개수로만 세줘야함 -> 뒷자리의 0의 개수와 1의 개수를 저장해주고 0을 만나면 (0의 개수++ && 1의 개수++), 1을 만나면 (0의 개수++) 가 됨
    // 3. 90까지 다 해보면 마지막 90번째의 개수가 2880067194370816120개가 나온다. 즉 int 범위를 가볍게 초과로 오답. 충분히 큰 데이터형인 unsigned long long을 쓰자.
    
    cout << pn[n - 1][0] + pn[n - 1][1];
    return 0;
}
