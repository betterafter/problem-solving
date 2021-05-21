#include <string>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

long long solution(int n, vector<int> times) {

    sort(times.begin(), times.end());

    // 1, 2, 3, 4, 5, 6, 7, 8, 9, 10
    long long left = 1, right = (long long)(times[times.size() - 1]) * n;
    long long answer = right;

    while (left <= right){
        long long mid = (left + right) / 2;
        long long num = 0;
        for(int i = 0; i < times.size(); i++){
            num += mid / times[i];
        }

        // 중간값 시간 안에 다 처리 못할 경우 :: 우측 이동
        if(n > num) {
            left = mid + 1;
        }
        // 중간값 시간 안에 다 처리할 경우 :: 좌측 이동 && answer 값 업데이트
        else if(n <= num) {
            right = mid - 1;
            if(answer >= mid) answer = mid;
        }
    }
    return answer;
}