#include<iostream>
#include <math.h>

using namespace std;

int main(int argc, char** argv)
{
    int test_case;
    int T;

    cin>>T;

    for(test_case = 1; test_case <= T; ++test_case)
    {
        int CurrUpper = 0, CurrLower = 0;
        char dir[20];
        string s;
        
        cin >> s;
        
        int i = 0, j = 0;
        while(i < s.size()){
            if(s[i] == 'n'){
                i += 5;
                dir[j] = 'n';
                j++;
            }
            else if(s[i] == 'w'){
                i += 4;
                dir[j] = 'w';
                j++;
            }
        }

        if(dir[j - 1] == 'n') { CurrUpper = 0; CurrLower = 1; }
        else if(dir[j - 1] == 'w') { CurrUpper = 90; CurrLower = 1; }
        
        for(int i = j - 2; i >= 0; i--){
            
            CurrUpper *= 2;
            CurrLower *= 2;
            
            if(dir[i] == 'n'){
                CurrUpper = CurrUpper - 90;
            }
            else if(dir[i] == 'w'){
                CurrUpper = CurrUpper + 90;
            }
        }

        while(CurrUpper % 2 == 0 && CurrLower != 1){
            CurrUpper = CurrUpper / 2;
            CurrLower = CurrLower / 2;
        }
        
        if(CurrUpper % CurrLower == 0) cout << "#" << test_case << " " << CurrUpper / CurrLower << '\n';
        else cout << "#" << test_case << " " << CurrUpper << "/" << CurrLower << '\n';
    }
    return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
