#include <string>
#include <vector>
#include <math.h>
#include <iostream>

using namespace std;


// a a a a a a 
// b         d
// b         d
// b         d
// c c c c c c

int mini = 10000000000;
vector<int> answer;

vector<vector<int> > rotation(vector<vector<int> > queries, int x1, int y1, int x2, int y2){

    mini = 10000000000;
    vector<vector<int> > res = queries;
    // 위쪽 테두리
    for(int i = x1 + 1; i <= x2; i++){
        res[y1][i] = queries[y1][i - 1];
        mini = min(res[y1][i], mini);
    }
    // 오른쪽 테두리
    for(int i = y1 + 1; i <= y2; i++){
        res[i][x2] = queries[i - 1][x2];
        mini = min(res[i][x2], mini);
    }
    // 아래쪽 테두리
    for(int i = x2 - 1; i >= x1; i--){
        res[y2][i] = queries[y2][i + 1];
        mini = min(res[y2][i], mini);
    }
    // 왼쪽 테두리
    for(int i = y2 - 1; i >= y1; i--){
        res[i][x1] = queries[i + 1][x1];
        mini = min(res[i][x1], mini);
    }
    answer.push_back(mini);
    return res;
}

vector<int> solution(int rows, int columns, vector<vector<int> > queries) {

    vector<vector<int> > table;
    for(int i = 0; i < 101; i++){
        vector<int> v(101);
        table.push_back(v);
    }

    for(int i = 1; i <= rows; i++){
        for(int j = 1; j <= columns; j++){
            table[i][j] = (i - 1) * columns + j;
        }
    }
    
    for(int i = 0; i < queries.size(); i++){
        table = rotation(table, queries[i][1], queries[i][0], queries[i][3], queries[i][2]);
    }

    
    return answer;
}
