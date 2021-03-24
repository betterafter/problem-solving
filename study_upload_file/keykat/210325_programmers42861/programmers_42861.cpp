#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <iostream>

using namespace std;

int parent[101];

bool compare(vector<int> a, vector<int> b){
    return a[2] < b[2];
}

int find(int x){
    if(x == parent[x]) return x;
    return parent[x] = find(parent[x]);
}

void uni(int n, int m){
    n = find(n); m = find(m);
    parent[n] = m;
}


int solution(int n, vector<vector<int> > costs) {
    int answer = 0;
    int dist = 0;

    sort(costs.begin(), costs.end(), compare);
    for(int i = 0; i < 101; i++) parent[i] = i;

    int idx = 0;
    while(idx < costs.size()){
        int n = costs[idx][0], m = costs[idx][1], len = costs[idx][2];
        if(find(n) != find(m)){
            uni(n, m); answer += len;
        }
        idx++;
    }

    return answer;
}