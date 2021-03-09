#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>
#include <queue>
#include <set>
#include <stack>

using namespace std;

long long check(double line[], int K, double mid, int N){
    long long num = 0;
    for(int i = 0; i < K; i++){
        num += line[i] / mid;
    } 
    return num;
}

long long binarysearch(double line[], int K, int N){
    long long left = 1; long long right = line[K - 1];
    long long result = 0;
    while(left <= right){
        long long mid = ((left + right) / 2);
        long long res = check(line, K, mid, N);
        if(res >= N){
            left = mid + 1;
            if(result < mid) result = mid;
        }
        else if(res < N){
            right = mid - 1;
        }
    }
    return result;
}

int main(){

    int K, N; cin >> K >> N;
    double line[K];
    for(int i = 0; i < K; i++){
        cin >> line[i];
    }  
    sort(line, line + K);
    cout << binarysearch(line, K, N);
    return 0;
}
