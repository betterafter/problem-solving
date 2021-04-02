#include <string>
#include <iostream>
#include <vector>
#include <set>

using namespace std;

char n[10];
set<int> nn;

bool isPrime(int n){
    if(n == 0 || n == 1) return false;
    if(n == 2) return true;
    for(int i = 2; i * i <= n; i++){
        if(n % i == 0) return false;
    }
    return true;
}

void dfs(int length, int maxLength, int visited[], string number){
    if(number.length() == length){
        int nnn = atoi(number.c_str());
        if(isPrime(nnn)){
            nn.insert(nnn);
        }
        return;
    }

    for(int i = 0; i < maxLength; i++){
        if(visited[i] == 0){
            visited[i] = 1;
            dfs(length, maxLength, visited, number + n[i]);
            visited[i] = 0;
        }
    }
}


int solution(string numbers) {
    int answer = 0;
    int visited[10] = { 0, };
    
    for(int i = 0; i < numbers.length(); i++){
        n[i] = numbers[i];
    }

    for(int i = 1; i <= numbers.length(); i++){
        dfs(i, numbers.length(), visited, "");
    }

    answer = nn.size();
    return answer;
}

int main(){

    solution("321");
}