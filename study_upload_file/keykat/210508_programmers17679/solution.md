<span style="font-family:Lato,PingFang SC,Microsoft YaHei,sans-serif">

## programmers 17679 - 프렌즈 4블록


### 문제 
<b>https://programmers.co.kr/learn/courses/30/lessons/17679</b>


<br/><br/><br/><br/><br/><br/>


### 문제 풀이<b>

배열 보고 dfs & bfs 유형인 줄 알았는데 그냥 구현해서 풀어도 되는 문제였음. 
dfs로 붙어 있는 것들 묶어서 다 터트려도 되기는 한데, 오히려 이쪽이 구현하기 더 빡셈.

(0,0) ~ (n,m)까지 돌면서, 해당 좌표 기준으로 오른쪽, 아래쪽, 대각선 아래쪽이 같은 모양이면 임시 맵에 전부 x로 바꿔줌 (터졌다는 얘기). 미리 터트리면 붙어있는 것에 대해서 처리를 못하니까 임시맵에만 터진 표시 해주고 메인맵에서는 계속 같은 모양끼리 묶어서 임시맵에 있는 그룹 터트리면 됨.

다 터트렸으면 메인맵을 터트린 맵으로 업데이트해주고, 메인맵을 '아래쪽부터' 탐색하면서 현재 좌표의 원소의 아래쪽이 빈공간이면 빈공간이 안나올때까지 좌표를 찾아서 내려주기만 하면 됨.

이 과정을 더이상 못 터트릴 때까지 반복.

```
void remove(int m, int n){
     for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            m2[i][j] = m1[i][j];
        }
    }
    isRmd = false;
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            char curr = m1[i][j];
            if(curr != 'x' && m1[i][j + 1] == curr && m1[i + 1][j] == curr && m1[i + 1][j + 1] == curr){
                m2[i][j] = 'x'; 
                m2[i][j + 1] = 'x'; 
                m2[i + 1][j] = 'x'; 
                m2[i + 1][j + 1] = 'x';
                isRmd = true;
            }
        }
    }
}
```
m1이 메인맵, m2가 임시맵이며, m1에서 터트릴 묶음 찾고, m2에서 터트리고난 후 공간을 빈공간으로 업데이트하는 과정 반복. isRmd = false 상태로 끝나면 터트린 적이 없다는 뜻으로 체크해주는 것임.

```
void down(int m, int n){
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            m1[i][j] = m2[i][j];
        }
    }
    for(int i = m - 1; i >= 0; i--){
        for(int j = 0; j < n; j++){
            if(m1[i][j] != 'x' && m1[i + 1][j] == 'x'){
                int h = i + 1;
                while(true){
                    if(m1[h][j] == 'x'){
                        h++;
                    }
                    if(h > m - 1 || m1[h][j] != 'x'){
                        h--; break;
                    }
                }
                m1[h][j] = m1[i][j]; m1[i][j] = 'x';
            }
        }
    }
}
```
현재 좌표 기준 아래 좌표가 빈공간이면, 빈공간이 안나올때까지 쭉 내려줌.

```
 while(isRmd){
        remove(m, n);
        down(m, n);
    }

```
이 과정을 계속 반복해주면 끝

</b>
</span>
