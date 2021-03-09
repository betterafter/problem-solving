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

int m[1025][1025] = { 0, };
int add[1025][1025] = { 0, };

int N, M;

void calc(){
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            add[i][j] = add[i - 1][j] + add[i][j - 1] - add[i - 1][j - 1] + m[i][j]; 
        }
    }
}

void print(){
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            cout << add[i][j] << " ";
        }
        cout << '\n';
    }
    cout << '\n';
}

int main(){

    ios::sync_with_stdio(false);
	cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            cin >> m[i][j];
        }
    }

    calc();
    for(int i = 0; i < M; i++){
        int x1, y1, x2, y2; cin >> y1 >> x1 >> y2 >> x2;
        cout << add[y2][x2] - add[y2][x1 - 1] - add[y1 - 1][x2] + add[y1 - 1][x1 - 1] << '\n';
    }

    
    return 0;
}
