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
int maxdp[2][3];
int mindp[2][3];

int m[1][3];

int main(){

    ios::sync_with_stdio(false);
	cin.tie(NULL);
    cout.tie(NULL);

    int N; cin >> N;
    for(int i = 0; i < N; i++){
        int a, b, c; cin >> m[0][0] >> m[0][1] >> m[0][2];
        if(i == 0){
            maxdp[0][0] = m[0][0]; maxdp[0][1] = m[0][1]; maxdp[0][2] = m[0][2];
            maxdp[1][0] = m[0][0]; maxdp[1][1] = m[0][1]; maxdp[1][2] = m[0][2];
            mindp[0][0] = m[0][0]; mindp[0][1] = m[0][1]; mindp[0][2] = m[0][2];
            mindp[1][0] = m[0][0]; mindp[1][1] = m[0][1]; mindp[1][2] = m[0][2];
        }
        else{
            maxdp[1][0] = max(maxdp[0][0], maxdp[0][1]) + m[0][0];
            mindp[1][0] = min(mindp[0][0], mindp[0][1]) + m[0][0];

            maxdp[1][1] = max(maxdp[0][0], maxdp[0][1]);
            maxdp[1][1] = max(maxdp[1][1], maxdp[0][2]);
            maxdp[1][1] += m[0][1];
            mindp[1][1] = min(mindp[0][0], mindp[0][1]);
            mindp[1][1] = min(mindp[1][1], mindp[0][2]);
            mindp[1][1] += m[0][1];
            
            maxdp[1][2] = max(maxdp[0][1], maxdp[0][2]) + m[0][2];
            mindp[1][2] = min(mindp[0][1], mindp[0][2]) + m[0][2];
            

            maxdp[0][0] = maxdp[1][0]; mindp[0][0] = mindp[1][0];
            maxdp[0][1] = maxdp[1][1]; mindp[0][1] = mindp[1][1];
            maxdp[0][2] = maxdp[1][2]; mindp[0][2] = mindp[1][2];
        }
    }


    int maxans = max(maxdp[1][0], maxdp[1][1]);
    maxans = max(maxans, maxdp[1][2]);

    int minans = min(mindp[1][0], mindp[1][1]);
    minans = min(minans, mindp[1][2]);

    // cout << "MAX : " << '\n';

    // for(int j = 0; j < 3; j++){
    //     cout << maxdp[1][j] << " ";
    // }
    // cout << '\n';
    
    // cout  << '\n';
    // cout << "MIN : " << '\n';

    // for(int j = 0; j < 3; j++){
    //     cout << mindp[1][j] << " ";
    // }
    // cout << '\n';
    
    // cout  << '\n';

    cout << maxans << " " << minans;
    return 0;
}

