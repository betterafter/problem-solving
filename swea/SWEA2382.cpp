#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

//  1
// 3 4
//  2
pair<int, int> map[100][100];
queue<pair<int, int> > virus;

//bool compare(pair<int, int> &a, pair<int, int> &b){
//    return a.first > b.first;
//}

void move(int size){
    
    pair<int, int> tmap[100][100];
    pair<int, int> biggest[100][100];
    
    int s = (int)virus.size();
    for(int i = 0; i < s; i++){
        // 미생물 군집이 있는 위치와 크기, 이동 방향에 대한 정보를 가져온다. queue로 만든 건 이 virus 큐에 이동 후의 군집들의 위치를 다시
        // 넣을 것이여서 이동 전의 위치들은 전부 빼주기 위함이다.
        int x = virus.front().first, y = virus.front().second, n = map[y][x].first, d = map[y][x].second;
        virus.pop(); map[y][x].first = 0; map[y][x].second = 0;
        // 현재 미생물 군집의 방향이 위쪽일 경우
        if(d == 1){
            int nx = x, ny = y - 1;
            // 이동하고자 하는 방향이 약을 바른 가장자리인 경우
            if(nx == 0 || nx == size - 1 || ny == 0 || ny == size - 1){
                // 해당 위치에 도달하는 미생물 군집의 크기는 절반이 되며 - 이 때, 미생물 군집의 총 합은 tmap에 저장하고,
                // 가장 큰 군집은 biggest에 저장하자. map에 총 합을 다이렉트로 저장해버리면 원래 같은 좌표에서 이동 준비를 하던 군집에도
                // 영향을 줄 수 있다.
                tmap[ny][nx].first += n / 2;
                // 해당 위치에서 가장 큰 미생물 군집은 biggest 맵에 방향과 함께 저장해준다. 방향은 반대가 된다.
                if(biggest[ny][nx].first < n / 2){
                    biggest[ny][nx] = make_pair(n / 2, 2);
                }
            }
            // 약을 바른 부분이 아닌 경우
            else{
                // 군집 크기는 변함이 없고, 방향도 그대로이다.
                tmap[ny][nx].first += n;
                if(biggest[ny][nx].first < n){
                    biggest[ny][nx] = make_pair(n, 1);
                }
            }
        }
        // 나머지 방향에 대해서도 같은 알고리즘이다.
        else if(d == 2){
            int nx = x, ny = y + 1;
            if(nx == 0 || nx == size - 1 || ny == 0 || ny == size - 1){
                tmap[ny][nx].first += n / 2;
                if(biggest[ny][nx].first < n / 2){
                    biggest[ny][nx] = make_pair(n / 2, 1);
                }
            }
            else{
                tmap[ny][nx].first += n;
                if(biggest[ny][nx].first < n){
                    biggest[ny][nx] = make_pair(n, 2);
                }
            }
        }
        else if(d == 3){
            int nx = x - 1, ny = y;
            if(nx == 0 || nx == size - 1 || ny == 0 || ny == size - 1){
                tmap[ny][nx].first += n / 2;
                if(biggest[ny][nx].first < n / 2){
                    biggest[ny][nx] = make_pair(n / 2, 4);
                }
            }
            else{
                tmap[ny][nx].first += n;
                if(biggest[ny][nx].first < n){
                    biggest[ny][nx] = make_pair(n, 3);
                }
            }
        }
        else if(d == 4){
            int nx = x + 1, ny = y;
            if(nx == 0 || nx == size - 1 || ny == 0 || ny == size - 1){
                tmap[ny][nx].first += n / 2;
                if(biggest[ny][nx].first < n / 2){
                    biggest[ny][nx] = make_pair(n / 2, 3);
                }
            }
            else{
                tmap[ny][nx].first += n;
                if(biggest[ny][nx].first < n){
                    biggest[ny][nx] = make_pair(n, 4);
                }
            
            }
        }
    }

    // 한 좌표에 들어오는 미생물 군집의 총 합은 tmap에 저장했으므로 tmap에서 꺼내고, 방향은 biggest에 가장 큰 군집의 크기와 함께 저장했으므로
    // biggest에서 꺼내오면 된다.
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            map[i][j].first = tmap[i][j].first;
            map[i][j].second = biggest[i][j].second;
            // 군집이 이동 및 결합이 이루어진 위치를 새로 virus 큐에 넣어준다.
            if(map[i][j].first != 0) virus.push(make_pair(j, i));
        }
    }
}


int main(){
    
    int T; cin >> T;
    for(int test_cast = 1; test_cast <= T; test_cast++){
        
        int n, m, k; cin >> n >> m >> k;
        int answer = 0;
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                map[i][j].first = 0; map[i][j].second = 0;
            }
        }
        while(!virus.empty()){
            virus.pop();
        }
        

        for(int i = 0; i < k; i++){
            int x, y, num, dir; cin >> y >> x >> num >> dir;
            virus.push(make_pair(x, y));
            map[y][x].first = num; map[y][x].second = dir;
        }

        for(int i = 0; i < m; i++){
            move(n);
        }
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                answer += map[i][j].first;
            }
        }
        cout << "#" << test_cast << " " << answer << '\n';
    }
    
    return 0;
}
