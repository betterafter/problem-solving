<span style="font-family:Lato,PingFang SC,Microsoft YaHei,sans-serif">

## programmers 42861 - 섬 연결하기


### 문제 
<b>https://programmers.co.kr/learn/courses/30/lessons/42861</b>


<br/><br/><br/><br/><br/><br/>


### 문제 풀이<b>
문제 분류도 탐욕법 (Greedy) 로 되어있고, 조금 간단해 보여서 쉬운 문제라고 생각할 수 있지만, 정확한 아이디어로 풀지 않는다면 조금 헤맬 수도 있을 것이라고 생각한다. 
사실 "최소의 비용"과 "모든 노드의 연결"이라는 조건으로 이 문제는 최소 신장 트리 유형이라고 볼 수 있을 것이다. 보통 크루스칼 알고리즘 (kruskal's algorithm)과 프림 알고리즘 (Prim's algorithm)은 최소 가중치를 가지는 간선에서부터 그 다음으로 작은 가중치를 가지는 간선을 탐색하기 때문에 탐욕법의 특성을 가지게 된다. 두 알고리즘에 대한 설명을 아래의 링크에서 확인할 수 있다.

https://keykat7.blogspot.com/2019/11/algorithm-minimum-spanning-tree-mst.html

크루스칼 알고리즘을 사용하기 위해선 유니온-파인드로 사이클이 생기는지 체크하고 사이클이 생기지 않을 때만 chunk에 포함하고 총 거리를 더해주면 된다. 

```java
int find(int x){
    if(x == parent[x]) return x;
    return parent[x] = find(parent[x]);
}

void uni(int n, int m){
    n = find(n); m = find(m);
    parent[n] = m;
}
```
유니온-파인드의 기본적인 형태로 만들었다. 각 노드의 parent는 자기 자신으로 따로 초기화해주고 uni 함수에서 노드 n과 m을 같은 부모를 가지게 함으로써 하나의 집합으로 묶어주었다.

```java
int idx = 0;
while(idx < costs.size()){
    int n = costs[idx][0], m = costs[idx][1], len = costs[idx][2];
    if(find(n) != find(m)){
        uni(n, m); answer += len;
    }
    idx++;
}
```
costs에서 가중치가 작은 값부터 가져오고 사이클이 형성되지 않을 때 (find(n) != find(m)), 두 노드를 같은 집합으로 묶고 가중치를 더해주었다.

구현 자체는 어렵지 않지만 해당 문제를 보고 최소 신장 트리 유형이라는 것을 떠올릴 수 있는지 확인하는 문제였다.
</b>
</span>
