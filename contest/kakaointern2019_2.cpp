#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <math.h>

using namespace std;

bool isused[100001];

bool compare(vector<string> &a, vector<string> &b){
    return a.size() < b.size();
}

// 문자열로 만들어진 정수를 int로 바꿔준다.
int toInt(string s){
    int tmp = 0;
    for(int i = 0; i <s.size(); i++){
        tmp += (s[i] - '0') * pow(10, s.size() - i - 1);
    }

    return tmp;
}


vector<int> solution(string s) {
    vector<int> answer;

    for(int i = 0; i < 100001; i++){
        isused[i] = false;
    }

    // 일단 해당 문자열에서 { , } 는 필요가 없으므로 제거해서 각각 벡터에 저장해준다. 그 저장한 벡터를 한 묶음으로 취급해서 최종 벡터에 넣어준다.
    vector<vector<string>> vv;
    for(int i = 1; i < s.size() - 1; i++){
        // '{' 가 나오면 '}'가 나올 때 까지, 즉 원소 하나를 모두 검사할 때까지 체크해준다.
        if(s[i] == '{'){
            vector<string> tv; i++;
            while(s[i] != '}'){
                string ss = "";
                // 이 때, ',' 나 '}'가 나오기 전까지 문자열을 합쳐준다. 
                // 가령 {1,2,3} 이면 '{' 버리고 '1'을 벡터에 넣고 ',' 나왔으므로 다시 돌아가고, '2'를 다시 벡터에 넣어주고... 를 하다가 마지막에 '}'에서
                // 끊어준다. 
                while(s[i] != ',' && s[i] != '}'){
                    ss += s[i]; i++;
                }
                // ','가 나오면 인덱스를 한칸 이동시켜서 탐색한다. '}'가 나오면 해당 원소 끝이니까 인덱스를 이동할 필요가 없다.
                tv.push_back(ss); if(s[i] == ',') i++;
            }
            // 벡터 묶음을 최종 벡터에 넣어준다.
            vv.push_back(tv);
        }
    }
    // 해당 최종 벡터를 정렬해준다.
    sort(vv.begin(), vv.end(), compare);

    // 최종 벡터의 내용을 길이순으로 소팅해줬는데, 예를 들어
    // {{1,2,3},{2,1},{1,2,3,4},{2}} 를 {{2},{2,1},{1,2,3},{1,2,3,4}} 로 바꿔준 것이다.
    // 여기서 문제의 조건을 잘 보면
    /////////////////////////// 조건 //////////////////////////////////////////////////////////////////////
    // 원소의 개수가 n개이고, 중복되는 원소가 없는 튜플 (a1, a2, a3, ..., an)이 주어질 때(단, a1, a2, ..., an은 자연수), 
    // 이는 다음과 같이 집합 기호 '{', '}'를 이용해 표현할 수 있습니다.
    // {{a1}, {a1, a2}, {a1, a2, a3}, {a1, a2, a3, a4}, ... {a1, a2, a3, a4, ..., an}}
    //////////////////////////////////////////////////////////////////////////////////////////////////////
    // 이므로 위의 원소를 가지는 튜플은 {a1 = 2}, {a1 = 2, a2 = 1}, {a1 = 2, a2 = 1, a3 = 3}, {a1 = 2, a2 = 1, a3 = 3, a4 = 4} 가 된다.
    // 즉 2번째 원소에서 2는 이미 a1으로 정해졌기 때문에 a2는 자연스럽게 1이되며, 3번째 원소에서 1, 2는 사용했으므로 a3 = 3이 되는 것이다.
    for(int i = 0; i < vv.size(); i++){
        for(int j = 0; j < vv[i].size(); j++){
            if(!isused[toInt(vv[i][j])]){
                isused[toInt(vv[i][j])] = true;
                answer.push_back(toInt(vv[i][j]));
            }
        }
    }


    return answer;
}