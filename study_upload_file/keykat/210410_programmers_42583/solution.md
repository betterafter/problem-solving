<span style="font-family:Lato,PingFang SC,Microsoft YaHei,sans-serif">

## programmers 42583 - 다리를 지나는 트럭


### 문제 
<b>https://programmers.co.kr/learn/courses/30/lessons/42583</b>


<br/><br/><br/><br/><br/><br/>


### 문제 풀이<b>

<br/><br/><br/>
문제가 조오금 쉬운 감이 없지 않아 있는데, 2019년 라인에서 비슷한 유형의 문제가 나왔다고 한다. 한번 쯤 체험하고 가는 것도 나쁘지 않다.

참고로 "트럭 여러 대가 강을 가로지르는 일 차선 다리를 정해진 순으로 건너려 합니다." 이걸 못 보고 최소 시간이 걸리도록 버스 순서를 정해주다가 참교육 당하고 바꿨다. 저 조건 없었으면 꽤 어려웠을텐데, 있으면 매우 쉬워진다.

그냥 1초씩 카운트하는 while문을 만들고, 그 안에서 버스를 큐에 넣고 현재 시간 - 큐에 넣은 시간 = 다리 길이가 되면 큐에서 빼면 된다. 버스를 넣을 땐 현재 큐에 들어간 버스 무게의 합을 체크해서 넣을 수 있는지 없는지만 판단해주면 끝난다.

```c++
while(!q.empty()){
    answer++; // 한 바퀴 돌 때마다 1초씩 카운트
    int w = q.front().first, t = q.front().second; // 맨 첨에 넣은 버스 가져오기
    
    // 현재 시각과 뺀 버스의 넣은 시점의 시간의 차가 다리 길이랑 같아지면 == 다리를 건넜으면
    // 큐에서 빼고 현재 큐에 들어가있는 버스들의 무게의 합에서 해당 버스의 무게를 빼준다.
    if(answer - t == bridge_length){  
        q.pop();
        curr_weight -= w;
    }

    // 매 바퀴마다 다음에 출발할 준비를 하고 있는 버스를 체크하면서, 그 버스가 다리 위에 올려도
    // 무게 초과 안하는지 체크하면서, 초과 안하면 큐에 넣고 무게 합에 추가하고, 기다리는 버스의
    // 인덱스를 한칸 옮겨준다.
    if(curr_idx < truck_weights.size() && curr_weight + truck_weights[curr_idx] <= weight){ 
        q.push(make_pair(truck_weights[curr_idx], answer));
        curr_weight += truck_weights[curr_idx];
        curr_idx++;
    }
}
```
끗.
</b>
</span>
