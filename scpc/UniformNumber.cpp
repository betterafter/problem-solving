//
//  UniformNumber.cpp
//  SCPC
//
//  Created by 신기열 on 17/05/2019.
//  Copyright © 2019 신기열. All rights reserved.
//

/*
 You should use the statndard input/output
 
 in order to receive a score properly.
 
 Do not use file input and output
 
 Please be very careful.
 */

#include <iostream>
#include <math.h>
#include <time.h>

using namespace std;

int Answer;

int main(int argc, char** argv)
{
    
    //clock_t begin, end;
    //begin = clock();
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
        
        Answer = 0; 
        /////////////////////////////////////////////////////////////////////////////////////////////
        long long N;
        cin >> N;
        
        int i = 2, flag = 0;
        //cout << tempN;
        while(i * i <= N){
            
            int U = N % i; long long n = N;
            while(n > i){
                if(n % i != U){ break; }
                if(n / i == n % i){ Answer = i; flag = 1; break;}
                n = n / i;
                //cout << i << " " << n << '\n';
            }

            if(flag == 1) break;
            i++;
        }
        
        if(Answer == 0){
            int i = 1;;
            while(i * i <= N){
                
                long long n = N, b = 0;
          
                if(n % i == 0) b = n / i - 1;
                if(b > i){ Answer = b; }
                i++;
            }
        }
        
        if(Answer == 0){
            Answer = N + 1;
        }

        /////////////////////////////////////////////////////////////////////////////////////////////
        
        // Print the answer to standard output(screen).
        cout << "Case #" << test_case+1 << endl;
        cout << Answer << endl;
    }
    //end = clock();
    //cout << (double)(end - begin) << '\n';
    return 0;//Your program should return 0 on normal termination.
}
