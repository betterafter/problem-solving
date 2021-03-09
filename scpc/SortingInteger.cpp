/*
 You should use the statndard input/output
 
 in order to receive a score properly.
 
 Do not use file input and output
 
 Please be very careful.
 */

#include <iostream>
#include <algorithm>

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
        int n[10001] = { 0, }, N;
        Answer = 0;
        cin >> N;
        
        for(int i = 1; i <= N; i++){
            cin >> n[i];
        }

        sort(n + 1, n + N + 1);
//        for(int i = 1; i <= N; i++){
//            cout << n[i] << " ";
//        }
        
        for(int i = 1; i <= N; i++){
            
            if(i % 2 != 0){
                Answer += n[i];
            }
            else if(i % 2 == 0){
                Answer -= n[i];
            }
            //cout << Answer << " ";
        }
        
        
        cout << "Case #" << test_case+1 << endl;
        cout << Answer << endl;
    }
    
    return 0;//Your program should return 0 on normal termination.
}
