#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <math.h>

using namespace std;

int main(){

    int x, y, w, h; cin >> x >> y >> w >> h;
    int ans = 10000000;
    ans = min(w - x, ans);
    ans = min(x - 0, ans);
    ans = min(h - y, ans);
    ans = min(y - 0, ans);
    cout << ans;
    return 0;
}
