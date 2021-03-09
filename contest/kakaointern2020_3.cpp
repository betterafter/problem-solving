#include <string>
#include <vector>
#include <map>
#include <math.h>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int> solution(vector<string> gems) {
    vector<int> answer;
    vector<string> temp;
    for(int i = 0; i < gems.size(); i++){
        temp.push_back(gems[i]);
    }


    map<string, int> m;
    map<string, int> gm;
    map<string, int> init;
    int left = 0, right = 0;

    sort(temp.begin(), temp.end());
    for(int i = 0; i < temp.size(); i++){
        m[temp[i]] = 0;
        init[temp[i]] = 0;
    }

    pair<int, int> ans = make_pair(100000, 10000010);
    while(left < gems.size() && right < gems.size()){

        string curr = gems[right];
        // 현재 보석이 gm 안에 없으면
        if(m[curr] == 0){
            gm[curr] = 0;
        }
        m[curr]++;
        // 이제 left ~ right 범위 안에 모든 보석이 다 들어갔다면 
        if(gm.size() == m.size()){
            while(m[gems[left]] != 1){
                m[gems[left]]--;
                left++;
            }
            if(ans.second - ans.first > right - left){
                ans = make_pair(left, right);
            }
        }
        right++;
    }
    answer.push_back(ans.first + 1);
    answer.push_back(ans.second + 1);
    return answer;
}


// int main(){

//     vector<string> gems;
//     const int size = 20;
//     string gem[size] = {
//         //"DIA", "RUBY", "RUBY", "DIA", "DIA", "EMERALD", "SAPPHIRE", "DIA"
//         //"a","a","a","a","a","a","a","a"
//         "e","a","b","c","a","b","a","c","d","e","d","a","c","e","d","b","a","b","c","d"
//     };

//     for(int i = 0; i < size; i++){
//         gems.push_back(gem[i]);
//     }

//     vector<int> answer = solution(gems);
//     cout << answer[0] << " , " << answer[1] << '\n';
//     return 0;
// }