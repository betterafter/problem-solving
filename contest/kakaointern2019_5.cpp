#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

#define ll long long

int answer;

// 선택 인원 수를 기준으로 k개의 연속한 0 짜리 밟음돌이 존재하면 해당 인원 수만큼은 건널 수 없다는 것을 의미한다.
bool ismove(ll m, vector<int> stones, int k){

    int usedstone = 0;
    for(int i = 0; i < stones.size(); i++){
        // stones에 적힌 수에서 해당 인원수를 뺀 값이 0보다 작으면 (0이면 해당 인원 수만큼은 건널 수 있는 거니까)
        if(stones[i] - m < 0){
            // 밟음돌을 카운트 해준다.
            usedstone++;
            // 이 때 카운트 한 수가 k와 같아지게 되면 건너 뛸 수 없는 상태가 되므로 해당 인원 수 만큼은 건널 수 없다는 말이 된다.
            if(usedstone == k){

                return false;
            }
        }
        // 빼준 값이 0이 아니면 연속이 끊기니까 0부터 다시 시작해준다.
        else usedstone = 0;
    }
    return true;
}


void binarysearch(ll mini, ll maxi, vector<int> stones, int k){
    // 왼쪽은 1로, 오른쪽은 상당히 큰 수로 시작해준다. 문제에서는 무한한 친구라고 제시되어있는데, 그냥 적당한 큰 수를 넣으면 되는 것 같다.
    ll left = mini, right = maxi;
    // 여기서부터 이분탐색 알고리즘이다.
    while(left <= right){
        ll mid = (left + right) / 2;
        // 해당 중앙값이 건너뛸 수 없다고 판별 되면 이 중앙값을 포함해서 더 큰 인원수는 건널 수 없다는 것이 판명된다.
        if(!ismove(mid, stones, k)){
            right = mid - 1;
        }
        // 해당 중앙값이 건너뛸 수 있다면 아직 이 값보다 큰 수 중에서도 가능한 인원 수가 존재할 수 있다.
        else if(ismove(mid, stones, k)){
            // 해당 중앙값은 통과되는데 바로 다음 1 큰 수는 안된다면 건널 수 있는 최대 인원수는 현재 중앙값이라는 의미이다.
            // 해당 중앙값과 그 다음 값이 ismove를 통과한다면 왼쪽값을 중앙값 + 1로 지정해서 새로운 중앙값을 구해서 다시 탐색해본다.
            if(ismove(mid + 1, stones, k)){
                left = mid + 1;
            }
            // 해당 중앙값은 통과했는데 그 다음 값은 통과하지 못했다면 최대 인원 수는 현재 중앙값이라는 의미이다.
            else{
                answer = mid; return;
            }
        }
    }
}


int solution(vector<int> stones, int k) {
    ll mini, maxi;

    mini = 1;  maxi = 1000000000000000000; 
    binarysearch(mini, maxi, stones, k);

    return answer;
}