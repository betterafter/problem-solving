#include<iostream>

using namespace std;

int main(int argc, char** argv)
{
    int test_case;
    int T;
    cin >> T;
    for(test_case = 1; test_case <= T; ++test_case)
    {
        int num[10];
        int mx = 0;
        int mn = 1000000;
        for(int i = 0; i < 10; i++){
            cin >> num[i];
        }
        for(int i = 0; i < 10; i++){
            int tmp = 0;
            while(num[i] > 0){
                tmp += num[i] % 10;
                num[i] /= 10;
            }
            
            mx = max(mx, tmp);
            mn = min(mn, tmp);
        }
        cout << "#" << test_case << " " << mx << " " << mn << '\n';
    }
    return 0;
}
