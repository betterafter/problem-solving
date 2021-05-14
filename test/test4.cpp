#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <math.h>
#include <algorithm>

using namespace std;

int state = 0;
int m[1001][1001];
vector<vector<int> > v3(1001);
int visited[1001][1001];
int states[1001];

int route[1001][1001];

int val[1001];
int MAX = 987654321;

int solution(int n, int start, int end, vector<vector<int> > roads, vector<int> traps) {
    int answer = 0;

    int trap[1001] = { 0, };
    for(int i = 0; i < traps.size(); i++){
        trap[traps[i]] = 1;
    }

    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= n; j++){
            m[i][j] = MAX;
        }
    }


    for(int i = 0; i < roads.size(); i++){

        m[roads[i][0]][roads[i][1]] = min(m[roads[i][0]][roads[i][1]],  roads[i][2]);
        m[roads[i][1]][roads[i][0]] = min(m[roads[i][0]][roads[i][1]],  roads[i][2]);

        v3[roads[i][1]].push_back(roads[i][0]);
        v3[roads[i][0]].push_back(roads[i][1]);

        route[roads[i][0]][roads[i][1]] = roads[i][0];
        route[roads[i][1]][roads[i][0]] = roads[i][0];
    }


    for(int i = 1; i <= n; i++){
        val[i] = MAX;
    }
    val[start] = 0;



    queue<pair<int, int> > q;
    q.push(make_pair(start, 0));
    while(!q.empty()){
        int curr = q.front().first; int v = q.front().second; q.pop();
        if(curr == end){
            val[end] = min(val[end], v);
        }

        for(int i = 0; i < v3[curr].size(); i++){
            int next = v3[curr][i];
            if(route[curr][next] == curr){
                if(val[end] == MAX){
                    //val[next] = val[curr] + m[curr][next];
                    //visited[curr][next] = 1;
                    q.push(make_pair(next, v + m[curr][next]));

                    if(trap[next] == 1){
                        for(int j = 0; j < v3[next].size(); j++){
                            int nnext = v3[next][j];
                        
                            if(route[next][nnext] == next){ 
                                route[next][nnext] = nnext;
                                route[nnext][next] = nnext;
                            }
                            else{ 
                                route[next][nnext] = next;
                                route[nnext][next] = next;
                            }
                        }
                    }
                }
            }
        }
    }

    answer = val[end];
    return answer;
}
