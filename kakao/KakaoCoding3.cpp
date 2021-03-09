//
//  KakaoCoding3.cpp
//  study
//
//  Created by 신기열 on 2019. 3. 20..
//  Copyright © 2019년 신기열. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <utility>
#include <cstring>
#include <map>
#include <vector>

using namespace std;

string cmp(string a, string b){
    
    if(a.length() <= b.length()){
        
        return a;
    }
    else{
        
        return b;
    }
}

int main(){
    

    vector<string> v;
    vector<pair<string, int> > strv;
    //vector<string, vector<pair<string, int> > > check;
    map<string, vector<pair<string, int> > > m;
    map<string, vector<pair<string, int> > > Notm;

    char Buffer[1000010];
    int boolbuf[10000];
    fgets(Buffer, sizeof(Buffer), stdin);
    Buffer[strlen(Buffer)-1] = '\0';
    
    int checker = 0;
    int j = 0;
    
    for(int i = 0; i < strlen(Buffer); i++){
        if(Buffer[i] == '=' && Buffer[i+1] == '='){
            boolbuf[j] = 1;
            j++;
        }
        else if(Buffer[i] == '!' && Buffer[i+1] == '='){
            boolbuf[j] = 0;
            j++;
        }
    }

    char* token = strtok(Buffer, "== && !=");

    while(token != NULL){
        
        v.push_back(token);

        token = strtok(NULL, "== && !=");
    }

 
    j = 1;
    
    if(boolbuf[0] == 0){
        Notm[v[0]].push_back(make_pair(v[1], boolbuf[0]));
    }
    else if(boolbuf[0] == 1){
        m[v[0]].push_back(make_pair(v[1], boolbuf[0]));
    }
    
    
    //값 넣어주기
    for(int i = 2; i < v.size(); i = i + 2){

        int flag = 0;

        //case 1 : key가 map에 존재하는 key
        if(m.find(v[i]) != m.end())
        {
            
            int f = 0;
            
            //같은 값이 있는지 확인
            for(int k = 0; k < m[v[i]].size(); k++){
                if(m[v[i]][k].first == v[i+1]){
                    f = 1;
                    
                    if(boolbuf[j] == 0){
                        checker = 1;
                        break;
                    }
                    
                    break;
                }
            }
            if(f == 0 && boolbuf[j] == 0){
                m[v[i]].push_back(make_pair(v[i+1], boolbuf[j]));
            }
            
            else if(f == 0 && boolbuf[j] == 1){
                m[v[i]].push_back(make_pair(v[i+1], boolbuf[j]));
            }
        }

        //case 2 : value가 map에 존재하는 key
        else if(m.find(v[i+1]) != m.end()){
            
            int f = 0;
            
            //같은 값이 있는지 확인
            for(int k = 0; k < m[v[i+1]].size(); k++){
                if(m[v[i+1]][k].first == v[i]){
                    f = 1;
                    
                    if(boolbuf[j] == 0){
                        checker = 1;
                        break;
                    }

                    break;
                }
            }
            if(f == 0 && boolbuf[j] == 1){

                m[v[i+1]].push_back(make_pair(v[i], boolbuf[j]));
            }
            
            else if(f == 0 && boolbuf[j] == 0){
                
                Notm[v[i+1]].push_back(make_pair(v[i], boolbuf[j]));
            }
        }

        //case 3 : 벡터를 뒤져서 어떤 key에 존재하는 값이고 참으로 연결되면 넣어줌
        else{
            for(int k = 1; k < i; k = k + 2){
                if(v[k] == v[i] && boolbuf[k/2] == 1 && boolbuf[j] == 1){
                    m[v[k-1]].push_back(make_pair(v[i+1], boolbuf[j]));
                    flag = 0;

                    break;
                }
                
                else if(v[k] == v[i+1] && boolbuf[k/2] == 1 && boolbuf[j] == 1){
                    m[v[k-1]].push_back(make_pair(v[i], boolbuf[j]));
                    flag = 0;

                    break;
                }
               
                else{
                    flag = 1;
                }
            }
        }

        //case 4 : 어느 key에도 존재하지 않으면 Notm에 새로 만들어줌
        if(boolbuf[j] == 0){
            
            Notm[v[i]].push_back(make_pair(v[i+1], boolbuf[j]));
        }
        //true 면 m에 넣어주고
        else if(flag == 1 && boolbuf[j] == 1){

            m[v[i]].push_back(make_pair(v[i+1], boolbuf[j]));
        }

        j++;
    }
    
    map<string, vector<pair<string, int> > >::iterator iter;

    if(checker == 0){
   
        // map = m 일때
        for(iter = m.begin(); iter != m.end(); iter++){
            
            strv = iter -> second;
            
            string str = iter -> first;
            string val = "";
            int IntCount = 0;
            
            int isIntSmaller = 0;
          
            for(int k = 0; k < strv.size(); k++){
                
                if(atoi(strv[k].first.c_str()) != 0 || strv[k].first.compare("0") == 0){
                    
                    val = strv[k].first;
                    
                    IntCount++;
                    
                    if(cmp(str, val) == val){
                        isIntSmaller = 1;
                    }
                }
                else{
                    if(strv[k].second == 1){
                        
                        str = cmp(str, strv[k].first);
                    }
                }
            }
            
            if(IntCount > 1){
                cout << "1==0";
                
                break;
            }
            
            if(isIntSmaller == 1){
                
                cout << iter -> first << "==" << val << "&&";
                
                
                for(int k = 0; k < strv.size(); k++){
                    if(strv[k].second == 1 && strv[k].first.compare(val) != 0){
                        cout << strv[k].first << "==" << val;
                        
                        if(k+1 < strv.size() || iter != --m.end()){
                            cout << "&&";
                        }
                    }
                }
            }
            
            else if(isIntSmaller == 0){

                if(str.compare(iter -> first) != 0){
                    cout << str << "==" << iter -> first << "&&";
                }
                for(int k = 0; k < strv.size(); k++){
                    if(strv[k].second == 1 && strv[k].first.compare(str) != 0){
                        cout << str << "==" << strv[k].first;
                        
                        if(k+1 < strv.size() || iter != --m.end()){
                            cout << "&&";
                        }
                    }
                }
            }
        }
    
        // map = Notm 일 때
        for(iter = Notm.begin(); iter != Notm.end(); iter++){
            
            strv = iter -> second;
            string str = iter -> first;
            
            if(!m.empty() && iter == Notm.begin()){
                cout << "&&";
            }
            
                for(int k = 0; k < strv.size(); k++){

                    if(strv[k].second == 0){
                        cout << iter -> first << "!=" << strv[k].first;
                    }
                    if(k+1 < strv.size() || iter != --Notm.end()){
                        cout << "&&";
                    }
                }
        }
    }
    
    return 0;
}
