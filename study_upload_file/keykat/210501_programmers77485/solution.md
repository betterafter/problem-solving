<span style="font-family:Lato,PingFang SC,Microsoft YaHei,sans-serif">

## programmers 77485 - 행렬 테두리 회전하기


### 문제 
<b>https://programmers.co.kr/learn/courses/30/lessons/77485</b>


<br/><br/><br/><br/><br/><br/>


### 문제 풀이<b>

문제 요약
- 배열에 1 ~ rows * colums의 수가 들어있다.
- 지정한 범위 내의 사각형의 테두리 회전시키기
- 그 중에서 가장 작은 수 구하기
- 이 과정을 반복해서 각 과정 속에서 구한 가장 작은 수를 전부 출력
- 지정한 사각형은 아래의 모양과 같다


(x1, y1)------(x1, y2)
| &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;|
| &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;|
| &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;|
| &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;|
| &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;|   
(x2, y1)------(x2, y2)

가로축이 y가 커지는 방향이고, 세로축이 x가 커지는 방향이다. 왜 이렇게 만들었는지는 모르지만 문제가 그렇다.


결국 회전하는 함수를 따로 만들어놓고, queries의 회전 크기에 맞춰 회전하면서 해당 queries 실행 중 가장 작은 값을 따로 저장하고 나중에 한꺼번에 출력하면 됨. 아이디어는 어려울 게 없고 그냥 빡구현 문제. x, y 좌표 때문에 시간 좀 잡아 먹었다. (눈치를 너무 늦게 챔)

일단 회전부터 구현한다. 상 -> 우 -> 하 -> 좌 순서로 돌렸는데, 순서는 상관 없음
```c++
vector<vector<int> > rotation(vector<vector<int> > queries, int x1, int y1, int x2, int y2){

    mini = 10000000000;
    vector<vector<int> > res = queries;
    // 위쪽 테두리
    for(int i = x1 + 1; i <= x2; i++){
        res[y1][i] = queries[y1][i - 1];
        mini = min(res[y1][i], mini);
    }
    // 오른쪽 테두리
    for(int i = y1 + 1; i <= y2; i++){
        res[i][x2] = queries[i - 1][x2];
        mini = min(res[i][x2], mini);
    }
    // 아래쪽 테두리
    for(int i = x2 - 1; i >= x1; i--){
        res[y2][i] = queries[y2][i + 1];
        mini = min(res[y2][i], mini);
    }
    // 왼쪽 테두리
    for(int i = y2 - 1; i >= y1; i--){
        res[i][x1] = queries[i + 1][x1];
        mini = min(res[i][x1], mini);
    }
    answer.push_back(mini);
    return res;
}
```
중요한 것은 이 한번의 회전에서의 최소값을 구해야하므로 mini에 최소값을 넣고, 회전이 끝나면 최소값을 answer에 넣어준다.

배열에 1 ~ rows * colums 집어넣기
```c++
 for(int i = 1; i <= rows; i++){
        for(int j = 1; j <= columns; j++){
            table[i][j] = (i - 1) * columns + j;
        }
    }
``` 

쿼리마다 회전 실행
```
for(int i = 0; i < queries.size(); i++){
        table = rotation(table, queries[i][1], queries[i][0], queries[i][3], queries[i][2]);
    }
```


</b>
</span>
