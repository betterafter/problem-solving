#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<vector<int>> b;
vector<int> basket;
int answer;

// 특정 x축 인덱스에서 인형을 뽑는다.
void pick(int pick){

    for(int i = 0; i < b.size(); i++){
        // y를 따라 쭉 내려가면서 0이 아닌건 뽑아준다. 이 때 뽑은 자리는 0 (빈공간) 으로 바꿔주고 바구니에 넣어준다.
        if(b[i][pick] != 0){
            basket.push_back(b[i][pick]);
            b[i][pick] = 0; 
            return;
        }
    }
}
// 바구니에서 인형을 터트릴 수 있는지 체크한다.
void iserase(){
    int size = basket.size();
    // 최소 인형이 2개일 때 부터 터트릴 수 있다.
    if(size > 1){
        // 바구니의 맨 마지막 것과 그 다음 것이 같은 인형일 때
        if(basket[size - 1] == basket[size - 2]){
            // 바구니에서 두개를 모두 꺼내준다 (폭파하므로 제거해준다.)
            basket.pop_back();
            basket.pop_back();
            // 폭파한 인형 갯수를 추가해준다.
            answer += 2;
        }
    }
}

int solution(vector<vector<int>> board, vector<int> moves) {

    b = board;

    for(int i = 0; i < moves.size(); i++){
        pick(moves[i] - 1);
        iserase();
    }

    return answer;
}