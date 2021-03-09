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

int N, M;
vector<vector<int> > v(101);
int kevin[101] = { 0, };
int resdistance = 987654321, mindistance = 987654321;

void distancecheck(int check, int goal, int distance, int visited[101]){

    if(check == goal){
        resdistance = min(distance, resdistance); return;
    }
    for(int i = 0; i < v[check].size(); i++){
        if(visited[v[check][i]] == 0){
            visited[v[check][i]] = 1;
            distancecheck(v[check][i], goal, distance + 1, visited);
            visited[v[check][i]] = 0;
        }
    }
    return;
}

void Search(){

    for(int i = 1; i <= N; i++){
        int visited[101] = { 0, };
        visited[i] = 1;
        for(int j = 1; j <= N; j++){
            if(i != j){
                distancecheck(i, j, 0, visited);
                kevin[i] += resdistance;
                resdistance = 987654321;
            }
        }
        mindistance = min(mindistance, kevin[i]);
        visited[i] = 0;
    }
}

int main(){

    ios::sync_with_stdio(false);
	cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    for(int i = 0; i < M; i++){
        int a, b; cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    Search();  
    int res = 1000;
    for(int i = 1; i <= N; i++){
        //cout << kevin[i] << " ";
        if(kevin[i] == mindistance){
            res = min(res, i);
        }
    }
    cout << res;
    return 0;
}
