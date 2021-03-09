#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>
#include <queue>

using namespace std;


int main(){

    int A, B, V; cin >> A >> B >> V;
    int n = 0, time = 0;

    time = (V - B) / (A - B);
    if((V - B) % (A - B) == 0) cout << time;
    else cout << time + 1;
    return 0;
}
