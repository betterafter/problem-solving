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

int main(){
    
    ios::sync_with_stdio(false);
	cin.tie(NULL);
    cout.tie(NULL);

    int n; cin >> n;
    for(int i = n; i >= 1; i--){
        for(int j = 0; j < n - i; j++){
            cout << " ";
        }
        for(int j = 0; j < 2 * i - 1; j++){
            cout << "*";
        }
        cout << '\n';
    }
    for(int i = 2; i <= n; i++){
        for(int j = 0; j < n - i; j++){
            cout << " ";
        }
        for(int j = 0; j < 2 * i - 1; j++){
            cout << "*";
        }
        cout << '\n';
    }
    return 0;
}
    
    

