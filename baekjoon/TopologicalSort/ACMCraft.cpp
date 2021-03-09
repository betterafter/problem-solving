//
//  ACMCraft.cpp
//  test
//
//  Created by 신기열 on 12/05/2019.
//  Copyright © 2019 신기열. All rights reserved.
//
//
#include <cstdio>
#include <iostream>
#include <list>
#include <queue>
#include <algorithm>

using namespace std;

int main(){

    int n;
    cin >> n;
    int result[n];

    for(int i = 0; i < n; i++){

        int N, K, finalBuilding, time[1000], buildOrder[1000] = { 0 };
        list<int> building[1000];
        cin >> N >> K;
        for(int j = 0; j < N; j++){
            cin >> time[j];
        }
        for(int j = 0; j < K; j++){
            int n1, n2;
            cin >> n1 >> n2;
            building[n1 - 1].push_back(n2 - 1);
            buildOrder[n2 - 1]++;
        }
        cin >> finalBuilding;

        int dtime[1000] = { 0 };
        queue<int> q;
        for(int j = 0; j < N; j++)
            if(!buildOrder[j]) q.push(j);
        
        while(buildOrder[finalBuilding - 1] > 0){
            if(!q.empty()){
                int b = q.front();
                q.pop();
                
                list<int> :: iterator iter;
                for(iter = building[b].begin(); iter != building[b].end(); ++iter){
                    dtime[*iter] = max(dtime[*iter], dtime[b] + time[b]);
                    if(--buildOrder[*iter] == 0){ q.push(*iter); }
                }
            }
            else { break; }
        }
        result[i] = dtime[finalBuilding - 1] + time[finalBuilding - 1];
        for(int j = 0; j < 1000; j++){
            building[j].clear();
        }
    }

    for(int i = 0; i < n; i++){
        cout << result[i] << '\n';
    }
}
