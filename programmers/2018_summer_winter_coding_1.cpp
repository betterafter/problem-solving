
// 문제 이름 : 스킬트리

#include <string>
#include <vector>
#include <map>

using namespace std;


int solution(string skill, vector<string> skill_trees) {
    int answer = 0;
    map<char, int> m;

    for(int i = 0; i < skill.length(); i++){
        m[skill[i]] = 1;
    }

    for(int i = 0; i < skill_trees.size(); i++){
        string curr_skill = skill_trees[i];
        string make_skill = "";
        for(int j = 0; j < curr_skill.length(); j++){
            if(m[curr_skill[j]] == 1){
                make_skill += curr_skill[j];
            }
        }
        bool match = true;
        for(int j = 0; j < make_skill.length(); j++){
            if(make_skill[j] == skill[j]) continue;
            else{
                match = false; break;
            }
        }
        if(match) answer++;
        
    }

    return answer;
}