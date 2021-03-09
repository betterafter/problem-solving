//
//  FindNumber.cpp
//  test
//
//  Created by 신기열 on 18/06/2019.
//  Copyright © 2019 신기열. All rights reserved.
//
#include <stdio.h>
#include <iostream>
#include <algorithm>

using namespace std;

int n, m, num1[100001];
int startIdx, endIdx;

//void LS(int search, int start, int end){
//
//    if(end - start <= 1){
//        if(num1[start] != search && num1[end] != search){
//            cout << 0 << '\n';
//            return;
//        }
//    }
//
//    if(search > num1[(end - start) / 2]){
//        LS(search, n / 2, n);
//    }
//    else if(search < num1[(end - start) / 2]){
//        LS(search, 0, n / 2);
//    }
//    else if(search == num1[(end - start) / 2]){
//        cout << 1 << '\n';
//        return;
//    }
//}

void LS(int search, int start, int end){
    
    startIdx = start;
    endIdx = end;
    
    while(endIdx - startIdx >= 0){
        if(search > num1[(endIdx + startIdx) / 2]){
            startIdx = ((endIdx + startIdx) / 2) + 1;
        }
        else if(search < num1[(endIdx + startIdx) / 2]){
            endIdx = ((endIdx + startIdx) / 2) - 1;
        }
        else if(search == num1[(endIdx + startIdx) / 2]){
            cout << 1 << '\n';
            return;
        }
    }
    cout << 0 << '\n';
    return;
}

int main(){
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> num1[i];
    }
    cin >> m;
    sort(num1, num1 + n);
    
    for(int i = 0; i < m; i++){
        int temp;
        cin >> temp;
        LS(temp, 0, n - 1);
    }
    
    return 0;
}

///////////////////// 재귀로 풀면 메모리 초과로 터진다. while문을 이용해서 이분탐색을 진행하자. //////////////
