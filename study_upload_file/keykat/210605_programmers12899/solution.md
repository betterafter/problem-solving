<span style="font-family:Lato,PingFang SC,Microsoft YaHei,sans-serif">

## programmers 12899 - 124나라의 숫자


### 문제 
<b>https://programmers.co.kr/learn/courses/30/lessons/12899</b>


<br/><br/><br/><br/><br/><br/>


### 문제 풀이<b>
굉장히 수학적인 문제여서 막상 코드는 무척 짧다.
1,2,4개로 모든 수를 만드는 건 마치 3진법과 같이 작동하는데, 그래서 3을 나눠주면서 연산하면 대충 맞아 떨어진다. 그래서 나눈 몫을 인덱스로 둘 때 [4,1,2]를 꺼내다 쓰면 된다.
다만 3진법에는 0,1,2로 연산을 하는데, 0이 맨 앞으로 오지 못해서 자리수를 하나 증가시키게 된다. 반대로 124진법에선 3의 배수로 딱 나눠 떨어지면 자릿수를 1 증가시키는게 아니기 때문에 나눈 몫에서 1을 빼주어야 한다.

</span>
