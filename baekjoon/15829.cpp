#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>
#include <queue>

using namespace std;


int main(){

    int L; cin >> L;
    long long r = 1;
    unsigned long long sum = 0;
    long long M = 1234567891;
    string s; cin >> s;
    for(int i = 0; i < L; i++){
        sum += (s[i] - 96) * r;
        sum %= M;
        r = r * 31; r %= M;
    }
    cout << sum % M;
    return 0;
}
