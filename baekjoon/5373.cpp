//
//  5373.cpp
//  BJ
//
//  Created by 신기열 on 30/10/2019.
//  Copyright © 2019 신기열. All rights reserved.
//

#include <stdio.h>
#include <iostream>

using namespace std;

char cube[6][3][3];
char ans[1000][3][3];

void tUD(char d, char dir){
    char tmp[6][3][3];
    for(int i = 0; i < 6; i++){
        for(int j = 0; j < 3; j++){
            for(int k = 0; k < 3; k++){
                tmp[i][j][k] = cube[i][j][k];
            }
        }
    }
    if(d == 'U'){
        if(dir == '+'){
            for(int i = 0; i < 3; i++){
                tmp[3][0][i] = cube[4][0][i]; tmp[4][0][i] = cube[2][0][i];
                tmp[5][0][i] = cube[3][0][i]; tmp[2][0][i] = cube[5][0][i];
            }
            for(int j = 0; j < 3; j++){
                for(int k = 0; k < 3; k++){
                    tmp[0][k][2 - j] = cube[0][j][k];
                }
            }
        }
        else if(dir == '-'){
            for(int i = 0; i < 3; i++){
                tmp[3][0][i] = cube[5][0][i]; tmp[4][0][i] = cube[3][0][i];
                tmp[5][0][i] = cube[2][0][i]; tmp[2][0][i] = cube[4][0][i];
            }
            for(int j = 0; j < 3; j++){
                for(int k = 0; k < 3; k++){
                    tmp[0][2 - k][j] = cube[0][j][k];
                }
            }
        }
    }
    else if(d == 'D'){
        if(dir == '+'){
            for(int i = 0; i < 3; i++){
                tmp[3][2][i] = cube[5][2][i]; tmp[4][2][i] = cube[3][2][i];
                tmp[5][2][i] = cube[2][2][i]; tmp[2][2][i] = cube[4][2][i];
            }
            for(int j = 0; j < 3; j++){
                for(int k = 0; k < 3; k++){
                    tmp[1][k][2 - j] = cube[1][j][k];
                }
            }
        }
        else if(dir == '-'){
            for(int i = 0; i < 3; i++){
                tmp[3][2][i] = cube[4][2][i]; tmp[4][2][i] = cube[2][2][i];
                tmp[5][2][i] = cube[3][2][i]; tmp[2][2][i] = cube[5][2][i];
            }
            for(int j = 0; j < 3; j++){
                for(int k = 0; k < 3; k++){
                    tmp[1][2 - k][j] = cube[1][j][k];
                }
            }
        }
    }
    for(int i = 0; i < 6; i++){
        for(int j = 0; j < 3; j++){
            for(int k = 0; k < 3; k++){
                cube[i][j][k] = tmp[i][j][k];
            }
        }
    }
}
void tLR(char d, char dir){
    char tmp[6][3][3];
    for(int i = 0; i < 6; i++){
        for(int j = 0; j < 3; j++){
            for(int k = 0; k < 3; k++){
                tmp[i][j][k] = cube[i][j][k];
            }
        }
    }
    if(d == 'L'){
        if(dir == '+'){
            for(int i = 0; i < 3; i++){
                tmp[3][i][2] = cube[1][2 - i][0]; tmp[0][i][0] = cube[3][2 - i][2];
                tmp[2][i][0] = cube[0][i][0]; tmp[1][i][0] = cube[2][i][0];
            }
            for(int j = 0; j < 3; j++){
                for(int k = 0; k < 3; k++){
                    tmp[4][k][2 - j] = cube[4][j][k];
                }
            }
        }
        else if(dir == '-'){
            for(int i = 0; i < 3; i++){
                tmp[3][i][2] = cube[0][2 - i][0]; tmp[0][i][0] = cube[2][i][0];
                tmp[2][i][0] = cube[1][i][0]; tmp[1][i][0] = cube[3][2 - i][2];
            }
            for(int j = 0; j < 3; j++){
                for(int k = 0; k < 3; k++){
                    tmp[4][2 - k][j] = cube[4][j][k];
                }
            }
        }
    }
    else if(d == 'R'){
        if(dir == '+'){
            for(int i = 0; i < 3; i++){
                tmp[3][i][0] = cube[0][2 - i][2]; tmp[2][i][2] = cube[1][i][2];
                tmp[1][i][2] = cube[3][2 - i][0]; tmp[0][i][2] = cube[2][i][2];
            }
            for(int j = 0; j < 3; j++){
                for(int k = 0; k < 3; k++){
                    tmp[5][k][2 - j] = cube[5][j][k];
                }
            }
        }
        else if(dir == '-'){
            for(int i = 0; i < 3; i++){
                tmp[3][i][0] = cube[1][2 - i][2]; tmp[0][i][2] = cube[3][2 - i][0];
                tmp[2][i][2] = cube[0][i][2]; tmp[1][i][2] = cube[2][i][2];
            }
            for(int j = 0; j < 3; j++){
                for(int k = 0; k < 3; k++){
                    tmp[5][2 - k][j] = cube[5][j][k];
                }
            }
        }
    }
    for(int i = 0; i < 6; i++){
        for(int j = 0; j < 3; j++){
            for(int k = 0; k < 3; k++){
                cube[i][j][k] = tmp[i][j][k];
            }
        }
    }
}

