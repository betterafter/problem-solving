<span style="font-family:Lato,PingFang SC,Microsoft YaHei,sans-serif">

## programmers 72410 - 신규 아이디 추천


### 문제 
<b>https://programmers.co.kr/learn/courses/30/lessons/72410</b>


<br/><br/><br/><br/><br/><br/>


### 문제 풀이<b>
기본적인 구현 및 문자열 처리 유형의 문제이며, 제시한 단계별 조건을 그대로 따라하면 충분히 풀 수 있다. 참고로 제한사항에 new_id의 길이가 1~1000자의 문자열이므로 O(n^3^)의 시간까지도 어느 정도 커버가 가능하기 때문에 시간복잡도는 크게 고려하지 않아도 된다. 단계 별로 보도록 하자.

<br><br>
<i>1단계 new_id의 모든 대문자를 대응되는 소문자로 치환합니다.</i>
```java
for(int i = 0; i < new_id.length(); i++){
        new_id[i] = tolower(new_id[i]);
}
```
<br><br>
<i>2단계 new_id에서 알파벳 소문자, 숫자, 빼기(-), 밑줄(_), 마침표(.)를 제외한 모든 문자를 제거합니다.</i>
```java
string step1 = "";
for(int i = 0; i < new_id.length(); i++){
    if((new_id[i] >= 'a' && new_id[i] <= 'z') || new_id[i] == '.' || new_id[i] == '-' || new_id[i] == '_' 
    || (new_id[i] >= '0' && new_id[i] <= '9')){
        step1 += new_id[i];
    }
}
```
new_id를 탐색하면서 a ~ z, 마침표( . )  , 빼기( - ),  언더바( _ ), 1 ~ 9만 붙이고 나머지는 건너뒨다.


<br><br>
<i>3단계 new_id에서 마침표(.)가 2번 이상 연속된 부분을 하나의 마침표(.)로 치환합니다.</i>
```java
string step2 = ""; step2 += step1[0];
for(int i = 1; i < step1.length(); i++){
    
    if(step1[i] != '.'){
        step2 += step1[i];
    }

    else if(step1[i] == '.'){
        if(step1[i - 1] != '.'){
            step2 += step1[i];
        }
    }
}
```
탐색하면서 마침표( . )가 아니면 이어 붙이고, 마침표( . )일 경우 이전 index의 캐릭터가 마침표가 아닐 때만 이어 붙인다.

<br><br>
<i>4단계 new_id에서 마침표(.)가 처음이나 끝에 위치한다면 제거합니다.</i>
```java
string step3 = "";
if(step2[0] != '.'){
    step3 += step2[0];
}
for(int i = 1; i < step2.length() - 1; i++){
    step3 += step2[i];
}
if(step2[step2.length() - 1] != '.'){
    step3 += step2[step2.length() - 1];
}
```
처음 index의 캐릭터가 마침표가 아니면 이어붙이고, 1 ~ index - 1번 캐릭터를 모두 이어붙인 후, 마지막 index도 0번 index와 같이 처리한다.

<br><br>
<i>5단계 new_id가 빈 문자열이라면, new_id에 "a"를 대입합니다.</i>
```java
string step4 = "";
if(step3.length() <= 0){
    step4 = "a";
}
else step4 = step3;
```

<br><br>
<i>6단계 new_id의 길이가 16자 이상이면, new_id의 첫 15개의 문자를 제외한 나머지 문자들을 모두 제거합니다.
     만약 제거 후 마침표(.)가 new_id의 끝에 위치한다면 끝에 위치한 마침표(.) 문자를 제거합니다.</i>
```java
string step5 = "";
if(step4.length() >= 16){
    for(int i = 0; i < 15; i++){
        step5 += step4[i];
    }

    if(step5[14] == '.'){
        step5 = step5.substr(0, 14);
    }
}
else step5 = step4;
```
16자리 이상이면 15개 문자를 전부 이어붙인 후에 마지막 문자가 마침표라면 다시 0 ~ 14번까지만 substr로 추출한다.

<br><br>
<i>7단계 new_id의 길이가 2자 이하라면, new_id의 마지막 문자를 new_id의 길이가 3이 될 때까지 반복해서 끝에 붙입니다.</i>
```java
string step6 = "";
if(step5.length() <= 2){
    for(int i = 0; i < step5.length(); i++){
        step6 += step5[i];
    }
    while(step6.length() < 3){
        step6 += step5[step5.length() - 1];
    }
}
else step6 = step5;
```
new_id의 길이가 2이하라면, 일단 헌재까지 만든 id를 복사하고, 길이가 3이 될 때까지 마지막 index의 문자를 복사하고 이어붙인다.

</b>
</span>
