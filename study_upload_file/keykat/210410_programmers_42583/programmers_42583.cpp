#include <string>
#include <vector>
#include <math.h>
#include <queue>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    int curr_weight = 0;
    int curr_idx = 0;

    queue<pair<int, int> > q; q.push(make_pair(truck_weights[curr_idx], 1)); 
    answer++; curr_weight += truck_weights[curr_idx]; curr_idx++; 

    while(!q.empty()){
        answer++;
        int w = q.front().first, t = q.front().second; 
        if(answer - t == bridge_length){ 
            q.pop();
            curr_weight -= w;
        }

        if(curr_idx < truck_weights.size() && curr_weight + truck_weights[curr_idx] <= weight){ 
            q.push(make_pair(truck_weights[curr_idx], answer));
            curr_weight += truck_weights[curr_idx];
            curr_idx++;
        }
    }


    return answer;
}