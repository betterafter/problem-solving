#include <string>
#include <vector>
#include <stack>
#include <iostream>

using namespace std;

pair<vector<long long>, vector<char> > mul(pair<vector<long long>, vector<char> > a){

    vector<long long> n = a.first; 
    vector<char> op = a.second;

    vector<long long> resi;
    vector<char> resc;

    resi.push_back(n[0]);

    for(int i = 0; i < op.size(); i++){
        if(op[i] == '*'){
            long long left = resi[resi.size() - 1];
            resi.pop_back();

            long long right = n[i + 1];

            resi.push_back(left * right);
        }
        else{
            resi.push_back(n[i + 1]);
            resc.push_back(op[i]);
        }
    }
    //     for(int i = 0; i < resi.size(); i++){
    //     cout << resi[i] << " ";
    // }
    // cout << '\n';
    return make_pair(resi, resc);
}

pair<vector<long long>, vector<char> > add(pair<vector<long long>, vector<char> > a){

    vector<long long> n = a.first; 
    vector<char> op = a.second;

    vector<long long> resi;
    vector<char> resc;

    resi.push_back(n[0]);

    for(int i = 0; i < op.size(); i++){
        if(op[i] == '+'){
            long long left = resi[resi.size() - 1];
            resi.pop_back();

            long long right = n[i + 1];

            resi.push_back(left + right);
        }
        else{
            resi.push_back(n[i + 1]);
            resc.push_back(op[i]);
        }
    }

    //     for(int i = 0; i < resi.size(); i++){
    //     cout << resi[i] << " ";
    // }
    // cout << '\n';
    return make_pair(resi, resc);
}

pair<vector<long long>, vector<char> > min(pair<vector<long long>, vector<char> > a){

    vector<long long> n = a.first; 
    vector<char> op = a.second;

    vector<long long> resi;
    vector<char> resc;

    resi.push_back(n[0]);

    for(int i = 0; i < op.size(); i++){
        if(op[i] == '-'){
            long long left = resi[resi.size() - 1];
            resi.pop_back();

            long long right = n[i + 1];

            resi.push_back(left - right);
        }
        else{
            resi.push_back(n[i + 1]);
            resc.push_back(op[i]);
        }
    }

    // for(int i = 0; i < resi.size(); i++){
    //     cout << resi[i] << " ";
    // }
    // cout << '\n';
    return make_pair(resi, resc);
}



pair<vector<long long>, vector<char> > init(string expression){

    vector<long long> resi;
    vector<char> resc;

    string temp = "";
    for(int i = 0; i < expression.size(); i++){
        if(expression[i] == '+' || expression[i] == '-' || expression[i] == '*'){
            resi.push_back(stoi(temp));
            resc.push_back(expression[i]);

            temp = "";
        }
        else{
            temp += expression[i];
        }
    }
    resi.push_back(stoi(temp));
    return make_pair(resi, resc);
}

long long res(pair<vector<int>, vector<char> > a){
    
    if(a.second[0] == '+'){
        return a.first[0] + a.first[1];
    }
    else if(a.second[0] == '-'){
        return a.first[0] - a.first[1];
    }
    else{
        return a.first[0] * a.first[1];
    }
}

long long max(long long a, long long b){
    if(a < b) return b;
    else return a;
}


long long solution(string expression) {
    long long answer = 0;

    answer = max(answer, abs(min(add(mul(init(expression)))).first[0]));
    answer = max(answer, abs(min(mul(add(init(expression)))).first[0]));

    answer = max(answer, abs(mul(min(add(init(expression)))).first[0]));
    answer = max(answer, abs(mul(add(min(init(expression)))).first[0]));

    answer = max(answer, abs(add(mul(min(init(expression)))).first[0]));
    answer = max(answer, abs(add(min(mul(init(expression)))).first[0]));




    // cout << addFirst(minFirst(mulFirst(expression))) << '\n';
    // cout << addFirst(mulFirst(minFirst(expression))) << '\n';

    // cout << minFirst(addFirst(mulFirst(expression))) << '\n';
    // cout << minFirst(mulFirst(addFirst(expression))) << '\n';

    // cout << mulFirst(addFirst(minFirst(expression))) << '\n';
    // cout << mulFirst(minFirst(addFirst(expression))) << '\n';



    return answer;
}

int main(){

    cout << solution("50*6-3*2");

    return 0;
}