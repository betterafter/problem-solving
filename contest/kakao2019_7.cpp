#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<pair<int, int>> block[210];

bool compare(pair<int, int> &a, pair<int, int> &b){
    if(a.second == b.second) return a.first < b.first;
    else return a.second < b.second;
}



/////////////////////////////////error/////////////////////////////////////////////////
// bool type_1(pair<int, int> &a, pair<int, int> &b, pair<int, int> &c, pair<int, int> &d){
//     if(b.first == a.first && b.second == a.second + 1){
//         if(c.first == a.first && c.second == a.second + 2){
//             if(d.first == a.first + 1 && d.second == a.second + 2){
//                 return true;
//             }
//         }
//     }
//     else return false;
// }
//
// 이런식으로 만들었었는데, else return false 해버리면 첫번째 if문만 통과 안되면 false가 되버린다.
// 즉 첫번째 if문이 통과되면 2, 3번째 if문과는 관계 없이 else return false가 나오지 않게 된다. 
// 그렇게 되면 default 값으로 return이 되니까 틀리게 됨.
// 이런 사소한 실수는 하지않도록 하자.


    // 만들 수 있는 블록은 
    // 
    //   ㅣ                                       |
    //   ㅣ                    |                  |                |                            |
    //   ㅣ___          _______|               ___|                |________                ____|____       
    //
    // 이 다섯가지 블록이 자신한테 안 걸치고 만들 수 있다.


// (x, y), (x, y + 1), (x, y + 2), (x + 1, y + 2)
bool type_1(pair<int, int> &a, pair<int, int> &b, pair<int, int> &c, pair<int, int> &d){
    if(b.first == a.first && b.second == a.second + 1){
        if(c.first == a.first && c.second == a.second + 2){
            if(d.first == a.first + 1 && d.second == a.second + 2){
                return true;
            }
        }
    }
    return false;
}

// (x, y), (x - 2, y + 1), (x - 1, y + 1), (x, y + 1)
bool type_2(pair<int, int> &a, pair<int, int> &b, pair<int, int> &c, pair<int, int> &d){
     if(b.first == a.first - 2 && b.second == a.second + 1){
        if(c.first == a.first - 1 && c.second == a.second + 1){
            if(d.first == a.first && d.second == a.second + 1){
                return true;
            }
        }
    }
    return false;
}

// (x, y), (x, y + 1), (x - 1, y + 2), (x, y + 2)
bool type_3(pair<int, int> &a, pair<int, int> &b, pair<int, int> &c, pair<int, int> &d){
     if(b.first == a.first && b.second == a.second + 1){
        if(c.first == a.first - 1 && c.second == a.second + 2){
            if(d.first == a.first && d.second == a.second + 2){
                return true;
            }
        }
    }
    return false;
}

// (x, y), (x, y + 1), (x + 1, y + 1), (x + 2, y + 1)
bool type_4(pair<int, int> &a, pair<int, int> &b, pair<int, int> &c, pair<int, int> &d){
     if(b.first == a.first && b.second == a.second + 1){
        if(c.first == a.first + 1 && c.second == a.second + 1){
            if(d.first == a.first + 2 && d.second == a.second + 1){
                return true;
            }
        }
    }
    return false;
}

// (x, y), (x - 1, y + 1), (x, y + 1), (x + 1, y + 1)
bool type_5(pair<int, int> &a, pair<int, int> &b, pair<int, int> &c, pair<int, int> &d){
     if(b.first == a.first - 1 && b.second == a.second + 1){
        if(c.first == a.first && c.second == a.second + 1){
            if(d.first == a.first + 1 && d.second == a.second + 1){
                return true;
            }
        }
    }
    return false;
}

