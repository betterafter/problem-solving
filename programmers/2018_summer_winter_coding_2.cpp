
// 문제 이름 : 방문 길이

#include <string>
using namespace std;

int map[11][11][4];

// 0 ~ 10
// 중심 : 5
int solution(string dirs) {
    int answer = 0;
    
    pair<int, int> curr = make_pair(5, 5);
    // 0 : up   1 : down   2 : left   3 : right
    for(int i = 0; i < dirs.length(); i++){
        int currx = curr.first, curry = curr.second;
        if(dirs[i] == 'U'){
            if(curry + 1 > 10) continue;
            if(map[currx][curry][0] == 0 && map[currx][curry + 1][1] == 0){
                answer++;
            }
            map[currx][curry][0] = 1; 
            map[currx][curry + 1][1] = 1;
            curr = make_pair(currx, curry + 1);
        }
        else if(dirs[i] == 'D'){
            if(curry - 1 < 0) continue;
            if(map[currx][curry][1] == 0 && map[currx][curry - 1][0] == 0){
                answer++;
            }
            map[currx][curry][1] = 0; 
            map[currx][curry - 1][0] = 1;
            curr = make_pair(currx, curry - 1);
        }
        else if(dirs[i] == 'L'){
            if(currx - 1 < 0) continue;
            if(map[currx][curry][2] == 0 && map[currx - 1][curry][3] == 0){
                answer++;
            }
            map[currx][curry][2] = 1; 
            map[currx - 1][curry][3] = 1;
            curr = make_pair(currx - 1, curry);
        }
        else if(dirs[i] == 'R'){
            if(currx + 1 > 10) continue;
            if(map[currx][curry][3] == 0 && map[currx + 1][curry][2] == 0){
                answer++;
            }
            map[currx][curry][3] = 1; 
            map[currx + 1][curry][2] = 1;
            curr = make_pair(currx + 1, curry);
        }
    }
    
    
    return answer;
}