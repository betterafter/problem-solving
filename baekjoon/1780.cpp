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

vector<int> iv;
vector<char> cv;

int paper[2187][2187];

int cnt_1, cnt_m1, cnt_0;


void divide(int x, int y, int length){

    int base = paper[y][x]; bool check = true;
    for(int i = y; i < y + length; i++){
        for(int j = x; j < x + length; j++){
            if(paper[i][j] != base){
                check = false; break;
            }
        }
        if(!check) break;
    }

    if(check){
        if(paper[y][x] == 1){
            cnt_1++; return;
        }
        else if(paper[y][x] == -1){
            cnt_m1++; return;
        }
        else{
            cnt_0++; return;
        }
    }
    else if(!check){
        divide(x, y, length / 3);
        divide(x + length / 3, y, length / 3);
        divide(x + 2 * length / 3, y, length / 3);

        divide(x, y + length / 3, length / 3);
        divide(x + length / 3, y + length / 3, length / 3);
        divide(x + 2 * length / 3, y + length / 3, length / 3);

        divide(x, y + 2 * length / 3, length / 3);
        divide(x + length / 3, y + 2 * length / 3, length / 3);
        divide(x + 2 * length / 3, y + 2 * length / 3, length / 3);
    }
}

int main(){

    ios::sync_with_stdio(false);
	cin.tie(NULL);
    cout.tie(NULL);
    
    int N; cin >> N;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> paper[i][j];
        }
    }
    divide(0, 0, N);
    cout << cnt_m1 << '\n' << cnt_0 << '\n' << cnt_1;
    return 0;
}
