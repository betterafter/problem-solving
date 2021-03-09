#include <stdio.h>
#include <iostream>

using namespace std;

int main(){

    int num[43] = { 0, };
    int ans = 0;
    for(int i = 0; i < 10; i++){
        int a; cin >> a;
        num[a % 42]++;
    }
    for(int i = 0; i < 42; i++){
        if(num[i] > 0) ans++;
    }
    cout << ans;
    return 0;
}