void tFB(char d, char dir){
    char tmp[6][3][3];
    for(int i = 0; i < 6; i++){
        for(int j = 0; j < 3; j++){
            for(int k = 0; k < 3; k++){
                tmp[i][j][k] = cube[i][j][k];
            }
        }
    }
    if(d == 'F'){
        if(dir == '+'){
            for(int i = 0; i < 3; i++){
                tmp[0][2][i] = cube[4][2 - i][2]; tmp[5][i][0] = cube[0][2][i];
                tmp[1][0][i] = cube[5][2 - i][0]; tmp[4][i][2] = cube[1][0][i];
            }
            for(int j = 0; j < 3; j++){
                for(int k = 0; k < 3; k++){
                    tmp[2][k][2 - j] = cube[2][j][k];
                }
            }
        }
        else if(dir == '-'){
            for(int i = 0; i < 3; i++){
                tmp[0][2][i] = cube[5][i][0]; tmp[4][i][2] = cube[0][2][2 - i];
                tmp[1][0][i] = cube[4][i][2]; tmp[5][i][0] = cube[1][0][2 - i];
            }
            for(int j = 0; j < 3; j++){
                for(int k = 0; k < 3; k++){
                    tmp[2][2 - k][j] = cube[2][j][k];
                }
            }
        }
    }
    else if(d == 'B'){
        if(dir == '+'){
            for(int i = 0; i < 3; i++){
                tmp[0][0][i] = cube[5][i][2]; tmp[4][i][0] = cube[0][0][2 - i];
                tmp[1][2][i] = cube[4][i][0]; tmp[5][i][2] = cube[1][2][2 - i];
            }
            for(int j = 0; j < 3; j++){
                for(int k = 0; k < 3; k++){
                    tmp[3][k][2 - j] = cube[3][j][k];
                }
            }
        }
        else if(dir == '-'){
            for(int i = 0; i < 3; i++){
                tmp[5][i][2] = cube[0][0][i]; tmp[1][2][i] = cube[5][2 - i][2];
                tmp[4][i][0] = cube[1][2][i]; tmp[0][0][i] = cube[4][2 - i][0];
            }
            for(int j = 0; j < 3; j++){
                for(int k = 0; k < 3; k++){
                    tmp[3][2 - k][j] = cube[3][j][k];
                }
            }
        }
    }
    for(int i = 0; i < 6; i++){
        for(int j = 0; j < 3; j++){
            for(int k = 0; k < 3; k++){
                cube[i][j][k] = tmp[i][j][k];
            }
        }
    }
}

void init(){
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            cube[0][i][j] = 'w'; cube[1][i][j] = 'y'; cube[2][i][j] = 'r';
            cube[3][i][j] = 'o'; cube[4][i][j] = 'g'; cube[5][i][j] = 'b';
        }
    }
}

int main(){
    init();
    
    int n; cin >> n;
    for(int i = 0; i < n; i++){
        int m; cin >> m; char d[m]; char dir[m];
        for(int j = 0; j < m; j++){
            cin >> d[j] >> dir[j];
        }
        for(int j = 0; j < m; j++){
            if((d[j] == 'U' && dir[j] == '+') || (d[j] == 'U' && dir[j] == '-') ||
               (d[j] == 'D' && dir[j] == '+') || (d[j] == 'D' && dir[j] == '-')){
                tUD(d[j], dir[j]);
            }
            else if((d[j] == 'L' && dir[j] == '+') || (d[j] == 'L' && dir[j] == '-') ||
                    (d[j] == 'R' && dir[j] == '+') || (d[j] == 'R' && dir[j] == '-')){
                tLR(d[j], dir[j]);
            }
            else if((d[j] == 'F' && dir[j] == '+') || (d[j] == 'F' && dir[j] == '-') ||
                    (d[j] == 'B' && dir[j] == '+') || (d[j] == 'B' && dir[j] == '-')){
                tFB(d[j], dir[j]);
            }
//            cout << "case " << j + 1 << '\n';
//            cout << "윗면" << "       아랫면" << "       앞면" << "       뒷면" << "       왼쪽면" << "       오른쪽면 " << '\n';
//            for(int p = 0; p < 3; p++){
//                for(int q = 0; q < 3; q++){
//                    cout << cube[0][p][q];
//                }
//                cout << "      ";
//                for(int q = 0; q < 3; q++){
//                    cout << cube[1][p][q];
//                }
//                cout << "      ";
//                for(int q = 0; q < 3; q++){
//                    cout << cube[2][p][q];
//                }
//                cout << "      ";
//                for(int q = 0; q < 3; q++){
//                    cout << cube[3][p][q];
//                }
//                cout << "      ";
//                for(int q = 0; q < 3; q++){
//                    cout << cube[4][p][q];
//                }
//                cout << "      ";
//                for(int q = 0; q < 3; q++){
//                    cout << cube[5][p][q];
//                }
//                cout << '\n';
//            }
        }
        for(int p = 0; p < 3; p++){
            for(int q = 0; q < 3; q++){
                ans[i][p][q] =  cube[0][p][q];
            }
        }
        init();
    }
    for(int i = 0; i < n; i++){
        for(int p = 0; p < 3; p++){
            for(int q = 0; q < 3; q++){
                cout << ans[i][p][q];
            }
            cout << '\n';
        }
    }

    return 0;
}
