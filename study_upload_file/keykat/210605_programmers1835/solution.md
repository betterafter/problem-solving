<span style="font-family:Lato,PingFang SC,Microsoft YaHei,sans-serif">

## programmers 1835 - 단체사진 찍기


### 문제 
<b>https://programmers.co.kr/learn/courses/30/lessons/1835</b>


<br/><br/><br/><br/><br/><br/>


### 문제 풀이<b>

문제 개 쓰레기임. 입력이 거의 백준 스타일
문제 자체는 쉽다. dfs로 일렬로 설 수 있는 모든 경우의 수 (8*7*6*5*4*3*2*1 가지)를 입력된 조건에 맞춰 파악하면 된다. 입력된 조건이 true면 계속 탐색, 아니면 false
모든 입력에 대하여 true이면 모든 조건에 만족 --> 가능한 경우 + 1

의 알고리즘인데, 제출해보면 문제가 1개 밖에 없다. 근데 무조건 틀리게 나옴.
알고보니 그 한개의 문제에 여러개의 테스트케이스를 박아놨음. 그래서 res 초기화 해야되고 dfs를 모든 테스트케이스에 대해 전부 돌면 시간 터지므로 약 40000개의 경우를 미리 구하고 어디다 저장해놓은 후에 불러다 써야됨.

</span>
