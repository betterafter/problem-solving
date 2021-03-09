#include <stdio.h>
#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>

using namespace std;

// 이 문제는 조건만 봐도 알 수 있듯이 시간 제한이 아주 빠듯하다. 따라서 시간을 잡아먹을 수 있는 요소들을 최대한 줄이는 것이 중요하다.

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

    long long answer = 0;
    int t; cin >> t;

    // 기본적인 아이디어는 A, B, C, D 합쳐서 0이 되는 쌍을 찾으면 되는데, 이럴 경우 for문을 4번 돌려야된다. 당연히 시간초과가 날 것이다. 따라서 
    // A, B의 특정 쌍 + C, D의 특정 쌍을 더한 값이 0이 되는 방식으로 바꿔서 풀어볼 수 있다.

    int A[4010], B[4010], C[4010], D[4010];
    // add_AB 배열과 add_CD 배열을 처음에 vector로 선언해서 더한 결과를 push_back으로 집어넣었는데 7퍼에서 시간초과가 난다.
    // 아마 벡터에 값을 삽입하는게 기본 배열보다 시간이 오래걸려 그런 것 같다.
    // 생각해보면 배열은 이미 공간을 정해놓고 그 자리에 값을 넣는 것인데 벡터는 공간을 실시간으로 할당하고 집어넣는 개념이니까 시간이 좀 더 걸릴 만 하다.
    int add_AB[16000000], add_CD[16000000];
    for(int i = 0; i < t; i++){
        cin >> A[i] >> B[i] >> C[i] >> D[i];
    }

    for(int i = 0; i < t; i++){
        for(int j = 0; j < t; j++){
            add_AB[i * t + j] = A[i] + B[j];
            add_CD[i * t + j] = C[i] + D[j];
        }
    }
    // sort는 AB는 할 필요 없다. 어차피 이분 탐색할 배열은 CD뿐이니까.
    sort(add_CD, add_CD + t * t); 

    for(int i = 0; i < t * t; i++){
        int left = 0, right = t * t;
        // lower_bound 및 upper_bound로 AB + CD가 0이 되는 인덱스를 찾아 그 값의 범위를 구해준다.
        int highkey = upper_bound(add_CD, t * t, -add_AB[i]);
        int lowkey = lower_bound(add_CD, t * t, -add_AB[i]);
        answer = answer + highkey - lowkey;
    }

    cout << answer;
    return 0;
}