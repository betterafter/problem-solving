#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <math.h>
#include <algorithm>


using namespace std;

map<string, int> m;
int res[11][1];

void dfs(int curr, int clength, int tlength, string orders, string order){

    sort(order.begin(), order.end());

    if(clength == tlength){

        map<string, int> :: iterator iter;
        for(iter = m.begin(); iter != m.end(); iter++){
            if(iter -> first == order){
                m[iter -> first]++;
                return;
            }
        }
        m[order] = 1; return;
    }

    for(int i = curr; i < orders.size(); i++){
        order += orders[i];
        dfs(i + 1, clength + 1, tlength, orders, order);
        order = order.substr(0, order.length() - 1);
    }

}


vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;

    for(int i = 0; i < course.size(); i++){
        for(int j = 0; j < orders.size(); j++){
            dfs(0, 0, course[i], orders[j], "");
        }
    }


    map<string, int> :: iterator iter;
    for(iter = m.begin(); iter != m.end(); iter++){
        res[(iter -> first).length()][0] = max(res[(iter -> first).length()][0], iter -> second);
    }

    // for(int i = 0; i < 10; i++){
    //     cout << res[i][0] << " ";
    // }

    for(iter = m.begin(); iter != m.end(); iter++){
        if(iter -> second == res[(iter -> first).length()][0]){
            if(iter -> second >= 2){
                answer.push_back(iter -> first);
            }
        }
    }

    // for(int i = 0; i < answer.size(); i++){
    //     cout << answer[i] << " ";
    // }

    // for(iter = m.begin(); iter != m.end(); iter++){
    //     cout << iter -> first << "     " << iter -> second << '\n';
    // }

    return answer;
}