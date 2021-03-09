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

int N;
char QT[64][64];

string res = "";

bool check(int x, int y, int length){
    char base = QT[y][x];
    for(int i = y; i < y + length; i++){
        for(int j = x; j < x + length; j++){

            if(QT[i][j] != base){
                return false;
            }
        }
    }
    return true;
}

void divide(int x, int y, int length){

    if(check(x, y, length)){
        if(QT[y][x] == '0'){
            res += "0"; return;
        }
        else res += "1"; return;
    }
    else{
        res += '(';
        divide(x, y, length / 2);
        divide(x + length / 2, y, length / 2);
        divide(x, y + length / 2, length / 2);
        divide(x + length / 2, y + length / 2, length / 2);
        res += ')';
    }
}


int main(){

    ios::sync_with_stdio(false);
	cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for(int i = 0; i < N; i++){
        string s; cin >> s;
        for(int j = 0; j < s.size(); j++){
            QT[i][j] = s[j];
        }
    }

    divide(0, 0, N);
    cout << res;
    return 0;
}
