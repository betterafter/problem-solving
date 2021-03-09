#include <iostream>
#include <algorithm>
#include <math.h>

using namespace std;

int main(){
    int sum = 0;
    for(int i = 0; i < 5; i++){
        int a; cin >> a;
        sum += a * a;
    }
    cout << sum % 10;
    return 0;
}