#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>

using namespace std;

struct compare{
    bool operator()(pair<int, pair<int, int> > &a,  pair<int, pair<int, int> > &b){
        // 우선순위가 같으면
        if(a.second.second == b.second.second){

            if(a.second.first == b.second.first){
                return a.first > b.first;
            }
            else return a.second.first > b.second.first;
        }
        else return a.second.second > b.second.second;
    }
};


bool ccompare(pair<int, pair<int, int> > &a, pair<int, pair<int, int> > &b){
    return a.second.first < b.second.first;
}

vector<int> solution(vector<int> t, vector<int> r) {
    vector<int> answer;

    priority_queue<pair<int, pair<int, int> >, vector<pair<int, pair<int, int> > >, compare> pq;
    vector<pair<int, pair<int, int> > > temp;
    
    for(int i = 0; i < t.size(); i++){
        temp.push_back(make_pair(i, make_pair(t[i], r[i])));
    }

    sort(temp.begin(), temp.end(), ccompare);

    int realtime = 0;
    int time = temp[0].second.first;
    int idx = 0;
    while(idx < t.size()){

        while(temp[idx].second.first == realtime){
            int i = temp[idx].first;
            int t = temp[idx].second.first;
            int r = temp[idx].second.second;
            
            pq.push(make_pair(i, make_pair(t, r)));
            idx++;
        }

        realtime++;
        
        if(!pq.empty()){ 
            answer.push_back(pq.top().first);
            pq.pop(); 
        }
    }

    while(!pq.empty()){
        answer.push_back(pq.top().first);
        pq.pop(); 
    }



    return answer;
}