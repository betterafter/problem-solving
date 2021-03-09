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

pair<int, int> mup, mdown, mleft, mright;
vector<pair<long long, long long> > v;
int n;

long long CCW(pair<long long, long long> p1, pair<long long, long long> p2, pair<long long, long long> p3){
    long long tmp = p1.first * p2.second + p2.first * p3.second + p3.first * p1.second;
    tmp -= (p1.second * p2.first + p2.second * p3.first + p3.second * p1.first);

    return tmp;
}

int main(){

    ios::sync_with_stdio(false);
	cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    for(int i = 0; i < n; i++){
        long long x, y; cin >> x >> y;
        v.push_back(make_pair(x, y));
    }

    long long ans = 0;
    for(int i = 0; i < v.size() - 2; i++){
        ans += CCW(v[0], v[i + 1], v[i + 2]);
    }
    ans = (long long)abs(ans);

    if(ans % 2 != 0) cout << ans / 2 << ".5";
    else cout << ans / 2 << ".0";
    return 0;
}

