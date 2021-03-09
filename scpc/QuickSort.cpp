#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

int Answer;

int main(int argc, char** argv)
{
    int T, test_case;
    
    cin >> T;
    for(test_case = 0; test_case  < T; test_case++)
    {
        Answer = 0;
        int n; cin >> n;
        map<int, int> m;
        vector<int> v1(n), v2(n);
        int dp[n];
        
        
        for(int i = 0; i < n; i++){
            cin >> v1[i];
            v2[i] = v1[i];
        }
        
        sort(v2.begin(), v2.end());
        for(int i = 0; i < n; i++){
            m.insert(make_pair(v2[i], i));
        }
        
        if(m[v1[0]] == 0) Answer++;
        dp[0] = v1[0];
        for(int i = 1; i < n; i++){
            if(m[v1[i]] == i && dp[i - 1] < v1[i]){
                Answer++;
            }
            dp[i] = max(dp[i - 1], v1[i]);
        }
        
        cout << "Case #" << test_case+1 << endl;
        cout << Answer << endl;
    }
    
    return 0;
}

// 개수만 똑같다고 되는게 아님. 최대 최소가 제대로 있는지를 확인해야됨
