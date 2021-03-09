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

int N, res;
deque<pair<int, int> > v;

int visited[15][15];

void print(){
    for(int i = 0; i < v.size(); i++){
        visited[v[i].second][v[i].first] = 1;

    }

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cout << visited[i][j] << " ";
        }
        cout << '\n';
    }
    cout << '\n';
    for(int i = 0; i < v.size(); i++){
        visited[v[i].second][v[i].first] = 0;

    }
}

bool meet(int x, int y){

    for(int i = 0; i < v.size(); i++){
        int xx = v[i].first, yy = v[i].second;
        if(xx == x) return true;
        if(x - xx == y - yy) return true;
        if(xx - x == y - yy) return true;
    }
    return false;
}


void check(int y, int cnt){
    if(cnt == N){
        //print();
        res++; return;
    }
    for(int i = 0; i < N; i++){
        if(!meet(i, y)){
            v.push_back(make_pair(i, y));
            check(y + 1, cnt + 1);
            v.pop_back();
        }   
    }
}


int main(){

    ios::sync_with_stdio(false);
	cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    check(0, 0);

    cout << res;
    return 0;
}
