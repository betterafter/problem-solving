#include <string>
#include <vector>
#include <iostream>
#include <set>
#include <queue>

using namespace std;

int answer = 0;
vector<vector<bool>> uv;


// 해당 알고리즘은 아래와 같이 작동한다.
// 1. 일단 모든 릴레이션의 속성을 전부 사용해서 해당 '속성그룹'이 후보키가 되는지 확인한다.
// 2. 후보키가 된다면 해당 '속성그룹'을 '사용' 으로 표시 (uv 벡터에 담기)
// 3. 처음 속성부터 마지막 속성 중에 한개를 선택해서 지운 '속성그룹'이 후보키가 되는지 재귀적으로 확인.

// ex) attribute a, b, c가 있을 때
// (a, b, c) 확인 -> 후보키이면 :: (재귀) a 지우고 (b, c) 확인 -> 후보키이면 :: (재귀) b 지우고 (c) 확인
// 다시 돌아와서 b 지우고 (a, c) 확인 -> 후보키이면 :: a 지우고 (c) 확인
// 재귀가 뭔지 안다면 이렇게만 적어도 이해할 수 있다고 생각한다... 아마도


// 해당 키 쌍이 사용된 적이 있는지 체크 (중복 체크)
bool isUsed(bool key[8]){

    for(int i = 0; i < uv.size(); i++){
        for(int j = 0; j < 8; j++){
            if(uv[i][j] == key[j]){
                if(j == 7){
                    return true;
                }
            }
            else break;
        }
    }
    return false;
}


// 즉 이런 경우이다.
// attribute     A          B         C
// data1         1          2         2
// data2         1          2         3
// data3         1          2         2
// data4         1          3         3
// 에서 data1 과 같은 내용을 담는 컬럼을 찾는 것이다. 위에서 data1 과 data3은 내용이 같으므로 후보키가 될 수 없다.
bool iscandidate(vector<vector<string>> v, bool isKey[8]){
    // i : 비교 기준 v의 원소 벡터
    for(int i = 0; i < v.size(); i++){
        bool iscorrect = false;
        // j : 비교 대상 v의 원소 벡터
        for(int j = 0; j < v.size(); j++){
            // 탐색 대상 컬럼이 자기 자신일 경우는 빼준다.
            if(i != j){
                // 일단 탐색대상과 기준 컬럼의 데이터가 일치한다고 가정하자.
                bool c = true;
                // 모든 속성에 대해서 탐색
                for(int k = 0; k < v[0].size(); k++){ 
                    // 해당 속성이 제외되지 않았으며 기준 속성의 데이터와 탐색 속성의 데이터가 같지 않다면 현재까지는 후보키라는 얘기다.
                    if(isKey[k] && v[j][k] != v[i][k]){
                        c = false;
                    }
                }
                // 현재의 탐색대상 컬럼과의 비교에서 일치하지 않는다면 c = false로 내려왔을테고, 일치한다면 c = true로 그대로 내려왔을 것이다.  
                if(c) iscorrect = true;
            }
            // 만약 iscorrect가 true가 된다면, 일치하는 데이터가 있다는 뜻이므로 후보키가 될 수 없다.
            if(iscorrect){
                return false;
            }
        }
    }
    // 위의 for문에서 한번도 걸러지지 않았다면 후보키라는 얘기다.
    return true;
}



// 후보키가 될 수 있는지 체크를 재귀적으로 표현한 함수. 매개변수 v는 릴레이션을, isKey는 해당 속성이 지워진 속성인지 담은 데이터
void check(vector<vector<string>> v, bool isKey[8]){

    // 해당 속성이 지워져있는지, 안 지워졌는지 체크
    int undelete = 0;
    for(int i = 0; i < v[0].size(); i++){
        if(isKey[i]) undelete++;
    }
    // 다 지워지고 컬럼이 한개 남으면 단독 후보키 취급, 즉 속성 1개짜리 후보키를 말하는 것
    if(undelete == 1){
        // 해당 릴레이션에 속성그룹에 대하여 후보키이면서,
        if(iscandidate(v, isKey)){
            // 해당키가 사용된 적이 없으면,
            if(!isUsed(isKey)){
                vector<bool> tmp;
                for(int i = 0; i < 8; i++){
                    // 해당 '속성그룹' 내용을
                    tmp.push_back(isKey[i]);
                }
                // uv에 넣어준다. (중복 체크를 위한 과정)
                uv.push_back(tmp);
                // 후보키이므로 answer + 1
                answer++; return;
            }
        }
    }
    // 단독 후보키가 아닐 때
    // 지금 isKey 형태가 후보키가 될 수 있을 때 :: 현재 가지고 있는 컬럼 중 하나씩 지워보면서 다시 되면 재귀, 전부 안되면 최소 후보키
    int thiscandidate = true;
    for(int i = 0; i < v[0].size(); i++){
        // 특정 속성에 대하여 하나씩 속성그룹에서 제외하면서 최소성을 찾아본다.
        // 해당 속성이 제외되지 않았으면
        if(isKey[i]){
            // 일단 지워서
            isKey[i] = false;
            // 지우고 난 후의 속성그룹이 후보키인지 체크하고 
            if(iscandidate(v, isKey)){
                // 후보키이면 재귀. 
                // 이 때 속성그룹에서 속성 하나를 지웠을 때 속성이 1개만 남거나, 최소성을 만족해서 밑에 if문으로 진입하기 전까지 재귀를 돌리는 것.
                // 여기에 걸친다는 것은 아직 최소성을 만족하지 않았다는 것.
                thiscandidate = false;
                check(v, isKey);
            }
            // 다시 복구
            isKey[i] = true;
        }
    }
    
    // 최소성을 체크하는 과정인데, 위에서 for문으로 속성 하나를 지웠을 때 후보키가 된다면, 현재 속성그룹은 최소성을 만족하지 못하기 때문에 후보키가 될 수 없는 것이다.
    // 따라서 위의 for문에서 걸러지지 않은 현재의 속성그룹은 최소성을 만족하는 것이다.
    // 여기서 위에처럼 answer + 1 해주고 사용에 체크를 해주면 되겠다.
    if(thiscandidate){
        if(!isUsed(isKey)){
                vector<bool> tmp;
                for(int i = 0; i < 8; i++){
                    tmp.push_back(isKey[i]);
                }
                uv.push_back(tmp);
                answer++; return;
            }
    }
}

int solution(vector<vector<string>> relation) {
    
    int vSize = relation.size();
    bool isKey[8]; 
    for(int i = 0; i < relation[0].size(); i++){
        isKey[i] = true;
    }

    check(relation, isKey);
    return answer;
}