#include <stdio.h>
#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>

using namespace std;

long blocked;


int main(){
    
    int D, N; cin >> D >> N;
    long dough[300001];
    long oven[300001];

    blocked = D + 1;
    long mini = 1000000001;
    long minoven = 1000000001;

    for(int i = 1; i <= D; i++){
        long t; cin >> t;
        minoven = min(t, minoven);
        oven[i] = minoven;
        
    }

    for(int i = 1; i <= N; i++){
        cin >> dough[i];
        mini = min(dough[i], mini);
    }
    // 해당 반죽이 이전 반죽보다 작으면 그 위에 살포시 얹으면 된다. 그리고 걸린 마지막 지점은 위로 한칸 올라가게 된다.
    for(int i = 1; i <= N; i++){
        if(i != 1 && dough[i] <= dough[i - 1]){
            blocked--;
        }
        // 이전 반죽보다 크다면
        else{
            // 맨 마지막으로 걸린 지점부터 맨 위까지 쭉 탐색해서
            for(int j = blocked - 1; j >= 1; j--){
                // 오븐보다 반죽이 더 클 경우 위로 한칸씩 계속 올려준다. 즉 반죽이 통과되다가 걸리는 지점을 밑에서부터 찾아주는 것이다.
                if(oven[j] < dough[i]){
                    blocked--;
                }
                // 쭉 올리다 오븐의 반지름이 더 커지게 되면 해당 지점까지는 통과된 것이다.
                else break;
            }
            // 특정 위치에서 걸린 것이므로 반죽은 그 위치보다 한칸 위에 얹혀있을 것이다.
            blocked--;
        }
    }
    // 걸린 지점이 0보다 작거나 같아지게 되면 피자가 오븐 안에 전부 들어가지 못한 것이다.
    if(blocked <= 0) blocked = 0;
    cout << blocked;
    return 0;
}