// 각 블록은 특정 부분이 채워지면 파괴할 수 있는데, 가령 1번 블록은 오른쪽에 2개를 채우면 파괴된다. 따라서 채워야할 x위치를 구하고, 
// 해당 위치의 y값을 맨 위까지 탐색해서 막고 있는 블록이 없으면 부술 수 있다. 이 때, 모든 블록이 채워야할 검은 블록의 개수가 2개이므로 (x1, y1), (x2, y2)
// 2개를 탐색하면 되겠다.
bool isDestruction(vector<vector<int>> board, int x1, int y1, int x2, int y2){

    for(int t = y1 - 1; t >= 0; t--){
        if(board[t][x1] != 0){
            return false;
        }
    }
    for(int t = y2 - 1; t >= 0; t--){
        if(board[t][x2] != 0){
            return false;
        }
    }
    return true;
}


int solution(vector<vector<int>> board) {
    int answer = 0;
    int boardsize = board.size();

    for(int i = 0; i < boardsize; i++){
        for(int j = 0; j < boardsize; j++){
            if(board[i][j] != 0)
                block[board[i][j]].push_back(make_pair(j, i));
        }
    }

    // 모양을 파악하기 위해 y가 작은 순, x가 작은 순으로 정렬
    for(int i = 1; i < 201; i++){
        if(block[i].size() > 0){
            sort(block[i].begin(), block[i].end(), compare);
        }
    }

    // 위에서부터 탐색해서 검정색을 뿌렸을 때 깰 수 있는지 확인
    // 검정색이 필요한 위치를 y를 따라 쭉 올라가면서 해당 위치에 0이 아닌 다른 숫자가 있는지 체크
    // 다른 숫자가 없으면 부수고 0으로 전부 바꿔줌
    for(int i = 0; i < boardsize; i++){
        for(int j = 0; j < boardsize; j++){
            // 현재 위치에 블록이 있으면
            if(board[i][j] != 0)
            {
                // 몇번 블록인지 확인하고,
                int block_num = board[i][j];
                // block벡터에서 해당 번호의 블록 위치를 전부 꺼내와서 몇번 타입의 블록인지 확인하고,
                if(type_1(block[block_num][0], block[block_num][1], block[block_num][2], block[block_num][3])){
                    // 파괴할 수 있는지 확인하고,
                    if(isDestruction(board, block[block_num][3].first, block[block_num][3].second,
                    block[block_num][3].first, block[block_num][3].second)){
                        // 파괴할 수 있으면 보드에서 해당 블록 조각의 좌표대로 데이터를 0 (빈 공간) 으로 바꿔준다.
                        for(int k = 0; k < 4; k++){
                            board[block[block_num][k].second][block[block_num][k].first] = 0;
                        }
                        // 파괴했으므로 answer + 1 해준다.
                        answer++;
                    }
                }
                else if(type_2(block[block_num][0], block[block_num][1], block[block_num][2], block[block_num][3])){
                    if(isDestruction(board, block[block_num][1].first, block[block_num][1].second,
                    block[block_num][2].first, block[block_num][2].second)){
                        for(int k = 0; k < 4; k++){
                            board[block[block_num][k].second][block[block_num][k].first] = 0;
                        }
                        answer++;
                    }
                }
                else if(type_3(block[block_num][0], block[block_num][1], block[block_num][2], block[block_num][3])){
                    if(isDestruction(board, block[block_num][2].first, block[block_num][2].second,
                    block[block_num][2].first, block[block_num][2].second)){
                        for(int k = 0; k < 4; k++){
                            board[block[block_num][k].second][block[block_num][k].first] = 0;
                        }
                        answer++;
                    }
                }
                else if(type_4(block[block_num][0], block[block_num][1], block[block_num][2], block[block_num][3])){
                    if(isDestruction(board, block[block_num][2].first, block[block_num][2].second,
                    block[block_num][3].first, block[block_num][3].second)){
                        for(int k = 0; k < 4; k++){
                            board[block[block_num][k].second][block[block_num][k].first] = 0;
                        }
                        answer++;
                    }
                }
                else if(type_5(block[block_num][0], block[block_num][1], block[block_num][2], block[block_num][3])){
                    if(isDestruction(board, block[block_num][1].first, block[block_num][1].second,
                    block[block_num][3].first, block[block_num][3].second)){
                        for(int k = 0; k < 4; k++){
                            board[block[block_num][k].second][block[block_num][k].first] = 0;
                        }
                        answer++;
                    }
                }
            }
        }
    }

    return answer;
}