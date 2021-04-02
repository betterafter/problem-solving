<span style="font-family:Lato,PingFang SC,Microsoft YaHei,sans-serif">

## programmers 42839 - 소수 찾기


### 문제 
<b>https://programmers.co.kr/learn/courses/30/lessons/42839</b>


<br/><br/><br/><br/><br/><br/>


### 문제 풀이<b>

<br/><br/><br/>
17 -> 1, 7, 17, 71의 숫자를 만들 수 있고 이 중에 소수는 7, 17, 71이다. 이와 같이 주어진 숫자 카드 중에서 만들 수 있는 수 중에 소수를 뽑아오면 되는 것이다.

딱 봐도 dfs를 돌려서 만들 수 있는 모든 수를 구하고, 그 중에서 에라토스테네스의 체로 소수를 구하면 끝나는 문제이다. 문제 분류가 완전 탐색인 이유는 모든 숫자를 찾아야하고, 그 중에서 소수를 전부 뒤져야되서 그런가보다.

```c++
void dfs(int length, int maxLength, int visited[], string number){
    
    if(number.length() == length){
        int nnn = atoi(number.c_str());
        if(isPrime(nnn)){
            nn.insert(nnn);
        }
        return;
    }

    for(int i = 0; i < maxLength; i++){
        if(visited[i] == 0){
            visited[i] = 1;
            dfs(length, maxLength, visited, number + n[i]);
            visited[i] = 0;
        }
    }
}
```
그냥 dfs를 돌리면서 만들 수 있는 모든 수의 조합을 찾아주면 된다. 가령 1234가 있으면, 1을 선택하고 2, 3, 4 중에 뽑고 싶으면 하나 뽑고, 나머지 중에 또 뽑고 싶으면 하나 뽑고,... 이런 식이다. 따라서 만들고자 하는 수의 길이가 1개 짜리인지, 4개 짜리인지도 구별해야 한다.

위의 코드에서
```c++
if(number.length() == length){
        int nnn = atoi(number.c_str());
        if(isPrime(nnn)){
            nn.insert(nnn);
        }
        return;
    }
```
이 부분이 길이를 체크하는 부분이다. 현재까지 만든 수의 길이가 의도한 길이와 같을 경우, 그게 소수인지 체크하고 뱉어내면 된다.

```c++
  for(int i = 0; i < maxLength; i++){
        if(visited[i] == 0){
            visited[i] = 1;
            dfs(length, maxLength, visited, number + n[i]);
            visited[i] = 0;
        }
    }
```
여기에서 수들의 조합을 뽑아낸다. 1234를 예를 들자면 1 ~ 4까지 하나 정하고, 그게 사용된 숫자인지 체크하고, 사용 안됐으면 그 수를 뽑아서 나머지 숫자를 가지고 dfs를 다시 돌리면 된다. 대신 dfs가 전부 끝났으면 사용 체크는 다시 체크를 해제해야 겠다.

```c++
bool isPrime(int n){
    if(n == 0 || n == 1) return false;
    if(n == 2) return true;
    for(int i = 2; i * i <= n; i++){
        if(n % i == 0) return false;
    }
    return true;
}
```
이번엔 에라토스테네스 체의 가장 대표적인 형태이다. 0, 1은 소수가 아니므로 제끼고, 2는 소수이므로 true를 반환해주면 된다.
이제 만든 수를 2 ~ n^(1/2)로 나눠서 나머지가 0이게 되면 해당 수는 소수가 아닌 합성수이므로 false를 반환하면 된다. 즉 2로 나눠지면 만든 수는 2의 배수이고, 3으로 나눠지면 3의 배수이게 되는 것이다.
루트 n까지만 탐색한 이유는, 어차피 2 ~ 루트 n까지 수로 걸러지게 되면, 루트 n부터 n까지 수로도 걸러지게 되기 때문이다. (어차피 n은 n보다 작은 i와 n / i와의 곱이니까, 1 ~ n 까지에 i와 n / i가 모두 들어가 있을 수 밖에 없음.)

결과적으로 위의 체로 만들어진 수를 소수판별하기만 하면 끝이다.
</b>
</span>
