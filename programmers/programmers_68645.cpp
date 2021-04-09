#include <string>
#include <vector>
#include <iostream>

using namespace std;

int num[2000][2000];

vector<int> solution(int n) {
    vector<int> answer;
    
    if(n == 1){
        answer.push_back(1);
        return answer;
    }

    if(n == 2){
        answer.push_back(1);
        answer.push_back(2);
        answer.push_back(3);
        return answer;
    }

    for(int i = 0; i <= n; i++) for(int j = 0; j <= n; j++) num[i][j] = 0;
    for(int i = 0; i <= n + 1; i++) num[i][0] = -1;
    for(int i = 0; i <= n + 2; i++) num[n + 1][i] = -1;
    for(int i = 0; i <= n + 1; i++) num[n + 1 - i][n + 2 - i] = -1;

    int count = 1;
    int cx = 1, cy = 1; 

    while(true){

        // 밑으로 내려가기
        while(num[cy][cx] == 0){
            num[cy][cx] = count;
            count++; 
            if(num[cy + 1][cx] == 0) cy++;
        }
        cx++;
        if(num[cy][cx] != 0) break;
        // 오른쪽으로 가기
        while(num[cy][cx] == 0){
            num[cy][cx] = count;
            count++;
            if(num[cy][cx + 1] == 0) cx++;
        }
        cy--; cx--;
        if(num[cy][cx] != 0) break;
        //대각선 왼쪽 위로 올라가기
        while(num[cy][cx] == 0){
            num[cy][cx] = count;
            count++; 
            if(num[cy - 1][cx - 1] == 0){ cx--; cy--; }
        }
        cy++;
        if(num[cy][cx] != 0) break;
    }

    // for(int i = 0; i < 10; i++){
    //     for(int j = 0; j < 10; j++){
    //         cout << num[i][j] << "   ";
    //     }
    //     cout << '\n';
    // }

    for(int y = 1; y <= n; y++){
        for(int x = 1; x <= y; x++){
            answer.push_back(num[y][x]);
        }
    }

    return answer;
}