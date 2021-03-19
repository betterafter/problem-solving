<span style="font-family:Lato,PingFang SC,Microsoft YaHei,sans-serif">

## programmers 72411 - 메뉴 리뉴얼


### 문제 
<b>https://programmers.co.kr/learn/courses/30/lessons/72411</b>


<br/><br/><br/><br/><br/><br/>


### 문제 풀이<b>
문제를 푸는 여러가지 방법이 존재할 수 있지만 필자는 DFS를 이용하여 문제를 해결하였으며, 마찬가지로 BFS를 사용해서 풀어도 무방하다고 생각한다. course의 요리 가짓 수를 보고 각 손님이 주문한 요리 리스트에서 만들 수 있는 세트 메뉴의 조합을 모두 만든 후 해당 세트 메뉴가 총 몇 번 나오는지를 세주면 된다.
<br><br><br><br>
문제 예시로 나와있는 1번 손님이 주문한 메뉴는 아래와 같다.
<i>A, B, C, F, G</i>

<br/>
문제에서 코스요리 메뉴는 최소 2가지 이상의 단품 메뉴로 구성되어야 한다고 했으므로, 조합한 코스 요리 메뉴의 길이가 2 이상인 것들만 만들어주면 된다. 
<br><br>

길이가 2일 경우 : AB, AC, AF, AG, BC, BF, BG, CF, CG, FG
길이가 3일 경우 : ABC, ABF, ABG, BCF, BCG, BFG, CFG
길이가 4일 경우 : ABCF, ABCG, ABFG, ACFG, BCFG
길이가 5일 경우 : ABCFG

<br><br>
이번엔 2번 손님이 주문한 메뉴를 보자. 2번 손님이 주문한 메뉴와 만들 수 있는 코스 요리 메뉴는 아래와 같다.
<i>A, C</i>

길이가 2일 경우 : AC

<br><br>
따라서 1번 손님과 2번 손님으로부터 AC라는 공통된 코스 요리 메뉴를 확인할 수 있다. 이와 같이 모든 손님에게서 나올 수 있는 코스 요리 메뉴의 조합을 모두 체크하고, 만들어진 코스 요리 메뉴를 map 자료구조에 집어넣어 어떤 코스 요리 메뉴가 몇 명의 손님에 의해 만들어질 수 있는지 체크하고, 제일 많은 손님에 의해 선택된 코스 요리를 꺼내어주면 된다.

사실 상 코스 요리 메뉴의 조합을 제대로 만들 수만 있다면 쉽게 풀 수 있는 문제이며, DFS의 핵심 아이디어는 아래와 같다.
```C++
void dfs(int curr, int clength, int tlength, string orders, string order){

    sort(order.begin(), order.end());

    if(clength == tlength){

        map<string, int> :: iterator iter;
        for(iter = m.begin(); iter != m.end(); iter++){
            if(iter -> first == order){
                m[iter -> first]++;
                return;
            }
        }
        m[order] = 1; return;
    }

    for(int i = curr; i < orders.size(); i++){
        order += orders[i];
        dfs(i + 1, clength + 1, tlength, orders, order);
        order = order.substr(0, order.length() - 1);
    }
}
```
curr : orders(손님이 주문한 메뉴들)에서 몇 번 index부터 탐색해야하는지 담은 변수
clength : 현재 조합하고 있는 코스요리메뉴의 현재까지의 길이 
tlength : 현재 조합하고 있는 코스요리메뉴의 목표 길이
orders : 손님이 주문한 메뉴
order : 현재 조합하고 있는 코스요리메뉴 문자열

<br>
curr번 index부터 orders의 끝까지 돌면서, DFS 탐색으로 clength = tlength가 될 때까지 order 변수를 만들어주고, 다 만든 후에는 map 자료구조에 넣어주면 된다.

</b>
</span>
