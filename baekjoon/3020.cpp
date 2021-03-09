#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <math.h>

using namespace std;

// 이진 탐색으로 구현한 lower_bound
long long lower_bound(int arr[], int n, int key){
    int start = 0; int end = n;
    while(end - start > 0){
        int mid = (start + end) / 2;
        if(arr[mid] < key){
            start = mid + 1;
        }
        else if(arr[mid] >= key){
            end = mid;
        }
    }
    return end;
}
// 이진 탐색으로 구현한 upper_bound
long long upper_bound(int arr[], int n, int key){
    int start = 0; int end = n;
    while(end - start > 0){
        int mid = (start + end) / 2;
        if(arr[mid] <= key){
            start = mid + 1;
        }
        else if(arr[mid] > key){
            end = mid;
        }
    }
    return end;
}

int main(){

    int bot[100010], top[100010];
    int N, H; cin >> N >> H;
    int less_destroy = N, less_cnt = 1;
    for(int i = 0; i < N / 2; i++){
        cin >> bot[i] >> top[i];
    }

    sort(bot, bot + N / 2); sort(top, top + N / 2);

    // ex) 1번째 구간 -> 길이가 1 이상 -> 석순은 길이가 1 이상이며 종유석은 길이가 H - 1 이상인 것.
    for(int i = 1; i <= H; i++){
        // 석순에 대한 범위
        int low_bot_dest = lower_bound(bot, N / 2, i);
        int up_bot_dest = N / 2;
        // 종유석에 대한 범위
        int low_top_dest = lower_bound(top, N / 2, H - i + 1);
        int up_top_dest = N / 2;

        int bot_cnt = up_bot_dest - low_bot_dest;
        int top_cnt = up_top_dest - low_top_dest;

        // 이전에 찾은 최소 파괴 수가 현재 파괴한 수와 같으면 개수를 추가한다. 
        if(less_destroy == bot_cnt + top_cnt) less_cnt++;
        // 그렇지 않으면 상황에 따라 갱신하거나 그대로 둔다.
        else{
            if(less_destroy > bot_cnt + top_cnt){
                less_destroy = bot_cnt + top_cnt;
                less_cnt = 1;
            }
        }
    }

    cout << less_destroy << " " << less_cnt;
    return 0;
}