#include <string>
#include <stdlib.h>
#include <vector>
#include <iostream>

using namespace std;

int res = 0;
char c[8] = {'A','C','F','J','M','N','R','T'};
vector<vector<char> > orders;


bool cond(vector<char> order, vector<string> data){
    
    for(int i = 0; i < data.size(); i++){
        char p1 = data[i][0];
        char p2 = data[i][2];
        char c = data[i][3];
        int len = data[i][4] - '0';
        
        int pi1 = -1, pi2 = -1;
        
        for(int j = 0; j < order.size(); j++){
            if(order[j] == p1) pi1 = j;
            if(order[j] == p2) pi2 = j;
        }
        
        if(c == '>'){
            if(abs(pi1 - pi2) - 1 > len) continue;
            else return false;
        }
        else if(c == '<'){
            if(abs(pi1 - pi2) - 1 < len) continue;
            else return false;
        }
        else{
            if(abs(pi1 - pi2) - 1 == len) continue;
            else return false;
        }
    }
    return true;
}



void dfs(vector<char> order, int visited[8], vector<string> data){
    if(order.size() == 8){
        orders.push_back(order);
        // if(cond(order, data)){
        //     res++;
        // }
        return;
    }
    
    for(int i = 0; i < 8; i++){
        if(visited[i] == 0){
            order.push_back(c[i]);
            visited[i] = 1;
            
            dfs(order, visited, data);
            
            order.pop_back();
            visited[i] = 0;
        }
    }
}

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int solution(int n, vector<string> data) {
    int answer = 0;
    
    vector<char> order;
    if(orders.size() <= 0){
        int visited[8] = {0,};
        vector<char> order;
        dfs(order, visited, data);   
    }
    for(int i = 0; i < orders.size(); i++){
        if(cond(orders[i], data)){
            res++;
        }
    }
    

    answer = res;
    res = 0;
    return answer;
}