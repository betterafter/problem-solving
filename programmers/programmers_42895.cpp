#include <string>
#include <vector>
#include <math.h>
#include <queue>
#include <set>
#include <iostream>

using namespace std;

set<int> s;

int solution(int N, int number) {

    int answer = 0;
    
    for(int i = 0; i < 8; i++){
        string str = "";
        for(int j = 0; j < i; j++){
            str += to_string(N);
        }
        s.add(atoi(str));
    }

    for(int i = 0; i < s.size(); i++){
        for(int j = 0; j < i; j++){
            for(int p = )
        }
    }

    return answer;
}