//
//  SpaceStation.cpp
//  SCPC
//
//  Created by 신기열 on 07/06/2019.
//  Copyright © 2019 신기열. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <list>
#include <queue>

using namespace std;

list<int> capsule[200001];
int removed[200001] = { 0, };


int Answer;

int main(int argc, char** argv)
{
    int T, test_case;
    cin >> T;
    for(test_case = 0; test_case  < T; test_case++)
    {

        queue<int> q;
        int N, M;
        cin >> N >> M;
        
        Answer = N;
        

        
        if(N > 2){
            for(int i = 0; i < M; i++){
                int n, m;
                cin >> n >> m;
                capsule[n].push_back(m);
                capsule[m].push_back(n);
            }
            
            for(int i = 1; i <= N; i++){
                q.push(i);
            }
            
            int cnt = 0;
            
            while(!q.empty()){
                //////////////////////////////////////////////////////////////////
                int i = q.front();
                q.pop();
                
                list<int>::iterator iter;
                for(iter = capsule[i].begin(); iter != capsule[i].end();){
                    if(removed[*iter] == 1){
                        capsule[i].erase(iter++);
                    }
                    else{
                        iter++;
                    }
                }
                
                if(capsule[i].size() == 2){
                    
                    int left = capsule[i].front(), right = capsule[i].back();
                    list<int>::iterator it1, it2;
                    
                    it1 = find(capsule[left].begin(), capsule[left].end(), right);
                    it2 = find(capsule[right].begin(), capsule[right].end(), left);
                    
                    if(it1 != capsule[left].end() && it2 != capsule[right].end()){
                        removed[i] = 1;
                        Answer--;
                        cnt = 0;
                    }
                }
                
                if(removed[i] == 0){
                    q.push(i);
                }
                
                cnt++;
                if(cnt == q.size() * 2){
                    break;
                }
            }
            /////////////////////////////////////////////////////////////////////
        }
        
        for(int i = 1; i <= N; i++){
            capsule[i].clear();
            removed[i] = 0;
        }
        
        cout << "Case #" << test_case+1 << endl;
        cout << Answer << endl;
    }
    
    return 0;
}
