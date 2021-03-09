#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>
#include <queue>
#include <set>
#include <stack>

using namespace std;

int s[21];

void add(int x){
    s[x] = 1;
}

void remove(int x){
    s[x] = 0;
}

bool check(int x){
    if(s[x] == 1) return true;
    return false;
}

void toggle(int x){
    if(s[x] == 1) s[x] = 0;
    else s[x] = 1;
}

void all(){
    for(int i = 1; i <= 20; i++){
        s[i] = 1;
    }
}

void empty(){
    for(int i = 1; i <= 20; i++){
        s[i] = 0;
    }
}

int main(){

    ios::sync_with_stdio(false);
	cin.tie(NULL);

    int M; cin >> M;
    for(int i = 0; i < M; i++){
        string ss; cin >> ss;
        if(ss == "add"){
            int t; cin >> t;
            add(t);
        }
        else if(ss == "remove"){
            int t; cin >> t;
            remove(t);
        }
        else if(ss == "check"){
            int t; cin >> t;
            cout << check(t) << '\n';

        }
        else if(ss == "toggle"){
            int t; cin >> t;
            toggle(t);
        }
        else if(ss == "all"){
            all();
        }
        else if(ss == "empty"){
            empty();
        }
    }

    
    return 0;
}
