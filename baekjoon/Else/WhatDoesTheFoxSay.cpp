//
//  WhatDoesTheFoxSay.cpp
//  test
//
//  Created by 신기열 on 13/06/2019.
//  Copyright © 2019 신기열. All rights reserved.
//
#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(){

    int T;
    cin >> T;
    cin.ignore();
    
    for(int test = 0; test < T; test++){
        int flag = 0;
        string s;
        
        getline(cin, s);
        vector<string> v;
        vector<string> others;
        vector<string> fox;
        //cout << s << '\n' << s.size() << '\n' << s[s.size()] << '\n';
        string temp;
        for(int i = 0; i <= s.size(); i++){
            
            if(s[i] != ' ' && i != s.size()){ temp += s[i]; }
            else if(s[i] == ' ' || i == s.size()){
                //cout << '\n' << i << '\n';
                others.push_back(temp);
                //cout << '\n' << temp << '\n';
                temp = "";
            }
        }

        while(1){

            string animal, does, howl;
            cin >> animal;

            if(animal.compare("what") == 0){
                string ignore;
                getline(cin , ignore);

                break;
            }
            else cin >> does >> howl;
            cin.ignore();
            v.push_back(howl);
        }

        
        for(int i = 0; i < others.size(); i++){
            for(int j = 0; j < v.size(); j++){
                if(others[i].compare(v[j]) == 0){
                    flag = 1; break;
                }
            }

            if(flag == 0) fox.push_back(others[i]);
            flag = 0;
        }

        for(int i = 0; i < fox.size(); i++){
            cout << fox[i];
            if(i != fox.size() - 1) cout << " ";
        }
        cout << '\n';
    }

    
    return 0;
}



//6
//toot woof wa ow ow ow pa blub blub pa toot pa blub pa pa ow pow toot
//dog goes woof
//fish goes blub
//elephant goes toot
//seal goes ow
//what does the fox say?
//to to tete ee erw re erw ee to to ee
//dog goes to
//fish goes tete
//seal goes ee
//what does the fox say?
//qwe qwe qwe aa sss dd qwe sd as ds as ds
//dog goes qwe
//what does the fox say?
//toot woof wa ow ow ow pa blub blub pa toot pa blub pa pa ow pow toot
//dog goes woof
//fish goes blub
//elephant goes toot
//seal goes ow
//what does the fox say?
//to to tete ee erw re erw ee to to ee
//dog goes to
//fish goes tete
//seal goes ee
//what does the fox say?
//qwe qwe qwe aa sss dd qwe sd as ds as ds
//dog goes qwe
//what does the fox say?

// cin을 쓰면 항상 '\n'가 들어간다. 생각해서 맨처음에 정수 받은 후에 ignore로 비워주자. getline으로 전체 울음소리를 받으면 마지막에도 '\n'가 저장된다. 이것도 고려해서 울음소리를 분리해서 저장해주자. 그 다음부터는 생각한대로.
