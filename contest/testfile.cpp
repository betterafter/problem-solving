#include <string>
#include <vector>
#include <deque>
#include <iostream>
#include <queue>

using namespace std;

vector<vector<int> > lawm(200010);
vector<vector<int> > res2(200010);
bool orderCheck[200010] = { false, };
bool inorder[200010] = { false, };


bool findCycle(int curr, int goal){

    //cout << "curr : " << curr << " " << "goal : " << goal << '\n';
    if(curr == goal) return true;
    if(inorder[curr] && !orderCheck[curr]) return false;

    for(int i = 0; i < res2[curr].size(); i++){
        //cout << "child : " << res2[curr][i] << " "; 
            //cout << "    searching..." << '\n';
        if(findCycle(res2[curr][i], goal)) return true;
        
    }
    return false;
}


bool find(vector<vector<int> > order){

    deque<pair<int, int> > dq;
    for(int i = 0; i < order.size(); i++){
        dq.push_back(make_pair(order[i][0], order[i][1]));
    }

    while(!dq.empty()){

        int size = dq.size();
        for(int i = 0; i < size; i++){

            pair<int, int> p = dq.back();
            dq.pop_back();

            if(findCycle(0, p.first)){
                orderCheck[p.first] = true;
                if(findCycle(0, p.second)){
                    orderCheck[p.second] = true;
                    //cout << p.first << " , " << p.second << "is cycle" << '\n';
                }
                else{
                    //cout << p.first << " , " << p.second << "is not cycle" << '\n';
                    orderCheck[p.first] = false;
                    dq.push_front(p);
                }
            }
            else dq.push_front(p);
        }
        if(size == dq.size()) return false;
    }
    return true;
}


void make_tree(int largest){

    //cout << "0" << '\n';
    queue<pair<int, int> > q;
    for(int i = 0; i < lawm[0].size(); i++){
        q.push(make_pair(lawm[0][i], 0));
        res2[0].push_back(lawm[0][i]);
        //cout << lawm[0][i] << " ";
    }
   // cout << '\n';

    while(!q.empty()){
        int parent = q.front().second;
        int curr = q.front().first;
        q.pop();

        for(int i = 0; i < lawm[curr].size(); i++){
            if(lawm[curr][i] != parent){
                res2[curr].push_back(lawm[curr][i]);
                q.push(make_pair(lawm[curr][i], curr));
                //cout << lawm[curr][i] << " ";
            }
            //cout << "   ";
        }
        //cout << '\n';
    }
}

bool solution(int n, vector<vector<int> > path, vector<vector<int> > order) {

    for(int i = 0; i < n; i++){
        inorder[i] = false;
        orderCheck[i] = false;
    }


    for(int i = 0; i < path.size(); i++){
        int front = path[i][0];
        int back = path[i][1];

        lawm[front].push_back(back);
        lawm[back].push_back(front);
    }

    for(int i = 0; i < order.size(); i++){
        inorder[order[i][0]] = true;
        inorder[order[i][1]] = true;
    }

//     for(int i = 0; i < n; i++){
//         cout << inorder[i] << " ";
//     }
//     cout << '\n';

//  for(int i = 0; i < n; i++){
//         cout << orderCheck[i] << " ";
//     }
//     cout << '\n';


    make_tree(n - 1);

    return find(order);
}

// int main(){

//     const int ps = 5;
//     const int os = 2;

//     int path[ps][2] = {
//         {0,1},{1,2},{2,3},{3,4},{4,5}
//     };

//     int order[os][2] = {
//         {1,3},{5,0}
//     };

//     vector<vector<int> > pv(ps, vector<int>(2, 0)), ov(os, vector<int>(2, 0));

//     for(int i = 0; i < ps; i++){
//         for(int j = 0; j < 2; j++){
//             pv[i][j] = path[i][j];
//         }
//     }

//      for(int i = 0; i < os; i++){
//         for(int j = 0; j < 2; j++){
//             ov[i][j] = order[i][j];
//         }
//     }
//     if(solution(11, pv, ov)) cout << "true";
//     else cout << "false";

//     return 0;
// }