//
//  FrogJump.cpp
//  SCPC
//
//  Created by 신기열 on 16/05/2019.
//  Copyright © 2019 신기열. All rights reserved.
//

/*
 You should use the statndard input/output
 
 in order to receive a score properly.
 
 Do not use file input and output
 
 Please be very careful.
 */

#include <iostream>
#include <queue>

using namespace std;

int Answer;

int main(int argc, char** argv)
{
    int T, test_case;
    /*
     The freopen function below opens input.txt file in read only mode, and afterward,
     the program will read from input.txt file instead of standard(keyboard) input.
     To test your program, you may save input data in input.txt file,
     and use freopen function to read from the file when using cin function.
     You may remove the comment symbols(//) in the below statement and use it.
     Use #include<cstdio> or #include <stdio.h> to use the function in your program.
     But before submission, you must remove the freopen function or rewrite comment symbols(//).
     */
    
    // freopen("input.txt", "r", stdin);
    
    cin >> T;
    for(test_case = 0; test_case  < T; test_case++)
    {
        
        Answer = 0; queue<int> q; int N, K, curr = 0, chk = 0, temp = 0;
        /////////////////////////////////////////////////////////////////////////////////////////////
        cin >> N;
        for(int i = 0; i < N; i++){
            int t;
            cin >> t;
            q.push(t);
        }
        
        cin >> K;
        
        while(!q.empty()){
 
            if(q.front() <= curr + K){
                temp = q.front(); q.pop(); chk++;
                if(q.empty()){
                    Answer++; break;
                }
            }
            else if(q.front() > curr + K || q.empty()){
                if(chk == 0){
                    Answer = -1; break;
                }
                else{
                    chk = 0; curr = temp; Answer++;
                }
            }
        }
        
        /////////////////////////////////////////////////////////////////////////////////////////////
        
        // Print the answer to standard output(screen).
        cout << "Case #" << test_case+1 << endl;
        cout << Answer << endl;
    }
    
    return 0;//Your program should return 0 on normal termination.
}
