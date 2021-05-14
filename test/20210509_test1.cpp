#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(vector<string> &a, vector<string> &b){
    return a[2] < b[2];
}

vector<int> solution(string code, string day, vector<string> data) {
    vector<int> answer;

    vector<vector<string> > vv;
    for(int i = 0; i < data.size(); i++){
        string temp = "";
        vector<string> v;
        int j = 0;
        while(j < data[i].size()){
            temp += data[i][j];
            
            if(temp == "price="){
                temp = "";
                j++;
                while(true){
                    if(data[i][j] == ' '){ break; }
                    temp += data[i][j];
                    j++;
                }
                v.push_back(temp);
                temp = "";
            }

            else if(temp == "code="){
                temp = "";
                j++;
                while(true){
                    if(data[i][j] == ' '){ break; }
                    temp += data[i][j];
                    j++;
                }
                v.push_back(temp);
                temp = "";
            }

            else if(temp == "time="){
                temp = "";
                j++;
                while(true){
                    if(j == data[i].size()){ break; }
                    temp += data[i][j];
                    j++;
                }
                v.push_back(temp);
                temp = "";
            }
            j++;
        }
        vv.push_back(v);
    }

    

    sort(vv.begin(), vv.end(), compare);



    for(int i = 0; i < vv.size(); i++){
        if(vv[i][1] == code && vv[i][2].find(day) != string::npos){
            answer.push_back(atoi(vv[i][0].c_str()));
        }
    }
    

    return answer;
}