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

string postfix_notation(string s){
    stack<char> op; string res = "";
    for(int i = 0; i < s.size(); i++){
        if(s[i] == ')'){
            while(!op.empty() && op.top() != '('){
                res += op.top(); op.pop();
            }
            op.pop();
        }
        else if(s[i] == '*' || s[i] == '/'){
            while(!op.empty() && (op.top() == '*' || op.top() == '/') && op.top() != '('){
                res += op.top(); op.pop();
            }
            op.push(s[i]);
        }
        else if(s[i] == '+' || s[i] == '-'){
            while(!op.empty() && op.top() != '('){
                res += op.top(); op.pop();
            }
            op.push(s[i]);
        }
        else if(s[i] == '('){
            op.push(s[i]);
        }
        else{
            res += s[i];
        }
    }
    while(!op.empty()){
        res += op.top(); op.pop();
    }
    return res;
}


string prefix_notation(string s){
    reverse(s.begin(), s.end());
    for(int i = 0; i < s.size(); i++){
        if(s[i] == '('){
            s[i] = ')';
        }
        else if(s[i] == ')'){
            s[i] = '(';
        }
    }
    string prefix = postfix_notation(s);
    reverse(prefix.begin(), prefix.end());
    return prefix;
}



int main(){

    ios::sync_with_stdio(false);
	cin.tie(NULL);
    cout.tie(NULL);

    string s; cin >> s;
    
    cout << prefix_notation(s) << '\n';
    cout << postfix_notation(s) << '\n';
    return 0;
}

