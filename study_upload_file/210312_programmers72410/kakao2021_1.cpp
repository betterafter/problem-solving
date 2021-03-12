#include <iostream>
#include <string>
#include <vector>

using namespace std;

string solution(string new_id) {
    string answer = "";


    // 1단계 new_id의 모든 대문자를 대응되는 소문자로 치환합니다.
    for(int i = 0; i < new_id.length(); i++){
        new_id[i] = tolower(new_id[i]);
    }



    // 2단계 new_id에서 알파벳 소문자, 숫자, 빼기(-), 밑줄(_), 마침표(.)를 제외한 모든 문자를 제거합니다.
    string step1 = "";
    for(int i = 0; i < new_id.length(); i++){
        // a~z, '.', '-', '_', 0~9인 것들만 step1에 붙인다.
        if((new_id[i] >= 'a' && new_id[i] <= 'z') || new_id[i] == '.' || new_id[i] == '-' || new_id[i] == '_' 
        || (new_id[i] >= '0' && new_id[i] <= '9')){
            step1 += new_id[i];
        }
    }



    // 3단계 new_id에서 마침표(.)가 2번 이상 연속된 부분을 하나의 마침표(.)로 치환합니다.
    string step2 = ""; step2 += step1[0];
    for(int i = 1; i < step1.length(); i++){
        // 현재 탐색 중인 index의 캐릭터가 '.'이 아닌 것들은 step2에 전부 붙이기
        if(step1[i] != '.'){
            step2 += step1[i];
        }
        // 현재 탐색 중인 index의 캐릭터가 '.'일 때, 이전 index의 캐릭터가 '.'이 아닐 때만 step2에 붙이기
        else if(step1[i] == '.'){
            if(step1[i - 1] != '.'){
                step2 += step1[i];
            }
        }
    }


    // 4단계 new_id에서 마침표(.)가 처음이나 끝에 위치한다면 제거합니다.  
    string step3 = "";
    // step2의 0번 index (처음)의 캐릭터가 '.'이 아니면 step3에 붙이기
    if(step2[0] != '.'){
        step3 += step2[0];
    }
    // step2의 1번부터 마지막 이전 index까지 step3에 붙이기
    for(int i = 1; i < step2.length() - 1; i++){
        step3 += step2[i];
    }
    // step3의 마지막 index의 캐릭터가 '.'이 아니면 step3에 붙이기
    if(step2[step2.length() - 1] != '.'){
        step3 += step2[step2.length() - 1];
    }


    // 5단계 new_id가 빈 문자열이라면, new_id에 "a"를 대입합니다.
    string step4 = "";
    if(step3.length() <= 0){
        step4 = "a";
    }
    else step4 = step3;



    // 6단계 new_id의 길이가 16자 이상이면, new_id의 첫 15개의 문자를 제외한 나머지 문자들을 모두 제거합니다.
    // 만약 제거 후 마침표(.)가 new_id의 끝에 위치한다면 끝에 위치한 마침표(.) 문자를 제거합니다.
    string step5 = "";
    // 16자 이상이면 15개까지만 step5에 붙이기
    if(step4.length() >= 16){
        for(int i = 0; i < 15; i++){
            step5 += step4[i];
        }
        // 이 때 마지막이 '.'이면 마지막도 잘라버리기
        if(step5[14] == '.'){
            step5 = step5.substr(0, 14);
        }
    }
    else step5 = step4;



    // 7단계 new_id의 길이가 2자 이하라면, new_id의 마지막 문자를 new_id의 길이가 3이 될 때까지 반복해서 끝에 붙입니다.
    string step6 = "";
    if(step5.length() <= 2){
        // 현재까지 만들어진 new_id의 길이가 2자 이하이면 일단 step6에 new_id를 복사하기
        for(int i = 0; i < step5.length(); i++){
            step6 += step5[i];
        }
        // 그리고 3이 될 때까지 마지막 캐릭터 붙이기
        while(step6.length() < 3){
            step6 += step5[step5.length() - 1];
        }
    }
    else step6 = step5;




    answer = step6;
    return answer;
}
