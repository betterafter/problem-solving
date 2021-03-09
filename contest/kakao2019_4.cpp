#include <string>
#include <vector>
#include <iostream>
#include <queue>
#include <math.h>
#include <algorithm>

using namespace std;

int solution(vector<int> food_times, long long k) {
    
    int answer = 0;

    // 일단 food_time 원소 다 집어넣기
    vector<int> v, tmp;
    for(int i = 0; i < food_times.size(); i++){
        v.push_back(food_times[i]);
    }

    sort(v.begin(), v.end());

    long long t = 0; int idx = 0;

    for(int i = 0; i < v.size(); i++){

        //////////////////////////////////////// ex) 3, 1, 4 를 6초 안에///////////////////////////////////////
        // 한바퀴 도는 시간
        // 3 1 4 -> 1 3 4 로 만들고 몇바퀴 몇시간을 뺄 수 있는지 체크
        if(i == 0) t += v[i] * (v.size() - i);
        else t += (v[i] - v[i - 1]) * (v.size() - i);
        
        // 몇바퀴 돌렸더니 시간이 넘어버리는 경우 일단 이전까지의 인덱스만
        if(t > k){
            idx = i - 1; break;
        }
    }
    // 모든 바퀴를 돌렸는데 시간이 남아버린 경우 = 음식을 다 먹음
    if(t <= k){
        return -1;
    }

    // 3 1 4 에서 -> 1 3 4 로 변경한 것 중에 제일 앞에 1개짜리만 돌려서 0 2 3 으로 만들어줬었다.
    // 이 때 2번째로 작은 값인 2를 돌리게 되면 k시간보다 초과하게 되므로 우리는 1만 한바퀴 돌려줬었다. (즉 3초만 사용)
    // 따라서 남은 2 3 으로 차근차근 소모시켜보겠다.
    // 해당 값은 food_times의 2번, 0번 인덱스에 들어있다.

    // tmp = {2, 0}
    // 이 때 먹는 순서는 정주행이므로 찾을때는 역주행으로 찾아야 된다. 3 1 4 -> 2 0 3 -> ... 를 앞에서부터 먹으니까 탐색은 뒤에서부터
    for(int i = food_times.size() - 1; i >= -1; i--){
        if(food_times[i] > v[idx]){
            tmp.push_back(i + 1);
        }
    }
    // 아직 안먹은 음식에 대한 정보가 들어있는 tmp 벡터에서 ::
    // t = 1 * 3 + (3-1) * 2 = 7초 였을 때
    // 남은 시간은 7 - (6 + 1) (이 때, 방송 오류가 난 후 재방송할 때 다음에 먹을 음식을 알아야하는 것이므로 +1) 이면 0초인데, 즉 다음에 먹을 음식의 인덱스가
    // tmp[0] = 4개짜리라는 얘기
    // 만약 5초 안에 였다면? 7 - (5 + 1) = 1이므로 tmp[1] = 3개짜리라는 것
    // 중요한 것은 모든 음식 중에서 안먹은 음식에 대한 정보만 뽑아서 벡터에 새로 담아서 돌려야한다는 것이다. 이 때 벡터에는 모든 음식이 아닌 안먹은 음식만 들어있으니까
    // 어떤 안먹는 음식에서 멈추는지 나머지 연산으로 구해야 한다.
    if(tmp.size() > 0){
        return tmp[(t - (k + 1)) % tmp.size()];
    }
    // tmp.size = 0 ? 이 말은 food_times의 모든 원소가 동일하다는 것. 이 때는 그냥 전체 시간을 전체 개수 + 1의 나머지를 구하면 된다.
    else return k % (food_times.size() + 1);

}