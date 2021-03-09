#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <math.h>

using namespace std;

// 잘못 푼 내용
// 1. 모든 배열 내에서 빈 공간이 있는지 전부 돌면서 체크하려다가 시간초과. 그냥 추가되면 추가된 개수를 1개씩 카운트해서 전체개수랑 같아지면 끝내면 되는 거였음.
// 2. while문 내에서 상 하 좌 우 에 대해 회전을 일일이 하면서 좌표이동을 시켰는데, 이 때 각 모서리에서 이동마다 추가된 개수 = 전체 개수를 확인해줘야함.
//    여기서 확인 안하고 while의 조건에만 체크를 해줘서 시간초과. (이럴 경우 while문 내의 모든 for문을 돌기 전까지 계속 돌기 때문에 시간이 좀 더 오래걸림)
// 3. cout으로 하니까 시간이 오래걸림. printf(%*d)로 하니까 단축
// 4. 전체 배열에 넣으면 메모리 초과
// 5. 모든 행의 길이가 같아야 하므로 전체 원소 중에 가장 긴 녀석을 실시간으로 찾아주고 마지막에 그 녀석의 길이를 확인해서 다른 원소들도 그 길이에 맞춰 공백을 추가.
//    이 때 한칸씩 좌표 이동이므로 최대값도 그냥 1 증가하면 됨. 굳이 max로 계속 크기 비교 할 필요가 없었음.
// 6. 1부터 시작 안하고 2, 3, 4, 5, ... 부터 회전을 시켜서 82퍼에서 시간초과가 났음. 주의할 것. 

int res[50][5];
int maxi = 0;

int numlen(int num){
    int len = 0;
    while(num != 0){
        num = num / 10; len++;
    }
    return len;
}

// movx, movy는 배열은 음수 인덱스를 가질 수 없으므로 맨 오른쪽 위의 좌표가 (0, 0)에 오도록 만들어주기 위해 움직이는 값
void arrcycle(int starty, int startx, int endy, int endx, int movy, int movx, int res[50][5]){

    int len = 2; int sx = 1, sy = 0, sv = 2;
    int total = (endx - startx + 1) * (endy - starty + 1); 
    int ssy, ssx;

    int x = 0, y = 0, v = 1;
    // 소용돌이 가장 가운데 (값이 1인 것) 가 좌표 포함이 되어있으면 넣어준다.
    if(startx <= x && endx >= x && starty <= y && endy >= y){
        res[y + movy][x + movx] = v; total--; maxi = v;
    }

    // 풀이 방식은 사람마다 다르겠지만 필자는 오른쪽변, 윗변, 왼쪽변, 아랫변을 순서대로 탐색하는 것을 1 사이클로 보고 풀었다.
    // 이 때 해당 좌표가 포함된 좌표인지 체크해줘야한다.
    // 참고로 해당 소용돌이는 맨 가운데인 1을 제외한 2, 3, 4, ... 부터 시작하므로 1이 좌표에 포함되는지는 따로 체크해줬다.
    // 일단 시작 좌표를 값이 2인 (1, 0) 부터 시작해준다.
    while(total != 0){
        // ssy, ssx는 해당 좌표가 어디까지 직진할지 체크하기 위한 좌표.
        ssy = sy - len + 1;
        for(int i = 0; i < len; i++){
            // 좌표가 포함되어 있으면 결과 좌표에 해당 값을 표시해준다. 이 때 전체 개수도 1개 빼준다. 이 때 전체값이 0이 되어버리면 더 구할필요없이 함수 탈출한다.
            if(startx <= sx && endx >= sx && starty <= sy && endy >= sy){
                res[sy + movy][sx + movx] = sv; total--; maxi = sv; if(total == 0) return;
            }
            // 소용돌이로 값이 1씩 커지는 형태이므로 현재값도 1 커져야한다.
            sv++; 
            // sy가 목표지점까지 도달할때까지는 1씩 빼준다.
            if(sy > ssy) sy--;
        }
        // 위로 올라간 후 윗변을 탐색해야하므로 x값을 왼쪽으로 이동시킨다.
        sx = sx - 1;

        // 알고리즘 자체가 좀 쓸데 없이 복잡한데, 쉽게 생각해서 오른쪽변 탐색 (2, 3) -> 윗변 탐색 (4, 5) -> 왼쪽변 탐색 (6, 7) -> 아랫변 탐색 (8, 9)
        // -> 다시 오른쪽변 탐색 (10, 11, 12, 13) -> 윗변 탐색 (14, 15, 16, 17) -> ... 를 반복해주는 것
        // 이 때 한 사이클의 변 길이는 2->4->6->8-> ... 로 커진다.

        ssx = sx - len + 1;
        for(int i = 0; i < len; i++){

            if(startx <= sx && endx >= sx && starty <= sy && endy >= sy){
                res[sy + movy][sx + movx] = sv; total--; maxi = sv; if(total == 0) return; 
            }
            sv++;
            if(sx > ssx) sx--;
        }
        sy = sy + 1;

        ssy = sy + len - 1;
        for(int i = 0; i < len; i++){
            if(startx <= sx && endx >= sx && starty <= sy && endy >= sy){
                res[sy + movy][sx + movx] = sv; total--; maxi = sv; if(total == 0) return; 
            }
            sv++;
            if(sy < ssy) sy++;
        }
        sx = sx + 1;
 
        ssx = sx + len - 1;
        for(int i = 0; i < len; i++){
            if(startx <= sx && endx >= sx && starty <= sy && endy >= sy){
                res[sy + movy][sx + movx] = sv; total--; maxi = sv; if(total == 0) return; 
            }
            sv++;
            if(sx < ssx) sx++;
        }
        sx++;
        len += 2;
    }
}



int main(){

    int r1, c1, r2, c2;
    cin >> r1 >> c1 >> r2 >> c2;
    int movx = 0, movy = 0;

    movy = -r1; movx = -c1;


    arrcycle(r1, c1, r2, c2, movy, movx, res);

    int lennum = numlen(maxi);

    // for(int i = 0; i <= r2 - r1; i++){
    //     for(int j = 0; j <= c2 - c1; j++){
    //         int cnt = lennum - numlen(res[i][j]);
    //         for(int k = 0; k < cnt; k++){
    //             cout << " ";
    //         } 
    //         cout << res[i][j] << " ";
    //     }
    //     cout << '\n';
    // }

    for (int i = 0; i <= r2-r1; i++)                
	{
		for (int j = 0; j <= c2-c1; j++)
		{
			printf("%*d ", lennum, res[i][j]);                   //출력
		}
		printf("\n");
	}

    return 0;
}