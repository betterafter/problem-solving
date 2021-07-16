<span style="font-family:Lato,PingFang SC,Microsoft YaHei,sans-serif">

## programmers 60057 - 문자열 압축


### 문제 
<b>https://programmers.co.kr/learn/courses/30/lessons/60057</b>


<br/><br/><br/><br/><br/><br/>


### 문제 풀이<b>

길이 1씩 끊어서 압축, 2씩 끊어서 압축, ... 의 과정을 반복한다. 
즉 
aabbccdd이면
1씩 끊어서 압축 : a a b b c c d d -> (a a) (b b) (c c) (d d) -> 2a 2b 2c 2d 인 셈이다.
따라서 전체 길이만큼 반복문을 돌려서 문자열을 끊고, 끊을 때마다 체크해주면 된다.
위의 예시로 

1. a
2. a a -> 앞이랑 뒤랑 체크해보니 압축 가능 -> 2a
3. (a a) b -> 이건 압축 불가능하므로 그대로  
4. (a a) (b b) -> 압축 가능 -> 2a 2b
...

이런 식이다. 
결국 현재까지 끊은 문자열과 바로 앞까지 끊은 문자열이 같은지 판단하라는 얘기


</span>
