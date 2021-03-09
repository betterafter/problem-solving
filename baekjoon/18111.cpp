#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>
#include <queue>
#include <set>
#include <stack>

int ground[500][500];

using namespace std;

int main(){

    int N, M; long long B; cin >> N >> M >> B;
    int mini = 256, maxi = 0;
    long long restime = 6400000000000, resheight = 0;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin >> ground[i][j];
            mini = min(ground[i][j], mini);
            maxi = max(ground[i][j], maxi);
        }
    }

    for(int n = 0; n <= 256; n++){
        long long b = B; long long time = 0;
        for(int y = 0; y < N; y++){
            for(int x = 0; x < M; x++){
                if(ground[y][x] < n){
                    b -= n - ground[y][x]; time += n - ground[y][x];
                }
                else if(ground[y][x] > n){
                    b += ground[y][x] - n; time += 2 * (ground[y][x] - n);
                }
            }
        }
        if(b >= 0){
            if(restime > time){
                restime = time; resheight = n;
            }
            else if(restime == time){
                if(resheight < n){
                    restime = time; resheight = n;
                }
            }
        }
    }

    cout << restime << " " << resheight;
    return 0;
}
