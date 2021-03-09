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


vector<long long> parr, marr;
vector<long long> arr;
long long ans = INT_MAX;

int main(){

    ios::sync_with_stdio(false);
	cin.tie(NULL);
    cout.tie(NULL);

    int pidx = 0, midx = 0;
    int N; cin >> N;
    for(int i = 0; i < N; i++){
        long long a; cin >> a;
        arr.push_back(a);
    }

    long long left = 0, right = arr.size() - 1;
    long long rleft = 0, rright = arr.size() - 1;

    while(left < right){

        if(abs(arr[left] + arr[right]) < ans){
            if(right < arr.size()){
                rleft = left; rright = right;
                ans = abs(arr[left] + arr[right]);
            }
        }
        if(arr[left] + arr[right] < 0) left++;
        else right--;
    }
    //cout << rleft << " " << rright << '\n';
    cout << arr[rleft] << " " << arr[rright];
    return 0;   
}

