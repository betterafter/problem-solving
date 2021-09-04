<span style="font-family:Lato,PingFang SC,Microsoft YaHei,sans-serif">

## programmers 17680 - 캐시


### 문제 
<b>https://programmers.co.kr/learn/courses/30/lessons/17680</b>


<br/><br/><br/><br/><br/><br/>


### 문제 풀이<b>

문제가 너무 쉬워서 첫번째꺼 3시간 걸렸는데 이건 2분 걸렸다.. lru를 모르면 풀기 힘들겠지만, 알면 너무 쉽다. 사실 lru 자체를 구현할 필요도 없고 굉장히 비슷한 행동만 하게 리스트로 표현하면 된다. (원래는 Doubly Linked List + Hash Map을 이용한 알고리즘)
lru 에 대해선 노션에 써놨던 내용을 복붙했다.

**LRU : Hash Map과 Doubly Linked List의 혼합 방식. (get : O(1), set : O(1))**

**HashMap<key String, LRU Node> : 어떤 키값에 해당하는 LRU 노드를 쌍으로 묶어서 준다.** 

(1) 왜 굳이 Hash Map과 Doubly Linked List를 같이 쓰느냐? → Hash Map에서 어떤 키 값에 대한 노드를 O(1)로 바로 찾을 수 있어서 좋고, 이 때 오랫동안 사용하지 않아서 뒤로 밀리는 Node는 사라지게 되면서 Hash Map에 연결된 Node 또한 Null로 바뀌고 해당 key에 해당하는 Hash Map에 저장된 데이터 또한 소멸될 것. 즉 Doubly Linked List만 사용하면 리스트를 다 뒤져야하니 O(n)의 시간이 나올테고, 특정 key에 따라 Hash Map에 다 저장해버리는 건 공간 복잡도 면에서 엄청나게 비효율적이게 될 것. 

(2) Hash Map에 있는 키를 꼭 지울 필요가 있는가? → 당연히 공간이 무제한이라면 지울 필요가 없지만, 데이터가 끊임 없이 쌓이는 경우 Hash Map에 저장된 내용이 너무 많아지게 되고, 공간적으로 매우 비효율적이 됨. 캐시에서 빠진 노드에 대한 키 값은 지워가는 것이 가장 효율적.

ex) 캐시 사이즈가 3인 LRU에서 apple → banana → orange → banana → grape → apple 순으로 찾기
```
      **Hash Map**                                                    **Doubly Linked List**

(1) map[apple] = apple(n)                                HEAD - apple(n) - TAIL



(2) map[apple] = apple(n)                               HEAD - banana(n) - apple(n) - TAIL

map[banana] = banana(n)



(3) map[apple] = apple(n)                               HEAD - orange(n) - banana(n) - apple(n) - TAIL

map[banana] = banana(n)

map[orange] = orange(n)



(4) map[apple] = apple(n)                               HEAD - banana(n) - orange(n)  - apple(n) - TAIL

map[banana] = banana(n)

map[orange] = orange(n)



(5) map[banana] = banana(n)                         HEAD - grape(n) - banana(n) - orange(n)  - TAIL

map[orange] = orange(n)

map[grape] = grape(n)



(6) map[banana] = banana(n)                         HEAD - apple(n) - grape(n) - banana(n)  - TAIL

map[grape] = grape(n)

map[apple] = apple(n)
```
</span>
