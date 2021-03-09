#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<vector<bool>> answervector;

// 이미 선택된 묶음인지 체크. 같은 선택쌍이 존재하면 answer에 추가하지 않는다.
bool isanswerused(vector<bool> used){
    for(int i = 0; i < answervector.size(); i++){
        bool correct = true;
        // 8개의 요소가 모두 같은 벡터가 존재하는지 확인해준다.
        for(int j = 0; j < 8; j++){
            if(answervector[i][j] != used[j]){
                correct = false; break;
            }
        }
        if(correct) return true;
    }
    return false;
}
// user_id : ["frodo", "fradi", "crodo", "abc123", "frodoc"]
// banned_id :["fr*d*", "*rodo", "******", "******"]
// 문제의 예시이다.
// 이 때     frodo = fr*d*  or  *rodo            fradi = fr*d*               crodo = *rodo
//          abc123 = ******   or    ******      frodoc = ******    or     ******
// 유저 아이디와 밴 아이디를 하나씩 매칭하는 알고리즘을 만들면 된다.

void pick(vector<string> user_id, vector<string> banned_id, bool used[8], bool bannedused[8]){
    // banned_id의 모든 원소들이 선택되었는지 확인
    bool allselected = true;
    for(int i = 0; i < banned_id.size(); i++){
        if(!bannedused[i]) allselected = false;
    }
    // 모두 선택되었을 때, 해당 선택묶음이 이미 사용된 것인지 체크. 
    if(allselected){
        vector<bool> tmp;
        for(int i = 0; i < 8; i++){
            tmp.push_back(used[i]);
        }
        if(!isanswerused(tmp)) answervector.push_back(tmp);
        return;
    }
    // 모든 유저 아이디에 대하여 밴 아이디 목록에 하나하나 매칭시켜본다.
    for(int i = 0; i < user_id.size(); i++){
        if(!used[i]){
            for(int j = 0; j < banned_id.size(); j++){
                // 매칭하기 위해 선택한 밴 아이디가 사용되지 않았으며, 사이즈가 같은지 체크해준다. (밴 아이디 중에 모두 *인 아이디가 있기 때문에 사이즈로 체크)
                if(!bannedused[j] && user_id[i].size() == banned_id[j].size()){
                    bool correct = true;
                    for(int k = 0; k < user_id[i].size(); k++){
                        // *은 어떤 문자도 되니까 *을 제외한 나머지 문자가 모두 같으면 매칭 가능 아이디로 판별
                        if(banned_id[j][k] != '*'){
                            if(user_id[i][k] != banned_id[j][k]){
                                correct = false; break;
                            }
                        }
                    }
                    if(correct){
                        // 매칭이 가능하면 해당 아이디를 사용으로 표시해주고 재귀를 돌려준다.
                        used[i] = true; bannedused[j] = true;
                        pick(user_id, banned_id, used, bannedused);
                        // 재귀가 끝나면 다시 미사용으로 표시해준다. (다시 for문 돌려야되니까)
                        used[i] = false; bannedused[j] = false;
                    }
                }
            }
        }
    }
}




int solution(vector<string> user_id, vector<string> banned_id) {
    int answer = 0;
    bool used[8] = { false, };
    bool bannedused[8] = { false, };

    // test case 5번
    // 제재 아이디 목록들을 구했을 때 아이디들이 나열된 순서와 관계없이 아이디 목록의 내용이 동일하다면 같은 것으로 처리하여 하나로 세면 됩니다."
    // 문제에 나와있음
    // 즉 유저 아이디 목록과 밴 아이디 목록이 길이가 같으면 그냥 모든 유저 아이디가 밴 아이디임.
    if(user_id.size() == banned_id.size()) return 1;
    pick(user_id, banned_id, used, bannedused);

    answer = answervector.size();
    return answer;
}



  