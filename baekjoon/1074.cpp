#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>
#include <queue>
#include <set>
#include <stack>

using namespace std;

int order;
bool allcheckup = false;
int r, c;

void divider(int x, int y, int length){
    if(allcheckup) return;
    if(length == 2){
        if(y == r && c == x){
            allcheckup = true; return;
        }
        order++;
        if(y == r && c == x + 1){
            allcheckup = true; return;
        }
        order++;
        if(y + 1 == r && c == x){
            allcheckup = true; return;
        }
        order++;
        if(y + 1 == r && c == x + 1){
            allcheckup = true; return;
        }
        order++;
        return;
    }
    else{
        divider(x, y, length / 2);
        divider(x + length / 2, y, length / 2);
        divider(x, y + length / 2, length / 2);
        divider(x + length / 2, y + length / 2, length / 2);
    }
}

int main(){

    ios::sync_with_stdio(false);
	cin.tie(NULL);

    int N; cin >> N >> r >> c;

    divider(0, 0, pow(2, N));

    cout << order;
    return 0;
}
