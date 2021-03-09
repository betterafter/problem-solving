//
//  PickNumber.cpp
//  SCPC
//
//  Created by 신기열 on 02/06/2019.
//  Copyright © 2019 신기열. All rights reserved.
//

/*
 You should use the statndard input/output
 
 in order to receive a score properly.
 
 Do not use file input and output
 
 Please be very careful.
 */

#include <iostream>
#include <map>

using namespace std;

int Answer;

int main(int argc, char** argv)
{
    int T, test_case;

    cin >> T;
    for(test_case = 0; test_case  < T; test_case++)
    {
        map<int, int> m;
        Answer = 0;
        
        int N;
        cin >> N;
        
        for(int i = 0; i < N; i++){
            int n;
            cin >> n;
            
            if(m.find(n) == m.end()){
                m.insert(make_pair(n, 1));
            }
            else{
                m[n]++;
            }
            //cout << ":" << m[n] << '\n';
        }
        
        map<int, int>:: iterator iter;
        for(iter = m.begin(); iter != m.end(); iter++){
            if((iter -> second) % 2 != 0){
                //cout << iter -> first << '\n';
                Answer ^= (iter -> first);
            }
        }
        
        
        cout << "Case #" << test_case+1 << endl;
        cout << Answer << endl;
    }
    
    return 0;//Your program should return 0 on normal termination.
}
