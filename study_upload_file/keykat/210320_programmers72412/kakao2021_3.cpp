#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int> infoTable[4][3][3][3];

// java, cpp, backend... 등을 인덱스화하여 infoTable에 넣어주기 위한 변환 메서드
int language(string str){
    if(str == "java") return 0;
    else if(str == "python") return 1;
    else if(str == "cpp") return 2;
    else return 3;
}

int skill(string str){
    if(str == "backend") return 0;
    else if(str == "frontend") return 1;
    else return 2;
}

int career(string str){
    if(str == "junior") return 0;
    else if(str == "senior") return 1;
    else return 2;
}

int  food(string str){
    if(str == "pizza") return 0;
    else if(str == "chicken") return 1;
    else return 2;
}


// lower_bound를 사용해 이분탐색을 하기 위한 메서드
int getCount(vector<int> v, int point){
    if(v.size() == 0) return 0;
    else return (int)v.size() - (lower_bound(v.begin(), v.end(), point) - v.begin());
}


// query 파싱
vector<string> parser(string q){
    string temp = "";
    vector<string> res;

    while(true){
        string parse = " and ";
        string temp = q.substr(0, q.find(parse));
        res.push_back(temp);
        if(q.find(parse) == -1) break;
        q = q.substr(q.find(parse) + parse.length());
    }   
    string div = res[res.size() - 1];
    res.pop_back(); res.push_back(div.substr(0, q.find(" "))); res.push_back(div.substr(q.find(" ") + 1));

    return res;
}

// info 파싱
vector<string> info_parser(string q){
    string temp = "";
    vector<string> res;

    while(true){
        string parse = " ";
        string temp = q.substr(0, q.find(parse));
        res.push_back(temp);
        if(q.find(parse) == -1) break;
        q = q.substr(q.find(parse) + parse.length());
    }   
    return res;
}

vector<int> solution(vector<string> info, vector<string> query) {
    vector<int> answer;
    int res[100000] = { 0, };

    for(int i = 0; i < info.size(); i++){
        string q = info[i];
        vector<string> data;
        data = info_parser(q);

        // infoTable에 지원자 점수 저장
        infoTable[ language(data[0]) ][ skill(data[1]) ][ career(data[2]) ][ food(data[3]) ].push_back(atoi(data[4].c_str()));
    }

    // 이분탐색을 위해 넣어준 값들을 오름차순으로 정렬할 필요가 있다.
    for(int i = 0; i < 3; i++)
        for(int j = 0; j < 2; j++)
            for(int k = 0; k < 2; k++)
                for(int l = 0; l < 2; l++)
                    sort(infoTable[i][j][k][l].begin(), infoTable[i][j][k][l].end());
                

    for(int p = 0; p < query.size(); p++){
        string q = query[p];
        vector<string> data = parser(q);

        for(int i = 0; i < 3; i++){
            if(language(data[0]) == i || language(data[0]) == 3){
                for(int j = 0; j < 2; j++){
                    if(skill(data[1]) == j || skill(data[1]) == 2){
                        for(int k = 0; k < 2; k++){
                            if(career(data[2]) == k || career(data[2]) == 2){
                                for(int l = 0; l < 2; l++){
                                    if(food(data[3]) == l || food(data[3]) == 2){
                                        res[p] += getCount(infoTable[i][j][k][l], atoi(data[4].c_str()));
                                    }
                                }              
                            }
                        }
                    }  
                }
            } 
        }
    }
    for(int i = 0; i < query.size(); i++){
        answer.push_back(res[i]);
    }
    return answer;
}


