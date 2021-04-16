#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;


// 큰 수 만들기

string solution(string number, int k) {
    string answer = "";

    int prev = -1;
    int next = k + 1;

    while(next <= number.length()){
        int MAX = 0;
        
        for(int i = prev + 1; i < next; i++){
            //cout << number[i] << " ";
            if(MAX < number[i]){
                MAX = number[i]; prev = i;
            }
        }
        //cout << '\n';
        k--; answer += number[prev]; next++;
        //cout << answer << '\n';
    }


    return answer;
}

int main(int argc, char const *argv[])
{
    cout << solution("1000000", 3);

    return 0;
}
