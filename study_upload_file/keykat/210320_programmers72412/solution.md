<span style="font-family:Lato,PingFang SC,Microsoft YaHei,sans-serif">

## programmers 72412 - 순위 검색


### 문제 
<b>https://programmers.co.kr/learn/courses/30/lessons/72412</b>


<br/><br/><br/><br/><br/><br/>


### 문제 풀이<b>
방법을 알면 구현 자체는 너무 어려운 수준은 아닐 수 있지만, 4차원 배열을 이용해 데이터베이스 테이블과 유사한 형태를 구현하는 것과, 이분 탐색으로 시간을 줄이는 것이 생각하기 상당히 까다로우며, 조건에 맞게 전처리를 잘 해주어야 하기 때문에 카카오 코테 기준 3번에 위치해 있음에도 불구하고 쉬운 문제는 아니다.

문제는 간단하다. query에 적힌 조건과 점수에 부합한 지원자를 찾아서, 해당 부서에 지원할 수 있는 지원자가 몇 명인지 찾으면 되는 것이다. 다만,

"info 배열의 크기는 1 이상 50,000 이하입니다."

단순히 하나하나 비교하면 정확성 테스트는 맞을지 몰라도 효율성 부분에서는 무조건 탈락. 심지어 해당 query를 트리 형태로 저장한다고 해도 이 정도 규모면 시간 안에 들어오지 못할 가능성이 높다.

아래의 형태를 가지는 테이블을 4차원 배열에 어떻게 저장하는지가 1차 목표이며, 점수에 부합하는 지원자가 몇명인지 이분 탐색으로 빠르게 뽑아내는 것이 2차 목표이다. 아래와 같은 테이블이 있다고 할 때, infoTable이라는 4차원 배열에 넣어보자.

언어	   직군	    경력	  소울 푸드	  점수
java	backend	junior	pizza	    150
java	backend	junior	pizza	    200
java	backend	junior	pizza	    250

java	backend	senior	pizza	    100
java	backend	senior	pizza	    200

java	frontend	junior	pizza	    150
java	frontend	junior	pizza	    200

cpp	frontend	junior	pizza	    100
cpp	frontend	junior	pizza	    200

python	frontend	junior	pizza	    100

<br/><br/>

vector<int> infoTable[3][2][2][2];

infoTable에서 첫번째 인자는 java, cpp, python를,
infoTable에서 두번째 인자는 backend, frontend를,
infoTable에서 세번째 인자는 junior, senior를,
infoTable에서 네번째 인자는 pizza, chicken을 표시하는 것이며, 
어떤 값이 몇번 index에 들어갈지는 편한대로 설정하면 된다.

즉
infoTable[0][0][0][0] : {150, 200, 250}
infoTable[0][0][1][0] : {100, 200}
infoTable[0][1][0][0] : {150, 200}
infoTable[1][1][0][0] : {100, 200}
infoTable[2][1][0][0] : {100}

와 같은 형태로 저장할 수 있다는 것이다.

코드에서 language ~ food라는 int형 메서드가 있는데, 이것이 java, cpp, python, backend... 등등을 숫자로 변환하여 테이블의 인덱스화 하기 위한 함수이다.

```java
int language(string str){
    if(str == "java") return 0;
    else if(str == "python") return 1;
    else if(str == "cpp") return 2;
    else return 3;
}

int skill(string str){
    if(str == "backend") return 0;
    else if(str == "frontend") return 1;
    else return 2;
}

int career(string str){
    if(str == "junior") return 0;
    else if(str == "senior") return 1;
    else return 2;
}

int  food(string str){
    if(str == "pizza") return 0;
    else if(str == "chicken") return 1;
    else return 2;
}
```


이렇게 수치화 한 것은 solution 함수에서 infoTable에 저장하기 위해 사용된다.
```java
infoTable[ language(data[0]) ][ skill(data[1]) ][ career(data[2]) ][ food(data[3]) ].push_back(atoi(data[4].c_str()));
```

집어 넣은 지원자들은 이분 탐색을 위해 오름차순 정렬할 필요가 있다.
```java
 for(int i = 0; i < 3; i++)
        for(int j = 0; j < 2; j++)
            for(int k = 0; k < 2; k++)
                for(int l = 0; l < 2; l++)
                    sort(infoTable[i][j][k][l].begin(), infoTable[i][j][k][l].end());
```

<br/><br/>
여기까지 하면 1차 목표인 지원자의 table화가 얼추 끝난다. 이분 탐색을 안다는 가정 하에 함수만 설명하겠다.
```java
int getCount(vector<int> v, int point){
    if(v.size() == 0) return 0;
    else return (int)v.size() - (lower_bound(v.begin(), v.end(), point) - v.begin());
}
```
vector가 비어있으면 고려할 필요가 없고, lower bound를 이용해 오름차순 정렬되어 있는 지원자 중에 목표 점수 이상인 지원자를 뽑아야한다. 가령 
{100, 100, 150, 150, 150, 200, 200, 250}, 목표 점수 150 이라고 한다면 
index : 2 ~ 7 까지가 지원자가 되며, 8명 중에 6명이 적합한 지원자가 된다. lower_bound는 오름차순 정렬된 배열에서 중복값을 포함해 목표 점수의 가장 작은 인덱스를 뽑아주는데, v.begin을 빼주면 몇번째부터 있는지를 알 수 있게 된다. 즉 (lower_bound(v.begin(), v.end(), point) - v.begin())으로 2번째부터 150점 이상인 지원자 존재한다는 것을 알게 되며, 전체에서 2를 빼주어 총 몇명의 적합한 지원자가 존재하는지를 알 수 있게 된다.

```java
for(int i = 0; i < 3; i++){
    if(language(data[0]) == i || language(data[0]) == 3){
        for(int j = 0; j < 2; j++){
            if(skill(data[1]) == j || skill(data[1]) == 2){
                for(int k = 0; k < 2; k++){
                    if(career(data[2]) == k || career(data[2]) == 2){
                        for(int l = 0; l < 2; l++){
                            if(food(data[3]) == l || food(data[3]) == 2){
                                res[p] += getCount(infoTable[i][j][k][l], atoi(data[4].c_str()));
                            }
                        }              
                    }
                }
            }  
        }
    } 
}
```
solution 함수의 이 다중 for문은 주어진 query를 돌면서 해당 query에 적잡한 지원자 수를 뽑아내는 것이다. "-" (조건 상관 없음)은 각각 3, 2, 2, 2를 반환하도록 했는데, query의 data나 "-"인 것들만 통과시키면서 지원자의 수를 res 배열에 담아준다.



</b>
</span>
