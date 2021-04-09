<span style="font-family:Lato,PingFang SC,Microsoft YaHei,sans-serif">

## programmers 68645 - 삼각 달팽이


### 문제 
<b>https://programmers.co.kr/learn/courses/30/lessons/68645</b>


<br/><br/><br/><br/><br/><br/>


### 문제 풀이<b>

생각보다 별 거 없는 문제. 그냥 한바퀴 그려서 위에서부터 출력하면 된다. 아이디어는 아래와 같다.

1.일단 결과가 아래와 같이 나오는 모양이 있다고 치자.
&nbsp;&nbsp;&nbsp;&nbsp;1
&nbsp;&nbsp;2&nbsp;9
&nbsp;3&nbsp;10&nbsp;8
4&nbsp;5&nbsp;6&nbsp;7
이걸 왼쪽으로 다 밀어주는 모양으로 만들 것이다.
1
2 9
3 10 8
4 5 6 7

<br/>
2.저렇게 만드려면 입력할 때 왼쪽 맨 위에서 아래로 입력 -> 끝난 지점에서 오른쪽으로 입력 -> 왼쪽 위 대각선으로 입력 순서로 입력해준다. 즉 아래와 같다.

(2-1)
1
2  
3
4

(2-2)
1
2
3
4 5 6 7

(2-3)
1
2 9
3   8
4 5 6 7

(2-4)
1
2 9
3 10 8
4 5 6 7 

이렇게 만들면 되는데, 조건을 정해주기 조금 복잡하다. 밑으로는 n만큼 내려갔다가, 오른쪽으로 n-1만큼 이동하고, 왼쪽 위 대각선 방향으로 n-2만큼 이동하고, 또 내려가고... 인데 수학적으로 만드려면 못 만들 건 없지만 그냥 생각하기 귀찮다. 그래서 조금 다른 방법으로 했다.

1.일단 입력해야 할 공간 주변으로 -1을 집어 넣는다. 위의 모양으로 치면 아래와 같이 된다.

-1 -1
-1 &nbsp;0 -1
-1 &nbsp;0  &nbsp;0 -1
-1 &nbsp;0  &nbsp;0 &nbsp;0 -1
-1 &nbsp;0  &nbsp;0 &nbsp;0 &nbsp;0 -1
-1 -1 -1 -1 -1 -1 -1

2.이제 밑으로 내려가다가 -1이나 0이 아닌 다른 수가 나오면 오른쪽으로 꺾고, 오른쪽으로 쭉 가다가 역시 -1 또는 0이 아닌 수가 나오면 대각선 왼쪽 위 방향으로 꺾고, 또 쭉 가는 알고리즘을 반복하면 된다. 참고로 1층 짜리와 2층 짜리는 -1로 에워싸는 작업이 더 귀찮아서 그냥 직접 벡터에 넣고 return 해줬다.

(왜 이렇게 귀찮게 만들었냐면, 생각하는 게 더 귀찮아서)

```c++
    for(int i = 0; i <= n; i++) for(int j = 0; j <= n; j++) num[i][j] = 0;
    for(int i = 0; i <= n + 1; i++) num[i][0] = -1;
    for(int i = 0; i <= n + 2; i++) num[n + 1][i] = -1;
    for(int i = 0; i <= n + 1; i++) num[n + 1 - i][n + 2 - i] = -1;

```
조건에 만족하도록 -1로 메꿔준다.

```c++
int count = 1;
int cx = 1, cy = 1; 

while(true){

    // 1. 밑으로 내려가기
    while(num[cy][cx] == 0){
        num[cy][cx] = count;
        count++; 
        if(num[cy + 1][cx] == 0) cy++;
    }
    cx++;
        // 오른쪽으로 못가면 탐색 끝
    if(num[cy][cx] != 0) break;


    // 2. 오른쪽으로 가기
    while(num[cy][cx] == 0){
        num[cy][cx] = count;
        count++;
        if(num[cy][cx + 1] == 0) cx++;
    }
    cy--; cx--;
        // 대각선 왼쪽 위로 못 가면 탐색 끝
    if(num[cy][cx] != 0) break;
    // 3. 대각선 왼쪽 위로 올라가기
    while(num[cy][cx] == 0){
        num[cy][cx] = count;
        count++; 
        if(num[cy - 1][cx - 1] == 0){ cx--; cy--; }
    }
    cy++;

        // 밑으로 못 내려가면 탐색 끝
    if(num[cy][cx] != 0) break;
}
```
주석에 설명한대로 따라하면 된다. 어차피 빡구현 문제이므로 특별히 신경써야 할 알고리즘은 없고, 현재 좌표만 잘 갱신해주면 크게 어려울 것 없다.


<br/><br/><br/>
</b>
</span>
