#include <string>
#include <vector>
#include <map>

using namespace std;

// 개인적으로 난이도는 상당하다고 생각하는데, 코드는 의외로 짧다. 문제 풀이 방법만 생각해내면 금방 풀 수 있는 문제인데, 
// 이런 문제를 어떻게 접근해야하는지 바로바로 생각을 못하겠다..
map<long long, long long> room;

// 이 문제는 특정 방 번호와 다음 방 번호 중에서 이용가능한 가장 가까운 방 번호를 key & value 값으로 map에 넣어주는 방식으로 풀 수 있다.
// find에서 맵에 특정 n번 방에 대한 정보가 아직 없다면 빈 방인 것으로 바로 이용하면 되고, 그렇지 않으면 n번 방보다 큰 방 번호 중에 제일 가까운 방을 
// "n번 방 다음으로 이용 가능한 방"으로 key & value 로 맵에 저장해준다.
long long find(long long n){
    if(!room[n]) return n;
    return room[n] = find(room[n]);
}


vector<long long> solution(long long k, vector<long long> room_number) {
    vector<long long> answer;

    for(long long i = 0; i < room_number.size(); i++){
        // 특정 방에 대한 정보가 아직 맵에 없으면 바로 이용할 수 있다. 해당 방 번호를 answer에 넣어준다.
        if(!room[room_number[i]]){
            answer.push_back(room_number[i]);
            // 이 때 해당 방 번호의 다음 방 번호부터 탐색을 시작해서 빈 방을 해당 방과 연결시켜준다.
            room[room_number[i]] = find(room_number[i] + 1);
        }
        // 특정 방이 맵에 이미 있으면
        else{
            // 해당 방의 이용가능한 다음 방을 탐색해준다.
            answer.push_back(find(room_number[i]));
            // 역시 해당 방과 탐색으로 찾은 이용가능한 다음 방과 매칭시켜준다.
            room[find(room_number[i])] = find(find(room_number[i]) + 1);
        }
    }

    return answer;
}