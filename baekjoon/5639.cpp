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

int tree2[1000000][2];

void postorder(int root){
    
    if(tree2[root][0] != 0) postorder(tree2[root][0]);
    if(tree2[root][1] != 0) postorder(tree2[root][1]);
    
    if(root != -1) cout << root << '\n';
}


void preorder2(int curr, int root){
    if(curr > root){
        if(tree2[root][1] == 0){
            tree2[root][1] = curr; return;
        }
        else{
            preorder2(curr, tree2[root][1]);
        }
    }
    else if(curr < root){
        if(tree2[root][0] == 0){
            tree2[root][0] = curr; return;
        }
        else{
            preorder2(curr, tree2[root][0]);
        }
    }
}


int main(){

    ios::sync_with_stdio(false);
	cin.tie(NULL);
    cout.tie(NULL);

    int n, root = -1;

    while(true){
        cin >> n; 
        if(cin.eof() == 1) break;
        if(root == -1) root = n;
        else preorder2(n, root);
    }

    postorder(root);
    
    return 0;
}

