#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int solution(vector<int> priorities, int location) {

    int answer = 0;
    int priority[10] = { 0, };

    queue<pair<int, int> > q;
    for(int i = 0; i < priorities.size(); i++){
        q.push(make_pair(i, priorities[i]));
        priority[priorities[i]]++;
    }

    while(!q.empty()){
        int order = q.front().first, prio = q.front().second; q.pop();
        bool isExist = false;
        for(int i = prio + 1; i < 10; i++){
            if(priority[i] > 0){
                isExist = true; break;
            }
        }
        if(isExist) q.push(make_pair(order, prio));
        else{
            priority[prio]--;
            if(order == location){
                answer = priorities.size() - q.size(); break;
            }
        }
    }


    return answer;
}

// int main(int argc, char const *argv[])
// {
//     vector<int> v;
//     v.push_back(2);
//     v.push_back(1);
//     v.push_back(3);
//     v.push_back(2);

//     solution(v, 1);
//     return 0;
// }
