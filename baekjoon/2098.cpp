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

int m[17][17], s[17][131072];
int N, MAX = 16000000; 


int check(int curr, int start, int visited){
    if(visited == (1 << N) - 1){
        if(m[curr][start] > 0){
            return m[curr][start];
        } 
        else return MAX; 
    }
    if(s[curr][visited] > 0){
        return s[curr][visited];
    }
    s[curr][visited] = MAX;
    for(int i = 0; i < N; i++){
        if(!(visited & (1 << i))){
            if(m[curr][i] > 0){
                int next = check(i, start, visited | (1 << i));
                s[curr][visited] = min(s[curr][visited], next + m[curr][i]);
            }
        }
    }
    return s[curr][visited];
}


int main(){

    ios::sync_with_stdio(false);
	cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> m[i][j];
        }
    }
    cout << check(0, 0, 1);

    return 0;
}

