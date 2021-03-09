/*
 You should use the standard input/output
 
 in order to receive a score properly.
 
 Do not use file input and output
 
 Please be very careful.
 */

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

unsigned long long Answer;

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
        vector<unsigned long long> ability;
        priority_queue<unsigned long long, vector<unsigned long long>, greater<unsigned long long> > pq;
        Answer = 0;
        
        int N, K;
        cin >> N >> K;
        
        for(int i = 0; i < N; i++){
            int a;
            cin >> a;
            ability.push_back(a);
        }
        
        sort(ability.begin(), ability.end());
        
        pq.push(ability[0]);

        int i = 1;
        while(i < ability.size()){
            if(ability[i] - pq.top() > K){
                pq.pop();
                pq.push(ability[i]);
            }
            else if(ability[i] - pq.top() <= K){
                pq.push(ability[i]);
            }
            
            i++;
        }
        
        Answer = pq.size();
        

        cout << "Case #" << test_case+1 << endl;
        cout << Answer << endl;
    }
    
    return 0;//Your program should return 0 on normal termination.
}
