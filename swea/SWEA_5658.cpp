#include<iostream>
#include <queue>
#include <set>

using namespace std;

// 16진수를 변환한 10진수를 담는 set
set<int, greater<int>> ans;

void calc(deque<char> dq){
    // 16을 몇번 곱해야하는지 체크하기 위한 변수
    int mul = (int)dq.size();
    int add = 0;
    // 덱의 16진수를 10진수로 변환
    for(int i = 0; i < dq.size(); i++){
        // 맨 앞부터 16 * (n - 1), 16 * (n - 2) ...
        int multiple = 1;
        for(int i = 1; i < mul; i++){
            multiple *= 16;
        }
        // 0 ~ 9이면 그냥 int형으로만 변환해준다.
        if(dq[i] >= '0' && dq[i] <= '9'){
            add = add + (dq[i] - 48) * multiple;
        }
        // A ~ F이면 10 ~ 15이므로 아래처럼 각 숫자를 변환해준다.
        else if(dq[i] >= 'A' && dq[i] <= 'F'){
            add = add + (dq[i] - 'A' + 10) * multiple;
        }
        mul--;
    }
    ans.insert(add);
}

int main(int argc, char** argv)
{
    int test_case;
    int T;

    cin>>T;

    for(test_case = 1; test_case <= T; ++test_case)
    {
        deque<char> one, two, three, four;
        int n, k;
        string s;
        cin >> n >> k;
        cin >> s;
        // string을 4등분해서 각각의 모서리 덱에 넣어준다.
        for(int i = 0; i < n / 4; i++){
            one.push_back(s[i]);
        }
        for(int i = n / 4; i < n / 4 * 2; i++){
            two.push_back(s[i]);
        }
        for(int i = n / 4 * 2; i < n / 4 * 3; i++){
            three.push_back(s[i]);
        }
        for(int i = n / 4 * 3; i < n / 4 * 4; i++){
            four.push_back(s[i]);
        }
        // 한번 회전할 때 마다 각 덱이 앞의 문자를 다음 모서리로 준다.
        for(int i = 1; i <= n; i++){
            int back_1 = one.back(), back_2 = two.back(), back_3 = three.back(), back_4 = four.back();
            one.pop_back(); two.push_front(back_1);
            two.pop_back(); three.push_front(back_2);
            three.pop_back(); four.push_front(back_3);
            four.pop_back(); one.push_front(back_4);

            // 10진수 변환 연산 실행
            calc(one); calc(two); calc(three); calc(four);
        }
        // 내림차순 정렬된 set에서 10번째를 출력해준다.
        int idx = 0;
        set<int> :: iterator iter;
        for(iter = ans.begin(); iter != ans.end(); iter++){
            if(idx == k - 1){
                cout << "#" << test_case << " " << *iter << '\n';
                break;
            }
            idx++;
        }
        ans.clear(); one.clear(); two.clear(); three.clear(); four.clear();
    }
    return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
