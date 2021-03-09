#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>
#include <queue>
#include <set>
#include <stack>
#include <map>

using namespace std;
long long MAX = 1000000000;

stack<long long> s;

bool NUM(long long x){
    s.push(x);
    return true;
}

bool POP(){
    if(s.empty()){
        cout << "ERROR" << '\n'; return false;
    }
    s.pop();
    return true;
}

bool INV(){
    if(s.empty()){
        cout << "ERROR" << '\n'; return false;
    }
    long long t = s.top(); 
    s.pop();  s.push(-t);
    return true;
}

bool DUP(){
    if(s.empty()){
        cout << "ERROR" << '\n'; return false;
    }
    long long t = s.top(); s.push(t);
    return true;
}

bool SWP(){
    if(s.size() < 2){
        cout << "ERROR" << '\n'; return false;
    }
    long long a = s.top(); s.pop();
    long long b = s.top(); s.pop();
    s.push(a); s.push(b);
    return true;
}

bool ADD(){
    if(s.size() < 2){
        cout << "ERROR" << '\n'; return false;
    }
    long long a = s.top(); s.pop();
    long long b = s.top(); s.pop();
    if(abs(a + b) > MAX){
        cout << "ERROR" << '\n'; return false;
    }
    s.push(a + b);
    return true;
}

bool SUB(){
    if(s.size() < 2){
        cout << "ERROR" << '\n'; return false;
    }
    long long a = s.top(); s.pop();
    long long b = s.top(); s.pop();
    if(abs(b - a) > MAX){
        cout << "ERROR" << '\n'; return false;
    }
    s.push(b - a);
    return true;
}

bool MUL(){
    if(s.size() < 2){
        cout << "ERROR" << '\n'; return false;
    }
    long long a = s.top(); s.pop();
    long long b = s.top(); s.pop();
    if(abs(b * a) > MAX){
        cout << "ERROR" << '\n'; return false;
    }
    s.push(a * b);
    return true;
}

bool DIV(){
    if(s.size() < 2){
        cout << "ERROR" << '\n'; return false;
    }
    long long a = s.top(); s.pop();
    long long b = s.top(); s.pop();
    if(a == 0){
        cout << "ERROR" << '\n'; return false;
    }
    if((a > 0 && b >= 0)){
        s.push(abs(b / a));
    }
    else if((a < 0 && b < 0)){
        s.push(abs(b / a));
    }
    else{
        s.push(-abs(b / a));
    }
    return true;
}

bool MOD(){
    if(s.size() < 2){
        cout << "ERROR" << '\n'; return false;
    }
    long long a = s.top(); s.pop();
    long long b = s.top(); s.pop();
    if(a == 0){
        cout << "ERROR" << '\n'; return false;
    }
    if(b >= 0){
        s.push(abs(b % a));
    }
    else if(b < 0){ 
        s.push(-abs(b % a));
    }
    return true;
}



void calc(vector<pair<string, int> > order){
    for(int i = 0; i < order.size(); i++){
        if(order[i].first == "NUM"){
            if(!NUM(order[i].second)) return;
        }
        else if(order[i].first == "POP"){
            if(!POP()) return;
        }
        else if(order[i].first == "INV"){
            if(!INV()) return;
        }
        else if(order[i].first == "DUP"){
            if(!DUP()) return;
        }
        else if(order[i].first == "SWP"){
            if(!SWP()) return;
        }
        else if(order[i].first == "ADD"){
            if(!ADD()) return;
        }
        else if(order[i].first == "SUB"){
            if(!SUB()) return;
        }
        else if(order[i].first == "MUL"){
            if(!MUL()) return;
        }
        else if(order[i].first == "DIV"){
            if(!DIV()) return;
        }
        else if(order[i].first == "MOD"){
            if(!MOD()) return;
        }

        if(!s.empty() && abs(s.top()) > MAX){
        cout << "ERROR" << '\n';
        while(!s.empty()){
            s.pop();
        }
        return;
        }
    }
    if(s.size() != 1) {
        cout << "ERROR" << '\n';
        while(!s.empty()){
            s.pop();
        }
        return;
    }
    
    cout << s.top() << '\n';
    s.pop();
}


int main(){

    ios::sync_with_stdio(false);
	cin.tie(NULL);
    cout.tie(NULL);

    vector<pair<string, int> > order;

    while(true){
        while(true){ 
            string s; cin >> s;
            if(s == "QUIT") return 0; 
            if(s == "END"){
                break;
            }
            else if(s == "NUM"){
                long long t; cin >> t;
                order.push_back(make_pair(s, t));
            }
            else order.push_back(make_pair(s, 0));
        }
        int N; cin >> N;
        for(int i = 0; i < N; i++){
            long long t; cin >> t; 
            s.push(t);
            calc(order);
            // 위에서 return 되는 조건에서 스택을 비우질 못한듯
            while(!s.empty()){
                s.pop();
            }
        }
        cout << '\n';
        order.clear();
        
    }

   
    return 0;
}

