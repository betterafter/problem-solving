<span style="font-family:Lato,PingFang SC,Microsoft YaHei,sans-serif">

## programmers 77486 - 다단계 칫솔 판매


### 문제 
<b>https://programmers.co.kr/learn/courses/30/lessons/77486</b>


<br/><br/><br/><br/><br/><br/>


### 문제 풀이<b>

문제 요약
- 진짜 다단계
- 트리로 본다면, 자식이 판 물건의 수익의 10%는 부모에게 가고, 90%는 자기가 가짐 (전형적인 다단계 구조)
- 10%가 1원 미만이면, 부모한테 안주고 그냥 자기가 다 가짐
- 트리에 있는 모든 노드가 각각 총 얼마 벌었는지 구하기

트리 빡구현 문제. 트리를 만들고 물건 팔면 부모한테 돈 떼주게 구현하면 됨.

일단 트리부터 만들기
```java
class node{

    
    String name; // 다단계 판매원의 이름
    node parent; // 판매원의 부모 노드
    ArrayList<node> child; // 판매원의 자식 노드들
    int money = 0; // 판매원이 벌은 수익
    HashMap<String, node> rootMap = new HashMap<>();
    // 루트 노드만 가지고 있는 HashMap인데, 왜 있는지 아래에서 설명

    public node(){};

    public node(String name, node parent, ArrayList<node> child, int money){
        this.name = name;
        this.parent = parent;
        this.child = child;
        this.money = money;
    }
    
    // 트리 연결하기
    void connect(String target, String c, node curr, node root){

        if(curr.name.equals(target)){
            // 노드 새로 만들어서 자식으로 붙혀주기
            node childNode = new node(c, curr, new ArrayList<>(), 0);
            curr.child.add(childNode);
            // 판매원맵에 따로 저장 
            root.rootMap.put(c, childNode);
            return;
        }
        // 없으면 냅두고
        if(curr.child.size() <= 0) return;
        // 있으면 자식 가지고 다시 재귀로 찾기
        for(int i = 0; i < curr.child.size(); i++){
            node n = curr.child.get(i);
            connect(target, c, n, root);
        }
    }

    // 트리에서 판매원 찾기 
    node search(String target, node curr){

        node temp = curr;
        // 현재 노드의 판매원 이름이 찾는 사람이면 이거 리턴
        if(curr.name.equals(target)){
            return curr;
        }
        // 자식들에도 없으면 null로 반환
        if(curr.child.size() <= 0) return null;

        node n;
        for(int i = 0; i < curr.child.size(); i++){
            n = search(target, curr.child.get(i));
            // 재귀로 찾은 것 중에 있으면 curr를 그 노드로 저장
            if(n != null) {curr = n; break;}
        }
        // 찾은게 없으면 null 반환
        if(temp == curr) return null;
        // 있으면 저장한 거 반환. 보통 있는게 보장되서 사실 상 바로 윗줄은 필요없긴 함
        else return curr;
    }

    // 부모한테 수익 나눠주기
    void send(node curr, int value){

        // 수익 1% 미만이면 지가 다 갖고
        if(value * 10 / 100 < 1){
            curr.money += value; return;
        }
        // 현재 판매원이 루트면 더 이상 나눠줄 필요 없고
        if(curr.parent == null) return;
        // 나머지는 지가 갖기
        curr.money += value - value * 10 / 100;
        // 수익 10%는 부모한테 올려주고
        send(curr.parent, value * 10 / 100);
    }
}
```

근데 판매원 맵이 왜 필요하냐? 판매원을 찾아서 부모에게 수익을 분배하는 과정에서 HashMap에 해당 판매원의 이름 - 노드 주소로 저장을 안하고 트리 탐색으로 찾는 방법으로 하니까 맨 밑의 딱 1문제가 시간이 터짐. 그래서 HashMap에 저장 해놓고 바로바로 찾을 수 있게 만드니까 간신히 통과됨.
```java
node root = new node("-", null, new ArrayList<>(), 0);

// 트리 구축
for(int i = 0; i < enroll.length; i++){
    root.connect(referral[i], enroll[i], root, root);
}

// 시간 초과 때문에 root에 HashMap<String, node> 로 매핑해서 조금 더 빠르게 찾게 만듬
for(int i = 0; i < seller.length; i++){
    root.send(root.rootMap.get(seller[i]), amount[i] * 100);
    //root.send(root.search(seller[i], root), amount[i] * 100);
}

// 트리 전체 돌면서 enroll에 있는 애들 각각 얼마 벌었는지 출력
answer = new int[enroll.length];
for(int i = 0; i < enroll.length; i++){
    answer[i] = root.search(enroll[i], root).money;
}
```

사실 상 트리 구현할 줄 모르면 못 풀고, 알면 푸는 문제였다. 조건이 너무 많아서 머리 터지는 줄

</b>
</span>
