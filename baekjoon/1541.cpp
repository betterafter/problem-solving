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

vector<int> iv;
vector<char> cv;



int main(){

    ios::sync_with_stdio(false);
	cin.tie(NULL);
    cout.tie(NULL);
    
    string s; cin >> s;
    string tmp = "";
    for(int i = 0; i < s.size(); i++){
        if(s[i] != '+' && s[i] != '-'){
            tmp += s[i];
            if(i == s.size() - 1){
                int t = atoi(tmp.c_str());
                iv.push_back(t);
          }
        }
        else{
            int t = atoi(tmp.c_str());
            iv.push_back(t);
            tmp = "";
            cv.push_back(s[i]);
        }
    }

    if(cv.size() == 0){
        cout << iv[0]; return 0;
    } 

    int i = 0; vector<int> res; int ttmp = iv[0]; int ans = 0;
    while(cv[i] == '+'){
        ttmp += iv[i + 1]; i++;
    }
    res.push_back(ttmp);
    while(i < cv.size()){
        vector<int> tmp;
        if(cv[i] == '-'){
            tmp.push_back(iv[i + 1]); i++;
            while(i < cv.size() && cv[i] == '+'){
                tmp.push_back(iv[i + 1]); i++;
            }
            int tt = 0;
            for(int i = 0; i < tmp.size(); i++){
                tt += tmp[i];
            }
            res.push_back(-tt);
        }
    }

    for(int i = 0; i < res.size(); i++){
        //cout << res[i] << " ";
        ans += res[i];
    }
    cout << ans;
    return 0;
}
