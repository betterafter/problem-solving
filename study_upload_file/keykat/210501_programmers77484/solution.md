<span style="font-family:Lato,PingFang SC,Microsoft YaHei,sans-serif">

## programmers 77484 - 로또의 최고순위와 최저순위


### 문제 
<b>https://programmers.co.kr/learn/courses/30/lessons/77484</b>


<br/><br/><br/><br/><br/><br/>


### 문제 풀이<b>

문제 요악

- 지워진 수는 0, 지워지지 않은 수는 1 ~ 45까지 표현
- 순위 기준이 문제와 같을 때, 최고 순위와 최저 순위 구하기
- 즉 지워진 수들이 전부 맞는 수들이면 최고 순위, 지워진 수들이 한나도 안 맞으면 최저 순위가 됨

애당초 숫자가 6개 밖에 없어서 for문을 몇개를 돌리든 시간은 문제가 안 된다. 그냥 완전 탐색으로 충분히 풀 수 있음

지워진 수 (0)이 몇갠지 따로 세주고, 안 지워진 수 중에 몇개가 맞는지 세준 후, 지워진 수를 n개라고 놓는다면 (table은 순위 변환 표) : 

1. 최고 순위 : 지워진 수 table(6 - n) + table(n)
2. 최저 순위 : 지워진 수 table(6 - n)

로 구하면 끝


순위 변환 테이블 구현
```c++
int trans(int n){
    if(n == 6) return 1;
    if(n == 5) return 2;
    if(n == 4) return 3;
    if(n == 3) return 4;
    if(n == 2) return 5;
    if(n == 1 || n == 0) return 6;
}
```
지워진 수, 안지워진 수 구하기
```c++
for(int i = 0; i < lottos.size(); i++){
    // 지워진 수의 개수 세주고
    if(lottos[i] == 0){
        zero++;
    }
    // 안 지워진 수의 개수도 세준다.
    else{
        for(int j = 0; j < win_nums.size(); j++){
            if(lottos[i] == win_nums[j]){
                cnt++; break;
            }
        }
    }
}
```

그리고 최저 순위, 최고 순위 answer에 넣기
```c++
answer.push_back(trans(cnt)); // 최저 순위 : (6 - n)
answer.push_back(trans(cnt + zero)); // 최고 순위
```


</b>
</span>
