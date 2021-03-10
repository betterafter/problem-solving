#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <math.h>
#include <algorithm>


using namespace std;

// 만들어진 세트메뉴를 몇명의 사람이 원하는지 저장하는 map
map<string, int> m;

// res[i][1] : 길이가 i인 세트메뉴를 원하는 손님의 최대 수
// 가령 abc를 2명, bcd를 3명, cde를 4명 원한다면, res[3][0] = 4가 되며,
// ab를 3명, bc를 2명, bcd를 4명, cde를 3명, cdef를 5명 원한다면 res[2][0] = 3, res[3][0] = 4, res[4][0] = 5가 됨
int res[11][1];


// curr : 현재까지 탐색한 index, clength : 현재까지의 길이, tlength : 만들고자 하는 세트 메뉴의 길이, orders : 현재 탐색 중인 주문, order : 만들어진 세트 메뉴
void dfs(int curr, int clength, int tlength, string orders, string order){

    // order를 알파벳 오름차순으로 정렬
    sort(order.begin(), order.end());

    // clength = tlength : 하나의 세트 메뉴 완성
    if(clength == tlength){
        // 맵을 돌면서 해당 세트 메뉴를 만든 적이 있다면 +1 하고, 없으면 1로 저장
        map<string, int> :: iterator iter;
        for(iter = m.begin(); iter != m.end(); iter++){
            if(iter -> first == order){
                m[iter -> first]++;
                return;
            }
        }
        m[order] = 1; return;
    }

    // ABCD라는 주문을 놓고 생각했을 때, 만들어질 수 있는 경우의 수는 AB, AC, AD, ABC, ABD, ACD, BCD, ABCD가 된다. 
    // dfs 함수의 curr 변수는 이를 위한 것이므로,
    // curr = 0일 때 탐색을 시작하면 현재의 order는 A, B, C, D 중 하나가 되며, 다음 dfs 때 curr = curr + 1가 되고 2번째 index인 B부터 탐색하기 시작하는 것

    // 즉 curr = 0 : A, B, C, D 중에서 선택하고 dfs
    // curr = 1 : curr = 0일 때 선택한 것이 
    // A이면 --> AB, AC, AD 중에서 선택하고 dfs
    // B이면 --> BC, BD 중에서 선택하고 dfs
    // C이면 --> CD 를 선택하고 dfs
    // D이면 끝

    // curr = 2 : curr = 1일 때 선택한 것이 
    // AB이면 --> ABC, ABD
    // AC이면 --> ACD
    // ...
    for(int i = curr; i < orders.size(); i++){
        order += orders[i];
        dfs(i + 1, clength + 1, tlength, orders, order);
        order = order.substr(0, order.length() - 1);
    }

}


vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;

    // 세트 메뉴의 길이가 course[i]이고, 손님이 주문한 orders[j]를 뽑아 dfs 돌리기
    for(int i = 0; i < course.size(); i++){
        for(int j = 0; j < orders.size(); j++){
            dfs(0, 0, course[i], orders[j], "");
        }
    }

    // 맵을 돌면서 위에서 설명한 res배열 업데이트
    map<string, int> :: iterator iter;
    for(iter = m.begin(); iter != m.end(); iter++){
        res[(iter -> first).length()][0] = max(res[(iter -> first).length()][0], iter -> second);
    }

    // map을 다시 돌면서 res랑 같은 value를 가진 map을 뽑아내기 (대신 2보다 작은 것들은 포함하지 않음)
    for(iter = m.begin(); iter != m.end(); iter++){
        if(iter -> second == res[(iter -> first).length()][0]){
            if(iter -> second >= 2){
                answer.push_back(iter -> first);
            }
        }
    }

    return answer;
}