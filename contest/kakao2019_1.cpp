//
//  kakao2018_1.cpp
//  Contest
//
//  Created by 신기열 on 24/09/2019.
//  Copyright © 2019 신기열. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

vector<string> solution(vector<string> record) {
    
    vector<string> answer;
    map<string, string> m;
    
    for(int i = 0; i < record.size(); i++){
        int j = 0;
        // 맨 앞의 문자가 C인 경우 ==> Change인 경우
        if(record[i][j] == 'C'){
            string ID = "", NAME = "";
            // C부터 공백이 나올때까지 그냥 넘긴다. 
             while(j < record[i].size()){
                while(record[i][j] != ' '){
                    j++;
                }
                // Change 다음에 공백이 나오므로 공백도 넘겨준다.
                j++;
                // Change ID 닉네임 형태이므로 ID 탐색. 
                while(record[i][j] != ' '){
                    ID += record[i][j];
                    j++;
                }
                // 마찬가지로 공백 넘기기
                j++;
                // 닉네임 탐색
                while(j != record[i].size()){
                    NAME += record[i][j];
                    j++;
                }
                // map에서 해당 ID의 값을 NAME으로 변경해준다.
                m[ID] = NAME;
            }
        }
        // 맨 앞의 문자가 E인 경우 ==> Enter인 경우
        else if(record[i][j] == 'E'){
            string ID = "", NAME = "";
            // 해당 record가 끝날 때 까지 반복
            while(j < record[i].size()){
                // Change와 알고리즘이 다를게 없는데, ID와 NAME 찾아서 map에 추가하면 된다.
                while(record[i][j] != ' '){
                    j++;
                }
                j++;
                while(record[i][j] != ' '){
                    ID += record[i][j];
                    j++;
                }
                j++;
                while(j != record[i].size()){
                    NAME += record[i][j];
                    j++;
                }
                // map[key] = value는 2가지 의미가 있는데, key가 map에 존재하면 NAME으로 변경해주고, 존재하지 않으면 추가해주는 것이다.
                // 즉 key값이 존재하지 않는다면 map.insert(make_pair(key, value))와 같은 의미가 된다.
                // 그런데 만약 해당 부분을 m.insert(make_pair(ID, NAME))으로만 썼다면 분명 틀리게 나올 것이다. (아마 한 2개정도 맞을 것이다.)
                // 문제를 잘 생각해보면, Enter는 유저가 채팅방에 들어오는 경우인데, insert를 사용한다면?
                // 해당 유저가 이전에 들어온 적이 있다면 map에 해당 유저 정보가 남아있을 것이므로 해당 유저에 대한 중복된 데이터가 생기게 될 것이다.
                // 예를 들어, (1, a), (2, b), (1, a) 순으로 Enter 했을 때 맵에도 동일한 데이터가 존재하겠지만,
                // 우리가 원하는 것은 채팅방에 있는 유저 정보 즉 (1, a), (2, b)와 같은 경우이다.
                // 따라서 중복을 아예 배제하거나, Leave할 때 map에서 해당 유저 정보를 찾아서 지워주는 식으로 만들어주면 되겠다.
                // 매우 간단한 문제인데 의외로 틀리는 사람이 있는 것 같아서 혹시나 해서 적어둔다.
                m[ID] = NAME;
            }
        }
    }

    // 채팅방에 들어오고 나가거나, 닉네임을 변경한 기록이 담긴 문자열 배열 record가 매개변수로 주어질 때, 
    // "모든 기록이 처리된 후," 최종적으로 방을 개설한 사람이 보게 되는 메시지를 문자열 배열 형태로 return 하도록 solution 함수를 완성하라.
    // 일단 key & value로 전부 저장한 다음 출력을 진행해야 한다. 실시간으로 출력하는게 아니다.
    for(int i = 0; i < record.size(); i++){

        int j = 0;
        // 위와 알고리즘은 다른게 별로 없다. Enter면 해당 ID를 찾아 들어왔다는 멘트를 출력하고, Leave면 나갔다는 멘트를 출력해주기만 하면 된다.
        // 이 때 출력문은 answer 벡터에 담아주면 된다.
        if(record[i][j] == 'E'){
            string ID = "";
            while(j < record[i].size()){
                while(record[i][j] != ' '){
                    j++;
                }
                j++;
                while(record[i][j] != ' '){
                    ID += record[i][j];
                    j++;
                }

                answer.push_back(m[ID] + "님이 들어왔습니다.");
                j = 0;
                break;
            }
        }

        else if(record[i][j] == 'L'){
            string ID = "";
            while(j < record[i].size()){
                while(record[i][j] != ' '){
                    j++;
                }
                j++;
                while(j != record[i].size()){
                    ID += record[i][j];
                    j++;
                }

                answer.push_back(m[ID] + "님이 나갔습니다.");
                j = 0;
                break;
            }
        }
    }
    
    return answer;
}

int main(){
    
    vector<string> v;
    v.push_back("Enter uid1234 Muzi");
    v.push_back("Enter uid4567 Prodo");
    v.push_back("Leave uid1234");
    v.push_back("Enter uid1234 Prodo");
    v.push_back("Change uid4567 Ryan");
    
    solution(v);
    
    for(int i = 0; i < solution(v).size(); i++){
        cout << solution(v)[i] << '\n';
    }

    return 0;
}
