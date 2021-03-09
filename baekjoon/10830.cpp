#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>
#include <queue>
#include <set>
#include <stack>
#include <map>
#include <limits.h>

using namespace std;

long long N, B;
long long arr[5][5];
long long res[5][5];

void mul(long long arr1[5][5], long long arr2[5][5]){
    long long tmp[5][5] = { 0, };
    for(int i = 0; i < N; i++){
        for(int k = 0; k < N; k++){
            long long sum = 0;
            for(int l = 0; l < N; l++){
                sum += arr1[i][l] * arr2[l][k]; 
            }
            tmp[i][k] = sum % 1000;
        }
    }
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            arr1[i][j] = tmp[i][j];
        }
    }
}

void printres(){
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cout << res[i][j] << " ";
        }
        cout << '\n';
    }
}


int main(){

    ios::sync_with_stdio(false);
	cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> B;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> arr[i][j];
        }
		res[i][i] = 1;
    }

	while(B > 0){
		if(B % 2 != 0){
			mul(res, arr);
		}
		mul(arr, arr);
		B /= 2;
	}

    printres();
    return 0;
}

