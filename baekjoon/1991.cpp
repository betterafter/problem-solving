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

map<char, pair<char, char> > m;

void preorder(char idx){
    cout << idx;
    if(m[idx].first != '.'){
        preorder(m[idx].first);
    }
    if(m[idx].second != '.'){
        preorder(m[idx].second);
    }
}

void inorder(char idx){
    if(m[idx].first != '.'){
        inorder(m[idx].first);
    }
    cout << idx;
    if(m[idx].second != '.'){
        inorder(m[idx].second);
    }
}

void postorder(char idx){
    if(m[idx].first != '.'){
        postorder(m[idx].first);
    }
    if(m[idx].second != '.'){
        postorder(m[idx].second);
    }
    cout << idx;
}

int main(){

    ios::sync_with_stdio(false);
	cin.tie(NULL);
    cout.tie(NULL);

    int N; cin >> N;
    for(int i = 0; i < N; i++){
        char a, b, c; cin >> a >> b >> c;
        m.insert(make_pair(a, make_pair(b, c)));
    }
    preorder('A');
    cout << '\n';
    inorder('A');
    cout << '\n';
    postorder('A');
    return 0;
}
