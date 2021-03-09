#include <stdio.h>
#include <iostream>
#include <math.h>

using namespace std;

int main(){

    int N, k, answer;
    cin >> N;
    cin >> k;

    // mid = left = 1, right = k 로 시작하여 (left * right) / 2 일 때, 이 mid보다 작은 숫자의 개수를 파악한다. mid 는 임의의 숫자를 의미한다.
    // 각 행에 대하여 i * j <= mid (임의의 숫자) 이므로 j <= mid / i 가 된다. 즉 mid보다 작은 j 수를 구한다.
    // 이 때 mid / i 가 N 보다 커질 수 있다. 이 땐 그냥 행의 최대인 N으로 개수를 카운트하자.
    // mid보다 작은 수의 개수가 k보다 작으면 아직 더 있는 것이므로 mid보다 더 큰 수에서 찾아야한다.
    // mid보다 작은 수의 개수가 k보다 크면 혹시 현재보다 더 적은 수가 있을 수 있으므로 mid보다 더 작은 수에서 찾아본다.
    int left = 1, right = k;
    while(left <= right){
        int mid = (left + right) / 2;
        int cnt = 0;
        // 1부터 N행까지 전부 돌면서 mid보다 작은 j의 수를 세준다. 이 때 j는 최대인 N을 넘을 수 없다.
        for(int i = 1; i <= N; i++){
            cnt += min(mid / i, N);
        }
        if(cnt < k){
            left = mid + 1;
        }
        else{
            answer = mid;
            right = mid - 1;
        }
    } 
    cout << answer;
}