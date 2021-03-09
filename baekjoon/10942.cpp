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

    int arr[2011] = { 0, };
    bool pel[2011][2011] = { false, };
    int N; cin >> N;
    for(int i = 1; i <= N; i++){
        cin >> arr[i];
        pel[i][i] = 1;
        if(arr[i] == arr[i - 1]) pel[i][i - 1] = 1;
        for(int j = 1; j < i - 1; j++){
            if(pel[i - 1][j + 1] && arr[j] == arr[i]){
                pel[i][j] = true;
            }
        }
    }

    // cout << '\n';
    // for(int i = 1; i <= N; i++){
    //     for(int j = 1; j <= N; j++){
    //         cout << pel[i][j] << " ";
    //     }
    //     cout << '\n';
    // }
    // cout << '\n';

    int M; cin >> M;
    for(int i = 0; i < M; i++){
        int x1, x2; cin >> x1 >> x2;
        cout << pel[x2][x1] << '\n';
    }
    
    return 0;
}

