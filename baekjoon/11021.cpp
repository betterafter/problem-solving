#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>
#include <queue>
#include <set>
#include <stack>
#include <map>

using namespace std;


int main(){

    ios::sync_with_stdio(false);
	cin.tie(NULL);
    cout.tie(NULL);
    int T; cin >> T;
    for(int i = 0; i < T; i++){
        int A, B; cin >> A >> B;
        cout << "Case #" << i + 1 << ": " << A + B << '\n';
    }
    


    
    return 0;
}
