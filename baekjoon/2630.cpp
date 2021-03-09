#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>
#include <queue>
#include <set>
#include <stack>

using namespace std;

int map[128][128];
int blue, white;

queue<pair<pair<int, int>, int> > q;

bool check(int x, int y, int length){
    for(int i = y; i < y + length; i++){
        for(int j = x; j < x + length; j++){
            if(map[i][j] != map[y][x]) return false;
        }
    }
    return true;
}

void divide(int n){
    q.push(make_pair(make_pair(0, 0), n));
    while(!q.empty()){
        int x = q.front().first.first, y = q.front().first.second, length = q.front().second; q.pop();
        if(!check(x, y, length)){
            q.push(make_pair(make_pair(x, y), length / 2));
            q.push(make_pair(make_pair(x + length / 2, y), length / 2));
            q.push(make_pair(make_pair(x, y + length / 2), length / 2));
            q.push(make_pair(make_pair(x + length / 2, y + length / 2), length / 2));
        }
        else{
            if(map[y][x] == 0) white++;
            else blue++;
        } 
    }
}


int main(){

    ios::sync_with_stdio(false);
	cin.tie(NULL);
    
    int n; cin >> n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> map[i][j];
        }
    }
    divide(n);
    cout << white << '\n' << blue;
    return 0;
}
