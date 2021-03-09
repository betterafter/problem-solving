#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>
#include <queue>
#include <set>
#include <stack>

using namespace std;

multiset<long long> ms;

void insert(long long x){
    ms.insert(x);
}

void delete1(){
    if(ms.size() > 0) ms.erase(--ms.end());
}

void delete2(){
    if(ms.size() > 0) ms.erase(ms.begin());
}

int main(){

    ios::sync_with_stdio(false);
	cin.tie(NULL);
    cout.tie(NULL);

    int T; cin >> T;
    for(int i = 0; i < T; i++){
        ms.clear();
        int N; cin >> N;
        for(int i = 0; i < N; i++){
            char c; cin >> c;
            if(c == 'I'){
                long long t; cin >> t;
                insert(t);
            }
            else if(c == 'D'){
                long long t; cin >> t;
                if(t == 1){
                    delete1();
                }
                else if(t == -1){
                    delete2();
                }
            }
        }

        if(ms.size() == 0) cout << "EMPTY" << '\n';
        else cout << *--ms.end() << " " << *ms.begin() << '\n';
    }


    
    
    return 0;
}
