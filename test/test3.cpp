#include <string>
#include <vector>
#include <stack>
#include <iostream>

using namespace std;

string solution(int n, int k, vector<string> cmd) {
    string answer = "";

    stack<int> s;
    char m[1000001];
    for(int i = 0; i < n; i++){
        m[i] = 'O';
    }

    int curr = n;

    for(int i = 0; i < cmd.size(); i++){
        
        if(cmd[i][0] == 'D'){
            string num = "";
            for(int j = 2; j < cmd[i].size(); j++){
                num += cmd[i][j];
            }   

            int nn = atoi(num.c_str());
            
            int res = nn % curr;
            if(res > curr - k - 1){
                k = res - (curr - k - 1) - 1;
            }
            else k = k + res;
        }

        else if(cmd[i][0] == 'C'){
            m[k] = 'X';
            s.push(k);
            if(k == curr){
                k = 0; 
            }

            curr--;
        }

        else if(cmd[i][0] == 'U'){
            string num = "";
            for(int j = 2; j < cmd[i].size(); j++){
                num += cmd[i][j];
            }   

            int nn = atoi(num.c_str());

            int res = nn % curr;
            if(res > k + 1){
                k = curr - (res - k - 1) - 1;
            }
            else k = k - res;
        }

        else if(cmd[i][0] == 'Z'){
            int last = s.top();
            s.pop();
            m[last] = 'O';
            curr++;
        }
    }

    for(int i = 0; i < n; i++){
        answer += m[i];
    }


    return answer;
}