#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>
#include <queue>
#include <set>
#include <stack>

using namespace std;

vector<string> v;

bool check(char c){
    if(c == 'A' ||c == 'B' || c == 'C' || c == 'D' || c == 'E' || c == 'F' || c == 'G' || c == 'H' || c == 'I' ||
    c == 'J' || c == 'K' || c == 'L' || c == 'M' || c == 'N' || c == 'O' || c == 'P' || c == 'Q' || c == 'R' ||
    c == 'S' || c == 'T' || c == 'U' || c == 'V' || c == 'W' || c == 'X' || c == 'Y' || c == 'Z'){
        return true;
    }
    return false;
}

class trienode{
    public :
    char ch;
    trienode *parent;
    vector<pair<trienode*, int> > child;
    trienode(char ch) : ch(ch){}
};

class trie{
    public :
    trienode *rootnode;
    trie() : rootnode(new trienode('\0')){};

    public : 
    void insert(string word, int num){
        int i = 0; 
        trienode *currnode = rootnode;
        while(i < word.size()){
            bool check = false; int idx;
            for(int j = 0; j < currnode -> child.size(); j++){
                if(currnode -> child[j].first -> ch == word[i]){
                    check = true; idx = j; break;
                }
            }
            if(!check) break;
            else{
                if(i == word.size() - 1){
                    currnode -> child[currnode -> child.size() - 1].second = num;
                }
                currnode = currnode -> child[idx].first;
            } 
            
            i++;
        }

        while(i < word.size()){
            currnode -> child.push_back(make_pair(new trienode(word[i]), -1));
            if(i == word.size() - 1){
                currnode -> child[currnode -> child.size() - 1].second = num;
            }
            currnode = currnode -> child[currnode -> child.size() - 1].first;
            i++;
        }
    }

    public:
    int find(string word){
        trienode *currnode = rootnode;
        int i = 0; int num = 0;
        while(i < word.size()){
            int idx;
            for(int j = 0; j < currnode -> child.size(); j++){
                if(currnode -> child[j].first -> ch == word[i]){
                    idx = j; num = currnode -> child[j].second; break;
                }
            }
            currnode = currnode -> child[idx].first;
            i++;
        }
        return num;
    }
};

int main(){

    ios::sync_with_stdio(false);
	cin.tie(NULL);
    
    int N, M; cin >> N >> M;
    trie *tri = new trie;
    for(int i = 1; i <= N; i++){
        string s; cin >> s;
        tri -> insert(s, i);
        v.push_back(s);
    }
    for(int i = 0 ; i < M; i++){
        string s; cin >> s;
        if(check(s[0])){
            cout << tri -> find(s) << '\n';
        }
        else cout << v[atoi(s.c_str()) - 1] << '\n';
    }

    
    return 0;
}
