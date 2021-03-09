#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <math.h>

using namespace std;

int main(){

    int N, K; cin >> N >> K;
    int nfac = 1, kfac = 1, n_kfac = 1;
    int n = N, k = K, n_k = N - K;
    while(n != 0){
        nfac *= n; n--;
    }
    while(k != 0){
        kfac *= k; k--;
    }
    while(n_k != 0){
        n_kfac *= n_k; n_k--;
    }

    cout << nfac / (kfac * n_kfac);
    return 0;
}
