#include <stdio.h>
#include<iostream>

using namespace std;

int main(int argc, char** argv)
{
    int test_case;
    int T;
    
    cin>>T;
    
    for(test_case = 1; test_case <= T; ++test_case)
    {
        int ans = 0;
        int N, B, E;
        cin >> N >> B >> E;
        int watch[N];
        for(int i = 0; i < N; i++){
            cin >> watch[i];
        }
        for(int i = 0; i < N; i++){
            int j = 0;
            while(watch[i] * j < B - E){
                j++;
            }
            if(watch[i] * j >= B - E && watch[i] * j <= B + E){
                ans++;
            }
        }
        
        
        cout << "#" << test_case << " " << ans << '\n';
    }
    return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
