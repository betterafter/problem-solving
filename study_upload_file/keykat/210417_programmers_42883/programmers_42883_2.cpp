#include <string>
#include <vector>

using namespace std;

int MAX = 0;


void dfs(int curr, int k, string number, vector<int> v, int visited[]){

    if(v.size() == k){
        int chk[20] = { 0, };
        for(int i = 0; i < v.size(); i++){
            chk[v[i]] = 1;
        }

        string res = "";
        for(int i = 0; i < number.length(); i++){
            if(chk[i] == 0) res += number[i];
        }

        if(atoi(res.c_str()) > MAX){
            MAX = atoi(res.c_str());
        }
        return;
    }

    int d;
    if(curr == 0) d = 0;
    else d = curr + 1;
    for(int i = d; i < number.length(); i++){
        if(visited[i] == 0){
            v.push_back(i);
            visited[i] = 1;
            dfs(i, k, number, v, visited);
            v.pop_back();
            visited[i] = 0;
        }
    }
}

string solution(string number, int k) {
    string answer = "";

    int visited[10000] = { 0, };
    vector<int> v;

    dfs(0, k, number, v, visited);
    
    answer = to_string(MAX);
    return answer;
}