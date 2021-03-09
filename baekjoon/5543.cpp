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

    int ham[3] = { 0, };
    int drink[2] = { 0, };
    for(int i = 0; i < 3; i++){
        cin >> ham[i];
    }
    for(int i = 0; i < 2; i++){
        cin >> drink[i];
    }
    sort(ham, ham + 3);
    sort(drink, drink + 2);

    cout << ham[0] + drink[0] - 50;
    return 0;
}
    
    

