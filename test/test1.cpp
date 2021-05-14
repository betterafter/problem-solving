#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;


map<string, char> m;


int solution(string s) {
    int answer = 0;

    string ans = "";

    m["zero"] = '0';
    m["one"] = '1';
    m["two"] = '2';
    m["three"] = '3';
    m["four"] = '4';
    m["five"] = '5';
    m["six"] = '6';
    m["seven"] = '7';
    m["eight"] = '8';
    m["nine"] = '9';



    string temp = "";
    for(int i = 0; i < s.size(); i++){
        if(s[i] == '0' || s[i] == '1' || s[i] == '2' || s[i] == '3' || s[i] == '4' || s[i] == '5' ||
        s[i] == '6' || s[i] == '7' || s[i] == '8' || s[i] == '9'){
            ans += s[i]; continue;
        }
        temp += s[i];
        if(m.find(temp) != m.end()){
            ans = ans + m[temp];
            temp = "";
        }

    }

    answer = atoi(ans.c_str());
    return answer;
}