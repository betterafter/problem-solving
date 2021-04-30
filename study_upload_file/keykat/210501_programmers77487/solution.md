<span style="font-family:Lato,PingFang SC,Microsoft YaHei,sans-serif">

## programmers 77487 - 헤비 유저가 소유한 장소


### 문제 
<b>https://programmers.co.kr/learn/courses/30/lessons/77487</b>


<br/><br/><br/><br/><br/><br/>


### 문제 풀이<b>

문제 요약
"이 서비스에서는 공간을 둘 이상 등록한 사람을 "헤비 유저"라고 부릅니다. 헤비 유저가 등록한 공간의 정보를 아이디 순으로 조회하는 SQL문을 작성해주세요."

그냥 이거 구하면 됨

프로그래머스 중소기업 대상 인턴쉽 문제들 풀면 자주 나오는 SQL 문제. 꼭 마지막에 1개는 나오더라. 버리기는 아까워서 그냥 들고옴.

```sql
select *
from places
where host_id in (
    select host_id 
    from places
    group by host_id
    having count(host_id) >= 2
)
order by id
```
host_id에 대하여 그룹으로 묶어주고, 2 이상인 것들만 냅두고 나머지는 다 버리고, 그런 host_id에 대해서 id순으로 정렬해주면 끝.

</b>
</span>
