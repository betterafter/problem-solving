<span style="font-family:Lato,PingFang SC,Microsoft YaHei,sans-serif">

## programmers 17677 - 뉴스 클러스터링


### 문제 
<b>https://programmers.co.kr/learn/courses/30/lessons/17677</b>


<br/><br/><br/><br/><br/><br/>


### 문제 풀이<b>
구현 문제. 문제에서 하라는대로 그대로 하면 된다. 

FRANCE	french는 문제에 예시가 있으므로 참고하면 되고,
aa1+aa2	AAAA12 같은 경우를 보면,

aa1+aa2
-> {aa, a1, a+, +a, aa, a2} -> {aa, aa}

AAAA12
-> {AA, AA, AA, A1, A2} -> {AA, AA, AA} -> {aa, aa, aa}

합집합 : {aa, aa, aa}
교집합 : {aa, aa}

을 계산하면 된다.

어차피 문장열 길이가 1000자 밖에 안되서 반복문을 3번씩 중첩해서 돌리는 경우가 아닌 이상 어지간하면 터질 일은 없을거라고 생각해서, map으로 다중집합 형태를 만들었다. 위의 경우에선
{aa, ab, aa bc} 라는 것이 있으면
m[aa] = 2
m[ab] = 1
m[bc] = 1
와 같은 식으로.

이렇게 각각 다중 집합을 만들어서 두개의 다중집합을 완전 탐색했음. 심지어 생각하기 귀찮아서 합집합의 개수를 셀 때는 첫번째 다중집합에서 뽑을 수 있는걸 반복문을 돌려서 센 다음에 두번째 다중집합에서 뽑을 수 있는걸 또 반복문으로 돌리는 짓을 했는데도 시간 초과가 안남.

```
// 여기서 첫번째 다중집합에 대한 교집합과 합집합의 원소들이 될 수 있는 것을 찾고
map<string, int> :: iterator iter;
    for(iter = m1.begin(); iter != m1.end(); iter++){
        string key = iter -> first;
        int value = iter -> second;
        bool both = false;
        map<string, int> :: iterator iter2;
        for(iter2 = m2.begin(); iter2 != m2.end(); iter2++){
            string key2 = iter2 -> first;
            int value2 = iter2 -> second;
            if(key == key2){
                res1 += max(value, value2);
                res2 += min(value, value2);
                both = true;
                break;
            }
        }
        if(!both){ 
            res1 += value;
        }
    }
// 두번째 다중집합에 대해서도 또 반복문을 돌렸음
map<string, int> :: iterator iter3;
    for(iter3 = m2.begin(); iter3 != m2.end(); iter3++){
        string key = iter3 -> first;
        int value = iter3 -> second;
        bool both = false;
        map<string, int> :: iterator iter2;
        for(iter2 = m1.begin(); iter2 != m1.end(); iter2++){
            string key2 = iter2 -> first;
            int value2 = iter2 -> second;
            if(key == key2){
                both = true;
                break;
            }
        }
        if(!both){ 
            res1 += value;
        }
    }
```

시간 복잡도 없이 그냥 구현을 할 수 있는지 묻는 문제인 것 같다.

</b>
</span>
