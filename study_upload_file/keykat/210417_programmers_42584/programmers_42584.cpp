#include <string>
#include <vector>
#include <stack>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer;

    int res[100010] = { 0, };
    stack<pair<int, int> > s;

    for(int i = 0; i < prices.size(); i++){
        int price = prices[i];
        while(!s.empty()){
            if(s.top().first > price){
                res[s.top().second] = i - s.top().second; 
                s.pop();
            }
            else break;
        }
        s.push(make_pair(price, i));
    }

    while(!s.empty()){
        res[s.top().second] = prices.size() - s.top().second - 1;
        s.pop();
    }

    for(int i = 0; i < prices.size(); i++){
        answer.push_back(res[i]);
    }
    return answer;
}