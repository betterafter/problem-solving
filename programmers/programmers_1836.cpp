#include <string>
#include <vector>
#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

// 리틀프렌즈사천성


string del(int x1, int y1, int x2, int y2, int m, int n, vector<string> board){

    string res = "";
    int x = x1, y = y1;
    

    while(y1 < m){
        if(board[y1][x1] != '.' && board[y1][x1] != board[y][x]) break;
        if(y1 == y2 && x1 == x2){
            res += board[y][x];
            return res;
        }
        if(y1 == y2){
            while(x1 < n){
                if(board[y1][x1] != '.' && board[y1][x1] != board[y][x]) break;
                if(y1 == y2 && x1 == x2){
                res += board[y][x];
                return res;
                }
                x1++;
            }
            x1 = x;
            while(x1 >= 0){
                if(board[y1][x1] != '.' && board[y1][x1] != board[y][x]) break;
                if(y1 == y2 && x1 == x2){
                res += board[y][x];
                return res;
                }
                x1--;
            }
        }

        y1++;
    }
    y1 = y;
    while(y1 >= 0){
        if(board[y1][x1] != '.' && board[y1][x1] != board[y][x]) break;
        if(y1 == y2 && x1 == x2){
            res += board[y][x];
            return res;
        }
        if(y1 == y2){
            while(x1 < n){
                if(board[y1][x1] != '.' && board[y1][x1] != board[y][x]) break;
                if(y1 == y2 && x1 == x2){
                res += board[y][x];
                return res;
                }
                x1++;
            }
            x1 = x;
            while(x1 >= 0){
                if(board[y1][x1] != '.' && board[y1][x1] != board[y][x]) break;
                if(y1 == y2 && x1 == x2){
                res += board[y][x];
                return res;
                }
                x1--;
            }
        }

        y1--;
    }
    return res;
}

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
string solution(int m, int n, vector<string> board) {
    string answer = "";

    int cnt = 0;
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(board[i][j] != '.' && board[i][j] != '*'){
                cnt++;
            }
        }
    }
    cnt /= 2;


    while(answer.length() < cnt){

        string temp = "";
        int tx1, ty1, tx2, ty2;

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){

                if(board[i][j] != '.' && board[i][j] != '*'){

                    int x1 = 0, y1 = 0;

                    for(int y = 0; y < m; y++){
                        for(int x = 0; x < n; x++){
                            if(board[y][x] == board[i][j] && (y != i || x != j)){
                                x1 = x; y1 = y; break;
                            }
                        }
                    }

                    string c = del(j, i, x1, y1, m, n, board);
                    if(c != ""){
                        if(temp == ""){
                            temp = c;
                            tx1 = j; ty1 = i; tx2 = x1; ty2 = y1;
                        }
                        else{
                            if(temp > c){
                                temp = c;
                                tx1 = j; ty1 = i; tx2 = x1; ty2 = y1;
                            }
                        }
                    }
                }
            }
        }

        if(temp != ""){
            board[ty1][tx1] = '.';
            board[ty2][tx2] = '.';
        }

        if(temp == ""){ 
            if(answer.length() != cnt)
                return "IMPOSSIBLE";
        }
        answer += temp;
    }



    return answer;
}
