//
//  14696.cpp
//  test
//
//  Created by 신기열 on 30/06/2019.
//  Copyright © 2019 신기열. All rights reserved.
//
#include <stdio.h>
#include <iostream>

using namespace std;


bool compare(int a, int b){
    return a > b;
}


void Check(int a, int *arr){
    if(a == 4) arr[0]++;
    else if(a == 3) arr[1]++;
    else if(a == 2) arr[2]++;
    else if(a == 1) arr[3]++;
}

void ResCompare(int *arr1, int *arr2){
    if(arr1[0] != arr2[0]){
        if(arr1[0] > arr2[0]){ cout << "A" << '\n'; return; }
        else { cout << "B" << '\n'; return; }
    }
    else if(arr1[1] != arr2[1]){
        if(arr1[1] > arr2[1]){ cout << "A" << '\n'; return; }
        else { cout << "B" << '\n'; return; }
    }
    else if(arr1[2] != arr2[2]){
        if(arr1[2] > arr2[2]){ cout << "A" << '\n'; return; }
        else { cout << "B" << '\n'; return; }
    }
    else if(arr1[3] != arr2[3]){
        if(arr1[3] > arr2[3]){ cout << "A" << '\n'; return; }
        else { cout << "B" << '\n'; return; }
    }
    else{
        cout << "D" << '\n'; return;
    }
}

int main(){
    
    int T; cin >> T;
    for(int test = 0; test < T; test++){
        
        int A[4] = { 0, }, B[4] = { 0, };
        int n; cin >> n;
        
        for(int i = 0; i < n; i++){
            int a; cin >> a;
            Check(a, A);
        }
        
        int m; cin >> m;
        
        for(int i = 0; i < m; i++){
            int b; cin >> b;
            Check(b, B);
        }
        
        ResCompare(A, B);
    }
    
    return 0;
}
