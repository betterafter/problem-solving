#include <stdio.h>
#include <iostream>

using namespace std;

int main(){
    int arr[100001] = { 0, };
    for(int i = 1; i < 100001; i++){
        arr[i] = i;
    }

    int N; cin >> N;
    for(int i = 2; i <= N; i++){

        for(int j = 2; j * j <= i; j++){
            arr[i] = min(arr[i], arr[i - j * j] + 1);
        }
    }
    cout << arr[N];
}
