//
//  MirrorInTheRoom.cpp
//  SCPC
//
//  Created by 신기열 on 16/05/2019.
//  Copyright © 2019 신기열. All rights reserved.
//

/*
 You should use the statndard input/output
 
 in order to receive a score properly.
 
 Do not use file input and output
 
 Please be very careful.
 */

#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

int Answer;

int main(void)
{
    int T, test_case;
    /*
     The freopen function below opens input.txt file in read only mode, and afterward,
     the program will read from input.txt file instead of standard(keyboard) input.
     To test your program, you may save input data in input.txt file,
     and use freopen function to read from the file when using scanf function.
     You may remove the comment symbols(//) in the below statement and use it.
     But before submission, you must remove the freopen function or rewrite comment symbols(//).
     */
    // freopen("input.txt", "r", stdin);
    
    /*
     If you remove the statement below, your program's output may not be rocorded
     when your program is terminated after the time limit.
     For safety, please use setbuf(stdout, NULL); statement.
     */
    setbuf(stdout, NULL);
    
    scanf("%d", &T);
    for(test_case = 0; test_case < T; test_case++)
    {
        
        /////////////////////////////////////////////////////////////////////////////////////////////
        int x = 0, y = 0, N, dir = 1, Answer = 0;

        vector<int> chk[1010];
        vector<char> room[1010];
        
        cin >> N;
        for(int i = 0; i < N; i++){
            string s;
            cin >> s;
            for(int j = 0; j < N; j++){
                room[j].push_back(s[j]);
                chk[j].resize(1010, 0);
            }
        }
        
        while(1){
            
            if(dir == 1){
                if(room[x][y] == '0'){
                    x++; dir = 1;
                }
                else if(room[x][y] == '1'){
                    if(chk[x][y] == 0){ Answer++; chk[x][y] = 1; } y--; dir = 3;
                }
                else if(room[x][y] == '2'){
                    if(chk[x][y] == 0){ Answer++; chk[x][y] = 1; } y++; dir = 4;
                }
            }
            else if(dir == 2){
                if(room[x][y] == '0'){
                    x--; dir = 2;
                }
                else if(room[x][y] == '1'){
                    if(chk[x][y] == 0){ Answer++; chk[x][y] = 1; } y++; dir = 4;
                }
                else if(room[x][y] == '2'){
                    if(chk[x][y] == 0){ Answer++; chk[x][y] = 1; } y--; dir = 3;
                }
            }
            else if(dir == 3){
                if(room[x][y] == '0'){
                    y--; dir = 3;
                }
                else if(room[x][y] == '1'){
                    if(chk[x][y] == 0){ Answer++; chk[x][y] = 1; } x++; dir = 1;
                }
                else if(room[x][y] == '2'){
                    if(chk[x][y] == 0){ Answer++; chk[x][y] = 1; } x--; dir = 2;
                }
            }
            else if(dir == 4){
                if(room[x][y] == '0'){
                    y++; dir = 4;
                }
                else if(room[x][y] == '1'){
                    if(chk[x][y] == 0){ Answer++; chk[x][y] = 1; } x--; dir = 2;
                }
                else if(room[x][y] == '2'){
                    if(chk[x][y] == 0){ Answer++; chk[x][y] = 1; } x++; dir = 1;
                }
            }
            if(x < 0 || y < 0 || x >= N || y >= N){
                break;
            }
        }
        
        
        
        /////////////////////////////////////////////////////////////////////////////////////////////
        
        // Print the answer to standard output(screen).
        
        printf("Case #%d\n", test_case+1);
        printf("%d\n", Answer);
        
    }
    
    return 0;//Your program should return 0 on normal termination.
}
