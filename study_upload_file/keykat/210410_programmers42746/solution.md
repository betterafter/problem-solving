<span style="font-family:Lato,PingFang SC,Microsoft YaHei,sans-serif">

## programmers 42746 - 가장 큰 수


### 문제 
<b>https://programmers.co.kr/learn/courses/30/lessons/42746</b>


<br/><br/><br/><br/><br/><br/>


### 문제 풀이<b>

<br/><br/><br/>
"예 날먹입니다. 문제 예시도 같은 건 좀..."

문제에 대한 설명은 하지 않겠다. 파이썬에서 삽입 정렬로 푸는 방법을 알았으니, c++에서는 어떻게 풀 수 있는지 알아보자.

```c++
#include <string>
#include <vector>
#include <math.h>
#include <algorithm>

using namespace std;

bool compare(string a, string b){
    return a + b > b + a;
}

string solution(vector<int> numbers) {
    string answer = "";
    vector<string> ns;
    for(int i = 0; i < numbers.size(); i++){
        ns.push_back(to_string(numbers[i]));
    }

    sort(ns.begin(), ns.end(), compare);

    for(int i = 0; i < ns.size(); i++){
        answer += ns[i];
    }
    if(answer[0] == '0') return "0";
    return answer;
}
```
보고 말 것도 없다. compare함수를 만들어서 규칙에 맞게 소팅해게끔 만들어주면 된다. 두개를 붙여봐서 더 크게 만들어지는 걸로 반환해주면 끝이다. 맨 앞쪽이 0이 나온다는 것은 뒤에 있는 것도 무조건 0이라는 뜻이므로 그냥 0을 반환해주면 된다. 끗.

</b>
</span>
