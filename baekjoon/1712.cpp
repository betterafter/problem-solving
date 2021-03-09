#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>
#include <queue>
#include <set>
#include <stack>
#include <map>
#include <string>

using namespace std;

long long a, b, c;

void check(){

    long long left = 0;
    long long right = 2100000000; 

    while(left <= right){
        long long mid = (left + right) / 2;
        if(a + b * mid < c * mid){
            if(a + b * (mid - 1) >= c * (mid - 1)){
                cout << mid; return;
            }
            right = mid - 1;
        }
        else if(a + b * mid > c * mid){
            left = mid + 1;
        }

        else{
            cout << mid + 1; return;
        }
    }
}

void check2(){
    cout << a / (c - b) + 1;
}

int main(){
    
    ios::sync_with_stdio(false);
	cin.tie(NULL);
    cout.tie(NULL);

    cin >> a >> b >> c;

    if(b >= c) { cout << -1; return 0; }

    check2();

    return 0;
}
    
    

