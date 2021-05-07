#include <string>
#include <vector>
#include <iostream>

using namespace std;

char m1[31][31], m2[31][31];
bool isRmd = true;

void remove(int m, int n){
     for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            m2[i][j] = m1[i][j];
        }
    }
    isRmd = false;
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            char curr = m1[i][j];
            if(curr != 'x' && m1[i][j + 1] == curr && m1[i + 1][j] == curr && m1[i + 1][j + 1] == curr){
                m2[i][j] = 'x'; 
                m2[i][j + 1] = 'x'; 
                m2[i + 1][j] = 'x'; 
                m2[i + 1][j + 1] = 'x';
                isRmd = true;
            }
        }
    }
}

void down(int m, int n){
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            m1[i][j] = m2[i][j];
        }
    }
    for(int i = m - 1; i >= 0; i--){
        for(int j = 0; j < n; j++){
            if(m1[i][j] != 'x' && m1[i + 1][j] == 'x'){
                int h = i + 1;
                while(true){
                    if(m1[h][j] == 'x'){
                        h++;
                    }
                    if(h > m - 1 || m1[h][j] != 'x'){
                        h--; break;
                    }
                }
                m1[h][j] = m1[i][j]; m1[i][j] = 'x';
            }
        }
    }
}

int solution(int m, int n, vector<string> board) {
    int answer = 0;

    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            m1[i][j] = board[i][j];
            m2[i][j] = board[i][j];
        }
    }

    while(isRmd){
        remove(m, n);
        down(m, n);
    }

    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(m1[i][j] == 'x') answer++;
        }
    }


    return answer;
}