#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>
#include <queue>
#include <set>
#include <stack>
#include <map>
#include <limits.h>
#include <bitset>

using namespace std;
int N, M;
vector<string> word;
vector<bitset<26> > remember, tremember;

void recog(){
    remember.resize(N);
    for(int i = 0; i < word.size(); i++){
        for(int j = 0; j < word[i].size(); j++){
            remember[i][word[i][j] - 'a'] = 1;
        }
    }
    tremember = remember;
}

void print(){
    for(int i = 0; i < N; i++){
        for(int j = 0; j < 26; j++){
            cout << remember[i][j] << " ";
        }
        cout << '\n';
    }
    cout << '\n';
}

int main(){

    ios::sync_with_stdio(false);
	cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    for(int i = 0; i < N; i++){
        string w; cin >> w; word.push_back(w);

    }
    recog();

    for(int i = 0; i < M; i++){
        int o; char c; cin >> o >> c;
        int cnt = 0;
        //print();
        if(o == 1){
            for(int j = 0; j < N; j++){
                if(tremember[j][c - 'a'] == 1){
                    remember[j][c - 'a'] = 0;
                }
            }
        }
        else if(o == 2){
            for(int j = 0; j < N; j++){
                if(tremember[j][c - 'a'] == 1){
                    remember[j][c - 'a'] = 1;
                }
            }
        }
        for(int j = 0; j < N; j++){
            if(tremember[j] == remember[j]) cnt++;
        }
        cout << cnt << '\n';
    }
    
    return 0;
}

