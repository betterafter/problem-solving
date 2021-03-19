<span style="font-family:Lato,PingFang SC,Microsoft YaHei,sans-serif">

## programmers 42587 - 프린터


### 문제 
<b>https://programmers.co.kr/learn/courses/30/lessons/42587</b>


<br/><br/><br/><br/><br/><br/>


### 문제 풀이<b>
큐를 사용하는 가장 대표적인 문제로, 여러가지 형태로 자주 변형되는 문제이다. 특히 큐를 사용하는 것은 BFS와도 많이 연관되므로 잘 익혀두면 좋겠다. 아래의 3가지 조건만 잘 지켜준다면 어렵지 않은 문제이다.
1. 인쇄 대기목록의 가장 앞에 있는 문서(J)를 대기목록에서 꺼냅니다.
2. 나머지 인쇄 대기목록에서 J보다 중요도가 높은 문서가 한 개라도 존재하면 J를 대기목록의 가장 마지막에 넣습니다.
3. 그렇지 않으면 J를 인쇄합니다.

사실 상 아래의 코드 하나로 이 문제에 대한 설명이 해결된다.
```java
 while(!q.empty()){
    int order = q.front().first, prio = q.front().second; q.pop();
    bool isExist = false;
    for(int i = prio + 1; i < 10; i++){
        if(priority[i] > 0){
            isExist = true; break;
        }
    }
    if(isExist) q.push(make_pair(order, prio));
    else{
        priority[prio]--;
        if(order == location){
            answer = priorities.size() - q.size(); break;
        }
    }
}
```

현재의 위치와 우선순위를 pair로 묶은 큐를 계속 돌아본다. 현재의 문서의 우선순위를 확인하고, 전체 문서 중에 현재의 문서보다 우선순위가 높은 문서가 있다면 다시 큐에 넣고 다음 걸 체크해주는 것을 반복하면 된다. 이 때 priority 배열에 전체 문서의 우선순위를 모두 담아서 모든 문서의 우선순위를 체크하기 편하게 만들었고, 문서가 큐에서 빠질 때마다 같이 하나씩 빼게 만들었다.
</b>
</span>
