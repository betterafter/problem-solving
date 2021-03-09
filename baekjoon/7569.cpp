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

int box[100][100][100];

int M, N, H, day; 
queue<pair<pair<int, int>, int> > q;

void printer(){
    cout << '\n';
    cout << '\n';
    cout << day << '\n';
    for(int z = 0; z < H; z++){
        for(int y = 0; y < N; y++){
            for(int x = 0; x < M; x++){
                cout << box[z][y][x] << " ";
            }
            cout << '\n';
        }
        cout << '\n';
    }
}

void check(){

    while(!q.empty()){
        int size = q.size();
        for(int i = 0; i < size; i++){
            int x = q.front().first.first, y = q.front().first.second, z = q.front().second; q.pop();
            //cout << x << " " << y << " " << z << "     ";
            if(x + 1 < M && box[z][y][x + 1] == 0){
                box[z][y][x + 1] = 1; q.push(make_pair(make_pair(x + 1, y), z));
            }
            if(x - 1 >= 0 && box[z][y][x - 1] == 0){
                box[z][y][x - 1] = 1; q.push(make_pair(make_pair(x - 1, y), z));
            }
            if(y + 1 < N && box[z][y + 1][x] == 0){
                box[z][y + 1][x] = 1; q.push(make_pair(make_pair(x, y + 1), z));
            }
            if(y - 1 >= 0 && box[z][y - 1][x] == 0){
                box[z][y - 1][x] = 1; q.push(make_pair(make_pair(x, y - 1), z));
            }
            if(z + 1 < H && box[z + 1][y][x] == 0){
                box[z + 1][y][x] = 1; q.push(make_pair(make_pair(x, y), z + 1));
            }
            if(z - 1 >= 0 && box[z - 1][y][x] == 0){
                box[z - 1][y][x] = 1; q.push(make_pair(make_pair(x, y), z - 1));
            }
        }
        //cout << '\n';
        day++; 
        //printer();
    }
}




int main(){

    ios::sync_with_stdio(false);
	cin.tie(NULL);
    cout.tie(NULL);

    cin >> M >> N >> H;
    for(int z = 0; z < H; z++){
        for(int y = 0; y < N; y++){
            for(int x = 0; x < M; x++){
                cin >> box[z][y][x];
                if(box[z][y][x] == 1) q.push(make_pair(make_pair(x, y), z));
            }
        }
    }

    check();

    for(int z = 0; z < H; z++){
        for(int y = 0; y < N; y++){
            for(int x = 0; x < M; x++){
                if(box[z][y][x] == 0){
                    cout << -1; return 0;
                }
            }
        }
    }


    cout << day - 1;
    return 0;
}
