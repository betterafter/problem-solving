<span style="font-family:Lato,PingFang SC,Microsoft YaHei,sans-serif">

## programmers 43105 - 정수 삼각형


### 문제 
<b>https://programmers.co.kr/learn/courses/30/lessons/43105</b>


<br/><br/><br/><br/><br/><br/>


### 문제 풀이<b>

완전 전형적인 dp 문제. 어떤 지점에 도달할 때 최대를 dp배열에 저장하면서 쌓아나간다고 생각하면 됨.

t 배열에 삼각형 만들고 점화식을 세운다.

1
2 3
4 5 6


이면 dp[1][0] = max(dp[1][0], dp[0][0] + t[1][0])
dp[1][1] = max(dp[1][1], dp[0][0] + t[1][1])
이거 반복. 그럼 아래와 같이 나올 것이다.

1
3 4
7 9 10


그냥 밑에 줄의 2개 인덱스에 dp 연산 박아주면 끝임.

끗.
</span>
