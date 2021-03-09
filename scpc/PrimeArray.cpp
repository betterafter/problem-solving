#include <iostream>
#include <math.h>

using namespace std;

int Answer, mx;
int IsPrime[30001] = { 0, };



int makeInt(string s){
    
    int res = 0;
    for(int i = s.size() - 1; i >= 0; i--){
        res += (s[s.size() - 1 - i] - 48) * pow(10, i);
    }
    return res;
}


void DFS(string s, int *arr, int cnt){
    
    int t = makeInt(s);
    
    if(t == 0 || t == 1) return;
    
    if(IsPrime[t] == 1){
        arr[t] = cnt;
        mx = max(mx, arr[t]);
        
        //cout << t << " : " << arr[t] << '\n';
    }
    
    else if(IsPrime[t] == 0){
        cnt++;
        arr[t] = cnt;
        mx = max(mx, arr[t]);
        
        //cout << t << " : " << arr[t] << '\n';
        
    }
    
    for(int i = 0; i < s.size(); i++){
        string temp = s;
        int ti = makeInt(temp.erase(i, 1));
        
        //cout << "ti" << " : " << ti << " = " << IsPrime[ti] << '\n';
        
        if(IsPrime[ti] == 0) DFS(temp, arr, cnt);
    }
}


int main(int argc, char** argv)
{
    
    for(int i = 2; i < 30000; i++){
        int j = 2;
        while(i * j < 30000){
            IsPrime[i * j] = 1; j++;
        }
    }

    
    int T, test_case; cin >> T;
    for(test_case = 0; test_case  < T; test_case++)
    {
        int dpa[30001] = { 0, }, dpb[30001] = { 0, };
        int cnt = 0;
        int maxA = 0, maxB = 0;
        string A, B; cin >> A >> B;
        
        if(IsPrime[makeInt(A)] == 1) maxA = 0;
        else{
            DFS(A, dpa, cnt);
            maxA = mx;
        }
        mx = 0;
        
        if(IsPrime[makeInt(B)] == 1) maxB = 0;
        else{
            DFS(B, dpb, cnt);
            maxB = mx;
        }
        mx = 0;
        

        if(maxA > maxB) Answer = 1;
        else if(maxA < maxB) Answer = 2;
        else Answer = 3;
        
        //cout << maxA << " " << maxB << '\n';

        cout << "Case #" << test_case+1 << endl;
        cout << Answer << endl;
        

    }
    
    return 0;
}
