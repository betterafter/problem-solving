#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>
#include <queue>
#include <map>

using namespace std;


vector<int> v;
vector<int>::iterator low;
vector<int>::iterator high;

// int lower_bound(vector<int> arr, int n, int key){
//     int start = 0; int end = n;
//     while(end - start > 0){
//         int mid = (start + end) / 2;
//         if(arr[mid] < key){
//             start = mid + 1;
//         }
//         else if(arr[mid] >= key){
//             end = mid;
//         }
//     }
//     return end;
// }

// int upper_bound(vector<int> arr, int n, int key){
//     int start = 0; int end = n;
//     while(end - start > 0){
//         int mid = (start + end) / 2;
//         if(arr[mid] <= key){
//             start = mid + 1;
//         }
//         else if(arr[mid] > key){
//             end = mid;
//         }
//     }
//     return end;
// }


int main(){

    cin.tie(NULL);
    ios_base::sync_with_stdio(false);


    int n; cin >> n;
    for(int i = 0; i < n; i++){
        int t; cin >> t;
        v.push_back(t);
    }

    sort(v.begin(), v.end());
    int nn; cin >> nn;
    for(int i = 0; i < nn; i++){
        int t; cin >> t;

        low = lower_bound(v.begin(), v.end(), t);
        high = lower_bound(v.begin(), v.end(), t + 1);
        cout << high - low << " ";
    }

    return 0;
}
