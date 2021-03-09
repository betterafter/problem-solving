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

string s, b, res = "", res2 = "";
stack<char> st;
stack<string> resstack;

// void Pop_Stick(){
//     string tmp = "";
//     while(!st.empty()){
//         tmp = st.top() + tmp; 
//         st.pop();
//     }
//     res = res + tmp;
// }

// void check1(){
//     for(int i = 0; i < s.size(); i++){
//         // 닫는 문자
//         if(s[i] == b[b.size() - 1]){
//             st.push(s[i]);

//             if(st.size() < b.size()){
//                 Pop_Stick();
//             }
//             else{
//                 string tmp = ""; bool chk = true;
//                 for(int k = b.size() - 1; k >= 0; k--){
//                     tmp = st.top() + tmp; 
//                     if(st.top() != b[k]) chk = false;
//                     st.pop();
//                 }
//                 if(!chk){
//                     res = res + tmp;
//                     Pop_Stick();
//                 }
//             }
//         }
//         else{
//             bool in = false;
//             for(int j = 0; j < b.size(); j++){
//                 if(s[i] == b[j]){
//                     st.push(s[i]); in = true; break;
//                 }
//             }
//             if(!in){
//                 Pop_Stick(); res += s[i];
//             }
//         }
//     }
//     Pop_Stick();
// }

void check2(){

    for(int i = 0; i < s.size(); i++){
        res2 += s[i];
        if(res2.size() >= b.size() && s[i] == b[b.size() - 1]){
            bool chk = true;
            for(int j = 0; j < b.size(); j++){
                if(res2[res2.size() - 1 - j] != b[b.size() - 1 - j]){
                    chk = false; break;
                }
            }
            if(chk){
                for(int j = 0; j < b.size(); j++){
                    res2.pop_back();
                }
            }
        }
    }
}




int main(){
    
    ios::sync_with_stdio(false);
	cin.tie(NULL);
    cout.tie(NULL);
    
     cin >> s >> b;

    check2();    

    if(res2 == "") cout << "FRULA";
    else cout << res2;
    return 0;
}
    
    

