#include <iostream>
#include <string>
#include <vector>

using namespace std;

string solution(string new_id) {
    string answer = "";

    for(int i = 0; i < new_id.length(); i++){
        new_id[i] = tolower(new_id[i]);
    }

    string step1 = "";
    for(int i = 0; i < new_id.length(); i++){
        if((new_id[i] >= 'a' && new_id[i] <= 'z') || new_id[i] == '.' || new_id[i] == '-' || new_id[i] == '_' 
        || (new_id[i] >= '0' && new_id[i] <= '9')){
            step1 += new_id[i];
        }
    }

    string step2 = ""; step2 += step1[0];
    for(int i = 1; i < step1.length(); i++){
        
        if(step1[i] != '.'){
            step2 += step1[i];
        }

        else if(step1[i] == '.'){
            if(step1[i - 1] != '.'){
                step2 += step1[i];
            }
        }
    }

    string step3 = "";
    if(step2[0] != '.'){
        step3 += step2[0];
    }
    for(int i = 1; i < step2.length() - 1; i++){
        step3 += step2[i];
    }
    if(step2[step2.length() - 1] != '.'){
        step3 += step2[step2.length() - 1];
    }

    string step4 = "";
    if(step3.length() <= 0){
        step4 = "a";
    }
    else step4 = step3;

    string step5 = "";
    if(step4.length() >= 16){
        for(int i = 0; i < 15; i++){
            step5 += step4[i];
        }

        if(step5[14] == '.'){
            step5 = step5.substr(0, 14);
        }
    }
    else step5 = step4;

    string step6 = "";
    if(step5.length() <= 2){
        for(int i = 0; i < step5.length(); i++){
            step6 += step5[i];
        }
        while(step6.length() < 3){
            step6 += step5[step5.length() - 1];
        }
    }
    else step6 = step5;

    answer = step6;
    return answer;
}
