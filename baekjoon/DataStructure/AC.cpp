//
//  AC.cpp
//  test
//
//  Created by 신기열 on 11/06/2019.
//  Copyright © 2019 신기열. All rights reserved.
//
#include <stdio.h>
#include <iostream>
#include <deque>
#include <algorithm>
#include <string>

using namespace std;

int main(){
    
    int T;
    cin >> T;
    
    for(int test = 0; test < T; test++){
        
        string func, seq;
        cin >> func;
        
        int count, flag = 0, Isreverse = 0;
        deque<string> store;
        cin >> count;
        cin >> seq;
        
        for(int i = 0; i < seq.size(); i++){
            if(seq[i] != ',' && seq[i] != '[' && seq[i] != ']'){
                string temp;
                while(seq[i] != ',' && seq[i] != ']'){
                    temp += seq[i];
                    i++;
                }
                store.push_back(temp);
            }
        }
        
        for(int i = 0; i < func.size(); i++){

            if(func[i] == 'R'){
                if(!store.empty()){
                    if(Isreverse == 1) Isreverse = 0;
                    else if(Isreverse == 0) Isreverse = 1;
                    //reverse(store.begin(), store.end());
                }
            }
            
            else if(func[i] == 'D'){
                if(!store.empty()){
                    if(Isreverse == 1) store.pop_back();
                    else if(Isreverse == 0) store.pop_front();
                }
                else{ flag = 1; break; }
            }
        }
        
        if(Isreverse == 1) reverse(store.begin(), store.end());
        
        if(flag == 1){
            cout << "error" << '\n';
        }
        else{
            cout << "[";
            deque<string>::iterator iter;
            for(iter = store.begin(); iter != store.end();){
                cout << *iter;
                iter++;
                if(iter != store.end()) cout << ",";
            }
            cout << "]" << '\n';
        }
    }
    
    return 0;
}
