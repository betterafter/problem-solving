#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>
#include <queue>
#include <set>
#include <stack>
#include <map>

using namespace std;

// 특별한 알고리즘보다 상당한 창의력을 요하는 문제이다. 
// 가령 A B라는 개미가 있다고 하고, 아래 그림과 같은 형태로 위치해있다고 생각해보자.

//      A               B
//  1   2   3   4   5   6   7   8   9
// 이 개미는 잘 가다가 4번 지점에서 부딪혀서 아래 처럼 될 것이고,

//              A
//              B      
//  1   2   3   4   5   6   7   8   9


// 방향을 틀어 반대 방향으로 갈 것이다. 

//          A       B   
//  1   2   3   4   5   6   7   8   9

// 이 때를 잘 생각해보자. 상식적으로는 A가 왼쪽으로 다시 향할 것이고 B가 오른쪽으로 향할 것인데, 개미에 대한 이 기호를 안 붙혔다면
// 그냥 개미 2마리가 잘 가다가 4번 지점에 부딪혀 반대방향으로 가는 것이 그냥 4번지점에서 부딪히든 말든 쭉 가던길 가는 것 처럼 보일 수 있다!
// (어차피 개미 생긴게 똑같이 생겨서 어떤게 A고 B이고 써놓지 않으면 구분할 순 없지않은가)
// 좀 더 쉽게 말하자면, A가 가는 길을 B가 대신 가고, B가 가던 길을 A가 대신 가는 것이니까 넘버링을 안 붙힌다면 결론적으론 그냥 통과하는 것처럼 보인다는 것이다.
// 따라서 어떤 지점에서 부딪히든 말든 그냥 통과하는 것이라고 보면 된다.
// 그렇다면 개미 번호는? 위의 아이디어와 다르게 우리는 개미의 번호를 이미 알고 있지 않은가? 
// 가령 개미들이 아래와 같이 배치되어있다고 생각해보자. 오른쪽은 방향, 그 옆의 숫자는 개미 번호를 의미한다. 
//   right_1         right_2                  left_3          left_4                 right_5          left_6          right_7
// 0     1       2       3       4       5       6       7       8       9       10      11      12      13      14      15      16
// 이 때 왼쪽으로 가는 개미는 3, 4, 6번 3마리, 오른쪽으로 가는 개미는 1, 2, 5, 7번 4마리이다.
// 위의 통과하는 아이디어를 적용한다면, 1번 개미는 1 -> 16 까지 15초만에 가는 것이고, 2번 개미는 16 - 3 = 13초만에, 3번 개미는 6 -> 0 까지 6초만에 가는 것이다.
// 이 때 왼쪽으로 이동하는 개미 중 가장 오래 걸리는 개미는 4번 개미 (8 - 0 = 8) 이고, 오른쪽으로 이동하는 개미 중 가장 오래 걸리는 개미는 1번 개미 (16 - 1) 이 되겠다.
// 우리는 위에서 개미가 부딪혀서 반대로 가는 방법 대신에, 바톤터치하듯이 통과하는 아이디어를 생각했었다. 그 아이디어를 적용해보면 가령 right_1은 왼쪽으로 가는 어떤
// 개미에 의해 바톤터치해서 결국 오른쪽으로 쭉 가는 모양새가 나오게 된다. 한마디로 개미가 어떤 방향으로 가든간에 왼쪽으로 가서 떨어지는 개미는 3마리, 오른쪽으로 가서 
// 떨어지는 개미는 4마리가 나올 수 밖에 없게 되는 것이다. 위의 정렬을 아래와 같이 다시 바꿔줄 수 있는 것이다.

//    left_1          left_2                 left_3          right_4                  right_5         right_6         right_7
// 0     1       2       3       4       5       6       7       8       9       10      11      12      13      14      15      16
// 이 때, 왼쪽으로 가서 떨어지는 개미들 중에선 가장 오른쪽에 있는 Left_3 개미가 제일 늦게 떨어질 것이고, 오른쪽으로 가서 떨어지는 개미들 중에선 right_4 개미가 
// 가장 늦게 떨어지게 될 것이다. 따라서 left 로 가는 개미들의 수를 세어주고, 왼쪽으로 가서 떨어지는 개미 중에 가장 늦게 떨어지는 개미의 시간과, 오른쪽으로 가서 
// 떨어지는 개미 중에 가장 늦게 떨어지는 개미의 시간 중 더 오래 걸리는 것을 구하고, 그게 만약 왼쪽-떨-개미의 시간이라면 left_3가 되겠고, 반대로 오른쪽-떨-개미의 
// 시간이라면 right_4가 될 것이다. 

int N, L;
int v[100001];
int fin_ant, fin_time = 0, left_cnt = 0, fallen_left, fallen_right;
pair<int, int> res[100001];

bool compare(pair<int, int> &a, pair<int, int> &b){
    return a.second < b.second;
}


int main(){

    ios::sync_with_stdio(false);
	cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> L;
    for(int i = 1; i <= N; i++){
        int p; cin >> p;
        v[i] = p;
    }
    for(int i = 1; i <= N; i++){

        if(v[i] >= 0){
            fallen_right = max(L - v[i], fallen_right);
        }
        else if(v[i] < 0){ 
            left_cnt++;
            fallen_left = max(abs(v[i]), fallen_left);
        }
        
        res[i - 1] = make_pair(i, abs(v[i]));
    }

    sort(res, res + N, compare);

    if(fallen_left > fallen_right){
        cout << res[left_cnt - 1].first << " " << fallen_left;
    }
    else{
        cout << res[left_cnt].first << " " << fallen_right;
    }
    return 0;
}

