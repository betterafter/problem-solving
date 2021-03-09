#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>
#include <queue>
#include <set>
#include <stack>

using namespace std;

bool check(vector<char> v){
    int sl = 0, bl = 0;
    stack<char> s;
    for(int i = 0; i < v.size(); i++){

        if(v[i] == '(' || v[i] == '['){
            s.push(v[i]);
        }
        else if(v[i] == ')'){
            if(s.size() > 0 && s.top() == '(') s.pop();
            else return false;
        }
        else if(v[i] == ']'){
            if(s.size() > 0 && s.top() == '[') s.pop();
            else return false;
        }
    }
    if(s.size() > 0) return false;
    return true;
}


int main(){

    int i = 1;
    while(true){
        // 1.
        string s; getline(cin, s);

        // 2.
        //char ss[100]; cin.getline(ss, 100);

        if(s[0] == '.') break;
        vector<char> v;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '[' || s[i] == ']' || s[i] == '(' || s[i] == ')'){
                v.push_back(s[i]);
            }
        }

        if(check(v)) cout << "yes" << '\n';
        else cout << "no" << '\n';
        cin.clear();
    }
    
    return 0;
}
