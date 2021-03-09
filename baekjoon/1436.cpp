#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>
#include <queue>

using namespace std;


int main(){

    int n; cin >> n;
    int cnt = 1; int num = 666;
    while(cnt <= n){
        string s = to_string(num);
        if(s.find("666") != string::npos){
            if(cnt == n){
                cout << num; return 0;
            }
            cnt++;
        }
        num++;
    }
    return 0;
}
