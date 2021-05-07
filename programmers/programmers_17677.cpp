#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <algorithm>
#include <math.h>
#include <set>

using namespace std;

vector<string> strv1, strv2;
map<string, int> m1, m2;
set<string> s;

vector<string> parser(string str, vector<string> strv){

    for(int i = 0; i < str.size() - 1; i++){
        string temp = "";
        char c1 = tolower(str[i]), c2 = tolower(str[i + 1]);
        if(c1 >= 'a' && c1 <= 'z' && c2 >= 'a' && c2 <= 'z'){
            temp = temp + c1 + c2;
            strv.push_back(temp);
        }
    }

    return strv;
}


int solution(string str1, string str2) {
    int answer = 0;
    double res1 = 0, res2 = 0;

    strv1 = parser(str1, strv1);
    strv2 = parser(str2, strv2);

    for(int i = 0; i < strv1.size(); i++){
        s.insert(strv1[i]);
        if(m1.find(strv1[i]) == m1.end()){
            m1[strv1[i]] = 1;
        }
        else{
            m1[strv1[i]]++;
        }
    }

    for(int i = 0; i < strv2.size(); i++){
        s.insert(strv2[i]);
        if(m2.find(strv2[i]) == m2.end()){
            m2[strv2[i]] = 1;
        }
        else{
            m2[strv2[i]]++;
        }
    }

    map<string, int> :: iterator iter;
    for(iter = m1.begin(); iter != m1.end(); iter++){
        string key = iter -> first;
        int value = iter -> second;
        bool both = false;
        map<string, int> :: iterator iter2;
        for(iter2 = m2.begin(); iter2 != m2.end(); iter2++){
            string key2 = iter2 -> first;
            int value2 = iter2 -> second;
            if(key == key2){
                res1 += max(value, value2);
                res2 += min(value, value2);
                both = true;
                break;
            }
        }
        if(!both){ 
            res1 += value;
        }
    }

    map<string, int> :: iterator iter3;
    for(iter3 = m2.begin(); iter3 != m2.end(); iter3++){
        string key = iter3 -> first;
        int value = iter3 -> second;
        bool both = false;
        map<string, int> :: iterator iter2;
        for(iter2 = m1.begin(); iter2 != m1.end(); iter2++){
            string key2 = iter2 -> first;
            int value2 = iter2 -> second;
            if(key == key2){
                both = true;
                break;
            }
        }
        if(!both){ 
            res1 += value;
        }
    }


    if(res1 == 0) answer = 1 * 65536;
    else answer = floor((res2 / res1) * 65536);
    return answer;
}