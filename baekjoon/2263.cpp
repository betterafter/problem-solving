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

int N;
vector<int> inorder, postorder;

void check(pair<int, int> io, pair<int, int> po){


    if(po.second < po.first) return;

    int root = postorder[po.second];
    cout << root << " ";

    pair<int, int> inleft, inright;
    pair<int, int> postleft, postright;

    int i = io.first; inleft.first = i;
    while(inorder[i] != root){
        i++;
    }
    inleft.second = i - 1;
    i++;
    inright.first = i;
    inright.second = io.second;

    postleft.first = po.first;
    postleft.second = postleft.first + inleft.second - inleft.first;
    postright.first = postleft.second + 1;
    postright.second = po.second - 1;


    // cout << inleft.first << " " << inleft.second << '\n';
    // cout << inright.first << " " << inright.second << '\n';

    // cout << postleft.first << " " << postleft.second << '\n';
    // cout << postright.first << " " << postright.second << '\n';




    check(inleft, postleft);
    check(inright, postright);
}

int main(){

    ios::sync_with_stdio(false);
	cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for(int i = 0; i < N; i++){
        int a; cin >> a;
        inorder.push_back(a);
    }
    for(int i = 0; i < N; i++){
        int a; cin >> a;
        postorder.push_back(a);
    }
    check(make_pair(0, inorder.size() - 1), make_pair(0, postorder.size() - 1));
    return 0;
}

