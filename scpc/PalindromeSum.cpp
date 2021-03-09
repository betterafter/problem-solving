/*
 You should use the standard input/output
 
 in order to receive a score properly.
 
 Do not use file input and output
 
 Please be very careful.
 */

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int isPalin[100001] = { 0, };
int palin[10001];
int idx = 0;


int Once(int num){
    for(int i = 0; i < idx; i++){
        for(int j = 0; j < idx; j++){
            if(palin[i] + palin[j] == num){
                cout << "2 " << palin[j] << " " << palin[i] << '\n';
                return 1;
            }
        }
    }
    return 0;
}

int Twice(int num){
    for(int i = 0; i < idx; i++){
        for(int j = 0; j < idx; j++){
            for(int k = 0; j < idx; k++){
                if(palin[i] + palin[j] + palin[k] == num){
                    cout << "3 " << palin[k] << " " << palin[j] << " " << palin[i] << '\n';
                    return 1;
                }
            }
        }
    }
    return 0;
}


int main(int argc, char** argv)
{
    int T, test_case;
    cin >> T;
    for(test_case = 0; test_case  < T; test_case++)
    {
        int num;
        cin >> num;
        
        
        for(int i = 1; i <= 9; i++){
            isPalin[i] = 1;
            palin[idx] = i;
            idx++;
        }
        
        
        for(int i = 1; i <= 9; i++){
            int p = 10 * i + i;
            isPalin[p] = 1;
            palin[idx] = p;
            idx++;
        }
        
        
        for(int i = 1; i <= 9; i++){
            for(int j = 0; j <= 9; j++){
                int p = 100 * i + j * 10 + i;
                isPalin[p] = 1;
                palin[idx] = p;
                idx++;
            }
        }
        
        
        for(int i = 1; i <= 9; i++){
            for(int j = 0; j <= 9; j++){
                int p = 1000 * i + 100 * j + 10 * j + i;
                isPalin[p] = 1;
                palin[idx] = p;
                idx++;
            }
        }
        
        if(isPalin[num] == 1){
            cout << 1 << " " << num << '\n';
        }
        
        else if(isPalin[num] == 0){
            if(Once(num) == 0 && Twice(num) == 0){
                cout << "0" << '\n';
            }
        }
        
        cout << "Case #" << test_case+1 << endl;
        //cout << Answer << endl;
    }
    
    return 0;//Your program should return 0 on normal termination.
}
