#include <string>
#include <vector>
#include <math.h>
#include <iostream>

using namespace std;


int solution(string name) {

    int answer = 0;
    int cnt[21] = { 0, };
    vector<int> idx;

    for(int i = 0; i < name.length(); i++){
        cnt[i] = min(name[i] - 'A', 90 - name[i] + 1);
        answer += cnt[i];
        if(name[i] != 'A') idx.push_back(i);
    }

    int dist = 10000000;

    int len = 0;
    // 왼쪽 커서만 쭉 눌렀을 때
    for(int i = name.length() - 1; i >= idx[0]; i--){
        len++;
    }
    dist = min(dist, len + 1);

    // 오른쪽 갔다가 다시 돌아와서 왼쪽 쭉 누르는 패턴 반복
    // AAABABABAA라는 것이 있으면
    // 1. AABABAB (왼쪽 커서만 누르기)
    // 2. AAAB (오른쪽 커서 누르기) -> 다시 처음으로 돌아간 후 -> AABAB (왼쪽 커서 누르기)
    // 3. AAABAB (오른쪽 커서 누르기) -> 다시 처음으로 돌아간 후 -> AAB (왼쪽 커서 누르기)
    // 4. AAABABAB (오른쪽 커서만 누르면 끝)
    for(int i = 0; i < idx.size(); i++){
        len = 0;
        // 오른쪽 커서 누르기
        for(int p = 0; p < idx[i]; p++){
            len++;
        }
        // 다시 뒤로 이동
        len *= 2;
        // 왼쪽 커서를 누를 필요가 있다면 왼쪽 커서 누르기. AABBAA 같은 경우에서 AABB까지 누르면 왼쪽 커서는 누를 필요가 없으니까.
        if(idx.size() - 1 >= i + 1){
            for(int q = idx[i + 1]; q < name.length(); q++){
                len++;
            }
        }
        dist = min(dist, len);
    }

    answer = answer + dist;
    return answer;
}