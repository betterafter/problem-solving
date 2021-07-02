<span style="font-family:Lato,PingFang SC,Microsoft YaHei,sans-serif">

## programmers 64064 - 불량 사용자


### 문제 
<b>https://programmers.co.kr/learn/courses/30/lessons/64064</b>


<br/><br/><br/><br/><br/><br/>


### 문제 풀이<b>

파이썬의 permutaions를 이용하면 쉽게 풀 수 있었다. 
user_id에서 banned_id 길이 만큼 뽑아서 순열을 만들어주고, 만들어진 순열 원소와 banned_id와 매칭이 되는지 체크.
이 때 같은 아이디 목록이 나올 수 있으므로 중복되는 것은 제거하던가, 사전에 미리 체크를 해주어야 한다.

매칭된 user_id 리스트를 소팅 후 튜플로 만들고 set에 넣어주면 편하게 중복 제거할 수 있다.



</span>
